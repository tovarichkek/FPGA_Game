// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain__pch.h"
#include "Vmain___024root.h"

VL_ATTR_COLD void Vmain___024root___eval_final(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__stl(Vmain___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmain___024root___eval_phase__stl(Vmain___024root* vlSelf);

VL_ATTR_COLD void Vmain___024root___eval_settle(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vmain___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("main.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vmain___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__stl(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmain___024root___stl_sequent__TOP__0(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->test_game__DOT__game__DOT__ball = (((((0x3ffU 
                                                   & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                  >= (IData)(vlSelf->test_game__DOT__game__DOT__ball_h_coord)) 
                                                 & ((0x3ffU 
                                                     & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                    <= 
                                                    ((IData)(0x10U) 
                                                     + (IData)(vlSelf->test_game__DOT__game__DOT__ball_h_coord)))) 
                                                & ((IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count) 
                                                   >= (IData)(vlSelf->test_game__DOT__game__DOT__ball_v_coord))) 
                                               & ((IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count) 
                                                  <= 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlSelf->test_game__DOT__game__DOT__ball_v_coord))));
    vlSelf->test_game__DOT__game__DOT____VdfgTmp_h2ebd0c62__0 
        = ((((((0x3ffU & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
               >= (IData)(vlSelf->test_game__DOT__game__DOT__board1_h_coord)) 
              & ((0x3ffU & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                 <= ((IData)(0x64U) + (IData)(vlSelf->test_game__DOT__game__DOT__board1_h_coord)))) 
             & ((IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count) 
                >= (IData)(vlSelf->test_game__DOT__game__DOT__board1_v_coord))) 
            & ((IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count) 
               <= ((IData)(0x14U) + (IData)(vlSelf->test_game__DOT__game__DOT__board1_v_coord)))) 
           | (((((0x3ffU & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                 >= (IData)(vlSelf->test_game__DOT__game__DOT__board2_h_coord)) 
                & ((0x3ffU & (IData)(vlSelf->test_game__DOT__display_ctrl__DOT__h_count)) 
                   <= ((IData)(0x64U) + (IData)(vlSelf->test_game__DOT__game__DOT__board2_h_coord)))) 
               & ((IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count) 
                  >= (IData)(vlSelf->test_game__DOT__game__DOT__board2_v_coord))) 
              & ((IData)(vlSelf->test_game__DOT__display_ctrl__DOT__v_count) 
                 <= ((IData)(0x14U) + (IData)(vlSelf->test_game__DOT__game__DOT__board2_v_coord)))));
}

VL_ATTR_COLD void Vmain___024root___eval_stl(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vmain___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmain___024root___eval_triggers__stl(Vmain___024root* vlSelf);

VL_ATTR_COLD bool Vmain___024root___eval_phase__stl(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmain___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vmain___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__act(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge pixel_clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__nba(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge pixel_clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmain___024root___ctor_var_reset(Vmain___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->pixel_clk = 0;
    vlSelf->sim_rst = 0;
    vlSelf->button_c = 0;
    vlSelf->button_u = 0;
    vlSelf->button_d = 0;
    vlSelf->button_r = 0;
    vlSelf->button_l = 0;
    vlSelf->accel_data_x = 0;
    vlSelf->accel_data_y = 0;
    vlSelf->sw0 = 0;
    vlSelf->sw1 = 0;
    vlSelf->sw2 = 0;
    vlSelf->sw3 = 0;
    vlSelf->sw4 = 0;
    vlSelf->sw5 = 0;
    vlSelf->sw6 = 0;
    vlSelf->sw7 = 0;
    vlSelf->sw8 = 0;
    vlSelf->sdl_sx = 0;
    vlSelf->sdl_sy = 0;
    vlSelf->sdl_de = 0;
    vlSelf->sdl_r = 0;
    vlSelf->sdl_g = 0;
    vlSelf->sdl_b = 0;
    vlSelf->test_game__DOT__disp_enbl = 0;
    vlSelf->test_game__DOT__game__DOT__regime_store = 0;
    vlSelf->test_game__DOT__game__DOT__frames_cntr = 0;
    vlSelf->test_game__DOT__game__DOT__end_of_frame = 0;
    vlSelf->test_game__DOT__game__DOT__ball = 0;
    vlSelf->test_game__DOT__game__DOT__board1_h_coord = 0;
    vlSelf->test_game__DOT__game__DOT__board1_v_coord = 0;
    vlSelf->test_game__DOT__game__DOT__board2_h_coord = 0;
    vlSelf->test_game__DOT__game__DOT__board2_v_coord = 0;
    vlSelf->test_game__DOT__game__DOT__logo_counter = 0;
    vlSelf->test_game__DOT__game__DOT__ball_h_coord = 0;
    vlSelf->test_game__DOT__game__DOT__ball_v_coord = 0;
    vlSelf->test_game__DOT__game__DOT__x_direction = 0;
    vlSelf->test_game__DOT__game__DOT__y_direction = 0;
    vlSelf->test_game__DOT__game__DOT____VdfgTmp_h2ebd0c62__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 480000; ++__Vi0) {
        vlSelf->test_game__DOT__game__DOT__logo_rom__DOT__rom[__Vi0] = 0;
    }
    vlSelf->test_game__DOT__display_ctrl__DOT__h_count = 0;
    vlSelf->test_game__DOT__display_ctrl__DOT__v_count = 0;
    vlSelf->__Vtrigprevexpr___TOP__pixel_clk__0 = 0;
}
