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
    WData/*127:0*/ __Vtemp56[4];
    WData/*127:0*/ __Vtemp57[4];
    WData/*127:0*/ __Vtemp58[4];
    WData/*127:0*/ __Vtemp59[4];
    WData/*127:0*/ __Vtemp60[4];
    WData/*127:0*/ __Vtemp61[4];
    WData/*127:0*/ __Vtemp62[4];
    WData/*127:0*/ __Vtemp63[4];
    WData/*127:0*/ __Vtemp64[4];
    WData/*127:0*/ __Vtemp65[4];
    WData/*127:0*/ __Vtemp66[4];
    WData/*127:0*/ __Vtemp67[4];
    WData/*127:0*/ __Vtemp68[4];
    WData/*127:0*/ __Vtemp69[4];
    WData/*127:0*/ __Vtemp70[4];
    WData/*127:0*/ __Vtemp71[4];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->toplevel__DOT__dmem_ren));
            tracep->chgBit(oldp+1,(vlTOPp->toplevel__DOT__dmem_wen));
            tracep->chgBit(oldp+2,(vlTOPp->toplevel__DOT__dmem_read_ready));
            tracep->chgBit(oldp+3,(vlTOPp->toplevel__DOT__dmem_write_done));
            tracep->chgBit(oldp+4,(vlTOPp->toplevel__DOT__imem_ren));
            tracep->chgBit(oldp+5,(vlTOPp->toplevel__DOT__imem_read_ready));
            tracep->chgBit(oldp+6,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheStall));
            tracep->chgBit(oldp+7,(vlTOPp->toplevel__DOT__cpu__DOT__icacheStall));
            tracep->chgBit(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead));
            tracep->chgBit(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite));
            tracep->chgBit(oldp+10,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
            tracep->chgSData(oldp+11,((0x3ffU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),10);
            tracep->chgSData(oldp+12,((0x1fffU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),13);
            tracep->chgCData(oldp+13,((0xfU & ((0U 
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
            tracep->chgIData(oldp+14,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
            tracep->chgSData(oldp+15,((0x1ffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                                 >> 4U))),9);
            tracep->chgCData(oldp+16,((0x3fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                >> 4U))),6);
            tracep->chgBit(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen));
            tracep->chgBit(oldp+18,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen));
            tracep->chgIData(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr),32);
            tracep->chgIData(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC),32);
            tracep->chgIData(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC),32);
            tracep->chgIData(oldp+22,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC),32);
            tracep->chgIData(oldp+23,(((IData)(4U) 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),32);
            tracep->chgIData(oldp+24,((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)),32);
            tracep->chgIData(oldp+25,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
                                        : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                                            ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                               + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                                            : ((IData)(4U) 
                                               + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)))),32);
            tracep->chgBit(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
            tracep->chgBit(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
            tracep->chgIData(oldp+28,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC)),32);
            tracep->chgIData(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend),32);
            tracep->chgIData(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend),32);
            tracep->chgIData(oldp+31,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 0xfU)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0xfU))])),32);
            tracep->chgIData(oldp+32,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 0x14U)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0x14U))])),32);
            tracep->chgIData(oldp+33,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA),32);
            tracep->chgIData(oldp+34,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB),32);
            tracep->chgCData(oldp+35,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3),3);
            tracep->chgCData(oldp+36,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7),7);
            tracep->chgCData(oldp+37,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2),5);
            tracep->chgCData(oldp+38,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1),5);
            tracep->chgCData(oldp+39,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd),5);
            tracep->chgBit(oldp+40,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst));
            tracep->chgBit(oldp+41,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc));
            tracep->chgBit(oldp+42,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC));
            tracep->chgBit(oldp+43,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump));
            tracep->chgBit(oldp+44,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR));
            tracep->chgCData(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl),3);
            tracep->chgBit(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead));
            tracep->chgBit(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite));
            tracep->chgBit(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg));
            tracep->chgBit(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite));
            tracep->chgCData(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3),3);
            tracep->chgCData(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3),3);
            tracep->chgCData(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr),5);
            tracep->chgIData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut),32);
            tracep->chgIData(oldp+54,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut),32);
            tracep->chgBit(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero));
            tracep->chgBit(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR));
            tracep->chgIData(oldp+57,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData),32);
            tracep->chgBit(oldp+58,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
            tracep->chgBit(oldp+59,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
            tracep->chgIData(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut),32);
            tracep->chgCData(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr),5);
            tracep->chgIData(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut),32);
            tracep->chgBit(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg));
            tracep->chgBit(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite));
            tracep->chgIData(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA),32);
            tracep->chgIData(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB),32);
            tracep->chgIData(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val),32);
            tracep->chgIData(oldp+68,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                         : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend)),32);
            tracep->chgIData(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA),32);
            tracep->chgIData(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB),32);
            tracep->chgIData(oldp+71,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
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
            tracep->chgIData(oldp+72,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData),32);
            tracep->chgBit(oldp+73,((0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val)));
            tracep->chgBit(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
            tracep->chgBit(oldp+75,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
            tracep->chgBit(oldp+76,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
            tracep->chgBit(oldp+77,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
            tracep->chgBit(oldp+78,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
            tracep->chgBit(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc));
            tracep->chgBit(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
            tracep->chgBit(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
            tracep->chgBit(oldp+82,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
            tracep->chgBit(oldp+83,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
            tracep->chgBit(oldp+84,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
            tracep->chgBit(oldp+85,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch));
            tracep->chgBit(oldp+86,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid));
            tracep->chgBit(oldp+87,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex));
            tracep->chgBit(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem));
            tracep->chgBit(oldp+89,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc));
            tracep->chgCData(oldp+90,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),7);
            tracep->chgCData(oldp+91,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+92,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl),3);
            tracep->chgCData(oldp+93,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x19U))),7);
            tracep->chgCData(oldp+94,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+95,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+96,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 7U))),5);
            tracep->chgCData(oldp+97,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                                        ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                                        : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2))),5);
            tracep->chgCData(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp),4);
            tracep->chgCData(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA),2);
            tracep->chgCData(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB),2);
            tracep->chgIData(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i),32);
            tracep->chgIData(oldp+102,(((0xfffff000U 
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
            tracep->chgIData(oldp+103,(((0xfffff000U 
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
            tracep->chgIData(oldp+104,((0xfffff000U 
                                        & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),32);
            tracep->chgIData(oldp+105,(((0xfff00000U 
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
            tracep->chgBit(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow));
            tracep->chgBit(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache));
            tracep->chgIData(oldp+108,((0x1ffffffU 
                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                           >> 7U))),25);
            tracep->chgIData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i),32);
            tracep->chgIData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0]),32);
            tracep->chgIData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1]),32);
            tracep->chgIData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2]),32);
            tracep->chgIData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3]),32);
            tracep->chgIData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4]),32);
            tracep->chgIData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5]),32);
            tracep->chgIData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6]),32);
            tracep->chgIData(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7]),32);
            tracep->chgIData(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8]),32);
            tracep->chgIData(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9]),32);
            tracep->chgIData(oldp+120,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[10]),32);
            tracep->chgIData(oldp+121,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[11]),32);
            tracep->chgIData(oldp+122,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[12]),32);
            tracep->chgIData(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[13]),32);
            tracep->chgIData(oldp+124,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[14]),32);
            tracep->chgIData(oldp+125,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[15]),32);
            tracep->chgIData(oldp+126,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[16]),32);
            tracep->chgIData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[17]),32);
            tracep->chgIData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[18]),32);
            tracep->chgIData(oldp+129,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[19]),32);
            tracep->chgIData(oldp+130,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[20]),32);
            tracep->chgIData(oldp+131,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[21]),32);
            tracep->chgIData(oldp+132,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[22]),32);
            tracep->chgIData(oldp+133,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[23]),32);
            tracep->chgIData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[24]),32);
            tracep->chgIData(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[25]),32);
            tracep->chgIData(oldp+136,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[26]),32);
            tracep->chgIData(oldp+137,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[27]),32);
            tracep->chgIData(oldp+138,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[28]),32);
            tracep->chgIData(oldp+139,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[29]),32);
            tracep->chgIData(oldp+140,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[30]),32);
            tracep->chgIData(oldp+141,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[31]),32);
            tracep->chgQData(oldp+142,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub),33);
            tracep->chgCData(oldp+144,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),2);
            tracep->chgBit(oldp+145,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+146,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)),2);
            tracep->chgCData(oldp+147,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel),8);
            tracep->chgSData(oldp+148,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half),16);
            tracep->chgCData(oldp+149,((0xfU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),4);
            tracep->chgCData(oldp+150,(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state),2);
            tracep->chgCData(oldp+151,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0]),2);
            tracep->chgCData(oldp+152,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1]),2);
            tracep->chgCData(oldp+153,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2]),2);
            tracep->chgCData(oldp+154,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3]),2);
            tracep->chgCData(oldp+155,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0]),2);
            tracep->chgCData(oldp+156,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1]),2);
            tracep->chgCData(oldp+157,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2]),2);
            tracep->chgCData(oldp+158,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3]),2);
            tracep->chgCData(oldp+159,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [0U][0U]),7);
            tracep->chgCData(oldp+160,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [0U][1U]),7);
            tracep->chgCData(oldp+161,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [1U][0U]),7);
            tracep->chgCData(oldp+162,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [1U][1U]),7);
            tracep->chgCData(oldp+163,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [2U][0U]),7);
            tracep->chgCData(oldp+164,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [2U][1U]),7);
            tracep->chgCData(oldp+165,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [3U][0U]),7);
            tracep->chgCData(oldp+166,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [3U][1U]),7);
            __Vtemp56[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][0U];
            __Vtemp56[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][1U];
            __Vtemp56[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][2U];
            __Vtemp56[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][3U];
            tracep->chgWData(oldp+167,(__Vtemp56),128);
            __Vtemp57[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][0U];
            __Vtemp57[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][1U];
            __Vtemp57[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][2U];
            __Vtemp57[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][3U];
            tracep->chgWData(oldp+171,(__Vtemp57),128);
            __Vtemp58[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][0U];
            __Vtemp58[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][1U];
            __Vtemp58[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][2U];
            __Vtemp58[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][3U];
            tracep->chgWData(oldp+175,(__Vtemp58),128);
            __Vtemp59[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][0U];
            __Vtemp59[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][1U];
            __Vtemp59[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][2U];
            __Vtemp59[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][3U];
            tracep->chgWData(oldp+179,(__Vtemp59),128);
            __Vtemp60[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][0U];
            __Vtemp60[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][1U];
            __Vtemp60[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][2U];
            __Vtemp60[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][3U];
            tracep->chgWData(oldp+183,(__Vtemp60),128);
            __Vtemp61[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][0U];
            __Vtemp61[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][1U];
            __Vtemp61[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][2U];
            __Vtemp61[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][3U];
            tracep->chgWData(oldp+187,(__Vtemp61),128);
            __Vtemp62[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][0U];
            __Vtemp62[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][1U];
            __Vtemp62[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][2U];
            __Vtemp62[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][3U];
            tracep->chgWData(oldp+191,(__Vtemp62),128);
            __Vtemp63[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][0U];
            __Vtemp63[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][1U];
            __Vtemp63[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][2U];
            __Vtemp63[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][3U];
            tracep->chgWData(oldp+195,(__Vtemp63),128);
            tracep->chgCData(oldp+199,((3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                              >> 4U))),2);
            tracep->chgCData(oldp+200,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                                 >> 6U))),7);
            tracep->chgIData(oldp+201,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j),32);
            tracep->chgCData(oldp+202,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne),2);
            tracep->chgBit(oldp+203,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead) 
                                       & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite))) 
                                      | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite) 
                                         & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead))))));
            tracep->chgBit(oldp+204,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__replace));
            tracep->chgCData(oldp+205,((0xfU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),4);
            tracep->chgCData(oldp+206,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state),3);
            tracep->chgCData(oldp+207,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0]),2);
            tracep->chgCData(oldp+208,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1]),2);
            tracep->chgCData(oldp+209,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2]),2);
            tracep->chgCData(oldp+210,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3]),2);
            tracep->chgCData(oldp+211,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0]),2);
            tracep->chgCData(oldp+212,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1]),2);
            tracep->chgCData(oldp+213,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2]),2);
            tracep->chgCData(oldp+214,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3]),2);
            tracep->chgCData(oldp+215,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0]),2);
            tracep->chgCData(oldp+216,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1]),2);
            tracep->chgCData(oldp+217,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2]),2);
            tracep->chgCData(oldp+218,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3]),2);
            tracep->chgCData(oldp+219,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [0U][0U]),4);
            tracep->chgCData(oldp+220,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [0U][1U]),4);
            tracep->chgCData(oldp+221,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [1U][0U]),4);
            tracep->chgCData(oldp+222,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [1U][1U]),4);
            tracep->chgCData(oldp+223,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [2U][0U]),4);
            tracep->chgCData(oldp+224,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [2U][1U]),4);
            tracep->chgCData(oldp+225,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [3U][0U]),4);
            tracep->chgCData(oldp+226,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [3U][1U]),4);
            __Vtemp64[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][0U];
            __Vtemp64[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][1U];
            __Vtemp64[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][2U];
            __Vtemp64[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][3U];
            tracep->chgWData(oldp+227,(__Vtemp64),128);
            __Vtemp65[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][0U];
            __Vtemp65[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][1U];
            __Vtemp65[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][2U];
            __Vtemp65[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][3U];
            tracep->chgWData(oldp+231,(__Vtemp65),128);
            __Vtemp66[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][0U];
            __Vtemp66[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][1U];
            __Vtemp66[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][2U];
            __Vtemp66[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][3U];
            tracep->chgWData(oldp+235,(__Vtemp66),128);
            __Vtemp67[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][0U];
            __Vtemp67[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][1U];
            __Vtemp67[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][2U];
            __Vtemp67[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][3U];
            tracep->chgWData(oldp+239,(__Vtemp67),128);
            __Vtemp68[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][0U];
            __Vtemp68[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][1U];
            __Vtemp68[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][2U];
            __Vtemp68[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][3U];
            tracep->chgWData(oldp+243,(__Vtemp68),128);
            __Vtemp69[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][0U];
            __Vtemp69[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][1U];
            __Vtemp69[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][2U];
            __Vtemp69[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][3U];
            tracep->chgWData(oldp+247,(__Vtemp69),128);
            __Vtemp70[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][0U];
            __Vtemp70[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][1U];
            __Vtemp70[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][2U];
            __Vtemp70[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][3U];
            tracep->chgWData(oldp+251,(__Vtemp70),128);
            __Vtemp71[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][0U];
            __Vtemp71[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][1U];
            __Vtemp71[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][2U];
            __Vtemp71[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][3U];
            tracep->chgWData(oldp+255,(__Vtemp71),128);
            tracep->chgCData(oldp+259,((3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                              >> 4U))),2);
            tracep->chgCData(oldp+260,((0xfU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                >> 6U))),4);
            tracep->chgIData(oldp+261,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j),32);
            tracep->chgCData(oldp+262,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne),2);
            tracep->chgIData(oldp+263,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0]),32);
            tracep->chgIData(oldp+264,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1]),32);
            tracep->chgIData(oldp+265,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2]),32);
            tracep->chgIData(oldp+266,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3]),32);
            tracep->chgBit(oldp+267,(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgWData(oldp+268,(vlTOPp->toplevel__DOT__imem_dout),128);
            tracep->chgBit(oldp+272,((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))));
            tracep->chgCData(oldp+273,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter),4);
            tracep->chgIData(oldp+274,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgWData(oldp+275,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout),128);
            tracep->chgBit(oldp+279,(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen));
            tracep->chgBit(oldp+280,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))));
            tracep->chgWData(oldp+281,(vlTOPp->toplevel__DOT__cpu__DOT__icacheDin),128);
            tracep->chgWData(oldp+285,(vlTOPp->toplevel__DOT__cpu__DOT__icacheDout),128);
            tracep->chgBit(oldp+289,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen));
            tracep->chgBit(oldp+290,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen));
            tracep->chgBit(oldp+291,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))));
            tracep->chgBit(oldp+292,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit));
            tracep->chgWData(oldp+293,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin),128);
            tracep->chgSData(oldp+297,(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess),16);
            tracep->chgCData(oldp+298,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg),2);
            tracep->chgCData(oldp+299,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict),2);
            tracep->chgCData(oldp+300,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask),2);
            tracep->chgCData(oldp+301,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg),2);
            tracep->chgCData(oldp+302,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict),2);
            tracep->chgCData(oldp+303,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask),2);
            tracep->chgBit(oldp+304,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset));
            tracep->chgBit(oldp+305,(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgWData(oldp+306,(vlTOPp->toplevel__DOT__dmem_dout),128);
            tracep->chgBit(oldp+310,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready));
            tracep->chgBit(oldp+311,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
        }
        tracep->chgBit(oldp+312,(vlTOPp->clock));
        tracep->chgBit(oldp+313,(vlTOPp->reset));
        tracep->chgIData(oldp+314,(((IData)(vlTOPp->reset)
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[
                                    (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                           >> 2U))]
                                     : 0U)),32);
        tracep->chgIData(oldp+315,(((IData)(vlTOPp->reset)
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[
                                    (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                           >> 2U))]
                                     : 0U)),32);
        tracep->chgCData(oldp+316,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                     ? (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid) 
                                         & (~ (IData)(
                                                      (0U 
                                                       != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)))))
                                         ? 1U : 0U)
                                     : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                         ? ((IData)(vlTOPp->toplevel__DOT__imem_read_ready)
                                             ? 2U : 1U)
                                         : 0U))),2);
        tracep->chgIData(oldp+317,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i),32);
        tracep->chgCData(oldp+318,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                     ? 0U : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                                  ? 
                                                 (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite) 
                                                   & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead)))
                                                   ? 4U
                                                   : 0U)
                                                  : 
                                                 ((IData)(vlTOPp->toplevel__DOT__dmem_read_ready)
                                                   ? 3U
                                                   : 2U))
                                              : ((1U 
                                                  & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                                  ? 
                                                 ((IData)(vlTOPp->toplevel__DOT__dmem_write_done)
                                                   ? 2U
                                                   : 1U)
                                                  : 
                                                 (((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead) 
                                                     & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite))) 
                                                    | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite) 
                                                       & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead)))) 
                                                   & (~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)))))
                                                   ? 
                                                  ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit)
                                                    ? 1U
                                                    : 2U)
                                                   : 0U))))),3);
        tracep->chgIData(oldp+319,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i),32);
        tracep->chgBit(oldp+320,((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter))));
        tracep->chgCData(oldp+321,(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter),4);
        tracep->chgIData(oldp+322,(vlTOPp->toplevel__DOT__Data_Mem__DOT__i),32);
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
    }
}
