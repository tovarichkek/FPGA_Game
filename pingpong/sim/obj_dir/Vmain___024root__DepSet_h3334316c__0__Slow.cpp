// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain__pch.h"
#include "Vmain___024root.h"

VL_ATTR_COLD void Vmain___024root___eval_static__TOP(Vmain___024root* vlSelf);

VL_ATTR_COLD void Vmain___024root___eval_static(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_static\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmain___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vmain___024root___eval_static__TOP(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_static__TOP\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.test_game__DOT__game__DOT__x_direction = 0U;
    vlSelfRef.test_game__DOT__game__DOT__y_direction = 2U;
    vlSelfRef.test_game__DOT__game__DOT__rand_mod = 0xaU;
    vlSelfRef.test_game__DOT__game__DOT__delta_speed = 0U;
}

VL_ATTR_COLD void Vmain___024root___eval_initial(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_initial\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__pixel_clk__0 = vlSelfRef.pixel_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__button_c__0 = vlSelfRef.button_c;
}

VL_ATTR_COLD void Vmain___024root___eval_final(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_final\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__stl(Vmain___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmain___024root___eval_phase__stl(Vmain___024root* vlSelf);

VL_ATTR_COLD void Vmain___024root___eval_settle(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_settle\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
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
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__stl(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___dump_triggers__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmain___024root___stl_sequent__TOP__0(Vmain___024root* vlSelf);

VL_ATTR_COLD void Vmain___024root___eval_stl(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vmain___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vmain___024root___stl_sequent__TOP__0(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___stl_sequent__TOP__0\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
           | ((((((0x3ffU & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                  >= (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord)) 
                 & ((0x3ffU & (IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__h_count)) 
                    <= ((IData)(0x64U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_h_coord)))) 
                & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                   >= (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_v_coord))) 
               & ((IData)(vlSelfRef.test_game__DOT__display_ctrl__DOT__v_count) 
                  <= ((IData)(0x14U) + (IData)(vlSelfRef.test_game__DOT__game__DOT__board2_v_coord)))) 
              & (~ (IData)(vlSelfRef.test_game__DOT__game__DOT__regime_store))));
}

VL_ATTR_COLD void Vmain___024root___eval_triggers__stl(Vmain___024root* vlSelf);

VL_ATTR_COLD bool Vmain___024root___eval_phase__stl(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___eval_phase__stl\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmain___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vmain___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__act(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___dump_triggers__act\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge pixel_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge button_c)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmain___024root___dump_triggers__nba(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___dump_triggers__nba\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge pixel_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge button_c)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmain___024root___ctor_var_reset(Vmain___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vmain__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain___024root___ctor_var_reset\n"); );
    auto &vlSelfRef = std::ref(*vlSelf).get();
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
    vlSelf->test_game__DOT__game__DOT__ball_h_coord = 0;
    vlSelf->test_game__DOT__game__DOT__ball_v_coord = 0;
    vlSelf->test_game__DOT__game__DOT__x_direction = 0;
    vlSelf->test_game__DOT__game__DOT__y_direction = 0;
    vlSelf->test_game__DOT__game__DOT__rand_mod = 0;
    vlSelf->test_game__DOT__game__DOT__delta_speed = 0;
    vlSelf->test_game__DOT__game__DOT__p1_count = 0;
    vlSelf->test_game__DOT__game__DOT__p2_count = 0;
    vlSelf->test_game__DOT__game__DOT____VdfgRegularize_h4fb47ce6_2_0 = 0;
    vlSelf->test_game__DOT__display_ctrl__DOT__h_count = 0;
    vlSelf->test_game__DOT__display_ctrl__DOT__v_count = 0;
    vlSelf->__Vdly__test_game__DOT__game__DOT__regime_store = 0;
    vlSelf->__Vtrigprevexpr___TOP__pixel_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__button_c__0 = 0;
}
