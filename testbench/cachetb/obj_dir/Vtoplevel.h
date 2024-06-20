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
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ toplevel__DOT__Instruction_Mem__DOT__counter_reset;
        CData/*0:0*/ toplevel__DOT__Data_Mem__DOT__counter_reset;
        CData/*0:0*/ toplevel__DOT__dmem_ren;
        CData/*0:0*/ toplevel__DOT__dmem_wen;
        CData/*0:0*/ toplevel__DOT__dmem_ready;
        CData/*0:0*/ toplevel__DOT__dmem_done;
        CData/*0:0*/ toplevel__DOT__imem_ren;
        CData/*0:0*/ toplevel__DOT__imem_ready;
        CData/*7:0*/ toplevel__DOT__imem_block_address;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__ren;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__wen;
        CData/*6:0*/ toplevel__DOT__cpu__DOT__addr;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__byteSelectVector;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__cacheHit;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__cacheDirtyBit;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__memReadReady;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__memWriteDone;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__stall;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__cacheMemWen;
        CData/*7:0*/ toplevel__DOT__cpu__DOT__cacheBytesAccess;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__memRen;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__memWen;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__dcache_stall;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__icache_stall;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__dcache_ren;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__dcache_wen;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__dcache_addr;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__DcacheRen;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__DcacheWen;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__DcacheMemWen;
        CData/*7:0*/ toplevel__DOT__cpu__DOT__DcacheBytesAccess;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__DcacheBlockAddr;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__DcacheDirtyBit;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IcacheRen;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IcacheMemWen;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__IcacheBlockAddr;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__IcacheDirtyBit;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3;
        CData/*6:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg;
        CData/*4:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr;
    };
    struct {
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__Jump;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__Branch;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl;
        CData/*3:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__overflow;
        CData/*0:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache;
        CData/*7:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__hitReg;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__mask;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__mask;
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__Dcntr__DOT__state;
        CData/*2:0*/ toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state;
        CData/*0:0*/ toplevel__DOT__Instruction_Mem__DOT__delayed;
        CData/*3:0*/ toplevel__DOT__Instruction_Mem__DOT__delay_counter;
        CData/*0:0*/ toplevel__DOT__Data_Mem__DOT__flag;
        CData/*0:0*/ toplevel__DOT__Data_Mem__DOT__delayed;
        CData/*3:0*/ toplevel__DOT__Data_Mem__DOT__delay_counter;
        CData/*0:0*/ toplevel__DOT__Data_Mem__DOT__temp_done;
        SData/*15:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__din;
        WData/*127:0*/ toplevel__DOT__cpu__DOT__IcacheDin[4];
        WData/*127:0*/ toplevel__DOT__cpu__DOT__IcacheDout[4];
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__PC;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__PC_new;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__instr;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA;
    };
    struct {
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__DMemOut;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__i;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__j;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__i;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__j;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__m;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__l;
        QData/*63:0*/ toplevel__DOT__cpu__DOT__cacheDout;
        QData/*63:0*/ toplevel__DOT__cpu__DOT__memDout;
        QData/*63:0*/ toplevel__DOT__cpu__DOT__cacheDin;
        QData/*63:0*/ toplevel__DOT__cpu__DOT__dcache_output;
        QData/*63:0*/ toplevel__DOT__cpu__DOT__DcacheDin;
        QData/*63:0*/ toplevel__DOT__cpu__DOT__DcacheDout;
        QData/*32:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub;
        QData/*63:0*/ toplevel__DOT__Data_Mem__DOT__temp_din;
        IData/*31:0*/ toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[32];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[4];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__status_col[4];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[4][2];
        WData/*127:0*/ toplevel__DOT__cpu__DOT__Icache__DOT__data_col[4][2][4];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[4];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[4];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[4];
        CData/*1:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[4][2];
        QData/*63:0*/ toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[4][2];
        WData/*127:0*/ toplevel__DOT__Instruction_Mem__DOT__data[16][4];
        QData/*63:0*/ toplevel__DOT__Data_Mem__DOT__data[16];
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*6:0*/ toplevel__DOT____Vcellout__cpu__dmem_block_address;
    CData/*6:0*/ __Vtableidx1;
    CData/*5:0*/ __Vtableidx2;
    CData/*7:0*/ __Vtableidx3;
    CData/*2:0*/ __Vtableidx4;
    CData/*0:0*/ __Vdly__toplevel__DOT__Data_Mem__DOT__flag;
    CData/*3:0*/ __Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter;
    CData/*3:0*/ __Vdly__toplevel__DOT__Data_Mem__DOT__delay_counter;
    CData/*0:0*/ __VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    CData/*0:0*/ __VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset;
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*0:0*/ __Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    CData/*0:0*/ __Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset;
    IData/*31:0*/ toplevel__DOT____Vcellout__cpu__dmem_din;
    IData/*31:0*/ toplevel__DOT__cpu__DOT____Vcellout__pipeline__dcache_input;
    CData/*0:0*/ __Vm_traceActivity[6];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__Branch[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__Jump[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR[128];
    static CData/*0:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC[128];
    static CData/*2:0*/ __Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl[128];
    static CData/*0:0*/ __Vtable2_toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken[64];
    static CData/*2:0*/ __Vtable3_toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state[256];
    static CData/*0:0*/ __Vtable4_toplevel__DOT__cpu__DOT__stall[8];
    static CData/*0:0*/ __Vtable4_toplevel__DOT__cpu__DOT__cacheMemWen[8];
    static CData/*0:0*/ __Vtable4_toplevel__DOT__cpu__DOT__memRen[8];
    static CData/*0:0*/ __Vtable4_toplevel__DOT__cpu__DOT__memWen[8];
    
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
  public:
    static void _combo__TOP__3(Vtoplevel__Syms* __restrict vlSymsp);
    static void _combo__TOP__8(Vtoplevel__Syms* __restrict vlSymsp);
  private:
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
    static void _sequent__TOP__10(Vtoplevel__Syms* __restrict vlSymsp);
    static void _sequent__TOP__11(Vtoplevel__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vtoplevel__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vtoplevel__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vtoplevel__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vtoplevel__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vtoplevel__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vtoplevel__Syms* __restrict vlSymsp) VL_ATTR_COLD;
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
