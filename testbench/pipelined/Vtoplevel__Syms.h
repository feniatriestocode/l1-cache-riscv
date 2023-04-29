// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VTOPLEVEL__SYMS_H_
#define _VTOPLEVEL__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vtoplevel.h"
#include "Vtoplevel___024unit.h"

// SYMS CLASS
class Vtoplevel__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtoplevel*                     TOPp;
    
    // CREATORS
    Vtoplevel__Syms(Vtoplevel* topp, const char* namep);
    ~Vtoplevel__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
