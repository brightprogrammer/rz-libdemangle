// SPDX-FileCopyrightText: 2023 deroad <wargio@libero.it>
// SPDX-License-Identifier: LGPL-3.0-only

#include "minunit.h"

mu_demangle_tests(gnu_v2,
	// fuzzed strings
	mu_demangle_test("_ITM_deregisterTMCCCCCCCCCCCCCCCCCCCtart__5555555555555555CloneTable", NULL),
	// normal
	mu_demangle_test("_vt.foo", "foo virtual table"),
	mu_demangle_test("_vt$foo", "foo virtual table"),
	mu_demangle_test("_vt$foo$bar", "foo::bar virtual table"),
	mu_demangle_test("__vt_foo", "foo virtual table"),
	mu_demangle_test("_3foo$varname", "foo::varname"),
	mu_demangle_test("__thunk_4__$_7ostream", "virtual function thunk (delta:-4) for ostream::~ostream(void)"),
	mu_demangle_test("_$_3foo", "foo::~foo(void)"),
	mu_demangle_test("_._3foo", "foo::~foo(void)"),
	mu_demangle_test("_Q22rs2tu$vw", "rs::tu::vw"),
	mu_demangle_test("__t6vector1Zii", "vector<int>::vector(int)"),
	mu_demangle_test("foo__1Ai", "A::foo(int)"),
	mu_demangle_test("foo__1Afe", "A::foo(float,...)"),
	mu_demangle_test("_AddColor__10ZafDisplayUcUcUcUcUc", "ZafDisplay::_AddColor(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char)"),
	mu_demangle_test("I_EEEEET_PNS0_7IsolateENS0_7Runtime10FunctionIdEPKNS2_16TSCallDescriptorENS2_7OpIndexESU_RKT0_", NULL),
	// end

	// the following tests are taken from : https://github.com/abelbriggs1/gnu2-demangler/blob/master/tests/test_demangler.py
	// and modified both before and after modification code is licensed under LGPL-v3-only
	mu_demangle_test("saveOnQuitOverlay__Fv", "saveOnQuitOverlay(void)"),
	mu_demangle_test("textShake__FiPi", "textShake(int, int *)"),
	mu_demangle_test("InitRTState__5Shell", "Shell::InitRTState(void)"),
	mu_demangle_test("Check__6UArrayi", "UArray::Check(int)"),
	mu_demangle_test("updateBlimpWeaponState__16PrisonLevelSoundii", "PrisonLevelSound::updateBlimpWeaponState(int, int)"),
	mu_demangle_test("Round__Ff", "Round(float)"),

	mu_demangle_test("AddAlignment__9ivTSolverUiP12ivInteractorP7ivTGlue", "ivTSolver::AddAlignment(unsigned int, ivInteractor *, ivTGlue *)"),
	mu_demangle_test("ArrowheadIntersects__9ArrowLineP9ArrowheadR6BoxObjP7Graphic", "ArrowLine::ArrowheadIntersects(Arrowhead *, BoxObj &, Graphic *)"),
	mu_demangle_test("AtEnd__13ivRubberGroup", "ivRubberGroup::AtEnd(void)"),
	mu_demangle_test("BgFilter__9ivTSolverP12ivInteractor", "ivTSolver::BgFilter(ivInteractor *)"),
	mu_demangle_test("CoreConstDecls__8TextCodeR7ostream", "TextCode::CoreConstDecls(ostream &)"),
	mu_demangle_test("CoreConstDecls__8TextCodeO7ostream", "TextCode::CoreConstDecls(ostream &&)"),
	mu_demangle_test("Detach__8StateVarP12StateVarView", "StateVar::Detach(StateVarView *)"),
	mu_demangle_test("Done__9ComponentG8Iterator", "Component::Done(Iterator)"),
	mu_demangle_test("Effect__11RelateManipR7ivEvent", "RelateManip::Effect(ivEvent &)"),
	mu_demangle_test("Effect__11RelateManipO7ivEvent", "RelateManip::Effect(ivEvent &&)"),
	mu_demangle_test("IsAGroup__FP11GraphicViewP11GraphicComp", "IsAGroup(GraphicView *, GraphicComp *)"),
	mu_demangle_test("IsA__10ButtonCodeUl", "ButtonCode::IsA(unsigned long)"),
	mu_demangle_test("ReadName__FR7istreamPc", "ReadName(istream &, char *)"),
	mu_demangle_test("Redraw__13StringBrowseriiii", "StringBrowser::Redraw(int, int, int, int)"),
	mu_demangle_test("Rotate__13ivTransformerf", "ivTransformer::Rotate(float)"),
	mu_demangle_test("SetExport__16MemberSharedNameUi", "MemberSharedName::SetExport(unsigned int)"),
	mu_demangle_test("InsertBody__15H_PullrightMenuii", "H_PullrightMenu::InsertBody(int, int)"),
	mu_demangle_test("InsertCharacter__9TextManipc", "TextManip::InsertCharacter(char)"),
	mu_demangle_test("Set__5DFacePcii", "DFace::Set(char *, int, int)"),
	mu_demangle_test("FindFixed__FRP4CNetP4CNet", "FindFixed(CNet *&, CNet *)"),
	mu_demangle_test("FindFixed__FOP4CNetP4CNet", "FindFixed(CNet *&&, CNet *)"),
	mu_demangle_test("Fix48_abort__FR8twolongs", "Fix48_abort(twolongs &)"),
	mu_demangle_test("Fix48_abort__FO8twolongs", "Fix48_abort(twolongs &&)"),
	mu_demangle_test("GetBgColor__C9ivPainter", "ivPainter::GetBgColor(void) const"),
	mu_demangle_test("Rotated__C13ivTransformerf", "ivTransformer::Rotated(float) const"),
	mu_demangle_test("Set__14ivControlState13ControlStatusUi", "ivControlState::Set(ControlStatus, unsigned int)"),
	mu_demangle_test("GetBarInfo__15iv2_6_VScrollerP13ivPerspectiveRiT2", "iv2_6_VScroller::GetBarInfo(ivPerspective *, int &, int &)"),
	mu_demangle_test("GetBarInfo__15iv2_6_VScrollerP13ivPerspectiveOiT2", "iv2_6_VScroller::GetBarInfo(ivPerspective *, int &&, int &&)"),
	mu_demangle_test("InsertToplevel__7ivWorldP12ivInteractorT1", "ivWorld::InsertToplevel(ivInteractor *, ivInteractor *)"),
	mu_demangle_test("InsertToplevel__7ivWorldP12ivInteractorT1iiUi", "ivWorld::InsertToplevel(ivInteractor *, ivInteractor *, int, int, unsigned int)"),
	mu_demangle_test("VConvert__9ivTSolverP12ivInteractorRP8TElementT2", "ivTSolver::VConvert(ivInteractor *, TElement *&, TElement *&)"),
	mu_demangle_test("VConvert__9ivTSolverP7ivTGlueRP8TElement", "ivTSolver::VConvert(ivTGlue *, TElement *&)"),
	mu_demangle_test("VOrder__9ivTSolverUiRP12ivInteractorT2", "ivTSolver::VOrder(unsigned int, ivInteractor *&, ivInteractor *&)"),

	mu_demangle_test("__aml__5Fix16i", "Fix16::operator*=(int)"),
	mu_demangle_test("__aa__3fooRT0", "foo::operator&&(foo &)"),
	mu_demangle_test("__aad__3fooRT0", "foo::operator&=(foo &)"),
	mu_demangle_test("__ad__3fooRT0", "foo::operator&(foo &)"),
	mu_demangle_test("__adv__3fooRT0", "foo::operator/=(foo &)"),
	mu_demangle_test("__aer__3fooRT0", "foo::operator^=(foo &)"),
	mu_demangle_test("__als__3fooRT0", "foo::operator<<=(foo &)"),
	mu_demangle_test("__amd__3fooRT0", "foo::operator%=(foo &)"),
	mu_demangle_test("__ami__3fooRT0", "foo::operator-=(foo &)"),
	mu_demangle_test("__aml__3FixRT0", "Fix::operator*=(Fix &)"),
	mu_demangle_test("__aml__5Fix32RT0", "Fix32::operator*=(Fix32 &)"),
	mu_demangle_test("__aor__3fooRT0", "foo::operator|=(foo &)"),
	mu_demangle_test("__apl__3fooRT0", "foo::operator+=(foo &)"),
	mu_demangle_test("__ars__3fooRT0", "foo::operator>>=(foo &)"),
	mu_demangle_test("__as__3fooRT0", "foo::operator=(foo &)"),
	mu_demangle_test("__cl__3fooRT0", "foo::operator()(foo &)"),
	mu_demangle_test("__cl__6Normal", "Normal::operator()(void)"),
	mu_demangle_test("__cl__6Stringii", "String::operator()(int, int)"),
	mu_demangle_test("__cm__3fooRT0", "foo::operator, (foo &)"),
	mu_demangle_test("__co__3foo", "foo::operator~(void)"),
	mu_demangle_test("__dl__3fooPv", "foo::operator delete(void *)"),
	mu_demangle_test("__dv__3fooRT0", "foo::operator/(foo &)"),
	mu_demangle_test("__eq__3fooRT0", "foo::operator==(foo &)"),
	mu_demangle_test("__10ivTelltaleiP7ivGlyph", "ivTelltale::ivTelltale(int, ivGlyph *)"),
	mu_demangle_test("__10ivViewportiP12ivInteractorUi", "ivViewport::ivViewport(int, ivInteractor *, unsigned int)"),
	mu_demangle_test("__10ostrstream", "ostrstream::ostrstream(void)"),
	mu_demangle_test("__10ostrstreamPcii", "ostrstream::ostrstream(char *, int, int)"),
	mu_demangle_test("__11BitmapTablei", "BitmapTable::BitmapTable(int)"),
	mu_demangle_test("__12ViewportCodeP12ViewportComp", "ViewportCode::ViewportCode(ViewportComp *)"),
	mu_demangle_test("__12iv2_6_Borderii", "iv2_6_Border::iv2_6_Border(int, int)"),
	mu_demangle_test("__12ivBreak_Listl", "ivBreak_List::ivBreak_List(long)"),
	mu_demangle_test("__14iv2_6_MenuItemiP12ivInteractor", "iv2_6_MenuItem::iv2_6_MenuItem(int, ivInteractor *)"),
	mu_demangle_test("__20DisplayList_IteratorR11DisplayList", "DisplayList_Iterator::DisplayList_Iterator(DisplayList &)"),
	mu_demangle_test("__3fooRT0", "foo::foo(foo &)"),
	mu_demangle_test("__3fooiN31", "foo::foo(int, int, int, int)"),
	mu_demangle_test("__3fooiRT0iT2iT2", "foo::foo(int, foo &, int, foo &, int, foo &)"),
	mu_demangle_test("__6KeyMapPT0", "KeyMap::KeyMap(KeyMap *)"),
	mu_demangle_test("__8ArrowCmdP6EditorUiUi", "ArrowCmd::ArrowCmd(Editor *, unsigned int, unsigned int)"),
	mu_demangle_test("__9F_EllipseiiiiP7Graphic", "F_Ellipse::F_Ellipse(int, int, int, int, Graphic *)"),
	mu_demangle_test("__9FrameDataP9FrameCompi", "FrameData::FrameData(FrameComp *, int)"),
	mu_demangle_test("__9HVGraphicP9CanvasVarP7Graphic", "HVGraphic::HVGraphic(CanvasVar *, Graphic *)"),
	mu_demangle_test("__Q23foo3bar", "foo::bar::bar(void)"),
	mu_demangle_test("__Q33foo3bar4bell", "foo::bar::bell::bell(void)"),

	mu_demangle_test("_$_10BitmapComp", "BitmapComp::~BitmapComp(void)"),
	mu_demangle_test("_$_9__io_defs", "__io_defs::~__io_defs(void)"),
	mu_demangle_test("_$_Q23foo3bar", "foo::bar::~bar(void)"),
	mu_demangle_test("_$_Q33foo3bar4bell", "foo::bar::bell::~bell(void)"),
	mu_demangle_test("__tiv", "void type_info node"),
	mu_demangle_test("__tiUs", "unsigned short type_info node"),
	mu_demangle_test("__tiSc", "signed char type_info node"),
	mu_demangle_test("__ti9type_info", "type_info type_info node"),
	mu_demangle_test("__ti19__builtin_type_info", "__builtin_type_info type_info node"),
	mu_demangle_test("__tiQ210Pedestrian8Strategy", "Pedestrian::Strategy type_info node"),
	mu_demangle_test("__tf13bad_exception", "bad_exception type_info function"),
	mu_demangle_test("__tf17__class_type_info", "__class_type_info type_info function"),
	mu_demangle_test("__tfUx", "unsigned long long type_info function"),

	mu_demangle_test("_GLOBAL_$I$_10Pedestrian$s_animConfig", "global constructors keyed to Pedestrian::s_animConfig"),
	mu_demangle_test("_GLOBAL_$D$hudInfo", "global destructors keyed to hudInfo"),
	mu_demangle_test("_GLOBAL_$I$hudInfo", "global constructors keyed to hudInfo"),

	mu_demangle_test("_10PageButton$__both", "PageButton::__both"),
	mu_demangle_test("_3RNG$singleMantissa", "RNG::singleMantissa"),
	mu_demangle_test("_5IComp$_release", "IComp::_release"),

	mu_demangle_test("_vt$10AttractPed", "AttractPed virtual table"),
	mu_demangle_test("_vt$14CorpseStrategy", "CorpseStrategy virtual table"),
	mu_demangle_test("_vt$17__array_type_info", "__array_type_info virtual table"),

	mu_demangle_test("find__t8_Rb_tree2ZUsZUs", "_Rb_tree<unsigned short, unsigned short>::find(void)"),
	mu_demangle_test("find__t8_Rb_tree5ZUsZt4pair2ZCUsZUsZt10_Select1st1Zt4pair2ZCUsZUsZt4less1ZUsZt9allocator1ZUsRCUs", "_Rb_tree<unsigned short, pair<unsigned short const, unsigned short>, _Select1st<pair<unsigned short const, unsigned short>>, less<unsigned short>, allocator<unsigned short>>::find(unsigned short const &)"),
	mu_demangle_test("_$_t13_Rb_tree_base2Zt4pair2ZCUsZUsZt9allocator1ZUs", "_Rb_tree_base<pair<unsigned short const, unsigned short>, allocator<unsigned short>>::~_Rb_tree_base(void)"),
	mu_demangle_test("_$_t3map4ZUsZUsZt4less1ZUsZt9allocator1ZUs", "map<unsigned short, unsigned short, less<unsigned short>, allocator<unsigned short>>::~map(void)"),
	mu_demangle_test("_S_oom_malloc__t23__malloc_alloc_template1i0Ui", "__malloc_alloc_template<0>::_S_oom_malloc(unsigned int)"),
	mu_demangle_test("_S_chunk_alloc__t24__default_alloc_template2b0i0UiRi", "__default_alloc_template<false, 0>::_S_chunk_alloc(unsigned int, int &)"),
	mu_demangle_test("_M_insert__t8_Rb_tree5ZUiZt4pair2ZCUiZUsZt10_Select1st1Zt4pair2ZCUiZUsZt4less1ZUiZt9allocator1ZUsP18_Rb_tree_node_baseT1RCt4pair2ZCUiZUs", "_Rb_tree<unsigned int, pair<unsigned int const, unsigned short>, _Select1st<pair<unsigned int const, unsigned short>>, less<unsigned int>, allocator<unsigned short>>::_M_insert(_Rb_tree_node_base *, _Rb_tree_node_base *, pair<unsigned int const, unsigned short> const &)"),

	mu_demangle_test("dbsTraverse__FPP9_hierheadPFP9_hierheadP8_fvectorPA3_f_vP8_fvector", "dbsTraverse(_hierhead **, void (*)(_hierhead *, _fvector *, float (*)[3]), _fvector *)"),

	mu_demangle_test("lexicographical_compare__H2ZPCScZPCSc_X01X11_b", "bool lexicographical_compare<signed char const *, signed char const *>(signed char const *, signed char const *)"),

	// the following tests are taken from libiberty/testsuite/demangle-expected in gcc-2.95.3 source code
	// The source code is licensed under GPL v2
	mu_demangle_test("AddAlignment__9ivTSolverUiP12ivInteractorP7ivTGlue", "ivTSolver::AddAlignment(unsigned int, ivInteractor *, ivTGlue *)"),
	mu_demangle_test("ArrowheadIntersects__9ArrowLineP9ArrowheadR6BoxObjP7Graphic", "ArrowLine::ArrowheadIntersects(Arrowhead *, BoxObj &, Graphic *)"),
	mu_demangle_test("AtEnd__13ivRubberGroup", "ivRubberGroup::AtEnd(void)"),
	mu_demangle_test("BgFilter__9ivTSolverP12ivInteractor", "ivTSolver::BgFilter(ivInteractor *)"),
	mu_demangle_test("Check__6UArrayi", "UArray::Check(int)"),
	mu_demangle_test("CoreConstDecls__8TextCodeR7ostream", "TextCode::CoreConstDecls(ostream &)"),
	mu_demangle_test("Detach__8StateVarP12StateVarView", "StateVar::Detach(StateVarView *)"),
	mu_demangle_test("Done__9ComponentG8Iterator", "Component::Done(Iterator)"),
	mu_demangle_test("Effect__11RelateManipR7ivEvent", "RelateManip::Effect(ivEvent &)"),
	mu_demangle_test("FindFixed__FRP4CNetP4CNet", "FindFixed(CNet *&, CNet *)"),
	mu_demangle_test("Fix48_abort__FR8twolongs", "Fix48_abort(twolongs &)"),
	mu_demangle_test("GetBarInfo__15iv2_6_VScrollerP13ivPerspectiveRiT2", "iv2_6_VScroller::GetBarInfo(ivPerspective *, int &, int &)"),
	mu_demangle_test("GetBgColor__C9ivPainter", "ivPainter::GetBgColor(void) const"),
	mu_demangle_test("InsertBody__15H_PullrightMenuii", "H_PullrightMenu::InsertBody(int, int)"),
	mu_demangle_test("InsertCharacter__9TextManipc", "TextManip::InsertCharacter(char)"),
	mu_demangle_test("InsertToplevel__7ivWorldP12ivInteractorT1", "ivWorld::InsertToplevel(ivInteractor *, ivInteractor *)"),
	mu_demangle_test("InsertToplevel__7ivWorldP12ivInteractorT1iiUi", "ivWorld::InsertToplevel(ivInteractor *, ivInteractor *, int, int, unsigned int)"),
	mu_demangle_test("IsAGroup__FP11GraphicViewP11GraphicComp", "IsAGroup(GraphicView *, GraphicComp *)"),
	mu_demangle_test("IsA__10ButtonCodeUl", "ButtonCode::IsA(unsigned long)"),
	mu_demangle_test("ReadName__FR7istreamPc", "ReadName(istream &, char *)"),
	mu_demangle_test("Redraw__13StringBrowseriiii", "StringBrowser::Redraw(int, int, int, int)"),
	mu_demangle_test("Rotate__13ivTransformerf", "ivTransformer::Rotate(float)"),
	mu_demangle_test("Rotated__C13ivTransformerf", "ivTransformer::Rotated(float) const"),
	mu_demangle_test("Round__Ff", "Round(float)"),
	mu_demangle_test("SetExport__16MemberSharedNameUi", "MemberSharedName::SetExport(unsigned int)"),
	mu_demangle_test("Set__14ivControlState13ControlStatusUi", "ivControlState::Set(ControlStatus, unsigned int)"),
	mu_demangle_test("Set__5DFacePcii", "DFace::Set(char *, int, int)"),
	mu_demangle_test("VConvert__9ivTSolverP12ivInteractorRP8TElementT2", "ivTSolver::VConvert(ivInteractor *, TElement *&, TElement *&)"),
	mu_demangle_test("VConvert__9ivTSolverP7ivTGlueRP8TElement", "ivTSolver::VConvert(ivTGlue *, TElement *&)"),
	mu_demangle_test("VOrder__9ivTSolverUiRP12ivInteractorT2", "ivTSolver::VOrder(unsigned int, ivInteractor *&, ivInteractor *&)"),
	mu_demangle_test("_10PageButton$__both", "PageButton::__both"),
	mu_demangle_test("_3RNG$singleMantissa", "RNG::singleMantissa"),
	mu_demangle_test("_5IComp$_release", "IComp::_release"),
	mu_demangle_test("_$_10BitmapComp", "BitmapComp::~BitmapComp(void)"),
	mu_demangle_test("_$_9__io_defs", "__io_defs::~__io_defs(void)"),
	mu_demangle_test("_$_Q23foo3bar", "foo::bar::~bar(void)"),
	mu_demangle_test("_$_Q33foo3bar4bell", "foo::bar::bell::~bell(void)"),
	mu_demangle_test("__10ivTelltaleiP7ivGlyph", "ivTelltale::ivTelltale(int, ivGlyph *)"),
	mu_demangle_test("__10ivViewportiP12ivInteractorUi", "ivViewport::ivViewport(int, ivInteractor *, unsigned int)"),
	mu_demangle_test("__10ostrstream", "ostrstream::ostrstream(void)"),
	mu_demangle_test("__10ostrstreamPcii", "ostrstream::ostrstream(char *, int, int)"),
	mu_demangle_test("__11BitmapTablei", "BitmapTable::BitmapTable(int)"),
	mu_demangle_test("__12ViewportCodeP12ViewportComp", "ViewportCode::ViewportCode(ViewportComp *)"),
	mu_demangle_test("__12iv2_6_Borderii", "iv2_6_Border::iv2_6_Border(int, int)"),
	mu_demangle_test("__12ivBreak_Listl", "ivBreak_List::ivBreak_List(long)"),
	mu_demangle_test("__14iv2_6_MenuItemiP12ivInteractor", "iv2_6_MenuItem::iv2_6_MenuItem(int, ivInteractor *)"),
	mu_demangle_test("__20DisplayList_IteratorR11DisplayList", "DisplayList_Iterator::DisplayList_Iterator(DisplayList &)"),
	mu_demangle_test("__3fooRT0", "foo::foo(foo &)"),
	mu_demangle_test("__3fooiN31", "foo::foo(int, int, int, int)"),
	mu_demangle_test("__3fooiRT0iT2iT2", "foo::foo(int, foo &, int, foo &, int, foo &)"),
	mu_demangle_test("__6KeyMapPT0", "KeyMap::KeyMap(KeyMap *)"),
	mu_demangle_test("__8ArrowCmdP6EditorUiUi", "ArrowCmd::ArrowCmd(Editor *, unsigned int, unsigned int)"),
	mu_demangle_test("__9F_EllipseiiiiP7Graphic", "F_Ellipse::F_Ellipse(int, int, int, int, Graphic *)"),
	mu_demangle_test("__9FrameDataP9FrameCompi", "FrameData::FrameData(FrameComp *, int)"),
	mu_demangle_test("__9HVGraphicP9CanvasVarP7Graphic", "HVGraphic::HVGraphic(CanvasVar *, Graphic *)"),
	mu_demangle_test("__Q23foo3bar", "foo::bar::bar(void)"),
	mu_demangle_test("__Q33foo3bar4bell", "foo::bar::bell::bell(void)"),
	mu_demangle_test("__aa__3fooRT0", "foo::operator&&(foo &)"),
	mu_demangle_test("__aad__3fooRT0", "foo::operator&=(foo &)"),
	mu_demangle_test("__ad__3fooRT0", "foo::operator&(foo &)"),
	mu_demangle_test("__adv__3fooRT0", "foo::operator/=(foo &)"),
	mu_demangle_test("__aer__3fooRT0", "foo::operator^=(foo &)"),
	mu_demangle_test("__als__3fooRT0", "foo::operator<<=(foo &)"),
	mu_demangle_test("__amd__3fooRT0", "foo::operator%=(foo &)"),
	mu_demangle_test("__ami__3fooRT0", "foo::operator-=(foo &)"),
	mu_demangle_test("__aml__3FixRT0", "Fix::operator*=(Fix &)"),
	mu_demangle_test("__aml__5Fix16i", "Fix16::operator*=(int)"),
	mu_demangle_test("__aml__5Fix32RT0", "Fix32::operator*=(Fix32 &)"),
	mu_demangle_test("__aor__3fooRT0", "foo::operator|=(foo &)"),
	mu_demangle_test("__apl__3fooRT0", "foo::operator+=(foo &)"),
	mu_demangle_test("__ars__3fooRT0", "foo::operator>>=(foo &)"),
	mu_demangle_test("__as__3fooRT0", "foo::operator=(foo &)"),
	mu_demangle_test("__cl__3fooRT0", "foo::operator()(foo &)"),
	mu_demangle_test("__cl__6Normal", "Normal::operator()(void)"),
	mu_demangle_test("__cl__6Stringii", "String::operator()(int, int)"),
	mu_demangle_test("__cm__3fooRT0", "foo::operator, (foo &)"),
	mu_demangle_test("__co__3foo", "foo::operator~(void)"),
	mu_demangle_test("__dl__3fooPv", "foo::operator delete(void *)"),
	mu_demangle_test("__dv__3fooRT0", "foo::operator/(foo &)"),
	mu_demangle_test("__eq__3fooRT0", "foo::operator==(foo &)"),
	mu_demangle_test("__er__3fooRT0", "foo::operator^(foo &)"),
	mu_demangle_test("__ge__3fooRT0", "foo::operator>=(foo &)"),
	mu_demangle_test("__gt__3fooRT0", "foo::operator>(foo &)"),
	mu_demangle_test("__le__3fooRT0", "foo::operator<=(foo &)"),
	mu_demangle_test("__ls__3fooRT0", "foo::operator<<(foo &)"),
	mu_demangle_test("__ls__FR7ostreamPFR3ios_R3ios", "operator<<(ostream &, ios &(*)(ios &))"),
	mu_demangle_test("__ls__FR7ostreamR3Fix", "operator<<(ostream &, Fix &)"),
	mu_demangle_test("__lt__3fooRT0", "foo::operator<(foo &)"),
	mu_demangle_test("__md__3fooRT0", "foo::operator%(foo &)"),
	mu_demangle_test("__mi__3fooRT0", "foo::operator-(foo &)"),
	mu_demangle_test("__ml__3fooRT0", "foo::operator*(foo &)"),
	mu_demangle_test("__mm__3fooi", "foo::operator--(int)"),
	mu_demangle_test("__ne__3fooRT0", "foo::operator!=(foo &)"),
	mu_demangle_test("__nt__3foo", "foo::operator!(void)"),
	mu_demangle_test("__nw__3fooi", "foo::operator new(int)"),
	mu_demangle_test("__oo__3fooRT0", "foo::operator||(foo &)"),
	mu_demangle_test("__opPc__3foo", "foo::operator char *(void)"),
	mu_demangle_test("__opi__3foo", "foo::operator int(void)"),
	mu_demangle_test("__or__3fooRT0", "foo::operator|(foo &)"),
	mu_demangle_test("__pl__3fooRT0", "foo::operator+(foo &)"),
	mu_demangle_test("__pp__3fooi", "foo::operator++(int)"),
	mu_demangle_test("__rf__3foo", "foo::operator->(void)"),
	mu_demangle_test("__rm__3fooRT0", "foo::operator->*(foo &)"),
	mu_demangle_test("__rs__3fooRT0", "foo::operator>>(foo &)"),
	mu_demangle_test("_new_Fix__FUs", "_new_Fix(unsigned short)"),
	mu_demangle_test("_vt.foo", "foo virtual table"),
	mu_demangle_test("_vt.foo.bar", "foo::bar virtual table"),
	mu_demangle_test("_vt$foo", "foo virtual table"),
	mu_demangle_test("_vt$foo$bar", "foo::bar virtual table"),
	mu_demangle_test("append__7ivGlyphPT0", "ivGlyph::append(ivGlyph *)"),
	mu_demangle_test("clearok__FP7_win_sti", "clearok(_win_st *, int)"),
	mu_demangle_test("complexfunc2__FPFPc_i", "complexfunc2(int (*)(char *))"),
	mu_demangle_test("complexfunc3__FPFPFPl_s_i", "complexfunc3(int (*)(short (*)(long *)))"),
	mu_demangle_test("complexfunc4__FPFPFPc_s_i", "complexfunc4(int (*)(short (*)(char *)))"),
	mu_demangle_test("complexfunc5__FPFPc_PFl_i", "complexfunc5(int (*(*)(char *))(long))"),
	mu_demangle_test("complexfunc6__FPFPi_PFl_i", "complexfunc6(int (*(*)(int *))(long))"),
	mu_demangle_test("complexfunc7__FPFPFPc_i_PFl_i", "complexfunc7(int (*(*)(int (*)(char *)))(long))"),
	mu_demangle_test("foo__FiN30", "foo(int, int, int, int)"),
	mu_demangle_test("foo__FiR3fooiT1iT1", "foo(int, foo &, int, foo &, int, foo &)"),
	mu_demangle_test("foo___3barl", "bar::foo_(long)"),
	mu_demangle_test("insert__15ivClippingStacklRP8_XRegion", "ivClippingStack::insert(long, _XRegion *&)"),
	mu_demangle_test("insert__16ChooserInfo_ListlR11ChooserInfo", "ChooserInfo_List::insert(long, ChooserInfo &)"),
	mu_demangle_test("insert__17FontFamilyRepListlRP15ivFontFamilyRep", "FontFamilyRepList::insert(long, ivFontFamilyRep *&)"),
	mu_demangle_test("leaveok__FP7_win_stc", "leaveok(_win_st *, char)"),
	mu_demangle_test("left_mover__C7ivMFKitP12ivAdjustableP7ivStyle", "ivMFKit::left_mover(ivAdjustable *, ivStyle *) const"),
	mu_demangle_test("overload1arg__FSc", "overload1arg(signed char)"),
	mu_demangle_test("overload1arg__FUc", "overload1arg(unsigned char)"),
	mu_demangle_test("overload1arg__FUi", "overload1arg(unsigned int)"),
	mu_demangle_test("overload1arg__FUl", "overload1arg(unsigned long)"),
	mu_demangle_test("overload1arg__FUs", "overload1arg(unsigned short)"),
	mu_demangle_test("overload1arg__Fc", "overload1arg(char)"),
	mu_demangle_test("overload1arg__Fd", "overload1arg(double)"),
	mu_demangle_test("overload1arg__Ff", "overload1arg(float)"),
	mu_demangle_test("overload1arg__Fi", "overload1arg(int)"),
	mu_demangle_test("overload1arg__Fl", "overload1arg(long)"),
	mu_demangle_test("overload1arg__Fs", "overload1arg(short)"),
	mu_demangle_test("overload1arg__Fv", "overload1arg(void)"),
	mu_demangle_test("overloadargs__Fi", "overloadargs(int)"),
	mu_demangle_test("overloadargs__Fii", "overloadargs(int, int)"),
	mu_demangle_test("overloadargs__Fiii", "overloadargs(int, int, int)"),
	mu_demangle_test("overloadargs__Fiiii", "overloadargs(int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiii", "overloadargs(int, int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiiii", "overloadargs(int, int, int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiiiii", "overloadargs(int, int, int, int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiiiiii", "overloadargs(int, int, int, int, int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiiiiiii", "overloadargs(int, int, int, int, int, int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiiiiiiii", "overloadargs(int, int, int, int, int, int, int, int, int, int)"),
	mu_demangle_test("overloadargs__Fiiiiiiiiiii", "overloadargs(int, int, int, int, int, int, int, int, int, int, int)"),
	mu_demangle_test("poke__8ivRasterUlUlffff", "ivRaster::poke(unsigned long, unsigned long, float, float, float, float)"),
	mu_demangle_test("polar__Fdd", "polar(double, double)"),
	mu_demangle_test("scale__13ivTransformerff", "ivTransformer::scale(float, float)"),
	mu_demangle_test("sgetn__7filebufPci", "filebuf::sgetn(char *, int)"),
	mu_demangle_test("shift__FP5_FrepiT0", "shift(_Frep *, int, _Frep *)"),
	mu_demangle_test("test__C6BitSeti", "BitSet::test(int) const"),
	mu_demangle_test("test__C6BitSetii", "BitSet::test(int, int) const"),
	mu_demangle_test("text_source__8Documentl", "Document::text_source(long)"),
	mu_demangle_test("variance__6Erlangd", "Erlang::variance(double)"),
	mu_demangle_test("view__14DocumentViewerP8ItemViewP11TabularItem", "DocumentViewer::view(ItemView *, TabularItem *)"),
	mu_demangle_test("xy_extents__11ivExtensionffff", "ivExtension::xy_extents(float, float, float, float)"),
	mu_demangle_test("zero__8osMemoryPvUi", "osMemory::zero(void *, unsigned int)"),
	mu_demangle_test("_2T4$N", "T4::N"),
	mu_demangle_test("_Q22T42t1$N", "T4::t1::N"),
	mu_demangle_test("get__2T1", "T1::get(void)"),
	mu_demangle_test("get__Q22T11a", "T1::a::get(void)"),
	mu_demangle_test("get__Q32T11a1b", "T1::a::b::get(void)"),
	mu_demangle_test("get__Q42T11a1b1c", "T1::a::b::c::get(void)"),
	mu_demangle_test("get__Q52T11a1b1c1d", "T1::a::b::c::d::get(void)"),
	mu_demangle_test("put__2T1i", "T1::put(int)"),
	mu_demangle_test("put__Q22T11ai", "T1::a::put(int)"),
	mu_demangle_test("put__Q32T11a1bi", "T1::a::b::put(int)"),
	mu_demangle_test("put__Q42T11a1b1ci", "T1::a::b::c::put(int)"),
	mu_demangle_test("put__Q52T11a1b1c1di", "T1::a::b::c::d::put(int)"),
	mu_demangle_test("bar__3fooPv", "foo::bar(void *)"),
	mu_demangle_test("bar__C3fooPv", "foo::bar(void *) const"),
	mu_demangle_test("__eq__3fooRT0", "foo::operator==(foo &)"),
	mu_demangle_test("__eq__C3fooR3foo", "foo::operator==(foo &) const"),
	mu_demangle_test("elem__t6vector1Zdi", "vector<double>::elem(int)"),
	mu_demangle_test("elem__t6vector1Zii", "vector<int>::elem(int)"),
	mu_demangle_test("__t6vector1Zdi", "vector<double>::vector(int)"),
	mu_demangle_test("__t6vector1Zii", "vector<int>::vector(int)"),
	mu_demangle_test("_$_t6vector1Zdi", "vector<double>::~vector(int)"),
	mu_demangle_test("_$_t6vector1Zii", "vector<int>::~vector(int)"),
	mu_demangle_test("__nw__t2T11ZcUi", "T1<char>::operator new(unsigned int)"),
	mu_demangle_test("__nw__t2T11Z1tUi", "T1<t>::operator new(unsigned int)"),
	mu_demangle_test("__dl__t2T11ZcPv", "T1<char>::operator delete(void *)"),
	mu_demangle_test("__dl__t2T11Z1tPv", "T1<t>::operator delete(void *)"),
	mu_demangle_test("__t2T11Zci", "T1<char>::T1(int)"),
	mu_demangle_test("__t2T11Zc", "T1<char>::T1(void)"),
	mu_demangle_test("__t2T11Z1ti", "T1<t>::T1(int)"),
	mu_demangle_test("__t2T11Z1t", "T1<t>::T1(void)"),
	mu_demangle_test("__Q2t4List1Z10VHDLEntity3Pix", "List<VHDLEntity>::Pix::Pix(void)"),
	mu_demangle_test("__Q2t4List1Z10VHDLEntity3PixPQ2t4List1Z10VHDLEntity7element", "List<VHDLEntity>::Pix::Pix(List<VHDLEntity>::element *)"),
	mu_demangle_test("__Q2t4List1Z10VHDLEntity3PixRCQ2t4List1Z10VHDLEntity3Pix", "List<VHDLEntity>::Pix::Pix(List<VHDLEntity>::Pix const &)"),
	mu_demangle_test("__Q2t4List1Z10VHDLEntity7elementRC10VHDLEntityPT0", "List<VHDLEntity>::element::element(VHDLEntity const &, List<VHDLEntity>::element *)"),
	mu_demangle_test("__Q2t4List1Z10VHDLEntity7elementRCQ2t4List1Z10VHDLEntity7element", "List<VHDLEntity>::element::element(List<VHDLEntity>::element const &)"),
	mu_demangle_test("__cl__C11VHDLLibraryGt4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntity", "VHDLLibrary::operator()(PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>>) const"),
	mu_demangle_test("__cl__Ct4List1Z10VHDLEntityRCQ2t4List1Z10VHDLEntity3Pix", "List<VHDLEntity>::operator()(List<VHDLEntity>::Pix const &) const"),
	mu_demangle_test("__ne__FPvRCQ2t4List1Z10VHDLEntity3Pix", "operator!=(void *, List<VHDLEntity>::Pix const &)"),
	mu_demangle_test("__ne__FPvRCt4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntity", "operator!=(void *, PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>> const &)"),
	mu_demangle_test("__t4List1Z10VHDLEntityRCt4List1Z10VHDLEntity", "List<VHDLEntity>::List(List<VHDLEntity> const &)"),
	mu_demangle_test("__t4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntity", "PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>>::PixX(void)"),
	mu_demangle_test("__t4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntityP14VHDLLibraryRepGQ2t4List1Z10VHDLEntity3Pix", "PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>>::PixX(VHDLLibraryRep *, List<VHDLEntity>::Pix)"),
	mu_demangle_test("__t4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntityRCt4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntity", "PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>>::PixX(PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>> const &)"),
	mu_demangle_test("nextE__C11VHDLLibraryRt4PixX3Z11VHDLLibraryZ14VHDLLibraryRepZt4List1Z10VHDLEntity", "VHDLLibrary::nextE(PixX<VHDLLibrary, VHDLLibraryRep, List<VHDLEntity>> &) const"),
	mu_demangle_test("next__Ct4List1Z10VHDLEntityRQ2t4List1Z10VHDLEntity3Pix", "List<VHDLEntity>::next(List<VHDLEntity>::Pix &) const"),
	mu_demangle_test("_GLOBAL_$D$set", "global destructors keyed to set"),
	mu_demangle_test("_GLOBAL_$I$set", "global constructors keyed to set"),
	mu_demangle_test("__as__t5ListS1ZUiRCt5ListS1ZUi", "ListS<unsigned int>::operator=(ListS<unsigned int> const &)"),
	mu_demangle_test("__cl__Ct5ListS1ZUiRCQ2t5ListS1ZUi3Vix", "ListS<unsigned int>::operator()(ListS<unsigned int>::Vix const &) const"),
	mu_demangle_test("__cl__Ct5SetLS1ZUiRCQ2t5SetLS1ZUi3Vix", "SetLS<unsigned int>::operator()(SetLS<unsigned int>::Vix const &) const"),
	mu_demangle_test("__t10ListS_link1ZUiRCUiPT0", "ListS_link<unsigned int>::ListS_link(unsigned int const &, ListS_link<unsigned int> *)"),
	mu_demangle_test("__t10ListS_link1ZUiRCt10ListS_link1ZUi", "ListS_link<unsigned int>::ListS_link(ListS_link<unsigned int> const &)"),
	mu_demangle_test("__t5ListS1ZUiRCt5ListS1ZUi", "ListS<unsigned int>::ListS(ListS<unsigned int> const &)"),
	mu_demangle_test("next__Ct5ListS1ZUiRQ2t5ListS1ZUi3Vix", "ListS<unsigned int>::next(ListS<unsigned int>::Vix &) const"),
	mu_demangle_test("__ne__FPvRCQ2t5SetLS1ZUi3Vix", "operator!=(void *, SetLS<unsigned int>::Vix const &)"),
	mu_demangle_test("__t8ListElem1Z5LabelRt4List1Z5Label", "ListElem<Label>::ListElem(List<Label> &)"),
	mu_demangle_test("__t8BDDHookV1ZPcRCPc", "BDDHookV<char *>::BDDHookV(char *const &)"),
	mu_demangle_test("_vt$t8BDDHookV1ZPc", "BDDHookV<char *> virtual table"),
	mu_demangle_test("__ne__FPvRCQ211BDDFunction4VixB", "operator!=(void *, BDDFunction::VixB const &)"),
	mu_demangle_test("__eq__FPvRCQ211BDDFunction4VixB", "operator==(void *, BDDFunction::VixB const &)"),
	mu_demangle_test("relativeId__CQ36T_phi210T_preserve8FPC_nextRCQ26T_phi210T_preserveRC10Parameters", "T_phi2::T_preserve::FPC_next::relativeId(T_phi2::T_preserve const &, Parameters const &) const"));

mu_main(gnu_v2, cxx, RZ_DEMANGLE_OPT_ENABLE_ALL);
