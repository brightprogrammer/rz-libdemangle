// SPDX-FileCopyrightText: 2025 RizinOrg <info@rizin.re>
// SPDX-FileCopyrightText: 2025 Siddharth Mishra <admin@brightprogrammer.in>
// SPDX-License-Identifier: LGPL-3.0-only

#include "demangle.h"

#include <stdio.h>

#include "demangler_util.h"


// See issue :
//   https://github.com/rizinorg/rz-libdemangle/issues/8
//
// For name mangling scheme for GNU v2 ABI, see section 8.4 (Gnu v2 name mangling)
//   https://github.com/rizinorg/rizin/files/6154867/calling_conventions.pdf
//
// A better formatted document can be found here :
//   https://kb.brightprogrammer.in/s/15fd1dd9-d47d-4ec1-9339-7c111db41ab5
//
// For name mangling scheme for GNU v3 ABI, see
//   https://itanium-cxx-abi.github.io/cxx-abi/abi.html#mangling-structure

/**
 * \b String iterator
 **/
typedef struct StrIter {
    const char* beg; /**< \b Beginning position of string. */
    const char* end; /**< \b Ending of string (usually points to the null-terminator char). */
    const char* cur; /**< \b Current read position. */
} StrIter;

typedef struct Demdem {
    StrIter      original;
    DemString*   demangled;
    CpDemOptions opts;
} CpDem;

static CpDem*      cpdem_init (CpDem* dem, const char* mangled, CpDemOptions opts);
static const char* cpdem_get_demangled (CpDem* dem);
static CpDem*      cpdem_public_name (CpDem* dem);

/**
 * \b Takes a mangled input, and returns corresponding demangled form.
 *
 * The returned string is allocated new. It is the responsibility of caller to
 * free the returned string.
 *
 * \p mangled : Mangled input.
 * \p opts : Options for demangling.
 *
 * \return Demangled output on success.
 * \return NULL otherwise.
 */
const char* cp_demangle (const char* mangled, CpDemOptions opts) {
    if (!mangled) {
        fprintf (stderr, "invalid arguments\n");
        return NULL;
    }

    CpDem dem = {0};
    return cpdem_get_demangled (cpdem_public_name (cpdem_init (&dem, mangled, opts)));
}

static CpDem* cpdem_deinit (CpDem* dem);
static CpDem* cpdem_qualifiers_list (CpDem* dem);
static CpDem* cpdem_name (CpDem* dem);
static CpDem* cpdem_class_names (CpDem* dem, ut64 qualifiers_count);
static CpDem* cpdem_func_params (CpDem* dem);

// Current read position
// NOTE that this returns char* (pointer) instead of char
#define CUR(dem)           ((dem)->original.cur)
#define BEG(dem)           ((dem)->original.beg)
#define END(dem)           ((dem)->original.end)
#define IN_RANGE(dem, pos) ((pos) >= BEG (dem) ? ((pos) < END (dem) ? 1 : 0) : 0)
#define SET_CUR(dem, pos)  ((dem)->original.cur = IN_RANGE (dem, pos) ? (pos) : CUR (dem))

// Read but don't advance
#define PEEK(dem) (IN_RANGE (dem, CUR (dem)) ? *(dem)->original.cur : 0)

// Read and advance one position
#define READ(dem) (IN_RANGE (dem, CUR (dem)) ? *(dem)->original.cur++ : 0)

// Advance by one character
// NOTE that this returns char* (pointer) instead of char
#define ADV(dem) (IN_RANGE (dem, CUR (dem)) ? (dem)->original.cur++ : NULL)

// Is current character a terminator
#define IS_TERM(dem) (IN_RANGE (dem, CUR (dem)) && ((PEEK (dem) == '.') || (PEEK (dem) == '$')))

CpDem* cpdem_init (CpDem* dem, const char* mangled, CpDemOptions opts) {
    if (!dem || !mangled) {
        return NULL;
    }

    memset (dem, 0, sizeof (CpDem));
    dem->original =
        ((StrIter) {.beg = mangled, .end = mangled + strlen (mangled) + 1, .cur = mangled});
    dem->opts      = opts;
    dem->demangled = dem_string_new();
    return dem;
}

CpDem* cpdem_deinit (CpDem* dem) {
    if (!dem) {
        return NULL;
    }

    dem_string_free (dem->demangled);
    memset (dem, 0, sizeof (CpDem));
    return dem;
}

const char* cpdem_get_demangled (CpDem* dem) {
    if (!dem) {
        return NULL;
    }

    const char* result =
        dem_str_ndup (dem_string_buffer (dem->demangled), dem_string_length (dem->demangled));

    cpdem_deinit (dem);
    return result;
}

CpDem* cpdem_public_name (CpDem* dem) {
    if (!dem) {
        return NULL;
    }

    // _
    if (PEEK (dem) == '_') {
        ADV (dem);

        // _ <qualifiers list> <list term> <name>
        if (!cpdem_qualifiers_list (dem) || !IS_TERM (dem) || !ADV (dem) || !cpdem_name (dem)) {
            return NULL;
        }
    } else {
        // <name>
        if (!cpdem_name (dem)) {
            return NULL;
        }

        // <name> __F [<parameter type>]+
        if (!strncmp (CUR (dem), "__F", 3)) {
            SET_CUR (dem, CUR (dem) + 3);
            return cpdem_func_params (dem);
        } else {
            // <name> __ <qualifiers list> [<parameter type>]+
            return cpdem_func_params (cpdem_qualifiers_list (dem));
        }
    }

    return dem;
}

CpDem* cpdem_qualifiers_list (CpDem* dem) {
    if (!dem) {
        return NULL;
    }

    char* end             = NULL;
    ut64  qualifier_count = 1;

    // if more than 1 qualifier
    // Q
    if (PEEK (dem) == 'Q') {
        ADV (dem);

        // if more than 9 qualifiers
        // Q _
        if (PEEK (dem) == '_') {
            ADV (dem);

            // Q _ <qualifiers count> _
            qualifier_count = strtoull (CUR (dem), &end, 10);
            if (*end != '_' || !qualifier_count) {
                return NULL;
            }
        } else {
            // Q <qualifiers count>
            qualifier_count = strtoull (CUR (dem), &end, 10);
            if (!*end || !qualifier_count) {
                return NULL;
            }
        }
    }

    // update current position
    SET_CUR (dem, end);

    // get each qualifier
    // <qualifiers count> [<name length> <class name>]+
    return cpdem_class_names (dem, qualifier_count);
}

CpDem* cpdem_name (CpDem* dem) {
    if (!dem) {
        return NULL;
    }

    // match character by character
    while (PEEK (dem)) {
        dem_string_append_char (dem->demangled, READ (dem));

        // __ [F | Q | [0-9]]
        // If a qualifier(s) list or a function parameter(s) list starts then name ends there
        if (IN_RANGE (dem, CUR (dem) + 2)) {
            const char* cur = CUR (dem);
            if (cur[0] == '_' && cur[1] == '_' &&
                (cur[2] == 'F' || cur[2] == 'Q' || IS_DIGIT (cur[2]))) {
                break;
            }
        }
    }

    return dem;
}

CpDem* cpdem_class_names (CpDem* dem, ut64 qualifiers_count) {
    if (!dem || !qualifiers_count) {
        return NULL;
    }

    // temporary string to append class/namespace names in order
    DemString* class_names = dem_string_new();

    // get each qualifier and append in class names list
    while (qualifiers_count--) {
        // <name length>
        char* end         = NULL;
        ut64  name_length = strtoull (CUR (dem), &end, 10);
        if (!*end || !name_length) {
            return NULL;
        }
        SET_CUR (dem, end);

        // <name length> <class name>
        dem_string_append_n (class_names, CUR (dem), name_length);
        dem_string_append_n (class_names, "::", 2);
        SET_CUR (dem, CUR (dem) + name_length);
    }

    dem_string_append_prefix_n (
        dem->demangled,
        dem_string_buffer (class_names),
        dem_string_length (class_names)
    );
    dem_string_free (class_names);

    return dem;
}

CpDem* cpdem_func_params (CpDem* dem) {
    if (!dem) {
        return NULL;
    }

    DemString* param_list = dem_string_new();
    dem_string_append_char (param_list, '(');

#define APPEND(x)                                                                                  \
    {                                                                                              \
        first_param = first_param ? (dem_string_append (param_list, x), false) :                   \
                                    (dem_string_append (param_list, ", " x), false);               \
        break;                                                                                     \
    }

    bool first_param = true;
    while (PEEK (dem)) {
        switch (READ (dem)) {
            case 'b' :
                APPEND ("bool");
            case 'c' :
                APPEND ("char");
            case 'd' :
                APPEND ("double");
            case 'e' :
                APPEND ("...");
            case 'f' :
                APPEND ("float");
            case 'i' :
                APPEND ("int");
            case 'l' :
                APPEND ("long int");
            case 'r' :
                APPEND ("long double");
            case 's' :
                APPEND ("short int");
            case 'w' :
                APPEND ("wchar_t");
            case 'x' :
                APPEND ("long long");
            case 'U' :
                switch (READ (dem)) {
                    case 'c' :
                        APPEND ("unsigned char");
                    case 's' :
                        APPEND ("unsigned short int");
                    case 'i' :
                        APPEND ("unsigned int");
                    case 'l' :
                        APPEND ("unsigned long int");
                    case 'x' :
                        APPEND ("unsigned long long");
                    default :
                        break;
                }
                break;
            case 'S' :
                switch (READ (dem)) {
                    case 'c' :
                        APPEND ("signed char");
                    default :
                        break;
                }
                break;
            case 'J' :
                switch (READ (dem)) {
                    case 'f' :
                        APPEND ("__complex__ float");
                    case 'd' :
                        APPEND ("__complex__ double");
                    default :
                        break;
                }
                break;
            default :
                break;
        }
    }

#undef APPEND

    // there mustn't be anything else after parsing all function param types
    if (PEEK (dem)) {
        dem_string_free (param_list);
        return NULL;
    }

    dem_string_append_char (param_list, ')');

    dem_string_append_n (
        dem->demangled,
        dem_string_buffer (param_list),
        dem_string_length (param_list)
    );
    dem_string_free (param_list);

    return dem;
}