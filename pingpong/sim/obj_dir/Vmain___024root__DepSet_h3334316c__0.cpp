// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain__pch.h"
#include "Vmain___024root.h"

void Vmain___024root___eval_act(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

void Vmain___024root___nba_sequent__TOP__0(Vmain___024root* vlSelf);

void Vmain___024root___eval_nba(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vmain___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vmain___024root___nba_sequent__TOP__0(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___nba_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vdly__test_game__DOT__game__DOT__frames_cntr;
    __Vdly__test_game__DOT__game__DOT__frames_cntr = 0;
    CData/*0:0*/ __Vdly__test_game__DOT__game__DOT__regime_store;
    __Vdly__test_game__DOT__game__DOT__regime_store = 0;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__board2_h_coord;
    __Vdly__test_game__DOT__game__DOT__board2_h_coord = 0;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__board1_h_coord;
    __Vdly__test_game__DOT__game__DOT__board1_h_coord = 0;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__ball_h_coord;
    __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__ball_v_coord;
    __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0;
    SData/*10:0*/ __Vdly__test_game__DOT__display_ctrl__DOT__h_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0;
    SData/*9:0*/ __Vdly__test_game__DOT__display_ctrl__DOT__v_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__v_count = 0;
    // Body
    __Vdly__test_game__DOT__game__DOT__regime_store 
        = vlSelfRef.test_game__DOT__game__DOT__regime_store;
    __Vdly__test_game__DOT__display_ctrl__DOT__h_count 
        = vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__v_count 
        = vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count;
    __Vdly__test_game__DOT__game__DOT__frames_cntr 
        = vlSelfRef.test_game__DOT__game__DOT__frames_cntr;
    __Vdly__test_game__DOT__game__DOT__board2_h_coord 
        = vlSelfRef.test_game__DOT__game__DOT__board2_h_coord;
    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
        = vlSelfRef.test_game__DOT__game__DOT__board1_h_coord;
    __Vdly__test_game__DOT__game__DOT__ball_h_coord 
        = vlSelfRef.test_game__DOT__game__DOT__ball_h_coord;
    __Vdly__test_game__DOT__game__DOT__ball_v_coord 
        = vlSelfRef.test_game__DOT__game__DOT__ball_v_coord;
    if (vlSelfRef.sim_rst) {
        __Vdly__test_game__DOT__game__DOT__regime_store = 1U;
        __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0U;
        __Vdly__test_game__DOT__display_ctrl__DOT__v_count = 0U;
        __Vdly__test_game__DOT__game__DOT__frames_cntr = 0U;
        __Vdly__test_game__DOT__game__DOT__board2_h_coord = 0x15eU;
        __Vdly__test_game__DOT__game__DOT__board1_h_coord = 0x15eU;
        __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0x186U;
        __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0x186U;
        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x122U;
        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x122U;
        vlSelfRef.test_game__DOT__game__DOT__board1_v_coord = 0U;
        vlSelfRef.test_game__DOT__game__DOT__board2_v_coord = 0x244U;
    } else {
        if ((0x41fU > (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count))) {
            __Vdly__test_game__DOT__display_ctrl__DOT__h_count 
                = (0x7ffU & ((IData)(1U) + (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)));
        } else {
            __Vdly__test_game__DOT__display_ctrl__DOT__v_count 
                = ((0x273U > (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count))
                    ? (0x3ffU & ((IData)(1U) + (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count)))
                    : 0U);
            __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0U;
        }
        if ((2U == vlSelfRef.test_game__DOT__game__DOT__frames_cntr)) {
            __Vdly__test_game__DOT__game__DOT__frames_cntr = 0U;
        } else if (vlSelfRef.test_game__DOT__game__DOT__end_of_frame) {
            __Vdly__test_game__DOT__game__DOT__frames_cntr 
                = ((IData)(1U) + vlSelfRef.test_game__DOT__game__DOT__frames_cntr);
        }
        if (((IData)(vlSelfRef.test_game__DOT__game__DOT__end_of_frame) 
             & (0U == vlSelfRef.test_game__DOT__game__DOT__frames_cntr))) {
            if (vlSelfRef.test_game__DOT__game__DOT__regime_store) {
                if (vlSelfRef.button_u) {
                    __Vdly__test_game__DOT__game__DOT__board2_h_coord 
                        = ((0x14U > (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord))
                            ? 0U : (0x3ffU & ((IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord) 
                                              - (IData)(0x14U))));
                } else if (vlSelfRef.button_r) {
                    __Vdly__test_game__DOT__game__DOT__board2_h_coord 
                        = ((0x31fU <= ((IData)(0x78U) 
                                       + (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord)))
                            ? 0x2bbU : (0x3ffU & ((IData)(0x14U) 
                                                  + (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord))));
                }
                if (vlSelfRef.button_l) {
                    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                        = ((0x14U > (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord))
                            ? 0U : (0x3ffU & ((IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord) 
                                              - (IData)(0x14U))));
                } else if (vlSelfRef.button_d) {
                    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                        = ((0x31fU <= ((IData)(0x78U) 
                                       + (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord)))
                            ? 0x2bbU : (0x3ffU & ((IData)(0x14U) 
                                                  + (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord))));
                }
            } else if ((1U & (~ (IData)(vlSelfRef.test_game__DOT__game__DOT__regime_store)))) {
                if (((~ (1U & (((IData)(1U) + (IData)(vlSelfRef.accel_data_y)) 
                               >> 7U))) & (0U != (0xffU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlSelfRef.accel_data_y)))))) {
                    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                        = ((0x14U > (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord))
                            ? 0U : (0x3ffU & ((IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord) 
                                              - (IData)(0x14U))));
                } else if ((1U & ((((IData)(1U) + (IData)(vlSelfRef.accel_data_y)) 
                                   >> 7U) & (0U != 
                                             (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.accel_data_y))))))) {
                    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                        = ((0x31fU <= ((IData)(0x78U) 
                                       + (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord)))
                            ? 0x2bbU : (0x3ffU & ((IData)(0x14U) 
                                                  + (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord))));
                }
            }
            if (vlSelfRef.test_game__DOT__game__DOT__x_direction) {
                if ((0x31fU <= ((IData)(0x20U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_h_coord)))) {
                    vlSelfRef.test_game__DOT__game__DOT__x_direction 
                        = (1U & (~ (IData)(vlSelfRef.test_game__DOT__game__DOT__x_direction)));
                    __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0x30fU;
                } else {
                    __Vdly__test_game__DOT__game__DOT__ball_h_coord 
                        = (0x3ffU & ((IData)(0x10U) 
                                     + (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_h_coord)));
                }
            } else if ((0x10U > (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_h_coord))) {
                vlSelfRef.test_game__DOT__game__DOT__x_direction 
                    = (1U & (~ (IData)(vlSelfRef.test_game__DOT__game__DOT__x_direction)));
                __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0U;
            } else {
                __Vdly__test_game__DOT__game__DOT__ball_h_coord 
                    = (0x3ffU & ((IData)(vlSelfRef.test_game__DOT__game__DOT__ball_h_coord) 
                                 - (IData)(0x10U)));
            }
            if (vlSelfRef.test_game__DOT__game__DOT__y_direction) {
                if ((0x257U <= ((IData)(0x20U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_v_coord)))) {
                    vlSelfRef.test_game__DOT__game__DOT__y_direction 
                        = (1U & (~ (IData)(vlSelfRef.test_game__DOT__game__DOT__y_direction)));
                    __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x247U;
                } else {
                    __Vdly__test_game__DOT__game__DOT__ball_v_coord 
                        = (0x3ffU & ((IData)(0x10U) 
                                     + (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_v_coord)));
                }
            } else if ((0x10U > (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_v_coord))) {
                vlSelfRef.test_game__DOT__game__DOT__y_direction 
                    = (1U & (~ (IData)(vlSelfRef.test_game__DOT__game__DOT__y_direction)));
                __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0U;
            } else {
                __Vdly__test_game__DOT__game__DOT__ball_v_coord 
                    = (0x3ffU & ((IData)(vlSelfRef.test_game__DOT__game__DOT__ball_v_coord) 
                                 - (IData)(0x10U)));
            }
        }
    }
    if (vlSelfRef.button_c) {
        __Vdly__test_game__DOT__game__DOT__regime_store 
            = (1U & ((IData)(1U) - (IData)(vlSelfRef.test_game__DOT__game__DOT__regime_store)));
    }
    vlSelfRef.sdl_sx = vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count;
    vlSelfRef.sdl_sy = vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count;
    vlSelfRef.sdl_r = (0xffU & ((((IData)(vlSelfRef.test_game__DOT__game__DOT__ball)
                                   ? 0xfU : ((IData)(vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0)
                                              ? ((IData)(vlSelfRef.sw6)
                                                  ? 0xcU
                                                  : 0xfU)
                                              : ((IData)(vlSelfRef.sw0)
                                                  ? 8U
                                                  : 0U))) 
                                 << 4U) | ((IData)(vlSelfRef.test_game__DOT__game__DOT__ball)
                                            ? 0xfU : 
                                           ((IData)(vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0)
                                             ? ((IData)(vlSelfRef.sw6)
                                                 ? 0xcU
                                                 : 0xfU)
                                             : ((IData)(vlSelfRef.sw0)
                                                 ? 8U
                                                 : 0U)))));
    vlSelfRef.sdl_g = (0xffU & ((((IData)(vlSelfRef.test_game__DOT__game__DOT__ball)
                                   ? ((IData)(vlSelfRef.sw4)
                                       ? 0xfU : 0U)
                                   : ((IData)(vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0)
                                       ? ((IData)(vlSelfRef.sw7)
                                           ? 0xcU : 0xfU)
                                       : ((IData)(vlSelfRef.sw1)
                                           ? 8U : 0U))) 
                                 << 4U) | ((IData)(vlSelfRef.test_game__DOT__game__DOT__ball)
                                            ? ((IData)(vlSelfRef.sw4)
                                                ? 0xfU
                                                : 0U)
                                            : ((IData)(vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0)
                                                ? ((IData)(vlSelfRef.sw7)
                                                    ? 0xcU
                                                    : 0xfU)
                                                : ((IData)(vlSelfRef.sw1)
                                                    ? 8U
                                                    : 0U)))));
    vlSelfRef.sdl_b = (0xffU & ((((IData)(vlSelfRef.test_game__DOT__game__DOT__ball)
                                   ? ((IData)(vlSelfRef.sw5)
                                       ? 0xfU : 0U)
                                   : ((IData)(vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0)
                                       ? ((IData)(vlSelfRef.sw8)
                                           ? 0xcU : 0xfU)
                                       : ((IData)(vlSelfRef.sw2)
                                           ? 8U : 0U))) 
                                 << 4U) | ((IData)(vlSelfRef.test_game__DOT__game__DOT__ball)
                                            ? ((IData)(vlSelfRef.sw5)
                                                ? 0xfU
                                                : 0U)
                                            : ((IData)(vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0)
                                                ? ((IData)(vlSelfRef.sw8)
                                                    ? 0xcU
                                                    : 0xfU)
                                                : ((IData)(vlSelfRef.sw2)
                                                    ? 8U
                                                    : 0U)))));
    vlSelfRef.sdl_de = vlSelfRef.test_game__DOT__disp_enbl;
    vlSelfRef.test_game__DOT__game__DOT__board2_h_coord 
        = __Vdly__test_game__DOT__game__DOT__board2_h_coord;
    vlSelfRef.test_game__DOT__game__DOT__regime_store 
        = __Vdly__test_game__DOT__game__DOT__regime_store;
    vlSelfRef.test_game__DOT__game__DOT__board1_h_coord 
        = __Vdly__test_game__DOT__game__DOT__board1_h_coord;
    vlSelfRef.test_game__DOT__game__DOT__ball_h_coord 
        = __Vdly__test_game__DOT__game__DOT__ball_h_coord;
    vlSelfRef.test_game__DOT__game__DOT__frames_cntr 
        = __Vdly__test_game__DOT__game__DOT__frames_cntr;
    vlSelfRef.test_game__DOT__game__DOT__ball_v_coord 
        = __Vdly__test_game__DOT__game__DOT__ball_v_coord;
    vlSelfRef.test_game__DOT__game__DOT__end_of_frame 
        = ((~ (IData)(vlSelfRef.sim_rst)) & ((0x31fU 
                                              == (0x3ffU 
                                                  & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count))) 
                                             & (0x257U 
                                                == (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count))));
    vlSelfRef.test_game__DOT__disp_enbl = ((IData)(vlSelfRef.sim_rst) 
                                           || (((0x31fU 
                                                 > (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                                                & (0x258U 
                                                   > (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count))) 
                                               || ((0x41fU 
                                                    == (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                                                   & ((0x257U 
                                                       > (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count)) 
                                                      | (0x273U 
                                                         == (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count))))));
    vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count 
        = __Vdly__test_game__DOT__display_ctrl__DOT__h_count;
    vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count 
        = __Vdly__test_game__DOT__display_ctrl__DOT__v_count;
    vlSelfRef.test_game__DOT__game__DOT__ball = (((
                                                   ((0x3ffU 
                                                     & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                                                    >= (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_h_coord)) 
                                                   & ((0x3ffU 
                                                       & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                                                      <= 
                                                      ((IData)(0x10U) 
                                                       + (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_h_coord)))) 
                                                  & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                                                     >= (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_v_coord))) 
                                                 & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                                                    <= 
                                                    ((IData)(0x10U) 
                                                     + (IData)(vlSelfRef.test_game__DOT__game__DOT__ball_v_coord))));
    vlSelfRef.test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0 
        = ((((((0x3ffU & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
               >= (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord)) 
              & ((0x3ffU & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                 <= ((IData)(0x64U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_h_coord)))) 
             & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                >= (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_v_coord))) 
            & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
               <= ((IData)(0x14U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__board1_v_coord)))) 
           | (((((0x3ffU & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                 >= (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord)) 
                & ((0x3ffU & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                   <= ((IData)(0x64U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord)))) 
               & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                  >= (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_v_coord))) 
              & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                 <= ((IData)(0x14U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_v_coord)))));
}

void Vmain___024root___eval_triggers__act(Vmain___024root* vlSelf);

bool Vmain___024root___eval_phase__act(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_phase__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vmain___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vmain___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vmain___024root___eval_phase__nba(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_phase__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vmain___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
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
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
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
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vmain___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("main.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vmain___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vmain___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vmain___024root___eval_debug_assertions(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_debug_assertions\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.pixel_clk & 0xfeU))) {
        Verilated::overWidthError("pixel_clk");}
    if (VL_UNLIKELY((vlSelfRef.sim_rst & 0xfeU))) {
        Verilated::overWidthError("sim_rst");}
    if (VL_UNLIKELY((vlSelfRef.button_c & 0xfeU))) {
        Verilated::overWidthError("button_c");}
    if (VL_UNLIKELY((vlSelfRef.button_u & 0xfeU))) {
        Verilated::overWidthError("button_u");}
    if (VL_UNLIKELY((vlSelfRef.button_d & 0xfeU))) {
        Verilated::overWidthError("button_d");}
    if (VL_UNLIKELY((vlSelfRef.button_r & 0xfeU))) {
        Verilated::overWidthError("button_r");}
    if (VL_UNLIKELY((vlSelfRef.button_l & 0xfeU))) {
        Verilated::overWidthError("button_l");}
    if (VL_UNLIKELY((vlSelfRef.sw0 & 0xfeU))) {
        Verilated::overWidthError("sw0");}
    if (VL_UNLIKELY((vlSelfRef.sw1 & 0xfeU))) {
        Verilated::overWidthError("sw1");}
    if (VL_UNLIKELY((vlSelfRef.sw2 & 0xfeU))) {
        Verilated::overWidthError("sw2");}
    if (VL_UNLIKELY((vlSelfRef.sw3 & 0xfeU))) {
        Verilated::overWidthError("sw3");}
    if (VL_UNLIKELY((vlSelfRef.sw4 & 0xfeU))) {
        Verilated::overWidthError("sw4");}
    if (VL_UNLIKELY((vlSelfRef.sw5 & 0xfeU))) {
        Verilated::overWidthError("sw5");}
    if (VL_UNLIKELY((vlSelfRef.sw6 & 0xfeU))) {
        Verilated::overWidthError("sw6");}
    if (VL_UNLIKELY((vlSelfRef.sw7 & 0xfeU))) {
        Verilated::overWidthError("sw7");}
    if (VL_UNLIKELY((vlSelfRef.sw8 & 0xfeU))) {
        Verilated::overWidthError("sw8");}
}
#endif  // VL_DEBUG
