// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain__pch.h"
#include "Vmain___024root.h"

void Vmain___024root___eval_act(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vmain___024root___nba_sequent__TOP__0(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__test_game__DOT__game__DOT__logo_counter;
    __Vdly__test_game__DOT__game__DOT__logo_counter = 0;
    SData/*10:0*/ __Vdly__test_game__DOT__display_ctrl__DOT__h_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0;
    SData/*9:0*/ __Vdly__test_game__DOT__display_ctrl__DOT__v_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__v_count = 0;
    // Body
    __Vdly__test_game__DOT__game__DOT__logo_counter 
        = vlSelf->test_game__DOT__game__DOT__logo_counter;
    __Vdly__test_game__DOT__display_ctrl__DOT__v_count 
        = vlSelf->test_game__DOT__display_ctrl__DOT__v_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__h_count 
        = vlSelf->test_game__DOT__display_ctrl__DOT__h_count;
    if (vlSelf->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__logo_counter = 0U;
        __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0U;
        __Vdly__test_game__DOT__display_ctrl__DOT__v_count = 0U;
    } else {
        if ((0xbebc200U >= vlSelf->test_game__DOT__game__DOT__logo_counter)) {
            __Vdly__test_game__DOT__game__DOT__logo_counter 
                = ((IData)(3U) + vlSelf->test_game__DOT__game__DOT__logo_counter);
        }
        if ((0x41fU > (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count))) {
            __Vdly__test_game__DOT__display_ctrl__DOT__h_count 
                = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)));
        } else {
            __Vdly__test_game__DOT__display_ctrl__DOT__v_count 
                = ((0x273U > (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count))
                    ? (0x3ffU & ((IData)(1U) + (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count)))
                    : 0U);
            __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0U;
        }
    }
    vlSelf->sdl_sy = vlSelf->test_game__DOT__display_ctrl__DOT__v_count;
    vlSelf->sdl_sx = vlSelf->test_game__DOT__display_ctrl__DOT__h_count;
    vlSelf->sdl_b = (0xffU & ((0xf0U & (((IData)(vlSelf->test_game__DOT__game__DOT__object_draw)
                                          ? ((0xbebc200U 
                                              > vlSelf->test_game__DOT__game__DOT__logo_counter)
                                              ? (vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                                                 [0U] 
                                                 >> 8U)
                                              : 0xfU)
                                          : ((IData)(vlSelf->sw2)
                                              ? 8U : 0U)) 
                                        << 4U)) | (0xfU 
                                                   & ((IData)(vlSelf->test_game__DOT__game__DOT__object_draw)
                                                       ? 
                                                      ((0xbebc200U 
                                                        > vlSelf->test_game__DOT__game__DOT__logo_counter)
                                                        ? 
                                                       (vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                                                        [0U] 
                                                        >> 8U)
                                                        : 0xfU)
                                                       : 
                                                      ((IData)(vlSelf->sw2)
                                                        ? 8U
                                                        : 0U)))));
    vlSelf->sdl_g = (0xffU & ((0xf0U & (((IData)(vlSelf->test_game__DOT__game__DOT__object_draw)
                                          ? ((0xbebc200U 
                                              > vlSelf->test_game__DOT__game__DOT__logo_counter)
                                              ? (vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                                                 [0U] 
                                                 >> 4U)
                                              : 0xfU)
                                          : ((IData)(vlSelf->sw1)
                                              ? 8U : 0U)) 
                                        << 4U)) | (0xfU 
                                                   & ((IData)(vlSelf->test_game__DOT__game__DOT__object_draw)
                                                       ? 
                                                      ((0xbebc200U 
                                                        > vlSelf->test_game__DOT__game__DOT__logo_counter)
                                                        ? 
                                                       (vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                                                        [0U] 
                                                        >> 4U)
                                                        : 0xfU)
                                                       : 
                                                      ((IData)(vlSelf->sw1)
                                                        ? 8U
                                                        : 0U)))));
    vlSelf->sdl_r = (0xffU & ((0xf0U & (((IData)(vlSelf->test_game__DOT__game__DOT__object_draw)
                                          ? ((0xbebc200U 
                                              > vlSelf->test_game__DOT__game__DOT__logo_counter)
                                              ? vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                                             [0U] : 0xfU)
                                          : ((IData)(vlSelf->sw0)
                                              ? 8U : 0U)) 
                                        << 4U)) | (0xfU 
                                                   & ((IData)(vlSelf->test_game__DOT__game__DOT__object_draw)
                                                       ? 
                                                      ((0xbebc200U 
                                                        > vlSelf->test_game__DOT__game__DOT__logo_counter)
                                                        ? 
                                                       vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                                                       [0U]
                                                        : 0xfU)
                                                       : 
                                                      ((IData)(vlSelf->sw0)
                                                        ? 8U
                                                        : 0U)))));
    vlSelf->sdl_de = vlSelf->test_game__DOT__disp_enbl;
    vlSelf->test_game__DOT__game__DOT__logo_counter 
        = __Vdly__test_game__DOT__game__DOT__logo_counter;
    vlSelf->test_game__DOT__disp_enbl = ((IData)(vlSelf->sim_rst) 
                                         || (((0x31fU 
                                               > (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                                              & (0x258U 
                                                 > (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count))) 
                                             || ((0x41fU 
                                                  == (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                 & ((0x257U 
                                                     > (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count)) 
                                                    | (0x273U 
                                                       == (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count))))));
    vlSelf->test_game__DOT__display_ctrl__DOT__h_count 
        = __Vdly__test_game__DOT__display_ctrl__DOT__h_count;
    vlSelf->test_game__DOT__display_ctrl__DOT__v_count 
        = __Vdly__test_game__DOT__display_ctrl__DOT__v_count;
    vlSelf->test_game__DOT__game__DOT__object_draw 
        = ((0xbebc200U > vlSelf->test_game__DOT__game__DOT__logo_counter) 
           & (((((0x14fU <= (0x3ffU & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count))) 
                 & (0x1cfU > (0x3ffU & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)))) 
                & (0xebU <= (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count))) 
               & (0x16bU > (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count))) 
              & (0U != vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom
                 [0U])));
}

void Vmain___024root___eval_nba(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vmain___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vmain___024root___eval_triggers__act(Vmain___024root* vlSelf);

bool Vmain___024root___eval_phase__act(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmain___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vmain___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmain___024root___eval_phase__nba(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmain___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__nba(Vmain___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__act(Vmain___024root* vlSelf);
#endif  // VL_DEBUG

void Vmain___024root___eval(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vmain___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("main.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vmain___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("main.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vmain___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vmain___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmain___024root___eval_debug_assertions(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->pixel_clk & 0xfeU))) {
        Verilated::overWidthError("pixel_clk");}
    if (VL_UNLIKELY((vlSelf->sim_rst & 0xfeU))) {
        Verilated::overWidthError("sim_rst");}
    if (VL_UNLIKELY((vlSelf->button_c & 0xfeU))) {
        Verilated::overWidthError("button_c");}
    if (VL_UNLIKELY((vlSelf->button_u & 0xfeU))) {
        Verilated::overWidthError("button_u");}
    if (VL_UNLIKELY((vlSelf->button_d & 0xfeU))) {
        Verilated::overWidthError("button_d");}
    if (VL_UNLIKELY((vlSelf->button_r & 0xfeU))) {
        Verilated::overWidthError("button_r");}
    if (VL_UNLIKELY((vlSelf->button_l & 0xfeU))) {
        Verilated::overWidthError("button_l");}
    if (VL_UNLIKELY((vlSelf->sw0 & 0xfeU))) {
        Verilated::overWidthError("sw0");}
    if (VL_UNLIKELY((vlSelf->sw1 & 0xfeU))) {
        Verilated::overWidthError("sw1");}
    if (VL_UNLIKELY((vlSelf->sw2 & 0xfeU))) {
        Verilated::overWidthError("sw2");}
    if (VL_UNLIKELY((vlSelf->sw3 & 0xfeU))) {
        Verilated::overWidthError("sw3");}
    if (VL_UNLIKELY((vlSelf->sw4 & 0xfeU))) {
        Verilated::overWidthError("sw4");}
    if (VL_UNLIKELY((vlSelf->sw5 & 0xfeU))) {
        Verilated::overWidthError("sw5");}
    if (VL_UNLIKELY((vlSelf->sw6 & 0xfeU))) {
        Verilated::overWidthError("sw6");}
    if (VL_UNLIKELY((vlSelf->sw7 & 0xfeU))) {
        Verilated::overWidthError("sw7");}
    if (VL_UNLIKELY((vlSelf->sw8 & 0xfeU))) {
        Verilated::overWidthError("sw8");}
}
#endif  // VL_DEBUG
