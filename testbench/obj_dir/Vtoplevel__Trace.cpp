// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoplevel__Syms.h"


void Vtoplevel::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtoplevel::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Variables
    WData/*127:0*/ __Vtemp31[4];
    WData/*127:0*/ __Vtemp32[4];
    WData/*127:0*/ __Vtemp33[4];
    WData/*127:0*/ __Vtemp34[4];
    WData/*127:0*/ __Vtemp35[4];
    WData/*127:0*/ __Vtemp36[4];
    WData/*127:0*/ __Vtemp37[4];
    WData/*127:0*/ __Vtemp38[4];
    WData/*127:0*/ __Vtemp46[4];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgBit(oldp+0,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+1,(vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess),8);
            tracep->chgQData(oldp+2,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDin),64);
            tracep->chgBit(oldp+4,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))));
            tracep->chgBit(oldp+5,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit));
            tracep->chgQData(oldp+6,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout),64);
            tracep->chgBit(oldp+8,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))));
            tracep->chgWData(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout),128);
            tracep->chgCData(oldp+13,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg),2);
            tracep->chgCData(oldp+14,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict),2);
            tracep->chgCData(oldp+15,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask),2);
            tracep->chgIData(oldp+16,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__m),32);
            tracep->chgCData(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg),2);
            tracep->chgCData(oldp+18,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict),2);
            tracep->chgCData(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask),2);
            tracep->chgBit(oldp+20,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset));
            tracep->chgBit(oldp+21,(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+22,(vlTOPp->toplevel__DOT__dmem_ready));
            tracep->chgBit(oldp+23,(vlTOPp->toplevel__DOT__dmem_done));
            tracep->chgBit(oldp+24,(vlTOPp->toplevel__DOT__imem_ready));
            tracep->chgBit(oldp+25,(vlTOPp->toplevel__DOT__cpu__DOT__stall));
            tracep->chgBit(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__cacheMemWen));
            tracep->chgBit(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__memRen));
            tracep->chgBit(oldp+28,(vlTOPp->toplevel__DOT__cpu__DOT__memWen));
            tracep->chgIData(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr),32);
            tracep->chgIData(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC),32);
            tracep->chgIData(oldp+31,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC),32);
            tracep->chgIData(oldp+32,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC),32);
            tracep->chgIData(oldp+33,(((IData)(4U) 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),32);
            tracep->chgIData(oldp+34,((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)),32);
            tracep->chgIData(oldp+35,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
                                        : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                                            ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                               + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                                            : ((IData)(4U) 
                                               + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)))),32);
            tracep->chgBit(oldp+36,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
            tracep->chgBit(oldp+37,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
            tracep->chgIData(oldp+38,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC)),32);
            tracep->chgIData(oldp+39,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend),32);
            tracep->chgIData(oldp+40,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend),32);
            tracep->chgIData(oldp+41,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 0xfU)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0xfU))])),32);
            tracep->chgIData(oldp+42,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 0x14U)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0x14U))])),32);
            tracep->chgIData(oldp+43,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA),32);
            tracep->chgIData(oldp+44,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB),32);
            tracep->chgCData(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3),3);
            tracep->chgCData(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7),7);
            tracep->chgCData(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2),5);
            tracep->chgCData(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1),5);
            tracep->chgCData(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd),5);
            tracep->chgBit(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst));
            tracep->chgBit(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc));
            tracep->chgBit(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC));
            tracep->chgBit(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump));
            tracep->chgBit(oldp+54,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR));
            tracep->chgCData(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl),3);
            tracep->chgBit(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead));
            tracep->chgBit(oldp+57,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite));
            tracep->chgBit(oldp+58,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg));
            tracep->chgBit(oldp+59,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite));
            tracep->chgCData(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3),3);
            tracep->chgCData(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3),3);
            tracep->chgCData(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr),5);
            tracep->chgIData(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut),32);
            tracep->chgIData(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut),32);
            tracep->chgBit(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero));
            tracep->chgBit(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR));
            tracep->chgCData(oldp+67,((0xfU & ((0U 
                                                == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                ? ((IData)(1U) 
                                                   << 
                                                   (3U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                : (
                                                   (1U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                    ? 
                                                   ((2U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                     ? 0xcU
                                                     : 3U)
                                                    : 0xfU)))),4);
            tracep->chgIData(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData),32);
            tracep->chgIData(oldp+69,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                        ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                            ? ((1U 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                   << 0x18U)
                                                : (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                   << 0x10U))
                                            : ((1U 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                   << 8U)
                                                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))
                                        : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                            ? ((0U 
                                                == 
                                                (3U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                                : (
                                                   (2U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                    ? 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 0x10U)
                                                    : 0U))
                                            : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))),32);
            tracep->chgBit(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead));
            tracep->chgBit(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite));
            tracep->chgBit(oldp+72,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
            tracep->chgBit(oldp+73,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
            tracep->chgIData(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut),32);
            tracep->chgCData(oldp+75,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr),5);
            tracep->chgIData(oldp+76,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut),32);
            tracep->chgBit(oldp+77,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg));
            tracep->chgBit(oldp+78,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite));
            tracep->chgIData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA),32);
            tracep->chgIData(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB),32);
            tracep->chgIData(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val),32);
            tracep->chgIData(oldp+82,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                         : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend)),32);
            tracep->chgIData(oldp+83,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA),32);
            tracep->chgIData(oldp+84,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB),32);
            tracep->chgIData(oldp+85,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                        ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
                                            : ((1U 
                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                                ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half)
                                                : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))
                                        : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
                                            : ((1U 
                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                                ? (
                                                   (0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half) 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half))
                                                : (
                                                   (0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel) 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))))),32);
            tracep->chgIData(oldp+86,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData),32);
            tracep->chgBit(oldp+87,((0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val)));
            tracep->chgBit(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
            tracep->chgBit(oldp+89,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
            tracep->chgBit(oldp+90,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
            tracep->chgBit(oldp+91,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
            tracep->chgBit(oldp+92,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
            tracep->chgBit(oldp+93,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc));
            tracep->chgBit(oldp+94,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
            tracep->chgBit(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
            tracep->chgBit(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
            tracep->chgBit(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
            tracep->chgBit(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
            tracep->chgBit(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch));
            tracep->chgBit(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid));
            tracep->chgBit(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex));
            tracep->chgBit(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem));
            tracep->chgBit(oldp+103,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
            tracep->chgBit(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc));
            tracep->chgCData(oldp+105,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),7);
            tracep->chgCData(oldp+106,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                              >> 0xcU))),3);
            tracep->chgCData(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl),3);
            tracep->chgCData(oldp+108,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0x19U))),7);
            tracep->chgCData(oldp+109,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0xfU))),5);
            tracep->chgCData(oldp+110,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0x14U))),5);
            tracep->chgCData(oldp+111,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 7U))),5);
            tracep->chgCData(oldp+112,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                                         ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                                         : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2))),5);
            tracep->chgCData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp),4);
            tracep->chgCData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA),2);
            tracep->chgCData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB),2);
            tracep->chgIData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i),32);
            tracep->chgIData(oldp+117,(((0xfffff000U 
                                         & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                           >> 0x1fU)))) 
                                            << 0xcU)) 
                                        | ((0xfe0U 
                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                               >> 0x14U)) 
                                           | (0x1fU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 7U))))),32);
            tracep->chgIData(oldp+118,(((0xfffff000U 
                                         & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                           >> 0x1fU)))) 
                                            << 0xcU)) 
                                        | ((0x800U 
                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                               << 4U)) 
                                           | ((0x7e0U 
                                               & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0x14U)) 
                                              | (0x1eU 
                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                    >> 7U)))))),32);
            tracep->chgIData(oldp+119,((0xfffff000U 
                                        & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),32);
            tracep->chgIData(oldp+120,(((0xfff00000U 
                                         & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                           >> 0x1fU)))) 
                                            << 0x14U)) 
                                        | ((0xff000U 
                                            & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr) 
                                           | ((0x800U 
                                               & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 9U)) 
                                              | ((0x7e0U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                     >> 0x14U)) 
                                                 | (0x1eU 
                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                       >> 0x14U))))))),32);
            tracep->chgBit(oldp+121,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow));
            tracep->chgIData(oldp+122,((0x1ffffffU 
                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                           >> 7U))),25);
            tracep->chgIData(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i),32);
            tracep->chgIData(oldp+124,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0]),32);
            tracep->chgIData(oldp+125,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1]),32);
            tracep->chgIData(oldp+126,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2]),32);
            tracep->chgIData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3]),32);
            tracep->chgIData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4]),32);
            tracep->chgIData(oldp+129,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5]),32);
            tracep->chgIData(oldp+130,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6]),32);
            tracep->chgIData(oldp+131,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7]),32);
            tracep->chgIData(oldp+132,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8]),32);
            tracep->chgIData(oldp+133,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9]),32);
            tracep->chgIData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[10]),32);
            tracep->chgIData(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[11]),32);
            tracep->chgIData(oldp+136,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[12]),32);
            tracep->chgIData(oldp+137,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[13]),32);
            tracep->chgIData(oldp+138,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[14]),32);
            tracep->chgIData(oldp+139,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[15]),32);
            tracep->chgIData(oldp+140,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[16]),32);
            tracep->chgIData(oldp+141,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[17]),32);
            tracep->chgIData(oldp+142,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[18]),32);
            tracep->chgIData(oldp+143,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[19]),32);
            tracep->chgIData(oldp+144,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[20]),32);
            tracep->chgIData(oldp+145,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[21]),32);
            tracep->chgIData(oldp+146,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[22]),32);
            tracep->chgIData(oldp+147,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[23]),32);
            tracep->chgIData(oldp+148,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[24]),32);
            tracep->chgIData(oldp+149,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[25]),32);
            tracep->chgIData(oldp+150,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[26]),32);
            tracep->chgIData(oldp+151,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[27]),32);
            tracep->chgIData(oldp+152,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[28]),32);
            tracep->chgIData(oldp+153,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[29]),32);
            tracep->chgIData(oldp+154,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[30]),32);
            tracep->chgIData(oldp+155,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[31]),32);
            tracep->chgQData(oldp+156,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub),33);
            tracep->chgCData(oldp+158,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),2);
            tracep->chgBit(oldp+159,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+160,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)),2);
            tracep->chgCData(oldp+161,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel),8);
            tracep->chgSData(oldp+162,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half),16);
            tracep->chgCData(oldp+163,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0]),2);
            tracep->chgCData(oldp+164,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1]),2);
            tracep->chgCData(oldp+165,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2]),2);
            tracep->chgCData(oldp+166,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3]),2);
            tracep->chgCData(oldp+167,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0]),2);
            tracep->chgCData(oldp+168,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1]),2);
            tracep->chgCData(oldp+169,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2]),2);
            tracep->chgCData(oldp+170,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3]),2);
            tracep->chgCData(oldp+171,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [0U][0U]),6);
            tracep->chgCData(oldp+172,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [0U][1U]),6);
            tracep->chgCData(oldp+173,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [1U][0U]),6);
            tracep->chgCData(oldp+174,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [1U][1U]),6);
            tracep->chgCData(oldp+175,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [2U][0U]),6);
            tracep->chgCData(oldp+176,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [2U][1U]),6);
            tracep->chgCData(oldp+177,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [3U][0U]),6);
            tracep->chgCData(oldp+178,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [3U][1U]),6);
            __Vtemp31[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][0U];
            __Vtemp31[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][1U];
            __Vtemp31[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][2U];
            __Vtemp31[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][3U];
            tracep->chgWData(oldp+179,(__Vtemp31),128);
            __Vtemp32[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][0U];
            __Vtemp32[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][1U];
            __Vtemp32[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][2U];
            __Vtemp32[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][3U];
            tracep->chgWData(oldp+183,(__Vtemp32),128);
            __Vtemp33[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][0U];
            __Vtemp33[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][1U];
            __Vtemp33[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][2U];
            __Vtemp33[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][3U];
            tracep->chgWData(oldp+187,(__Vtemp33),128);
            __Vtemp34[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][0U];
            __Vtemp34[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][1U];
            __Vtemp34[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][2U];
            __Vtemp34[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][3U];
            tracep->chgWData(oldp+191,(__Vtemp34),128);
            __Vtemp35[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][0U];
            __Vtemp35[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][1U];
            __Vtemp35[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][2U];
            __Vtemp35[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][3U];
            tracep->chgWData(oldp+195,(__Vtemp35),128);
            __Vtemp36[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][0U];
            __Vtemp36[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][1U];
            __Vtemp36[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][2U];
            __Vtemp36[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][3U];
            tracep->chgWData(oldp+199,(__Vtemp36),128);
            __Vtemp37[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][0U];
            __Vtemp37[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][1U];
            __Vtemp37[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][2U];
            __Vtemp37[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][3U];
            tracep->chgWData(oldp+203,(__Vtemp37),128);
            __Vtemp38[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][0U];
            __Vtemp38[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][1U];
            __Vtemp38[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][2U];
            __Vtemp38[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][3U];
            tracep->chgWData(oldp+207,(__Vtemp38),128);
            tracep->chgIData(oldp+211,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j),32);
            tracep->chgCData(oldp+212,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne),2);
            tracep->chgCData(oldp+213,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0]),2);
            tracep->chgCData(oldp+214,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1]),2);
            tracep->chgCData(oldp+215,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2]),2);
            tracep->chgCData(oldp+216,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3]),2);
            tracep->chgCData(oldp+217,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0]),2);
            tracep->chgCData(oldp+218,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1]),2);
            tracep->chgCData(oldp+219,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2]),2);
            tracep->chgCData(oldp+220,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3]),2);
            tracep->chgCData(oldp+221,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0]),2);
            tracep->chgCData(oldp+222,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1]),2);
            tracep->chgCData(oldp+223,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2]),2);
            tracep->chgCData(oldp+224,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3]),2);
            tracep->chgCData(oldp+225,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [0U][0U]),2);
            tracep->chgCData(oldp+226,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [0U][1U]),2);
            tracep->chgCData(oldp+227,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [1U][0U]),2);
            tracep->chgCData(oldp+228,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [1U][1U]),2);
            tracep->chgCData(oldp+229,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [2U][0U]),2);
            tracep->chgCData(oldp+230,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [2U][1U]),2);
            tracep->chgCData(oldp+231,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [3U][0U]),2);
            tracep->chgCData(oldp+232,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [3U][1U]),2);
            tracep->chgQData(oldp+233,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [0U][0U]),64);
            tracep->chgQData(oldp+235,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [0U][1U]),64);
            tracep->chgQData(oldp+237,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [1U][0U]),64);
            tracep->chgQData(oldp+239,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [1U][1U]),64);
            tracep->chgQData(oldp+241,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [2U][0U]),64);
            tracep->chgQData(oldp+243,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [2U][1U]),64);
            tracep->chgQData(oldp+245,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [3U][0U]),64);
            tracep->chgQData(oldp+247,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                       [3U][1U]),64);
            tracep->chgIData(oldp+249,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__l),32);
            tracep->chgCData(oldp+250,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne),2);
            tracep->chgCData(oldp+251,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state),3);
            tracep->chgCData(oldp+252,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state),3);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgQData(oldp+253,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[0]),64);
            tracep->chgQData(oldp+255,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[1]),64);
            tracep->chgQData(oldp+257,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[2]),64);
            tracep->chgQData(oldp+259,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[3]),64);
            tracep->chgQData(oldp+261,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[4]),64);
            tracep->chgQData(oldp+263,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[5]),64);
            tracep->chgQData(oldp+265,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[6]),64);
            tracep->chgQData(oldp+267,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[7]),64);
            tracep->chgQData(oldp+269,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[8]),64);
            tracep->chgQData(oldp+271,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[9]),64);
            tracep->chgQData(oldp+273,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[10]),64);
            tracep->chgQData(oldp+275,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[11]),64);
            tracep->chgQData(oldp+277,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[12]),64);
            tracep->chgQData(oldp+279,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[13]),64);
            tracep->chgQData(oldp+281,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[14]),64);
            tracep->chgQData(oldp+283,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[15]),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgQData(oldp+285,((((QData)((IData)(
                                                         ((0xfU 
                                                           == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))
                                                           ? 
                                                          vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                                                          [
                                                          (0xffU 
                                                           & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][1U]
                                                           : 0U))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          ((0xfU 
                                                            == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))
                                                            ? 
                                                           vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                                                           [
                                                           (0xffU 
                                                            & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][0U]
                                                            : 0U))))),64);
            if ((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))) {
                __Vtemp46[0U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                    [(0xffU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][0U];
                __Vtemp46[1U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                    [(0xffU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][1U];
                __Vtemp46[2U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                    [(0xffU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][2U];
                __Vtemp46[3U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                    [(0xffU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][3U];
            } else {
                __Vtemp46[0U] = 0U;
                __Vtemp46[1U] = 0U;
                __Vtemp46[2U] = 0U;
                __Vtemp46[3U] = 0U;
            }
            tracep->chgWData(oldp+287,(__Vtemp46),128);
            tracep->chgBit(oldp+291,((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))));
            tracep->chgCData(oldp+292,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter),4);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgBit(oldp+293,((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter))));
            tracep->chgCData(oldp+294,(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter),4);
            tracep->chgBit(oldp+295,((((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                       & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                      & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)))));
            tracep->chgBit(oldp+296,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
        }
        tracep->chgBit(oldp+297,(vlTOPp->clock));
        tracep->chgBit(oldp+298,(vlTOPp->reset));
        tracep->chgQData(oldp+299,(((((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                      & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                     & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)))
                                     ? vlTOPp->toplevel__DOT__Data_Mem__DOT__data
                                    [(0xfU & (IData)((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))))]
                                     : 0ULL)),64);
        tracep->chgIData(oldp+301,((IData)(((((0xfU 
                                               == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                              & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                             & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)))
                                             ? vlTOPp->toplevel__DOT__Data_Mem__DOT__data
                                            [(0xfU 
                                              & (IData)((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))))]
                                             : 0ULL))),32);
        tracep->chgIData(oldp+302,(((IData)(vlTOPp->reset)
                                     ? (IData)((vlTOPp->toplevel__DOT__cpu__DOT__cacheDout 
                                                >> 
                                                (8U 
                                                 & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                                    << 1U))))
                                     : 0U)),32);
        tracep->chgBit(oldp+303,((((IData)(vlTOPp->reset) 
                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren)) 
                                  & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen)))));
        tracep->chgBit(oldp+304,((((IData)(vlTOPp->reset) 
                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen)) 
                                  & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren)))));
        tracep->chgIData(oldp+305,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i),32);
        tracep->chgIData(oldp+306,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i),32);
        tracep->chgIData(oldp+307,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j),32);
        tracep->chgQData(oldp+308,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din),64);
        tracep->chgBit(oldp+310,(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag));
    }
}

void Vtoplevel::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
        vlTOPp->__Vm_traceActivity[4U] = 0U;
        vlTOPp->__Vm_traceActivity[5U] = 0U;
    }
}
