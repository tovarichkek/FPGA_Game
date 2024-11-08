// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmain.h for the primary calling header

#include "Vmain.h"
#include "Vmain__Syms.h"

//==========

void Vmain::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmain::eval\n"); );
    Vmain__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("main.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vmain::_eval_initial_loop(Vmain__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("main.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vmain::_sequent__TOP__3(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_sequent__TOP__3\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__test_game__DOT__game__DOT__regime_store 
        = vlTOPp->test_game__DOT__game__DOT__regime_store;
    vlTOPp->__Vdly__test_game__DOT__game__DOT__regime_store 
        = (1U & ((IData)(1U) - (IData)(vlTOPp->test_game__DOT__game__DOT__regime_store)));
}

VL_INLINE_OPT void Vmain::_sequent__TOP__4(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_sequent__TOP__4\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__test_game__DOT__game__DOT__x_direction;
    CData/*1:0*/ __Vdly__test_game__DOT__game__DOT__y_direction;
    CData/*7:0*/ __Vdly__test_game__DOT__game__DOT__p1_count;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__board2_h_coord;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__board1_h_coord;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__ball_h_coord;
    SData/*9:0*/ __Vdly__test_game__DOT__game__DOT__ball_v_coord;
    SData/*10:0*/ __Vdly__test_game__DOT__display_ctrl__DOT__h_count;
    SData/*9:0*/ __Vdly__test_game__DOT__display_ctrl__DOT__v_count;
    IData/*31:0*/ __Vdly__test_game__DOT__game__DOT__frames_cntr;
    IData/*31:0*/ __Vdly__test_game__DOT__game__DOT__rand_mod;
    // Body
    __Vdly__test_game__DOT__game__DOT__frames_cntr 
        = vlTOPp->test_game__DOT__game__DOT__frames_cntr;
    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
        = vlTOPp->test_game__DOT__game__DOT__board1_h_coord;
    __Vdly__test_game__DOT__game__DOT__board2_h_coord 
        = vlTOPp->test_game__DOT__game__DOT__board2_h_coord;
    __Vdly__test_game__DOT__game__DOT__p1_count = vlTOPp->test_game__DOT__game__DOT__p1_count;
    __Vdly__test_game__DOT__game__DOT__rand_mod = vlTOPp->test_game__DOT__game__DOT__rand_mod;
    __Vdly__test_game__DOT__display_ctrl__DOT__v_count 
        = vlTOPp->test_game__DOT__display_ctrl__DOT__v_count;
    __Vdly__test_game__DOT__display_ctrl__DOT__h_count 
        = vlTOPp->test_game__DOT__display_ctrl__DOT__h_count;
    __Vdly__test_game__DOT__game__DOT__x_direction 
        = vlTOPp->test_game__DOT__game__DOT__x_direction;
    __Vdly__test_game__DOT__game__DOT__ball_h_coord 
        = vlTOPp->test_game__DOT__game__DOT__ball_h_coord;
    __Vdly__test_game__DOT__game__DOT__y_direction 
        = vlTOPp->test_game__DOT__game__DOT__y_direction;
    __Vdly__test_game__DOT__game__DOT__ball_v_coord 
        = vlTOPp->test_game__DOT__game__DOT__ball_v_coord;
    if (vlTOPp->sim_rst) {
        vlTOPp->test_game__DOT__game__DOT__board1_v_coord = 0U;
    }
    if (vlTOPp->sim_rst) {
        vlTOPp->test_game__DOT__game__DOT__board2_v_coord = 0x244U;
    }
    vlTOPp->sdl_sy = vlTOPp->test_game__DOT__display_ctrl__DOT__v_count;
    vlTOPp->sdl_sx = vlTOPp->test_game__DOT__display_ctrl__DOT__h_count;
    vlTOPp->sdl_b = (0xffU & ((0xf0U & (((IData)(vlTOPp->test_game__DOT__game__DOT__ball)
                                          ? ((0x20U 
                                              & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                              ? 0xfU
                                              : 0U)
                                          : (((IData)(vlTOPp->test_game__DOT__game__DOT__board1) 
                                              | (IData)(vlTOPp->test_game__DOT__game__DOT__board2))
                                              ? ((0x100U 
                                                  & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                  ? 0xcU
                                                  : 0xfU)
                                              : (((IData)(vlTOPp->test_game__DOT__game__DOT__object_draw) 
                                                  & ((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
                                                     >> 9U))
                                                  ? 
                                                 ((IData)(vlTOPp->test_game__DOT__game__DOT__logo_rom_out) 
                                                  >> 8U)
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                   ? 8U
                                                   : 0U)))) 
                                        << 4U)) | (0xfU 
                                                   & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball)
                                                       ? 
                                                      ((0x20U 
                                                        & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                        ? 0xfU
                                                        : 0U)
                                                       : 
                                                      (((IData)(vlTOPp->test_game__DOT__game__DOT__board1) 
                                                        | (IData)(vlTOPp->test_game__DOT__game__DOT__board2))
                                                        ? 
                                                       ((0x100U 
                                                         & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                         ? 0xcU
                                                         : 0xfU)
                                                        : 
                                                       (((IData)(vlTOPp->test_game__DOT__game__DOT__object_draw) 
                                                         & ((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
                                                            >> 9U))
                                                         ? 
                                                        ((IData)(vlTOPp->test_game__DOT__game__DOT__logo_rom_out) 
                                                         >> 8U)
                                                         : 
                                                        ((4U 
                                                          & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                          ? 8U
                                                          : 0U)))))));
    vlTOPp->sdl_g = (0xffU & ((0xf0U & (((IData)(vlTOPp->test_game__DOT__game__DOT__ball)
                                          ? ((0x10U 
                                              & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                              ? 0xfU
                                              : 0U)
                                          : (((IData)(vlTOPp->test_game__DOT__game__DOT__board1) 
                                              | (IData)(vlTOPp->test_game__DOT__game__DOT__board2))
                                              ? ((0x80U 
                                                  & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                  ? 0xcU
                                                  : 0xfU)
                                              : (((IData)(vlTOPp->test_game__DOT__game__DOT__object_draw) 
                                                  & ((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
                                                     >> 9U))
                                                  ? 
                                                 ((IData)(vlTOPp->test_game__DOT__game__DOT__logo_rom_out) 
                                                  >> 4U)
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                   ? 8U
                                                   : 0U)))) 
                                        << 4U)) | (0xfU 
                                                   & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball)
                                                       ? 
                                                      ((0x10U 
                                                        & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                        ? 0xfU
                                                        : 0U)
                                                       : 
                                                      (((IData)(vlTOPp->test_game__DOT__game__DOT__board1) 
                                                        | (IData)(vlTOPp->test_game__DOT__game__DOT__board2))
                                                        ? 
                                                       ((0x80U 
                                                         & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                         ? 0xcU
                                                         : 0xfU)
                                                        : 
                                                       (((IData)(vlTOPp->test_game__DOT__game__DOT__object_draw) 
                                                         & ((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
                                                            >> 9U))
                                                         ? 
                                                        ((IData)(vlTOPp->test_game__DOT__game__DOT__logo_rom_out) 
                                                         >> 4U)
                                                         : 
                                                        ((2U 
                                                          & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                          ? 8U
                                                          : 0U)))))));
    vlTOPp->sdl_r = (0xffU & ((((IData)(vlTOPp->test_game__DOT__game__DOT__ball)
                                 ? 0xfU : (0xfU & (
                                                   ((IData)(vlTOPp->test_game__DOT__game__DOT__board1) 
                                                    | (IData)(vlTOPp->test_game__DOT__game__DOT__board2))
                                                    ? 
                                                   ((0x40U 
                                                     & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                     ? 0xcU
                                                     : 0xfU)
                                                    : 
                                                   (((IData)(vlTOPp->test_game__DOT__game__DOT__object_draw) 
                                                     & ((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
                                                        >> 9U))
                                                     ? (IData)(vlTOPp->test_game__DOT__game__DOT__logo_rom_out)
                                                     : 
                                                    ((1U 
                                                      & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                      ? 8U
                                                      : 0U))))) 
                               << 4U) | ((IData)(vlTOPp->test_game__DOT__game__DOT__ball)
                                          ? 0xfU : 
                                         (0xfU & (((IData)(vlTOPp->test_game__DOT__game__DOT__board1) 
                                                   | (IData)(vlTOPp->test_game__DOT__game__DOT__board2))
                                                   ? 
                                                  ((0x40U 
                                                    & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                    ? 0xcU
                                                    : 0xfU)
                                                   : 
                                                  (((IData)(vlTOPp->test_game__DOT__game__DOT__object_draw) 
                                                    & ((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
                                                       >> 9U))
                                                    ? (IData)(vlTOPp->test_game__DOT__game__DOT__logo_rom_out)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW))
                                                     ? 8U
                                                     : 0U)))))));
    vlTOPp->sdl_de = vlTOPp->test_game__DOT__disp_enbl;
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__frames_cntr = 0U;
    } else {
        if ((2U == vlTOPp->test_game__DOT__game__DOT__frames_cntr)) {
            __Vdly__test_game__DOT__game__DOT__frames_cntr = 0U;
        } else {
            if (vlTOPp->test_game__DOT__game__DOT__end_of_frame) {
                __Vdly__test_game__DOT__game__DOT__frames_cntr 
                    = ((IData)(1U) + vlTOPp->test_game__DOT__game__DOT__frames_cntr);
            }
        }
    }
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__board1_h_coord = 0x15eU;
    } else {
        if (((IData)(vlTOPp->test_game__DOT__game__DOT__end_of_frame) 
             & (0U == vlTOPp->test_game__DOT__game__DOT__frames_cntr))) {
            if (vlTOPp->test_game__DOT__game__DOT__regime_store) {
                if (vlTOPp->test_game__DOT__game__DOT__regime_store) {
                    if (((~ (1U & (((IData)(1U) + (IData)(vlTOPp->accel_data_y)) 
                                   >> 7U))) & (0U != 
                                               (0xffU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlTOPp->accel_data_y)))))) {
                        __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                            = ((0x14U > (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord))
                                ? 0U : (0x3ffU & ((IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord) 
                                                  - (IData)(0x14U))));
                    } else {
                        if ((1U & ((((IData)(1U) + (IData)(vlTOPp->accel_data_y)) 
                                    >> 7U) & (0U != 
                                              (0xffU 
                                               & ((IData)(1U) 
                                                  + (IData)(vlTOPp->accel_data_y))))))) {
                            __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                                = ((0x31fU <= ((IData)(0x78U) 
                                               + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)))
                                    ? 0x2bbU : (0x3ffU 
                                                & ((IData)(0x14U) 
                                                   + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord))));
                        }
                    }
                }
            } else {
                if (vlTOPp->button_l) {
                    __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                        = ((0x14U > (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord))
                            ? 0U : (0x3ffU & ((IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord) 
                                              - (IData)(0x14U))));
                } else {
                    if (vlTOPp->button_d) {
                        __Vdly__test_game__DOT__game__DOT__board1_h_coord 
                            = ((0x31fU <= ((IData)(0x78U) 
                                           + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)))
                                ? 0x2bbU : (0x3ffU 
                                            & ((IData)(0x14U) 
                                               + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord))));
                    }
                }
            }
        }
    }
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__board2_h_coord = 0x15eU;
    } else {
        if (((IData)(vlTOPp->test_game__DOT__game__DOT__end_of_frame) 
             & (0U == vlTOPp->test_game__DOT__game__DOT__frames_cntr))) {
            if ((1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__regime_store)))) {
                if (vlTOPp->button_u) {
                    __Vdly__test_game__DOT__game__DOT__board2_h_coord 
                        = ((0x14U > (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord))
                            ? 0U : (0x3ffU & ((IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord) 
                                              - (IData)(0x14U))));
                } else {
                    if (vlTOPp->button_r) {
                        __Vdly__test_game__DOT__game__DOT__board2_h_coord 
                            = ((0x31fU <= ((IData)(0x78U) 
                                           + (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)))
                                ? 0x2bbU : (0x3ffU 
                                            & ((IData)(0x14U) 
                                               + (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord))));
                    }
                }
            }
        }
    }
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0U;
        __Vdly__test_game__DOT__display_ctrl__DOT__v_count = 0U;
    } else {
        if ((0x41fU > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count))) {
            __Vdly__test_game__DOT__display_ctrl__DOT__h_count 
                = (0x7ffU & ((IData)(1U) + (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)));
        } else {
            __Vdly__test_game__DOT__display_ctrl__DOT__v_count 
                = ((0x273U > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))
                    ? (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count)))
                    : 0U);
            __Vdly__test_game__DOT__display_ctrl__DOT__h_count = 0U;
        }
    }
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0x186U;
    } else {
        if (((IData)(vlTOPp->test_game__DOT__game__DOT__end_of_frame) 
             & (0U == vlTOPp->test_game__DOT__game__DOT__frames_cntr))) {
            if (vlTOPp->test_game__DOT__game__DOT__x_direction) {
                if (((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                     < ((IData)(8U) + (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed)))) {
                    __Vdly__test_game__DOT__game__DOT__x_direction 
                        = (1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__x_direction)));
                    __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0U;
                } else {
                    __Vdly__test_game__DOT__game__DOT__ball_h_coord 
                        = (0x3ffU & (((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                                      - (IData)(8U)) 
                                     - (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed)));
                }
            } else {
                if ((0x31fU <= ((IData)(0x18U) + ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                                                  + (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed))))) {
                    __Vdly__test_game__DOT__game__DOT__x_direction 
                        = (1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__x_direction)));
                    __Vdly__test_game__DOT__game__DOT__ball_h_coord = 0x30fU;
                } else {
                    __Vdly__test_game__DOT__game__DOT__ball_h_coord 
                        = (0x3ffU & ((IData)(8U) + 
                                     ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                                      + (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed))));
                }
            }
        }
    }
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x122U;
    } else {
        if ((((IData)(vlTOPp->test_game__DOT__game__DOT__end_of_frame) 
              & (0U == vlTOPp->test_game__DOT__game__DOT__frames_cntr)) 
             & (IData)(vlTOPp->test_game__DOT__game__DOT__regime_store))) {
            __Vdly__test_game__DOT__game__DOT__y_direction 
                = (1U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction));
            if ((1U & (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))) {
                if (((0x14U > ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord) 
                               - (IData)(0xaU))) & 
                     ((((IData)(0x10U) + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord)) 
                       > (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)) 
                      & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                         < ((IData)(0x64U) + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)))))) {
                    __Vdly__test_game__DOT__game__DOT__y_direction 
                        = ((2U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction)) 
                           | (1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))));
                    __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x14U;
                } else {
                    if (VL_UNLIKELY((0xaU > (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord)))) {
                        VL_WRITEF("you lose\n");
                        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x24eU;
                        __Vdly__test_game__DOT__game__DOT__y_direction = 0U;
                    } else {
                        __Vdly__test_game__DOT__game__DOT__ball_v_coord 
                            = (0x3ffU & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord) 
                                         - (IData)(0xaU)));
                    }
                }
            } else {
                if (((0x243U < ((IData)(0x1aU) + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord))) 
                     & ((((IData)(0x10U) + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord)) 
                         > (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)) 
                        & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                           < ((IData)(0x64U) + (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)))))) {
                    __Vdly__test_game__DOT__game__DOT__y_direction 
                        = ((2U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction)) 
                           | (1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))));
                    __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x233U;
                } else {
                    if ((0x257U <= ((IData)(0x1aU) 
                                    + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord)))) {
                        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x247U;
                        __Vdly__test_game__DOT__game__DOT__y_direction = 1U;
                    } else {
                        __Vdly__test_game__DOT__game__DOT__ball_v_coord 
                            = (0x3ffU & ((IData)(0xaU) 
                                         + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord)));
                    }
                }
            }
        }
    }
    vlTOPp->test_game__DOT__game__DOT__x_direction 
        = __Vdly__test_game__DOT__game__DOT__x_direction;
    vlTOPp->test_game__DOT__disp_enbl = ((IData)(vlTOPp->sim_rst) 
                                         | (((0x31fU 
                                              > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                             & (0x258U 
                                                > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))) 
                                            | ((0x41fU 
                                                == (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                                               & ((0x257U 
                                                   > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count)) 
                                                  | (0x273U 
                                                     == (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))))));
    if (vlTOPp->sim_rst) {
        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x122U;
    } else {
        if ((((IData)(vlTOPp->test_game__DOT__game__DOT__end_of_frame) 
              & (0U == vlTOPp->test_game__DOT__game__DOT__frames_cntr)) 
             & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__regime_store)))) {
            if ((2U & (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))) {
                if (((((IData)(vlTOPp->button_u) | (IData)(vlTOPp->button_d)) 
                      | (IData)(vlTOPp->button_l)) 
                     | (IData)(vlTOPp->button_r))) {
                    vlTOPp->test_game__DOT__game__DOT__delta_speed 
                        = ((0x3f0U & (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed)) 
                           | (0xfU & vlTOPp->test_game__DOT__game__DOT__rand_mod));
                    __Vdly__test_game__DOT__game__DOT__y_direction 
                        = ((2U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction)) 
                           | (1U & (vlTOPp->test_game__DOT__game__DOT__rand_mod 
                                    >> 4U)));
                    __Vdly__test_game__DOT__game__DOT__y_direction 
                        = (1U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction));
                    __Vdly__test_game__DOT__game__DOT__rand_mod 
                        = VL_RANDOM_I(32);
                }
            } else {
                if ((1U & (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))) {
                    if (((0x14U > ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord) 
                                   - (IData)(0xaU))) 
                         & ((((IData)(0x10U) + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord)) 
                             > (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)) 
                            & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                               < ((IData)(0x64U) + (IData)(vlTOPp->test_game__DOT__game__DOT__board1_h_coord)))))) {
                        __Vdly__test_game__DOT__game__DOT__y_direction 
                            = ((2U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction)) 
                               | (1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))));
                        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x14U;
                        vlTOPp->test_game__DOT__game__DOT__delta_speed 
                            = ((0x3f0U & (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed)) 
                               | (0xfU & vlTOPp->test_game__DOT__game__DOT__rand_mod));
                        __Vdly__test_game__DOT__game__DOT__rand_mod 
                            = VL_RANDOM_I(32);
                    } else {
                        if (VL_UNLIKELY((0xaU > (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord)))) {
                            vlTOPp->test_game__DOT__game__DOT__p2_count 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlTOPp->test_game__DOT__game__DOT__p2_count)));
                            VL_WRITEF("%3#:%3#\n",8,
                                      vlTOPp->test_game__DOT__game__DOT__p1_count,
                                      8,(IData)(vlTOPp->test_game__DOT__game__DOT__p2_count));
                            __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x122U;
                            __Vdly__test_game__DOT__game__DOT__y_direction = 2U;
                        } else {
                            __Vdly__test_game__DOT__game__DOT__ball_v_coord 
                                = (0x3ffU & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord) 
                                             - (IData)(0xaU)));
                        }
                    }
                } else {
                    if (((0x243U < ((IData)(0x1aU) 
                                    + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord))) 
                         & ((((IData)(0x10U) + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord)) 
                             > (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)) 
                            & ((IData)(vlTOPp->test_game__DOT__game__DOT__ball_h_coord) 
                               < ((IData)(0x64U) + (IData)(vlTOPp->test_game__DOT__game__DOT__board2_h_coord)))))) {
                        __Vdly__test_game__DOT__game__DOT__y_direction 
                            = ((2U & (IData)(__Vdly__test_game__DOT__game__DOT__y_direction)) 
                               | (1U & (~ (IData)(vlTOPp->test_game__DOT__game__DOT__y_direction))));
                        __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x233U;
                        vlTOPp->test_game__DOT__game__DOT__delta_speed 
                            = ((0x3f0U & (IData)(vlTOPp->test_game__DOT__game__DOT__delta_speed)) 
                               | (0xfU & vlTOPp->test_game__DOT__game__DOT__rand_mod));
                        __Vdly__test_game__DOT__game__DOT__rand_mod 
                            = VL_RANDOM_I(32);
                    } else {
                        if (VL_UNLIKELY((0x257U <= 
                                         ((IData)(0x1aU) 
                                          + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord))))) {
                            __Vdly__test_game__DOT__game__DOT__p1_count 
                                = (0xffU & ((IData)(1U) 
                                            + (IData)(vlTOPp->test_game__DOT__game__DOT__p1_count)));
                            VL_WRITEF("%3#:%3#\n",8,
                                      vlTOPp->test_game__DOT__game__DOT__p1_count,
                                      8,(IData)(vlTOPp->test_game__DOT__game__DOT__p2_count));
                            __Vdly__test_game__DOT__game__DOT__ball_v_coord = 0x122U;
                            __Vdly__test_game__DOT__game__DOT__y_direction = 3U;
                        } else {
                            __Vdly__test_game__DOT__game__DOT__ball_v_coord 
                                = (0x3ffU & ((IData)(0xaU) 
                                             + (IData)(vlTOPp->test_game__DOT__game__DOT__ball_v_coord)));
                        }
                    }
                }
            }
        }
    }
    vlTOPp->test_game__DOT__game__DOT__p1_count = __Vdly__test_game__DOT__game__DOT__p1_count;
    vlTOPp->test_game__DOT__game__DOT__rand_mod = __Vdly__test_game__DOT__game__DOT__rand_mod;
    vlTOPp->test_game__DOT__game__DOT__frames_cntr 
        = __Vdly__test_game__DOT__game__DOT__frames_cntr;
    vlTOPp->test_game__DOT__game__DOT__y_direction 
        = __Vdly__test_game__DOT__game__DOT__y_direction;
    vlTOPp->test_game__DOT__game__DOT__ball_v_coord 
        = __Vdly__test_game__DOT__game__DOT__ball_v_coord;
    vlTOPp->test_game__DOT__game__DOT__ball_h_coord 
        = __Vdly__test_game__DOT__game__DOT__ball_h_coord;
    vlTOPp->test_game__DOT__game__DOT__board1_h_coord 
        = __Vdly__test_game__DOT__game__DOT__board1_h_coord;
    vlTOPp->test_game__DOT__game__DOT__board2_h_coord 
        = __Vdly__test_game__DOT__game__DOT__board2_h_coord;
    vlTOPp->test_game__DOT__game__DOT__end_of_frame 
        = ((~ (IData)(vlTOPp->sim_rst)) & ((0x31fU 
                                            == (0x3ffU 
                                                & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count))) 
                                           & (0x257U 
                                              == (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))));
    vlTOPp->test_game__DOT__display_ctrl__DOT__h_count 
        = __Vdly__test_game__DOT__display_ctrl__DOT__h_count;
    vlTOPp->test_game__DOT__display_ctrl__DOT__v_count 
        = __Vdly__test_game__DOT__display_ctrl__DOT__v_count;
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
    vlTOPp->test_game__DOT__game__DOT__logo_read_address 
        = (0x1ffffU & (((0x3ffU & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)) 
                        - (IData)(0xc7U)) + ((IData)(0x190U) 
                                             * (0x1ffffU 
                                                & ((IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count) 
                                                   - (IData)(0x8cU))))));
    vlTOPp->test_game__DOT__game__DOT__logo_rom_out 
        = ((0x1f3ffU >= vlTOPp->test_game__DOT__game__DOT__logo_read_address)
            ? vlTOPp->test_game__DOT__game__DOT__logo_rom__DOT__rom
           [vlTOPp->test_game__DOT__game__DOT__logo_read_address]
            : 0U);
}

VL_INLINE_OPT void Vmain::_combo__TOP__6(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_combo__TOP__6\n"); );
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
    vlTOPp->test_game__DOT__game__DOT__object_draw 
        = (((IData)(vlTOPp->test_game__DOT____Vcellinp__game__SW) 
            >> 9U) & ((((0xc8U <= (0x3ffU & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count))) 
                        & (0x257U > (0x3ffU & (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__h_count)))) 
                       & (0x8cU <= (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))) 
                      & (0x1cbU > (IData)(vlTOPp->test_game__DOT__display_ctrl__DOT__v_count))));
}

VL_INLINE_OPT void Vmain::_sequent__TOP__7(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_sequent__TOP__7\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->test_game__DOT__game__DOT__regime_store 
        = vlTOPp->__Vdly__test_game__DOT__game__DOT__regime_store;
}

VL_INLINE_OPT void Vmain::_multiclk__TOP__8(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_multiclk__TOP__8\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
}

void Vmain::_eval(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->button_c) & (~ (IData)(vlTOPp->__Vclklast__TOP__button_c)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->pixel_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pixel_clk)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    if (((IData)(vlTOPp->button_c) & (~ (IData)(vlTOPp->__Vclklast__TOP__button_c)))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    if ((((IData)(vlTOPp->button_c) & (~ (IData)(vlTOPp->__Vclklast__TOP__button_c))) 
         | ((IData)(vlTOPp->pixel_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__pixel_clk))))) {
        vlTOPp->_multiclk__TOP__8(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__button_c = vlTOPp->button_c;
    vlTOPp->__Vclklast__TOP__pixel_clk = vlTOPp->pixel_clk;
}

VL_INLINE_OPT QData Vmain::_change_request(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_change_request\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vmain::_change_request_1(Vmain__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_change_request_1\n"); );
    Vmain* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vmain::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmain::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((pixel_clk & 0xfeU))) {
        Verilated::overWidthError("pixel_clk");}
    if (VL_UNLIKELY((sim_rst & 0xfeU))) {
        Verilated::overWidthError("sim_rst");}
    if (VL_UNLIKELY((button_c & 0xfeU))) {
        Verilated::overWidthError("button_c");}
    if (VL_UNLIKELY((button_u & 0xfeU))) {
        Verilated::overWidthError("button_u");}
    if (VL_UNLIKELY((button_d & 0xfeU))) {
        Verilated::overWidthError("button_d");}
    if (VL_UNLIKELY((button_r & 0xfeU))) {
        Verilated::overWidthError("button_r");}
    if (VL_UNLIKELY((button_l & 0xfeU))) {
        Verilated::overWidthError("button_l");}
    if (VL_UNLIKELY((sw0 & 0xfeU))) {
        Verilated::overWidthError("sw0");}
    if (VL_UNLIKELY((sw1 & 0xfeU))) {
        Verilated::overWidthError("sw1");}
    if (VL_UNLIKELY((sw2 & 0xfeU))) {
        Verilated::overWidthError("sw2");}
    if (VL_UNLIKELY((sw3 & 0xfeU))) {
        Verilated::overWidthError("sw3");}
    if (VL_UNLIKELY((sw4 & 0xfeU))) {
        Verilated::overWidthError("sw4");}
    if (VL_UNLIKELY((sw5 & 0xfeU))) {
        Verilated::overWidthError("sw5");}
    if (VL_UNLIKELY((sw6 & 0xfeU))) {
        Verilated::overWidthError("sw6");}
    if (VL_UNLIKELY((sw7 & 0xfeU))) {
        Verilated::overWidthError("sw7");}
    if (VL_UNLIKELY((sw8 & 0xfeU))) {
        Verilated::overWidthError("sw8");}
    if (VL_UNLIKELY((sw9 & 0xfeU))) {
        Verilated::overWidthError("sw9");}
}
#endif  // VL_DEBUG
