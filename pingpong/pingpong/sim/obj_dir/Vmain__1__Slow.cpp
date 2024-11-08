// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain.h"
#include "Vmain__Syms.h"

void Vmain::_initial__TOP__2(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_initial__TOP__2\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test_game__DOT__game__DOT__x_direction = 0U;
    vlTOPp->test_game__DOT__game__DOT__delta_speed = 0U;
    vlTOPp->test_game__DOT__game__DOT__y_direction = 2U;
    vlTOPp->test_game__DOT__game__DOT__rand_mod = 0xaU;
}

void Vmain::_settle__TOP__5(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_settle__TOP__5\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test_game__DOT____Vcellinp__game__SW = 
        (((IData)(vlTOPp->sw9) << 9U) | (((IData)(vlTOPp->sw8) 
                                          << 8U) | 
                                         (((IData)(vlTOPp->sw7) 
                                           << 7U) | 
                                          (((IData)(vlTOPp->sw6) 
                                            << 6U) 
                                           | (((IData)(vlTOPp->sw5) 
                                               << 5U) 
                                              | (((IData)(vlTOPp->sw4) 
                                                  << 4U) 
                                                 | (((IData)(vlTOPp->sw3) 
                                                     << 3U) 
                                                    | (((IData)(vlTOPp->sw2) 
                                                        << 2U) 
                                                       | (((IData)(vlTOPp->sw1) 
                                                           << 1U) 
                                                          | (IData)(vlTOPp->sw0))))))))));
    vlTOPp->test_game__DOT__game__DOT__board1 = (((
                                                   ((0x3ffU 
                                                     & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                    >= (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)) 
                                                   & ((0x3ffU 
                                                       & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                      <= 
                                                      ((IData)(0x64U) 
                                                       + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)))) 
                                                  & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                     >= (IData)(vlTOPp->test_game__DOT__game__DOT__board1_v_coord))) 
                                                 & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                    <= 
                                                    ((IData)(0x14U) 
                                                     + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_v_coord))));
    vlTOPp->test_game__DOT__game__DOT__ball = (((((0x3ffU 
                                                   & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                  >= (IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord)) 
                                                 & ((0x3ffU 
                                                     & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                    <= 
                                                    ((IData)(0x10U) 
                                                     + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord)))) 
                                                & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                   >= (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord))) 
                                               & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                  <= 
                                                  ((IData)(0x10U) 
                                                   + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord))));
    vlTOPp->test_game__DOT__game__DOT__board2 = (((
                                                   (((0x3ffU 
                                                      & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                     >= (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)) 
                                                    & ((0x3ffU 
                                                        & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                                       <= 
                                                       ((IData)(0x64U) 
                                                        + (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)))) 
                                                   & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                      >= (IData)(vlTOPp->test_game__DOT__game__DOT__board2_v_coord))) 
                                                  & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                     <= 
                                                     ((IData)(0x14U) 
                                                      + (IData)(vlTOPp->test_game__DOT__game__DOT__board2_v_coord)))) 
                                                 & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__regime_store)));
    vlTOPp->test_game__DOT__game__DOT__logo_read_address 
        = (0x1ffffU & (((0x3ffU & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                        - (IData)(0xc7U)) + ((IData)(0x190U) 
                                             * (0x1ffffU 
                                                & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                   - (IData)(0x8cU))))));
    vlTOPp->test_game__DOT__game__DOT__object_draw 
        = (((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
            >> 9U) & ((((0xc8U <= (0x3ffU & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count))) 
                        & (0x257U > (0x3ffU & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)))) 
                       & (0x8cU <= (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))) 
                      & (0x1cbU > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))));
    vlTOPp->test_game__DOT__game__DOT__logo_rom_out 
        = ((0x1f3ffU >= vlTOPp->test_game__DOT__game__DOT__logo_read_address)
            ? vlTOPp->test_game__DOT__game__DOT__logo_rom__DOT__rom
           [vlTOPp->test_game__DOT__game__DOT__logo_read_address]
            : 0U);
}

void Vmain::_eval_initial(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_initial\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->_initial__TOP__2(vlSymsp);
    vlTOPp->__Vclklast__TOP__button_c = vlTOPp->button_c;
    vlTOPp->__Vclklast__TOP__pixel_clk = vlTOPp->pixel_clk;
}

void Vmain::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::final\n"); );
    // Variables
    Vmain__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vmain::_eval_settle(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_settle\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

void Vmain::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_ctor_var_reset\n"); );
    // Body
    pixel_clk = 0;
    sim_rst = 0;
    button_c = 0;
    button_u = 0;
    button_d = 0;
    button_r = 0;
    button_l = 0;
    accel_data_x = 0;
    accel_data_y = 0;
    sw0 = 0;
    sw1 = 0;
    sw2 = 0;
    sw3 = 0;
    sw4 = 0;
    sw5 = 0;
    sw6 = 0;
    sw7 = 0;
    sw8 = 0;
    sw9 = 0;
    sdl_sx = 0;
    sdl_sy = 0;
    sdl_de = 0;
    sdl_r = 0;
    sdl_g = 0;
    sdl_b = 0;
    test_game__DOT__disp_enbl = 0;
    test_game__DOT____Vcellinp__game__SW = 0;
    test_game__DOT__game__DOT__regime_store = 0;
    test_game__DOT__game__DOT__frames_cntr = 0;
    test_game__DOT__game__DOT__end_of_frame = 0;
    test_game__DOT__game__DOT__logo_rom_out = 0;
    test_game__DOT__game__DOT__logo_read_address = 0;
    test_game__DOT__game__DOT__object_draw = 0;
    test_game__DOT__game__DOT__board1 = 0;
    test_game__DOT__game__DOT__board2 = 0;
    test_game__DOT__game__DOT__ball = 0;
    test_game__DOT__game__DOT__board1_h_coord = 0;
    test_game__DOT__game__DOT__board1_v_coord = 0;
    test_game__DOT__game__DOT__board2_h_coord = 0;
    test_game__DOT__game__DOT__board2_v_coord = 0;
    test_game__DOT__game__DOT__ball_h_coord = 0;
    test_game__DOT__game__DOT__ball_v_coord = 0;
    test_game__DOT__game__DOT__x_direction = 0;
    test_game__DOT__game__DOT__y_direction = 0;
    test_game__DOT__game__DOT__rand_mod = 0;
    test_game__DOT__game__DOT__delta_speed = 0;
    test_game__DOT__game__DOT__p1_count = 0;
    test_game__DOT__game__DOT__p2_count = 0;
    { int __Vi0=0; for (; __Vi0<128000; ++__Vi0) {
            test_game__DOT__game__DOT__logo_rom__DOT__rom[__Vi0] = 0;
    }}
    test_game__DOT__display_ctrl__DOT__h_count = 0;
    test_game__DOT__display_ctrl__DOT__v_count = 0;
    __Vdly__test_game__DOT__game__DOT__regime_store = 0;
}
