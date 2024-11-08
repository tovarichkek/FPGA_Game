// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VMAIN_H_
#define VERILATED_VMAIN_H_  // guard

#include "verilated.h"

class Vmain__Syms;
class Vmain___024root;

// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vmain VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vmain__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&pixel_clk,0,0);
    VL_IN8(&sim_rst,0,0);
    VL_IN8(&button_c,0,0);
    VL_IN8(&button_u,0,0);
    VL_IN8(&button_d,0,0);
    VL_IN8(&button_r,0,0);
    VL_IN8(&button_l,0,0);
    VL_IN8(&accel_data_x,7,0);
    VL_IN8(&accel_data_y,7,0);
    VL_IN8(&sw0,0,0);
    VL_IN8(&sw1,0,0);
    VL_IN8(&sw2,0,0);
    VL_IN8(&sw3,0,0);
    VL_IN8(&sw4,0,0);
    VL_IN8(&sw5,0,0);
    VL_IN8(&sw6,0,0);
    VL_IN8(&sw7,0,0);
    VL_IN8(&sw8,0,0);
    VL_OUT8(&sdl_de,0,0);
    VL_OUT8(&sdl_r,7,0);
    VL_OUT8(&sdl_g,7,0);
    VL_OUT8(&sdl_b,7,0);
    VL_OUT16(&sdl_sx,10,0);
    VL_OUT16(&sdl_sy,9,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vmain___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vmain(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vmain(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vmain();
  private:
    VL_UNCOPYABLE(Vmain);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
};

#endif  // guard
