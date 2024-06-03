// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTOPLEVEL_H_
#define _VTOPLEVEL_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtoplevel__Syms;
class Vtoplevel_VerilatedVcd;


//----------

VL_MODULE(Vtoplevel) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(overflow,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ toplevel__DOT__cpu__DOT__inA_is_PC;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__branch_taken;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__IDEX_funct3;
        CData/*6:0*/ toplevel__DOT__cpu__DOT__IDEX_funct7;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__IDEX_instr_rs2;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__IDEX_instr_rs1;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__IDEX_instr_rd;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_RegDst;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_ALUSrc;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_inA_is_PC;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_Jump;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_JumpJALR;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__IDEX_ALUcntrl;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_MemRead;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_MemWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_MemToReg;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_RegWrite;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__EXMEM_funct3;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__MEMWB_funct3;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_Zero;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_JumpJALR;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__byte_select_vector;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_MemRead;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_MemWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_RegWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_MemToReg;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__MEMWB_MemToReg;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__MEMWB_RegWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__RegDst;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__MemRead;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__MemWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__MemToReg;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__ALUSrc;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__PCSrc;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__RegWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__Jump;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__JumpJALR;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__Branch;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IDEX_Branch;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__EXMEM_Branch;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__bubble_ifid;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__bubble_idex;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__bubble_exmem;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__write_ifid;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__write_pc;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__ALUcntrl;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__ALUOp;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__bypassA;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__bypassB;
        CData/*7:0*/ toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel;
        SData/*15:0*/ toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__IFID_instr;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__PC;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__IFID_PC;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__IDEX_PC;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__PC_new;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__IDEX_signExtend;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__signExtend;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__IDEX_rdA;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__IDEX_rdB;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__EXMEM_ALUOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut;
    };
    struct {
        IData/*31:0*/ toplevel__DOT__cpu__DOT__EXMEM_MemWriteData;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__MemWriteData;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__MEMWB_DMemOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__MEMWB_ALUOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__ALUInA;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__ALUInB;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__bypassOutA;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__bypassOutB;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__wRegData;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__imm_i;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__cpu_regs__DOT__i;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__cpu_alu__DOT__out_val;
        QData/*32:0*/ toplevel__DOT__cpu__DOT__cpu_alu__DOT__unsigned_sub;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__cpu_IMem__DOT__data[16384];
        IData/*31:0*/ toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[32];
        IData/*31:0*/ toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data[32768];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ __Vtableidx1;
    CData/*5:0*/ __Vtableidx2;
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*0:0*/ __Vm_traceActivity[2];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__RegDst[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__MemRead[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__MemWrite[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__MemToReg[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__ALUSrc[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__RegWrite[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__Branch[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__Jump[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__JumpJALR[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__inA_is_PC[128];
    static CData/*2:0*/ __Vtable1_toplevel__DOT__cpu__DOT__ALUcntrl[128];
    static CData/*0:0*/ __Vtable2_toplevel__DOT__cpu__DOT__branch_taken[64];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtoplevel__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtoplevel);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vtoplevel(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vtoplevel();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
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
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtoplevel__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtoplevel__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtoplevel__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtoplevel__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtoplevel__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtoplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtoplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vtoplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vtoplevel__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vtoplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard