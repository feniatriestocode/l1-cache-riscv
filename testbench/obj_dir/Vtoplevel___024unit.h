// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtoplevel.h for the primary calling header

#ifndef _VTOPLEVEL___024UNIT_H_
#define _VTOPLEVEL___024UNIT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtoplevel__Syms;
class Vtoplevel_VerilatedVcd;


//----------

VL_MODULE(Vtoplevel___024unit) {
  public:
    
    // INTERNAL VARIABLES
  private:
    Vtoplevel__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtoplevel___024unit);  ///< Copying not allowed
  public:
    Vtoplevel___024unit(const char* name = "TOP");
    ~Vtoplevel___024unit();
    
    // INTERNAL METHODS
    void __Vconfigure(Vtoplevel__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
