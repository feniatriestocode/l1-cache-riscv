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
    WData/*127:0*/ __Vtemp72[4];
    WData/*127:0*/ __Vtemp73[4];
    WData/*127:0*/ __Vtemp74[4];
    WData/*127:0*/ __Vtemp75[4];
    WData/*127:0*/ __Vtemp76[4];
    WData/*127:0*/ __Vtemp77[4];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->toplevel__DOT__dmem_ren));
            tracep->chgBit(oldp+1,(vlTOPp->toplevel__DOT__dmem_wen));
            tracep->chgBit(oldp+2,(vlTOPp->toplevel__DOT__dmem_read_ready));
            tracep->chgBit(oldp+3,(vlTOPp->toplevel__DOT__dmem_write_done));
            tracep->chgBit(oldp+4,(vlTOPp->toplevel__DOT__imem_ren));
            tracep->chgSData(oldp+5,(0U),9);
            tracep->chgBit(oldp+6,(vlTOPp->toplevel__DOT__imem_ready));
            tracep->chgBit(oldp+7,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen));
            tracep->chgBit(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen));
            tracep->chgBit(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheStall));
            tracep->chgBit(oldp+10,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheStall));
            tracep->chgBit(oldp+11,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)));
            tracep->chgSData(oldp+12,((0x1ffU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),9);
            tracep->chgIData(oldp+13,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr),32);
            tracep->chgIData(oldp+14,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC),32);
            tracep->chgIData(oldp+15,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC),32);
            tracep->chgIData(oldp+16,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC),32);
            tracep->chgIData(oldp+17,(((IData)(4U) 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),32);
            tracep->chgIData(oldp+18,((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                       + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)),32);
            tracep->chgBit(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
            tracep->chgIData(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend),32);
            tracep->chgIData(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend),32);
            tracep->chgIData(oldp+22,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 0xfU)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0xfU))])),32);
            tracep->chgIData(oldp+23,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                         & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                            == (0x1fU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 0x14U)))) 
                                        & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                        ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                       [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0x14U))])),32);
            tracep->chgIData(oldp+24,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA),32);
            tracep->chgIData(oldp+25,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB),32);
            tracep->chgCData(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3),3);
            tracep->chgCData(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7),7);
            tracep->chgCData(oldp+28,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2),5);
            tracep->chgCData(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1),5);
            tracep->chgCData(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd),5);
            tracep->chgBit(oldp+31,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst));
            tracep->chgBit(oldp+32,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc));
            tracep->chgBit(oldp+33,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC));
            tracep->chgBit(oldp+34,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump));
            tracep->chgBit(oldp+35,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR));
            tracep->chgCData(oldp+36,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl),3);
            tracep->chgBit(oldp+37,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead));
            tracep->chgBit(oldp+38,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite));
            tracep->chgBit(oldp+39,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg));
            tracep->chgBit(oldp+40,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite));
            tracep->chgCData(oldp+41,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3),3);
            tracep->chgCData(oldp+42,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3),3);
            tracep->chgCData(oldp+43,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr),5);
            tracep->chgIData(oldp+44,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut),32);
            tracep->chgBit(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero));
            tracep->chgBit(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR));
            tracep->chgIData(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData),32);
            tracep->chgBit(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead));
            tracep->chgBit(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite));
            tracep->chgBit(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
            tracep->chgBit(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
            tracep->chgIData(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut),32);
            tracep->chgCData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr),5);
            tracep->chgIData(oldp+54,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut),32);
            tracep->chgBit(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg));
            tracep->chgBit(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite));
            tracep->chgIData(oldp+57,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
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
            tracep->chgIData(oldp+58,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData),32);
            tracep->chgBit(oldp+59,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
            tracep->chgBit(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
            tracep->chgBit(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
            tracep->chgBit(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
            tracep->chgBit(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
            tracep->chgBit(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
            tracep->chgBit(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
            tracep->chgBit(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
            tracep->chgBit(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
            tracep->chgBit(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
            tracep->chgBit(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch));
            tracep->chgBit(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
            tracep->chgCData(oldp+71,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),7);
            tracep->chgCData(oldp+72,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+73,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl),3);
            tracep->chgCData(oldp+74,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x19U))),7);
            tracep->chgCData(oldp+75,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+76,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+77,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 7U))),5);
            tracep->chgCData(oldp+78,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                                        ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                                        : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2))),5);
            tracep->chgCData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp),4);
            tracep->chgCData(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA),2);
            tracep->chgCData(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB),2);
            tracep->chgIData(oldp+82,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i),32);
            tracep->chgIData(oldp+83,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0xfe0U & 
                                           (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                            >> 0x14U)) 
                                          | (0x1fU 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 7U))))),32);
            tracep->chgIData(oldp+84,(((0xfffff000U 
                                        & ((- (IData)(
                                                      (1U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                          >> 0x1fU)))) 
                                           << 0xcU)) 
                                       | ((0x800U & 
                                           (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                            << 4U)) 
                                          | ((0x7e0U 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0x14U)) 
                                             | (0x1eU 
                                                & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 7U)))))),32);
            tracep->chgIData(oldp+85,((0xfffff000U 
                                       & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),32);
            tracep->chgIData(oldp+86,(((0xfff00000U 
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
            tracep->chgIData(oldp+87,((0x1ffffffU & 
                                       (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                        >> 7U))),25);
            tracep->chgIData(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i),32);
            tracep->chgIData(oldp+89,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0]),32);
            tracep->chgIData(oldp+90,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1]),32);
            tracep->chgIData(oldp+91,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2]),32);
            tracep->chgIData(oldp+92,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3]),32);
            tracep->chgIData(oldp+93,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4]),32);
            tracep->chgIData(oldp+94,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5]),32);
            tracep->chgIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6]),32);
            tracep->chgIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7]),32);
            tracep->chgIData(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8]),32);
            tracep->chgIData(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9]),32);
            tracep->chgIData(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[10]),32);
            tracep->chgIData(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[11]),32);
            tracep->chgIData(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[12]),32);
            tracep->chgIData(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[13]),32);
            tracep->chgIData(oldp+103,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[14]),32);
            tracep->chgIData(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[15]),32);
            tracep->chgIData(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[16]),32);
            tracep->chgIData(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[17]),32);
            tracep->chgIData(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[18]),32);
            tracep->chgIData(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[19]),32);
            tracep->chgIData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[20]),32);
            tracep->chgIData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[21]),32);
            tracep->chgIData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[22]),32);
            tracep->chgIData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[23]),32);
            tracep->chgIData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[24]),32);
            tracep->chgIData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[25]),32);
            tracep->chgIData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[26]),32);
            tracep->chgIData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[27]),32);
            tracep->chgIData(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[28]),32);
            tracep->chgIData(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[29]),32);
            tracep->chgIData(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[30]),32);
            tracep->chgIData(oldp+120,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[31]),32);
            tracep->chgCData(oldp+121,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)),2);
            tracep->chgCData(oldp+122,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel),8);
            tracep->chgSData(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half),16);
            tracep->chgSData(oldp+124,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),13);
            tracep->chgCData(oldp+125,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),4);
            tracep->chgCData(oldp+126,(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state),2);
            tracep->chgCData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0]),2);
            tracep->chgCData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1]),2);
            tracep->chgCData(oldp+129,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2]),2);
            tracep->chgCData(oldp+130,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3]),2);
            tracep->chgCData(oldp+131,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0]),2);
            tracep->chgCData(oldp+132,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1]),2);
            tracep->chgCData(oldp+133,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2]),2);
            tracep->chgCData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3]),2);
            tracep->chgCData(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [0U][0U]),7);
            tracep->chgCData(oldp+136,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [0U][1U]),7);
            tracep->chgCData(oldp+137,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [1U][0U]),7);
            tracep->chgCData(oldp+138,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [1U][1U]),7);
            tracep->chgCData(oldp+139,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [2U][0U]),7);
            tracep->chgCData(oldp+140,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [2U][1U]),7);
            tracep->chgCData(oldp+141,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [3U][0U]),7);
            tracep->chgCData(oldp+142,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                       [3U][1U]),7);
            __Vtemp62[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][0U];
            __Vtemp62[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][1U];
            __Vtemp62[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][2U];
            __Vtemp62[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][0U][3U];
            tracep->chgWData(oldp+143,(__Vtemp62),128);
            __Vtemp63[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][0U];
            __Vtemp63[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][1U];
            __Vtemp63[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][2U];
            __Vtemp63[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [0U][1U][3U];
            tracep->chgWData(oldp+147,(__Vtemp63),128);
            __Vtemp64[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][0U];
            __Vtemp64[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][1U];
            __Vtemp64[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][2U];
            __Vtemp64[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][0U][3U];
            tracep->chgWData(oldp+151,(__Vtemp64),128);
            __Vtemp65[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][0U];
            __Vtemp65[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][1U];
            __Vtemp65[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][2U];
            __Vtemp65[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [1U][1U][3U];
            tracep->chgWData(oldp+155,(__Vtemp65),128);
            __Vtemp66[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][0U];
            __Vtemp66[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][1U];
            __Vtemp66[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][2U];
            __Vtemp66[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][0U][3U];
            tracep->chgWData(oldp+159,(__Vtemp66),128);
            __Vtemp67[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][0U];
            __Vtemp67[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][1U];
            __Vtemp67[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][2U];
            __Vtemp67[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [2U][1U][3U];
            tracep->chgWData(oldp+163,(__Vtemp67),128);
            __Vtemp68[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][0U];
            __Vtemp68[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][1U];
            __Vtemp68[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][2U];
            __Vtemp68[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][0U][3U];
            tracep->chgWData(oldp+167,(__Vtemp68),128);
            __Vtemp69[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][0U];
            __Vtemp69[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][1U];
            __Vtemp69[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][2U];
            __Vtemp69[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [3U][1U][3U];
            tracep->chgWData(oldp+171,(__Vtemp69),128);
            tracep->chgCData(oldp+175,(0U),2);
            tracep->chgCData(oldp+176,(0U),7);
            tracep->chgIData(oldp+177,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j),32);
            tracep->chgCData(oldp+178,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne),2);
            tracep->chgBit(oldp+179,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__replace));
            tracep->chgCData(oldp+180,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state),3);
            tracep->chgCData(oldp+181,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0]),2);
            tracep->chgCData(oldp+182,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1]),2);
            tracep->chgCData(oldp+183,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2]),2);
            tracep->chgCData(oldp+184,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3]),2);
            tracep->chgCData(oldp+185,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0]),2);
            tracep->chgCData(oldp+186,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1]),2);
            tracep->chgCData(oldp+187,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2]),2);
            tracep->chgCData(oldp+188,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3]),2);
            tracep->chgCData(oldp+189,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0]),2);
            tracep->chgCData(oldp+190,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1]),2);
            tracep->chgCData(oldp+191,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2]),2);
            tracep->chgCData(oldp+192,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3]),2);
            tracep->chgCData(oldp+193,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [0U][0U]),4);
            tracep->chgCData(oldp+194,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [0U][1U]),4);
            tracep->chgCData(oldp+195,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [1U][0U]),4);
            tracep->chgCData(oldp+196,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [1U][1U]),4);
            tracep->chgCData(oldp+197,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [2U][0U]),4);
            tracep->chgCData(oldp+198,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [2U][1U]),4);
            tracep->chgCData(oldp+199,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [3U][0U]),4);
            tracep->chgCData(oldp+200,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                       [3U][1U]),4);
            __Vtemp70[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][0U];
            __Vtemp70[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][1U];
            __Vtemp70[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][2U];
            __Vtemp70[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][0U][3U];
            tracep->chgWData(oldp+201,(__Vtemp70),128);
            __Vtemp71[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][0U];
            __Vtemp71[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][1U];
            __Vtemp71[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][2U];
            __Vtemp71[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [0U][1U][3U];
            tracep->chgWData(oldp+205,(__Vtemp71),128);
            __Vtemp72[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][0U];
            __Vtemp72[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][1U];
            __Vtemp72[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][2U];
            __Vtemp72[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][0U][3U];
            tracep->chgWData(oldp+209,(__Vtemp72),128);
            __Vtemp73[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][0U];
            __Vtemp73[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][1U];
            __Vtemp73[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][2U];
            __Vtemp73[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [1U][1U][3U];
            tracep->chgWData(oldp+213,(__Vtemp73),128);
            __Vtemp74[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][0U];
            __Vtemp74[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][1U];
            __Vtemp74[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][2U];
            __Vtemp74[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][0U][3U];
            tracep->chgWData(oldp+217,(__Vtemp74),128);
            __Vtemp75[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][0U];
            __Vtemp75[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][1U];
            __Vtemp75[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][2U];
            __Vtemp75[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [2U][1U][3U];
            tracep->chgWData(oldp+221,(__Vtemp75),128);
            __Vtemp76[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][0U];
            __Vtemp76[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][1U];
            __Vtemp76[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][2U];
            __Vtemp76[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][0U][3U];
            tracep->chgWData(oldp+225,(__Vtemp76),128);
            __Vtemp77[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][0U];
            __Vtemp77[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][1U];
            __Vtemp77[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][2U];
            __Vtemp77[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                [3U][1U][3U];
            tracep->chgWData(oldp+229,(__Vtemp77),128);
            tracep->chgIData(oldp+233,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j),32);
            tracep->chgIData(oldp+234,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0]),32);
            tracep->chgIData(oldp+235,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1]),32);
            tracep->chgIData(oldp+236,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2]),32);
            tracep->chgIData(oldp+237,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3]),32);
            tracep->chgBit(oldp+238,(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag));
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [3U]))) {
            tracep->chgBit(oldp+239,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen));
            tracep->chgBit(oldp+240,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen));
            tracep->chgBit(oldp+241,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen));
            tracep->chgCData(oldp+242,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                         ? (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen) 
                                             & (~ (IData)(
                                                          (0U 
                                                           != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)))))
                                             ? 1U : 0U)
                                         : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                             ? ((IData)(vlTOPp->toplevel__DOT__imem_read_ready)
                                                 ? 2U
                                                 : 1U)
                                             : 0U))),2);
            tracep->chgIData(oldp+243,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i),32);
            tracep->chgBit(oldp+244,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) 
                                       & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen))) 
                                      | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) 
                                         & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen))))));
            tracep->chgCData(oldp+245,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                         ? 0U : ((2U 
                                                  & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                                   ? 
                                                  (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) 
                                                    & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))
                                                    ? 4U
                                                    : 0U)
                                                   : 
                                                  ((IData)(vlTOPp->toplevel__DOT__dmem_read_ready)
                                                    ? 3U
                                                    : 2U))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                                   ? 
                                                  ((IData)(vlTOPp->toplevel__DOT__dmem_write_done)
                                                    ? 2U
                                                    : 1U)
                                                   : 
                                                  (((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) 
                                                      & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen))) 
                                                     | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) 
                                                        & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen)))) 
                                                    & (~ (IData)(
                                                                 (0U 
                                                                  != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)))))
                                                    ? 
                                                   ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit)
                                                     ? 1U
                                                     : 2U)
                                                    : 0U))))),3);
            tracep->chgIData(oldp+246,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i),32);
        }
        if (VL_UNLIKELY((vlTOPp->__Vm_traceActivity
                         [1U] | vlTOPp->__Vm_traceActivity
                         [4U]))) {
            tracep->chgCData(oldp+247,((0xfU & ((0U 
                                                 == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                 ? 
                                                ((IData)(1U) 
                                                 << 
                                                 (3U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                 : 
                                                ((1U 
                                                  == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                  ? 
                                                 ((2U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                   ? 0xcU
                                                   : 3U)
                                                  : 0xfU)))),4);
            tracep->chgBit(oldp+248,((1U & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                             ? ((2U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                  ? 
                                                 (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                  << 0x18U)
                                                  : 
                                                 (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                  << 0x10U))
                                                 : 
                                                ((1U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                  ? 
                                                 (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                  << 8U)
                                                  : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))
                                             : ((1U 
                                                 == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                 ? 
                                                ((0U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                  ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                                  : 
                                                 ((2U 
                                                   == 
                                                   (3U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                   ? 
                                                  (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                   << 0x10U)
                                                   : 0U))
                                                 : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData)))));
            tracep->chgIData(oldp+249,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                         ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                             ? ((1U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                 ? 
                                                (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                 << 0x18U)
                                                 : 
                                                (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                 << 0x10U))
                                             : ((1U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                 ? 
                                                (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                 << 8U)
                                                 : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))
                                         : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                             ? ((0U 
                                                 == 
                                                 (3U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                 ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                                 : 
                                                ((2U 
                                                  == 
                                                  (3U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                  ? 
                                                 (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                  << 0x10U)
                                                  : 0U))
                                             : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))),32);
            tracep->chgIData(oldp+250,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
                                         : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                                             ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                                + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                                             : ((IData)(4U) 
                                                + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)))),32);
            tracep->chgIData(oldp+251,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                         : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC)),32);
            tracep->chgIData(oldp+252,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                          ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                          : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                                        + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend)),32);
            tracep->chgIData(oldp+253,((1U & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                               ? ((2U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                   ? 
                                                  ((1U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                    ? 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 0x18U)
                                                    : 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 0x10U))
                                                   : 
                                                  ((1U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                    ? 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 8U)
                                                    : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))
                                               : ((1U 
                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (3U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                                    : 
                                                   ((2U 
                                                     == 
                                                     (3U 
                                                      & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                     ? 
                                                    (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                     << 0x10U)
                                                     : 0U))
                                                   : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData)))),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgBit(oldp+254,((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))));
            tracep->chgCData(oldp+255,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter),4);
            tracep->chgIData(oldp+256,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgWData(oldp+257,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout),128);
            tracep->chgSData(oldp+261,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess),16);
            tracep->chgWData(oldp+262,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin),128);
            tracep->chgBit(oldp+266,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))));
            tracep->chgBit(oldp+267,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit));
            tracep->chgWData(oldp+268,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin),128);
            tracep->chgBit(oldp+272,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))));
            tracep->chgWData(oldp+273,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout),128);
            tracep->chgCData(oldp+277,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg),2);
            tracep->chgCData(oldp+278,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict),2);
            tracep->chgCData(oldp+279,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask),2);
            tracep->chgCData(oldp+280,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg),2);
            tracep->chgCData(oldp+281,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict),2);
            tracep->chgCData(oldp+282,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask),2);
            tracep->chgBit(oldp+283,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset));
            tracep->chgBit(oldp+284,(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[4U])) {
            tracep->chgCData(oldp+285,(0U),6);
            tracep->chgBit(oldp+286,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)));
            tracep->chgCData(oldp+287,((0x3fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),6);
            tracep->chgBit(oldp+288,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
            tracep->chgIData(oldp+289,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut),32);
            tracep->chgIData(oldp+290,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA),32);
            tracep->chgIData(oldp+291,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB),32);
            tracep->chgIData(oldp+292,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val),32);
            tracep->chgIData(oldp+293,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA),32);
            tracep->chgIData(oldp+294,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB),32);
            tracep->chgBit(oldp+295,((0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val)));
            tracep->chgBit(oldp+296,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc));
            tracep->chgBit(oldp+297,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid));
            tracep->chgBit(oldp+298,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex));
            tracep->chgBit(oldp+299,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem));
            tracep->chgBit(oldp+300,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc));
            tracep->chgBit(oldp+301,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow));
            tracep->chgBit(oldp+302,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache));
            tracep->chgQData(oldp+303,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub),33);
            tracep->chgCData(oldp+305,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),2);
            tracep->chgBit(oldp+306,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                            >> 0x1fU))));
            tracep->chgSData(oldp+307,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),10);
            tracep->chgCData(oldp+308,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),4);
            tracep->chgCData(oldp+309,(0U),2);
            tracep->chgCData(oldp+310,(0U),4);
            tracep->chgCData(oldp+311,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne),2);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[5U])) {
            tracep->chgWData(oldp+312,(vlTOPp->toplevel__DOT__imem_dout),128);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[6U])) {
            tracep->chgWData(oldp+316,(vlTOPp->toplevel__DOT__dmem_dout),128);
        }
        tracep->chgBit(oldp+320,(vlTOPp->clock));
        tracep->chgBit(oldp+321,(vlTOPp->reset));
        tracep->chgBit(oldp+322,(((IData)(vlTOPp->reset)
                                   ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout[0U])
                                   : 0U)));
        tracep->chgBit(oldp+323,(((IData)(vlTOPp->reset)
                                   ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U])
                                   : 0U)));
        tracep->chgIData(oldp+324,(((IData)(vlTOPp->reset)
                                     ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout[0U])
                                     : 0U)),32);
        tracep->chgIData(oldp+325,(((IData)(vlTOPp->reset)
                                     ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U])
                                     : 0U)),32);
        tracep->chgIData(oldp+326,(((IData)(vlTOPp->reset)
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U]
                                     : 0U)),32);
        tracep->chgIData(oldp+327,(((IData)(vlTOPp->reset)
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout[0U]
                                     : 0U)),32);
        tracep->chgBit(oldp+328,((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter))));
        tracep->chgCData(oldp+329,(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter),4);
        tracep->chgBit(oldp+330,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready));
        tracep->chgBit(oldp+331,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
        tracep->chgIData(oldp+332,(vlTOPp->toplevel__DOT__Data_Mem__DOT__i),32);
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
        vlTOPp->__Vm_traceActivity[6U] = 0U;
    }
}
