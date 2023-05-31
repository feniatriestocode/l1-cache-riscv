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
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->toplevel__DOT__cpu__DOT__overflow));
            tracep->chgIData(oldp+1,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr),32);
            tracep->chgIData(oldp+2,(vlTOPp->toplevel__DOT__cpu__DOT__PC),32);
            tracep->chgIData(oldp+3,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC),32);
            tracep->chgIData(oldp+4,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC),32);
            tracep->chgIData(oldp+5,(((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__PC)),32);
            tracep->chgIData(oldp+6,((vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                      + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)),32);
            tracep->chgIData(oldp+7,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc)
                                       ? vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut
                                       : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Jump)
                                           ? (vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                              + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)
                                           : ((IData)(4U) 
                                              + vlTOPp->toplevel__DOT__cpu__DOT__PC)))),32);
            tracep->chgBit(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__inA_is_PC));
            tracep->chgBit(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__branch_taken));
            tracep->chgIData(oldp+10,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_JumpJALR)
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__bypassOutA
                                        : vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC)),32);
            tracep->chgIData(oldp+11,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend),32);
            tracep->chgIData(oldp+12,(vlTOPp->toplevel__DOT__cpu__DOT__signExtend),32);
            tracep->chgIData(oldp+13,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                   >> 0xfU)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                  >> 0xfU))])),32);
            tracep->chgIData(oldp+14,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                   >> 0x14U)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                  >> 0x14U))])),32);
            tracep->chgIData(oldp+15,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdA),32);
            tracep->chgIData(oldp+16,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdB),32);
            tracep->chgCData(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3),3);
            tracep->chgCData(oldp+18,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7),7);
            tracep->chgCData(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2),5);
            tracep->chgCData(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1),5);
            tracep->chgCData(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd),5);
            tracep->chgBit(oldp+22,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst));
            tracep->chgBit(oldp+23,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUSrc));
            tracep->chgBit(oldp+24,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_inA_is_PC));
            tracep->chgBit(oldp+25,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Jump));
            tracep->chgBit(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_JumpJALR));
            tracep->chgCData(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl),3);
            tracep->chgBit(oldp+28,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead));
            tracep->chgBit(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemWrite));
            tracep->chgBit(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemToReg));
            tracep->chgBit(oldp+31,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite));
            tracep->chgCData(oldp+32,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3),3);
            tracep->chgCData(oldp+33,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3),3);
            tracep->chgCData(oldp+34,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr),5);
            tracep->chgIData(oldp+35,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut),32);
            tracep->chgIData(oldp+36,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut),32);
            tracep->chgBit(oldp+37,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Zero));
            tracep->chgBit(oldp+38,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_JumpJALR));
            tracep->chgCData(oldp+39,(vlTOPp->toplevel__DOT__cpu__DOT__byte_select_vector),4);
            tracep->chgIData(oldp+40,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData),32);
            tracep->chgIData(oldp+41,(vlTOPp->toplevel__DOT__cpu__DOT__MemWriteData),32);
            tracep->chgBit(oldp+42,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemRead));
            tracep->chgBit(oldp+43,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite));
            tracep->chgBit(oldp+44,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite));
            tracep->chgBit(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemToReg));
            tracep->chgIData(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut),32);
            tracep->chgCData(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr),5);
            tracep->chgIData(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut),32);
            tracep->chgBit(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_MemToReg));
            tracep->chgBit(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite));
            tracep->chgIData(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA),32);
            tracep->chgIData(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB),32);
            tracep->chgIData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_alu__DOT__out_val),32);
            tracep->chgIData(oldp+54,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_JumpJALR)
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__bypassOutA
                                         : vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC) 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend)),32);
            tracep->chgIData(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__bypassOutA),32);
            tracep->chgIData(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__bypassOutB),32);
            tracep->chgIData(oldp+57,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                        ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                            ? vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut
                                            : ((1U 
                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half)
                                                : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel)))
                                        : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                            ? vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut
                                            : ((1U 
                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                ? (
                                                   (0xffff0000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half) 
                                                                      >> 0xfU)))) 
                                                       << 0x10U)) 
                                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half))
                                                : (
                                                   (0xffffff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel) 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel)))))),32);
            tracep->chgIData(oldp+58,(vlTOPp->toplevel__DOT__cpu__DOT__wRegData),32);
            tracep->chgBit(oldp+59,((0U == vlTOPp->toplevel__DOT__cpu__DOT__cpu_alu__DOT__out_val)));
            tracep->chgBit(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__RegDst));
            tracep->chgBit(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__MemRead));
            tracep->chgBit(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__MemWrite));
            tracep->chgBit(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__MemToReg));
            tracep->chgBit(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__ALUSrc));
            tracep->chgBit(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc));
            tracep->chgBit(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__RegWrite));
            tracep->chgBit(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__Jump));
            tracep->chgBit(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__JumpJALR));
            tracep->chgBit(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__Branch));
            tracep->chgBit(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Branch));
            tracep->chgBit(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Branch));
            tracep->chgBit(oldp+72,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid));
            tracep->chgBit(oldp+73,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex));
            tracep->chgBit(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem));
            tracep->chgBit(oldp+75,(vlTOPp->toplevel__DOT__cpu__DOT__write_ifid));
            tracep->chgBit(oldp+76,(vlTOPp->toplevel__DOT__cpu__DOT__write_pc));
            tracep->chgCData(oldp+77,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)),7);
            tracep->chgCData(oldp+78,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__ALUcntrl),3);
            tracep->chgCData(oldp+80,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 0x19U))),7);
            tracep->chgCData(oldp+81,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+82,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+83,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 7U))),5);
            tracep->chgCData(oldp+84,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst)
                                        ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd)
                                        : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2))),5);
            tracep->chgCData(oldp+85,(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp),4);
            tracep->chgCData(oldp+86,(vlTOPp->toplevel__DOT__cpu__DOT__bypassA),2);
            tracep->chgCData(oldp+87,(vlTOPp->toplevel__DOT__cpu__DOT__bypassB),2);
            tracep->chgIData(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__imm_i),32);
            tracep->chgIData(oldp+89,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 7U))))),32);
            tracep->chgIData(oldp+90,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0x800U & 
                                           (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                            << 4U)) 
                                          | ((0x7e0U 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                 >> 0x14U)) 
                                             | (0x1eU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                   >> 7U)))))),32);
            tracep->chgIData(oldp+91,((0xfffff000U 
                                       & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)),32);
            tracep->chgIData(oldp+92,(((0xfff00000U 
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
                                                      >> 0x14U))))))),32);
            tracep->chgSData(oldp+93,((0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                                                  >> 2U))),14);
            tracep->chgIData(oldp+94,((0x1ffffffU & 
                                       (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                        >> 7U))),25);
            tracep->chgIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__i),32);
            tracep->chgIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0]),32);
            tracep->chgIData(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[1]),32);
            tracep->chgIData(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[2]),32);
            tracep->chgIData(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[3]),32);
            tracep->chgIData(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[4]),32);
            tracep->chgIData(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[5]),32);
            tracep->chgIData(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[6]),32);
            tracep->chgIData(oldp+103,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[7]),32);
            tracep->chgIData(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[8]),32);
            tracep->chgIData(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[9]),32);
            tracep->chgIData(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[10]),32);
            tracep->chgIData(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[11]),32);
            tracep->chgIData(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[12]),32);
            tracep->chgIData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[13]),32);
            tracep->chgIData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[14]),32);
            tracep->chgIData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[15]),32);
            tracep->chgIData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[16]),32);
            tracep->chgIData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[17]),32);
            tracep->chgIData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[18]),32);
            tracep->chgIData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[19]),32);
            tracep->chgIData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[20]),32);
            tracep->chgIData(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[21]),32);
            tracep->chgIData(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[22]),32);
            tracep->chgIData(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[23]),32);
            tracep->chgIData(oldp+120,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[24]),32);
            tracep->chgIData(oldp+121,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[25]),32);
            tracep->chgIData(oldp+122,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[26]),32);
            tracep->chgIData(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[27]),32);
            tracep->chgIData(oldp+124,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[28]),32);
            tracep->chgIData(oldp+125,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[29]),32);
            tracep->chgIData(oldp+126,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[30]),32);
            tracep->chgIData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[31]),32);
            tracep->chgQData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_alu__DOT__unsigned_sub),33);
            tracep->chgCData(oldp+130,((3U & vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut)),2);
            tracep->chgSData(oldp+131,((0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                                   >> 2U))),15);
            tracep->chgBit(oldp+132,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                            >> 0x1fU))));
            tracep->chgCData(oldp+133,((3U & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut)),2);
            tracep->chgCData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel),8);
            tracep->chgSData(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half),16);
        }
        tracep->chgBit(oldp+136,(vlTOPp->clock));
        tracep->chgBit(oldp+137,(vlTOPp->reset));
        tracep->chgBit(oldp+138,(vlTOPp->MemWriteEnable));
        tracep->chgIData(oldp+139,(vlTOPp->MemAddr),32);
        tracep->chgIData(oldp+140,(vlTOPp->WriteData),32);
        tracep->chgIData(oldp+141,((((IData)(vlTOPp->reset) 
                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__write_ifid))
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__cpu_IMem__DOT__data
                                    [(0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                                                 >> 2U))]
                                     : 0U)),32);
        tracep->chgIData(oldp+142,(((IData)(vlTOPp->reset)
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data
                                    [(0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                                 >> 2U))]
                                     : 0U)),32);
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
    }
}
