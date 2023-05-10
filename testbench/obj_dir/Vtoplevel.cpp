// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtoplevel.h for the primary calling header

#include "Vtoplevel.h"
#include "Vtoplevel__Syms.h"

//==========

void Vtoplevel::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtoplevel::eval\n"); );
    Vtoplevel__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../src/pipelined/toplevel.v", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtoplevel::_eval_initial_loop(Vtoplevel__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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
            VL_FATAL_MT("../src/pipelined/toplevel.v", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__1(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__1\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0;
    // Body
    __Vdlyvset__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0 = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__i = 0x20U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData 
        = ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem)))
            ? 0U : vlTOPp->toplevel__DOT__cpu__DOT__bypassOutB);
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PCplus4 = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl = 0U;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PCplus4 
            = vlTOPp->toplevel__DOT__cpu__DOT__IFID_PCplus4;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl 
            = vlTOPp->toplevel__DOT__cpu__DOT__ALUcntrl;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUSrc = 
        ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUSrc));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_PC = ((1U 
                                                  & ((~ (IData)(vlTOPp->reset)) 
                                                     | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem)))
                                                  ? 0U
                                                  : vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC);
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Zero = (
                                                   (~ 
                                                    ((~ (IData)(vlTOPp->reset)) 
                                                     | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem))) 
                                                   & (0U 
                                                      == vlTOPp->toplevel__DOT__cpu__DOT__ALUOut));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut 
        = ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem)))
            ? 0U : (vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC 
                    + vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Branch = 
        ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem))) 
         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Branch));
    vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_MemToReg 
        = ((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemToReg));
    if (vlTOPp->reset) {
        vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut 
            = vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut;
        vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut 
            = vlTOPp->toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data
            [(0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                         >> 2U))];
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut = 0U;
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7 = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1 = 0U;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7 
            = (0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 0x19U));
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1 
            = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 0xfU));
    }
    vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite 
        = ((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3 = 
        ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3)
          : 7U);
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__CPU_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))) {
            __Vdlyvval__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0 
                = vlTOPp->toplevel__DOT__cpu__DOT__wRegData;
            __Vdlyvset__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0 = 1U;
            __Vdlyvdim0__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0 
                = vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdA = 
            ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__CPU_RegWrite) 
               & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                  == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                               >> 0xfU)))) & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))
              ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
              : vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data
             [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 0xfU))]);
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdB = 
            ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__CPU_RegWrite) 
               & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                  == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                               >> 0x14U)))) & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))
              ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
              : vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data
             [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 0x14U))]);
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdA = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdB = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[1U] = 1U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[2U] = 2U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[3U] = 3U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[4U] = 4U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[5U] = 5U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[6U] = 6U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[7U] = 7U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[8U] = 8U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[9U] = 9U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0xaU] = 0xaU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0xbU] = 0xbU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0xcU] = 0xcU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0xdU] = 0xdU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0xeU] = 0xeU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0xfU] = 0xfU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x10U] = 0x10U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x11U] = 0x11U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x12U] = 0x12U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x13U] = 0x13U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x14U] = 0x14U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x15U] = 0x15U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x16U] = 0x16U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x17U] = 0x17U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x18U] = 0x18U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x19U] = 0x19U;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x1aU] = 0x1aU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x1bU] = 0x1bU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x1cU] = 0x1cU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x1dU] = 0x1dU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x1eU] = 0x1eU;
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0x1fU] = 0x1fU;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[__Vdlyvdim0__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__cpu_regs__DOT__data__v0;
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IFID_PCplus4 = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__write_ifid) {
            vlTOPp->toplevel__DOT__cpu__DOT__IFID_PCplus4 
                = ((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__PC);
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC = 0U;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend 
            = vlTOPp->toplevel__DOT__cpu__DOT__signExtend;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC = vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Branch = 
        ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Branch));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemToReg 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemToReg));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__wRegData = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_MemToReg)
                                                  ? 
                                                 ((0U 
                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                   ? 
                                                  ((0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (0xffU 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut))
                                                   : 
                                                  ((1U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                    ? 
                                                   ((0xffff0000U 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut 
                                                                       >> 0xfU)))) 
                                                        << 0x10U)) 
                                                    | (0xffffU 
                                                       & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut))
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                     ? 
                                                    (0xffU 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut)
                                                     : 
                                                    ((5U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                      ? 
                                                     (0xffffU 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut)
                                                      : vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut))))
                                                  : vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut);
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3 = 
        ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem)))
          ? 7U : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3));
    vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr)
            : 0U);
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__write_ifid) {
            vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__PC;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemToReg 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MemToReg));
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3 = 
        ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex)))
          ? 0U : (7U & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 0xcU)));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr 
        = ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem)))
            ? 0U : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst)
                     ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd)
                     : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2)));
    if ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl))) {
        vlTOPp->toplevel__DOT__cpu__DOT__ALUOp = ((2U 
                                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl))
                                                    ? 
                                                   ((4U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                     ? 
                                                    ((2U 
                                                      & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                       ? 4U
                                                       : 3U)
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                       ? 
                                                      ((0U 
                                                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7))
                                                        ? 6U
                                                        : 7U)
                                                       : 2U))
                                                     : 
                                                    ((2U 
                                                      & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                      ? 
                                                     ((1U 
                                                       & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                       ? 9U
                                                       : 8U)
                                                      : 
                                                     ((1U 
                                                       & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                       ? 5U
                                                       : 0U)))
                                                    : 0xcU));
    } else {
        if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl))) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl))) {
                vlTOPp->toplevel__DOT__cpu__DOT__ALUOp = 0xbU;
            } else {
                if (((((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3)) 
                       | (1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))) 
                      | (4U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))) 
                     | (5U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3)))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__ALUOp = 1U;
                } else {
                    if (((6U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3)) 
                         | (7U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3)))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__ALUOp = 0xaU;
                    }
                }
            }
        } else {
            vlTOPp->toplevel__DOT__cpu__DOT__ALUOp 
                = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl))
                    ? 0U : ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                             ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                 ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                     ? 4U : 3U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7))
                                                     ? 6U
                                                     : 7U)
                                                    : 2U))
                             : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                 ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                     ? 9U : 8U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3))
                                                    ? 5U
                                                    : 
                                                   ((0U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7))
                                                     ? 0U
                                                     : 1U)))));
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__bypassA = 0U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite) 
         & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
             == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1))) {
            vlTOPp->toplevel__DOT__cpu__DOT__bypassA = 1U;
        }
    }
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite) 
         & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr)))) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr) 
             == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1))) {
            vlTOPp->toplevel__DOT__cpu__DOT__bypassA = 2U;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst = 
        ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__RegDst));
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2 = 0U;
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd 
            = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 7U));
        vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2 
            = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                        >> 0x14U));
    }
    vlTOPp->toplevel__DOT__cpu__DOT__bypassB = 0U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite) 
         & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
             == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2))) {
            vlTOPp->toplevel__DOT__cpu__DOT__bypassB = 1U;
        }
    }
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite) 
         & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr)))) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr) 
             == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2))) {
            vlTOPp->toplevel__DOT__cpu__DOT__bypassB = 2U;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__write_ifid) {
            vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                = vlTOPp->toplevel__DOT__cpu__DOT__cpu_IMem__DOT__data
                [(0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                             >> 2U))];
        }
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__write_pc) {
            vlTOPp->toplevel__DOT__cpu__DOT__PC = vlTOPp->toplevel__DOT__cpu__DOT__PC_new;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__PC = 0x400000U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__imm_i = ((0xfffff000U 
                                               & ((- (IData)(
                                                             (1U 
                                                              & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                 >> 0x1fU)))) 
                                                  << 0xcU)) 
                                              | (0xfffU 
                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                    >> 0x14U)));
    vlTOPp->toplevel__DOT__cpu__DOT__signExtend = (
                                                   (0x40U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                    ? 
                                                   ((0x20U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                     ? 
                                                    ((0x10U 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                      ? 0U
                                                      : 
                                                     ((8U 
                                                       & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                       ? 
                                                      ((4U 
                                                        & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                        ? 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? 
                                                         ((0xfff00000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                             >> 0x1fU)))) 
                                                              << 0x14U)) 
                                                          | ((0xff000U 
                                                              & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr) 
                                                             | ((0x800U 
                                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                    >> 9U)) 
                                                                | ((0x7e0U 
                                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                       >> 0x14U)) 
                                                                   | (0x1eU 
                                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                         >> 0x14U))))))
                                                          : 0U)
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? 
                                                         ((0xfffff000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                             >> 0x1fU)))) 
                                                              << 0xcU)) 
                                                          | ((0x800U 
                                                              & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                 << 4U)) 
                                                             | ((0x7e0U 
                                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                    >> 0x14U)) 
                                                                | (0x1eU 
                                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                      >> 7U)))))
                                                          : 0U)
                                                         : 0U))))
                                                     : 0U)
                                                    : 
                                                   ((0x20U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                     ? 
                                                    ((0x10U 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                      ? 
                                                     ((8U 
                                                       & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                        ? 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? 
                                                         (0xfffff000U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          : 0U)
                                                         : 0U)
                                                        : 0U))
                                                      : 
                                                     ((8U 
                                                       & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? 
                                                         ((0xfffff000U 
                                                           & ((- (IData)(
                                                                         (1U 
                                                                          & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                             >> 0x1fU)))) 
                                                              << 0xcU)) 
                                                          | ((0xfe0U 
                                                              & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                 >> 0x14U)) 
                                                             | (0x1fU 
                                                                & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                                   >> 7U))))
                                                          : 0U)
                                                         : 0U))))
                                                     : 
                                                    ((0x10U 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                      ? 
                                                     ((8U 
                                                       & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                        ? 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? 
                                                         (0xfffff000U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? vlTOPp->toplevel__DOT__cpu__DOT__imm_i
                                                          : 0U)
                                                         : 0U)))
                                                      : 
                                                     ((8U 
                                                       & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                       ? 0U
                                                       : 
                                                      ((4U 
                                                        & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                        ? 0U
                                                        : 
                                                       ((2U 
                                                         & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                         ? 
                                                        ((1U 
                                                          & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)
                                                          ? vlTOPp->toplevel__DOT__cpu__DOT__imm_i
                                                          : 0U)
                                                         : 0U))))));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__2(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__2\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0;
    SData/*14:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0;
    // Body
    __Vdlyvset__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0 = 0U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite) 
         & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemRead)))) {
        __Vdlyvval__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0 
            = vlTOPp->toplevel__DOT__cpu__DOT__MemWriteData;
        __Vdlyvset__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0 = 1U;
        __Vdlyvdim0__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0 
            = (0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                          >> 2U));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data[__Vdlyvdim0__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data__v0;
    }
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__5(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__5\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__cpu__DOT__MemWriteData = 
        ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3))
          ? ((0xffffff00U & ((- (IData)((1U & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData 
                                               >> 7U)))) 
                             << 8U)) | (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData))
          : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3))
              ? ((0xffff0000U & ((- (IData)((1U & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData 
                                                   >> 0xfU)))) 
                                 << 0x10U)) | (0xffffU 
                                               & vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData))
              : vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData));
    vlTOPp->WriteData = vlTOPp->toplevel__DOT__cpu__DOT__MemWriteData;
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut = 
        ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem)))
          ? 0U : vlTOPp->toplevel__DOT__cpu__DOT__ALUOut);
    vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemRead 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead));
    vlTOPp->MemWriteEnable = vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite;
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemWrite 
        = ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MemWrite));
    vlTOPp->MemAddr = vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut;
    vlTOPp->__Vtableidx2 = ((0x20U & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                      >> 0x1aU)) | 
                            (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Zero) 
                              << 4U) | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3) 
                                         << 1U) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Branch))));
    if (vlTOPp->__Vtablechg2[vlTOPp->__Vtableidx2]) {
        vlTOPp->toplevel__DOT__cpu__DOT__PCSrc = vlTOPp->__Vtable2_toplevel__DOT__cpu__DOT__PCSrc
            [vlTOPp->__Vtableidx2];
    }
    vlTOPp->toplevel__DOT__cpu__DOT__ALUInA = ((0U 
                                                == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bypassA))
                                                ? vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdA
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bypassA))
                                                    ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
                                                    : vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut));
    vlTOPp->toplevel__DOT__cpu__DOT__bypassOutB = (
                                                   (0U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bypassB))
                                                    ? vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdB
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bypassB))
                                                     ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
                                                     : vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut));
    if (VL_UNLIKELY(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemRead) 
                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite)))) {
        VL_WRITEF("\nMemory ERROR (time %0#): ren and wen both active!\n\n",
                  64,VL_TIME_UNITED_Q(1));
    }
    vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead = 
        ((~ ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex))) 
         & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MemRead));
    vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem = 0U;
    if (vlTOPp->toplevel__DOT__cpu__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__ALUInB = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUSrc)
                                                ? vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend
                                                : vlTOPp->toplevel__DOT__cpu__DOT__bypassOutB);
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr);
    vlTOPp->toplevel__DOT__cpu__DOT__RegDst = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__RegDst
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__MemRead = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__MemRead
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__MemWrite = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__MemWrite
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__MemToReg = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__MemToReg
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__ALUSrc = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__ALUSrc
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__RegWrite = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__RegWrite
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__Branch = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__Branch
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__Jump = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__Jump
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__ALUcntrl = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__ALUcntrl
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__ALUOut = (IData)(
                                                      (0x1ffffffffULL 
                                                       & ((0U 
                                                           == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                           + (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)))
                                                           : 
                                                          ((1U 
                                                            == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                            ? 
                                                           ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                            - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)))
                                                            : 
                                                           ((2U 
                                                             == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                             ? 
                                                            ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                             ^ (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)))
                                                             : 
                                                            ((3U 
                                                              == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                              ? 
                                                             ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                              | (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)))
                                                              : 
                                                             ((4U 
                                                               == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                               ? 
                                                              ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                               & (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)))
                                                               : 
                                                              ((5U 
                                                                == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                ? 
                                                               ((0x20U 
                                                                 >= vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                 ? 
                                                                ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                                 << vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                 : 0ULL)
                                                                : 
                                                               ((6U 
                                                                 == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                 ? 
                                                                ((0x20U 
                                                                  >= vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                  ? 
                                                                 ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                                  >> vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                  : 0ULL)
                                                                 : 
                                                                ((7U 
                                                                  == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                  ? 
                                                                 ((0x20U 
                                                                   >= vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                   ? 
                                                                  ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                                   >> vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                   : 0ULL)
                                                                  : 
                                                                 ((8U 
                                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                   ? 
                                                                  (VL_LTS_III(1,32,32, vlTOPp->toplevel__DOT__cpu__DOT__ALUInA, vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                    ? 1ULL
                                                                    : 0ULL)
                                                                   : 
                                                                  ((9U 
                                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                    ? 
                                                                   ((vlTOPp->toplevel__DOT__cpu__DOT__ALUInA 
                                                                     < vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)
                                                                     ? 1ULL
                                                                     : 0ULL)
                                                                    : 
                                                                   ((0xaU 
                                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                     ? 
                                                                    (0xffffffffULL 
                                                                     & (((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA)) 
                                                                         - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB))) 
                                                                        >> 1U))
                                                                     : 
                                                                    ((0xbU 
                                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                      ? (QData)((IData)(
                                                                                (0xfffff000U 
                                                                                & vlTOPp->toplevel__DOT__cpu__DOT__ALUInB)))
                                                                      : 
                                                                     ((0xcU 
                                                                       == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp))
                                                                       ? 
                                                                      ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_PC)) 
                                                                       + (QData)((IData)(
                                                                                (0xfffff000U 
                                                                                & vlTOPp->toplevel__DOT__cpu__DOT__ALUInB))))
                                                                       : 0ULL)))))))))))))));
    vlTOPp->toplevel__DOT__cpu__DOT__CPU_RegWrite = 
        (((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Jump) 
            & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite)) 
           & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite)) 
          & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite)) 
         | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite));
    vlTOPp->toplevel__DOT__cpu__DOT__write_ifid = 1U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__write_ifid = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__Jump) {
            if ((((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite) 
                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite)) 
                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite)) 
                  & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd) 
                     == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                  >> 7U)))) | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr) 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                    >> 7U))) 
                                               & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                      >> 7U)))))) {
                vlTOPp->toplevel__DOT__cpu__DOT__write_ifid = 0U;
            }
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid = 0U;
    if ((1U & (~ ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead) 
                  & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
                      == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                   >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
                                                 == 
                                                 (0x1fU 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                     >> 0x14U)))))))) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__Jump) {
            if ((1U & (~ (((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite) 
                             | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite)) 
                            | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite)) 
                           & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd) 
                              == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                           >> 7U)))) 
                          | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr) 
                              == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                           >> 7U))) 
                             & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 7U)))))))) {
                vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid = 1U;
            }
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex = 0U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex = 1U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__Jump) {
            if ((((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite) 
                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite)) 
                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite)) 
                  & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd) 
                     == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                  >> 7U)))) | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr) 
                                                == 
                                                (0x1fU 
                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                    >> 7U))) 
                                               & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                      >> 7U)))))) {
                vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex = 1U;
            }
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__write_pc = 1U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__write_pc = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__Jump) {
            vlTOPp->toplevel__DOT__cpu__DOT__write_pc 
                = (1U & (~ (((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite) 
                               | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite)) 
                              | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite)) 
                             & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd) 
                                == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 7U)))) 
                            | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr) 
                                == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 7U))) 
                               & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                  == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                               >> 7U)))))));
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__write_pc = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__PC_new = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc)
                                                ? vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut
                                                : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Jump)
                                                    ? 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr))
                                                     ? 
                                                    (vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                                     + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)
                                                     : 
                                                    ((0x1fU 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                         >> 0xfU)) 
                                                     + vlTOPp->toplevel__DOT__cpu__DOT__signExtend))
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlTOPp->toplevel__DOT__cpu__DOT__PC)));
}

void Vtoplevel::_eval(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_eval\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

VL_INLINE_OPT QData Vtoplevel::_change_request(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_change_request\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtoplevel::_change_request_1(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_change_request_1\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtoplevel::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
