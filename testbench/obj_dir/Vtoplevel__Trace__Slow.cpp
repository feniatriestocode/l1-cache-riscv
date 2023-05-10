// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtoplevel__Syms.h"


//======================

void Vtoplevel::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtoplevel::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtoplevel::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtoplevel::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtoplevel::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+122,"clock", false,-1);
        tracep->declBit(c+123,"reset", false,-1);
        tracep->declBit(c+124,"MemWriteEnable", false,-1);
        tracep->declBus(c+125,"MemAddr", false,-1, 31,0);
        tracep->declBus(c+126,"WriteData", false,-1, 31,0);
        tracep->declBit(c+122,"toplevel clock", false,-1);
        tracep->declBit(c+123,"toplevel reset", false,-1);
        tracep->declBit(c+124,"toplevel MemWriteEnable", false,-1);
        tracep->declBus(c+125,"toplevel MemAddr", false,-1, 31,0);
        tracep->declBus(c+126,"toplevel WriteData", false,-1, 31,0);
        tracep->declBit(c+122,"toplevel cpu clock", false,-1);
        tracep->declBit(c+123,"toplevel cpu reset", false,-1);
        tracep->declBit(c+124,"toplevel cpu MemWriteEnable", false,-1);
        tracep->declBus(c+125,"toplevel cpu MemAddr", false,-1, 31,0);
        tracep->declBus(c+126,"toplevel cpu WriteData", false,-1, 31,0);
        tracep->declBus(c+1,"toplevel cpu PC", false,-1, 31,0);
        tracep->declBus(c+2,"toplevel cpu IFID_PC", false,-1, 31,0);
        tracep->declBus(c+3,"toplevel cpu IDEX_PC", false,-1, 31,0);
        tracep->declBus(c+4,"toplevel cpu EXMEM_PC", false,-1, 31,0);
        tracep->declBus(c+5,"toplevel cpu IFID_PCplus4", false,-1, 31,0);
        tracep->declBus(c+6,"toplevel cpu IFID_instr", false,-1, 31,0);
        tracep->declBus(c+7,"toplevel cpu instr", false,-1, 31,0);
        tracep->declBus(c+8,"toplevel cpu IDEX_signExtend", false,-1, 31,0);
        tracep->declBus(c+9,"toplevel cpu signExtend", false,-1, 31,0);
        tracep->declBus(c+10,"toplevel cpu IDEX_rdA", false,-1, 31,0);
        tracep->declBus(c+11,"toplevel cpu IDEX_rdB", false,-1, 31,0);
        tracep->declBus(c+12,"toplevel cpu IDEX_funct3", false,-1, 2,0);
        tracep->declBus(c+13,"toplevel cpu IDEX_funct7", false,-1, 6,0);
        tracep->declBus(c+14,"toplevel cpu IDEX_PCplus4", false,-1, 31,0);
        tracep->declBus(c+15,"toplevel cpu IDEX_instr_rs2", false,-1, 4,0);
        tracep->declBus(c+16,"toplevel cpu IDEX_instr_rs1", false,-1, 4,0);
        tracep->declBus(c+17,"toplevel cpu IDEX_instr_rd", false,-1, 4,0);
        tracep->declBit(c+18,"toplevel cpu IDEX_RegDst", false,-1);
        tracep->declBit(c+19,"toplevel cpu IDEX_ALUSrc", false,-1);
        tracep->declBus(c+20,"toplevel cpu IDEX_ALUcntrl", false,-1, 2,0);
        tracep->declBit(c+93,"toplevel cpu IDEX_MemRead", false,-1);
        tracep->declBit(c+94,"toplevel cpu IDEX_MemWrite", false,-1);
        tracep->declBit(c+21,"toplevel cpu IDEX_MemToReg", false,-1);
        tracep->declBit(c+22,"toplevel cpu IDEX_RegWrite", false,-1);
        tracep->declBus(c+23,"toplevel cpu EXMEM_funct3", false,-1, 2,0);
        tracep->declBus(c+24,"toplevel cpu MEMWB_funct3", false,-1, 2,0);
        tracep->declBus(c+25,"toplevel cpu EXMEM_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+95,"toplevel cpu EXMEM_ALUOut", false,-1, 31,0);
        tracep->declBus(c+26,"toplevel cpu EXMEM_BranchALUOut", false,-1, 31,0);
        tracep->declBit(c+27,"toplevel cpu EXMEM_Zero", false,-1);
        tracep->declBus(c+28,"toplevel cpu EXMEM_MemWriteData", false,-1, 31,0);
        tracep->declBus(c+96,"toplevel cpu MemWriteData", false,-1, 31,0);
        tracep->declBit(c+97,"toplevel cpu EXMEM_MemRead", false,-1);
        tracep->declBit(c+98,"toplevel cpu EXMEM_MemWrite", false,-1);
        tracep->declBit(c+29,"toplevel cpu EXMEM_RegWrite", false,-1);
        tracep->declBit(c+30,"toplevel cpu EXMEM_MemToReg", false,-1);
        tracep->declBus(c+31,"toplevel cpu MEMWB_DMemOut", false,-1, 31,0);
        tracep->declBus(c+32,"toplevel cpu MEMWB_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+33,"toplevel cpu MEMWB_ALUOut", false,-1, 31,0);
        tracep->declBit(c+34,"toplevel cpu MEMWB_MemToReg", false,-1);
        tracep->declBit(c+35,"toplevel cpu MEMWB_RegWrite", false,-1);
        tracep->declBus(c+99,"toplevel cpu ALUInA", false,-1, 31,0);
        tracep->declBus(c+100,"toplevel cpu ALUInB", false,-1, 31,0);
        tracep->declBus(c+101,"toplevel cpu ALUOut", false,-1, 31,0);
        tracep->declBus(c+36,"toplevel cpu BranchALUOut", false,-1, 31,0);
        tracep->declBus(c+102,"toplevel cpu bypassOutB", false,-1, 31,0);
        tracep->declBus(c+127,"toplevel cpu DMemOut", false,-1, 31,0);
        tracep->declBus(c+37,"toplevel cpu MemOut", false,-1, 31,0);
        tracep->declBus(c+38,"toplevel cpu wRegData", false,-1, 31,0);
        tracep->declBus(c+39,"toplevel cpu PCplus4", false,-1, 31,0);
        tracep->declBus(c+40,"toplevel cpu JumpAddress", false,-1, 31,0);
        tracep->declBus(c+128,"toplevel cpu PC_new", false,-1, 31,0);
        tracep->declBit(c+103,"toplevel cpu Zero", false,-1);
        tracep->declBit(c+104,"toplevel cpu RegDst", false,-1);
        tracep->declBit(c+105,"toplevel cpu MemRead", false,-1);
        tracep->declBit(c+106,"toplevel cpu MemWrite", false,-1);
        tracep->declBit(c+107,"toplevel cpu MemToReg", false,-1);
        tracep->declBit(c+108,"toplevel cpu ALUSrc", false,-1);
        tracep->declBit(c+109,"toplevel cpu PCSrc", false,-1);
        tracep->declBit(c+110,"toplevel cpu RegWrite", false,-1);
        tracep->declBit(c+111,"toplevel cpu Jump", false,-1);
        tracep->declBit(c+112,"toplevel cpu CPU_RegWrite", false,-1);
        tracep->declBit(c+113,"toplevel cpu Branch", false,-1);
        tracep->declBit(c+41,"toplevel cpu IDEX_Branch", false,-1);
        tracep->declBit(c+42,"toplevel cpu EXMEM_Branch", false,-1);
        tracep->declBit(c+114,"toplevel cpu bubble_ifid", false,-1);
        tracep->declBit(c+115,"toplevel cpu bubble_idex", false,-1);
        tracep->declBit(c+116,"toplevel cpu bubble_exmem", false,-1);
        tracep->declBit(c+129,"toplevel cpu bubble_memwb", false,-1);
        tracep->declBit(c+117,"toplevel cpu write_ifid", false,-1);
        tracep->declBit(c+130,"toplevel cpu write_idex", false,-1);
        tracep->declBit(c+130,"toplevel cpu write_exmem", false,-1);
        tracep->declBit(c+130,"toplevel cpu write_memwb", false,-1);
        tracep->declBit(c+118,"toplevel cpu write_pc", false,-1);
        tracep->declBus(c+43,"toplevel cpu opcode", false,-1, 6,0);
        tracep->declBus(c+44,"toplevel cpu funct3", false,-1, 2,0);
        tracep->declBus(c+119,"toplevel cpu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+45,"toplevel cpu funct7", false,-1, 6,0);
        tracep->declBus(c+46,"toplevel cpu instr_rs1", false,-1, 4,0);
        tracep->declBus(c+47,"toplevel cpu instr_rs2", false,-1, 4,0);
        tracep->declBus(c+48,"toplevel cpu instr_rd", false,-1, 4,0);
        tracep->declBus(c+49,"toplevel cpu RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+50,"toplevel cpu ALUOp", false,-1, 3,0);
        tracep->declBus(c+51,"toplevel cpu bypassA", false,-1, 1,0);
        tracep->declBus(c+52,"toplevel cpu bypassB", false,-1, 1,0);
        tracep->declBus(c+53,"toplevel cpu imm_i", false,-1, 31,0);
        tracep->declBus(c+54,"toplevel cpu imm_s", false,-1, 31,0);
        tracep->declBus(c+55,"toplevel cpu imm_b", false,-1, 31,0);
        tracep->declBus(c+56,"toplevel cpu imm_u", false,-1, 31,0);
        tracep->declBus(c+57,"toplevel cpu imm_j", false,-1, 31,0);
        tracep->declBit(c+122,"toplevel cpu cpu_IMem clock", false,-1);
        tracep->declBit(c+123,"toplevel cpu cpu_IMem reset", false,-1);
        tracep->declBit(c+117,"toplevel cpu cpu_IMem ren", false,-1);
        tracep->declBit(c+129,"toplevel cpu cpu_IMem wen", false,-1);
        tracep->declBus(c+58,"toplevel cpu cpu_IMem addr", false,-1, 13,0);
        tracep->declBus(c+131,"toplevel cpu cpu_IMem din", false,-1, 31,0);
        tracep->declBus(c+7,"toplevel cpu cpu_IMem dout", false,-1, 31,0);
        tracep->declBit(c+122,"toplevel cpu cpu_regs clock", false,-1);
        tracep->declBit(c+123,"toplevel cpu cpu_regs reset", false,-1);
        tracep->declBus(c+46,"toplevel cpu cpu_regs raA", false,-1, 4,0);
        tracep->declBus(c+47,"toplevel cpu cpu_regs raB", false,-1, 4,0);
        tracep->declBus(c+32,"toplevel cpu cpu_regs wa", false,-1, 4,0);
        tracep->declBit(c+112,"toplevel cpu cpu_regs wen", false,-1);
        tracep->declBus(c+38,"toplevel cpu cpu_regs wd", false,-1, 31,0);
        tracep->declBus(c+10,"toplevel cpu cpu_regs rdA", false,-1, 31,0);
        tracep->declBus(c+11,"toplevel cpu cpu_regs rdB", false,-1, 31,0);
        tracep->declBus(c+59,"toplevel cpu cpu_regs i", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+60+i*1,"toplevel cpu cpu_regs data", true,(i+0), 31,0);}}
        tracep->declBus(c+9,"toplevel cpu signExtendUnit out", false,-1, 31,0);
        tracep->declBus(c+53,"toplevel cpu signExtendUnit imm_i", false,-1, 31,0);
        tracep->declBus(c+54,"toplevel cpu signExtendUnit imm_s", false,-1, 31,0);
        tracep->declBus(c+55,"toplevel cpu signExtendUnit imm_b", false,-1, 31,0);
        tracep->declBus(c+56,"toplevel cpu signExtendUnit imm_u", false,-1, 31,0);
        tracep->declBus(c+57,"toplevel cpu signExtendUnit imm_j", false,-1, 31,0);
        tracep->declBus(c+43,"toplevel cpu signExtendUnit opcode", false,-1, 6,0);
        tracep->declBit(c+104,"toplevel cpu control_main RegDst", false,-1);
        tracep->declBit(c+113,"toplevel cpu control_main Branch", false,-1);
        tracep->declBit(c+105,"toplevel cpu control_main MemRead", false,-1);
        tracep->declBit(c+106,"toplevel cpu control_main MemWrite", false,-1);
        tracep->declBit(c+107,"toplevel cpu control_main MemToReg", false,-1);
        tracep->declBit(c+108,"toplevel cpu control_main ALUSrc", false,-1);
        tracep->declBit(c+110,"toplevel cpu control_main RegWrite", false,-1);
        tracep->declBit(c+111,"toplevel cpu control_main Jump", false,-1);
        tracep->declBus(c+119,"toplevel cpu control_main ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+43,"toplevel cpu control_main opcode", false,-1, 6,0);
        tracep->declBit(c+114,"toplevel cpu control_stall_id bubble_ifid", false,-1);
        tracep->declBit(c+115,"toplevel cpu control_stall_id bubble_idex", false,-1);
        tracep->declBit(c+116,"toplevel cpu control_stall_id bubble_exmem", false,-1);
        tracep->declBit(c+129,"toplevel cpu control_stall_id bubble_memwb", false,-1);
        tracep->declBit(c+117,"toplevel cpu control_stall_id write_ifid", false,-1);
        tracep->declBit(c+130,"toplevel cpu control_stall_id write_idex", false,-1);
        tracep->declBit(c+130,"toplevel cpu control_stall_id write_exmem", false,-1);
        tracep->declBit(c+130,"toplevel cpu control_stall_id write_memwb", false,-1);
        tracep->declBit(c+118,"toplevel cpu control_stall_id write_pc", false,-1);
        tracep->declBus(c+46,"toplevel cpu control_stall_id ifid_rs", false,-1, 4,0);
        tracep->declBus(c+47,"toplevel cpu control_stall_id ifid_rt", false,-1, 4,0);
        tracep->declBus(c+48,"toplevel cpu control_stall_id ifid_rd", false,-1, 4,0);
        tracep->declBus(c+15,"toplevel cpu control_stall_id idex_rt", false,-1, 4,0);
        tracep->declBus(c+17,"toplevel cpu control_stall_id idex_rd", false,-1, 4,0);
        tracep->declBus(c+25,"toplevel cpu control_stall_id exmem_rd", false,-1, 4,0);
        tracep->declBus(c+32,"toplevel cpu control_stall_id memwb_rd", false,-1, 4,0);
        tracep->declBit(c+93,"toplevel cpu control_stall_id idex_memread", false,-1);
        tracep->declBit(c+111,"toplevel cpu control_stall_id Jump", false,-1);
        tracep->declBit(c+109,"toplevel cpu control_stall_id PCSrc", false,-1);
        tracep->declBit(c+22,"toplevel cpu control_stall_id IDEX_RegWrite", false,-1);
        tracep->declBit(c+29,"toplevel cpu control_stall_id EXMEM_RegWrite", false,-1);
        tracep->declBit(c+35,"toplevel cpu control_stall_id MEMWB_RegWrite", false,-1);
        tracep->declBus(c+132,"toplevel cpu branch_alu N", false,-1, 31,0);
        tracep->declBus(c+36,"toplevel cpu branch_alu out", false,-1, 31,0);
        tracep->declBit(c+92,"toplevel cpu branch_alu zero", false,-1);
        tracep->declBus(c+3,"toplevel cpu branch_alu inA", false,-1, 31,0);
        tracep->declBus(c+8,"toplevel cpu branch_alu inB", false,-1, 31,0);
        tracep->declBus(c+133,"toplevel cpu branch_alu op", false,-1, 3,0);
        tracep->declBus(c+134,"toplevel cpu branch_alu PC", false,-1, 31,0);
        tracep->declBus(c+132,"toplevel cpu cpu_alu N", false,-1, 31,0);
        tracep->declBus(c+101,"toplevel cpu cpu_alu out", false,-1, 31,0);
        tracep->declBit(c+103,"toplevel cpu cpu_alu zero", false,-1);
        tracep->declBus(c+99,"toplevel cpu cpu_alu inA", false,-1, 31,0);
        tracep->declBus(c+100,"toplevel cpu cpu_alu inB", false,-1, 31,0);
        tracep->declBus(c+50,"toplevel cpu cpu_alu op", false,-1, 3,0);
        tracep->declBus(c+4,"toplevel cpu cpu_alu PC", false,-1, 31,0);
        tracep->declBus(c+50,"toplevel cpu control_alu ALUOp", false,-1, 3,0);
        tracep->declBus(c+20,"toplevel cpu control_alu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+12,"toplevel cpu control_alu funct3", false,-1, 2,0);
        tracep->declBus(c+13,"toplevel cpu control_alu funct7", false,-1, 6,0);
        tracep->declBus(c+51,"toplevel cpu control_bypass_ex bypassA", false,-1, 1,0);
        tracep->declBus(c+52,"toplevel cpu control_bypass_ex bypassB", false,-1, 1,0);
        tracep->declBus(c+16,"toplevel cpu control_bypass_ex idex_rs", false,-1, 4,0);
        tracep->declBus(c+15,"toplevel cpu control_bypass_ex idex_rt", false,-1, 4,0);
        tracep->declBus(c+25,"toplevel cpu control_bypass_ex exmem_rd", false,-1, 4,0);
        tracep->declBus(c+32,"toplevel cpu control_bypass_ex memwb_rd", false,-1, 4,0);
        tracep->declBit(c+29,"toplevel cpu control_bypass_ex exmem_regwrite", false,-1);
        tracep->declBit(c+35,"toplevel cpu control_bypass_ex memwb_regwrite", false,-1);
        tracep->declBit(c+109,"toplevel cpu control_branch branch_taken", false,-1);
        tracep->declBus(c+23,"toplevel cpu control_branch funct3", false,-1, 2,0);
        tracep->declBit(c+42,"toplevel cpu control_branch Branch", false,-1);
        tracep->declBit(c+27,"toplevel cpu control_branch zero", false,-1);
        tracep->declBit(c+120,"toplevel cpu control_branch sign", false,-1);
        tracep->declBus(c+23,"toplevel cpu control_mem_in mem_select", false,-1, 2,0);
        tracep->declBus(c+28,"toplevel cpu control_mem_in ALUin", false,-1, 31,0);
        tracep->declBus(c+96,"toplevel cpu control_mem_in out", false,-1, 31,0);
        tracep->declBit(c+122,"toplevel cpu cpu_DMem clock", false,-1);
        tracep->declBit(c+123,"toplevel cpu cpu_DMem reset", false,-1);
        tracep->declBit(c+97,"toplevel cpu cpu_DMem ren", false,-1);
        tracep->declBit(c+98,"toplevel cpu cpu_DMem wen", false,-1);
        tracep->declBus(c+121,"toplevel cpu cpu_DMem addr", false,-1, 14,0);
        tracep->declBus(c+96,"toplevel cpu cpu_DMem din", false,-1, 31,0);
        tracep->declBus(c+127,"toplevel cpu cpu_DMem dout", false,-1, 31,0);
        tracep->declBus(c+24,"toplevel cpu control_mem_out mem_select", false,-1, 2,0);
        tracep->declBus(c+31,"toplevel cpu control_mem_out DMemOut", false,-1, 31,0);
        tracep->declBus(c+37,"toplevel cpu control_mem_out out", false,-1, 31,0);
    }
}

void Vtoplevel::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtoplevel::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtoplevel::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtoplevel__Syms* __restrict vlSymsp = static_cast<Vtoplevel__Syms*>(userp);
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->toplevel__DOT__cpu__DOT__PC),32);
        tracep->fullIData(oldp+2,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC),32);
        tracep->fullIData(oldp+3,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC),32);
        tracep->fullIData(oldp+4,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_PC),32);
        tracep->fullIData(oldp+5,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_PCplus4),32);
        tracep->fullIData(oldp+6,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr),32);
        tracep->fullIData(oldp+7,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_IMem__DOT__data
                                  [(0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                                               >> 2U))]),32);
        tracep->fullIData(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend),32);
        tracep->fullIData(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__signExtend),32);
        tracep->fullIData(oldp+10,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdA),32);
        tracep->fullIData(oldp+11,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdB),32);
        tracep->fullCData(oldp+12,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3),3);
        tracep->fullCData(oldp+13,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7),7);
        tracep->fullIData(oldp+14,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PCplus4),32);
        tracep->fullCData(oldp+15,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2),5);
        tracep->fullCData(oldp+16,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1),5);
        tracep->fullCData(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd),5);
        tracep->fullBit(oldp+18,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst));
        tracep->fullBit(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUSrc));
        tracep->fullCData(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl),3);
        tracep->fullBit(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemToReg));
        tracep->fullBit(oldp+22,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite));
        tracep->fullCData(oldp+23,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3),3);
        tracep->fullCData(oldp+24,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3),3);
        tracep->fullCData(oldp+25,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr),5);
        tracep->fullIData(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut),32);
        tracep->fullBit(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Zero));
        tracep->fullIData(oldp+28,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData),32);
        tracep->fullBit(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite));
        tracep->fullBit(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemToReg));
        tracep->fullIData(oldp+31,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut),32);
        tracep->fullCData(oldp+32,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr),5);
        tracep->fullIData(oldp+33,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut),32);
        tracep->fullBit(oldp+34,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_MemToReg));
        tracep->fullBit(oldp+35,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite));
        tracep->fullIData(oldp+36,((vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC 
                                    + vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend)),32);
        tracep->fullIData(oldp+37,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                     ? ((0xffffff00U 
                                         & ((- (IData)(
                                                       (1U 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut 
                                                           >> 7U)))) 
                                            << 8U)) 
                                        | (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut))
                                     : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                         ? ((0xffff0000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut 
                                                               >> 0xfU)))) 
                                                << 0x10U)) 
                                            | (0xffffU 
                                               & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut))
                                         : ((4U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                             ? (0xffU 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut)
                                             : ((5U 
                                                 == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                                 ? 
                                                (0xffffU 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut)
                                                 : vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut))))),32);
        tracep->fullIData(oldp+38,(vlTOPp->toplevel__DOT__cpu__DOT__wRegData),32);
        tracep->fullIData(oldp+39,(((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__PC)),32);
        tracep->fullIData(oldp+40,(((0x6fU == (0x7fU 
                                               & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr))
                                     ? (vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                        + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)
                                     : ((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                  >> 0xfU)) 
                                        + vlTOPp->toplevel__DOT__cpu__DOT__signExtend))),32);
        tracep->fullBit(oldp+41,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Branch));
        tracep->fullBit(oldp+42,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Branch));
        tracep->fullCData(oldp+43,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)),7);
        tracep->fullCData(oldp+44,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+45,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x19U))),7);
        tracep->fullCData(oldp+46,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+47,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+48,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 7U))),5);
        tracep->fullCData(oldp+49,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst)
                                     ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd)
                                     : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2))),5);
        tracep->fullCData(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp),4);
        tracep->fullCData(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__bypassA),2);
        tracep->fullCData(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__bypassB),2);
        tracep->fullIData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__imm_i),32);
        tracep->fullIData(oldp+54,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                         >> 7U))))),32);
        tracep->fullIData(oldp+55,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0x800U 
                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                            >> 7U)))))),32);
        tracep->fullIData(oldp+56,((0xfffff000U & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)),32);
        tracep->fullIData(oldp+57,(((0xfff00000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                     >> 0x1fU)))) 
                                      << 0x14U)) | 
                                    ((0xff000U & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr) 
                                     | ((0x800U & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                   >> 9U)) 
                                        | ((0x7e0U 
                                            & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                 >> 0x14U))))))),32);
        tracep->fullSData(oldp+58,((0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                                               >> 2U))),14);
        tracep->fullIData(oldp+59,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__i),32);
        tracep->fullIData(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0]),32);
        tracep->fullIData(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[1]),32);
        tracep->fullIData(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[2]),32);
        tracep->fullIData(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[3]),32);
        tracep->fullIData(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[4]),32);
        tracep->fullIData(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[5]),32);
        tracep->fullIData(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[6]),32);
        tracep->fullIData(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[7]),32);
        tracep->fullIData(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[8]),32);
        tracep->fullIData(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[9]),32);
        tracep->fullIData(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[10]),32);
        tracep->fullIData(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[11]),32);
        tracep->fullIData(oldp+72,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[12]),32);
        tracep->fullIData(oldp+73,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[13]),32);
        tracep->fullIData(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[14]),32);
        tracep->fullIData(oldp+75,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[15]),32);
        tracep->fullIData(oldp+76,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[16]),32);
        tracep->fullIData(oldp+77,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[17]),32);
        tracep->fullIData(oldp+78,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[18]),32);
        tracep->fullIData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[19]),32);
        tracep->fullIData(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[20]),32);
        tracep->fullIData(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[21]),32);
        tracep->fullIData(oldp+82,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[22]),32);
        tracep->fullIData(oldp+83,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[23]),32);
        tracep->fullIData(oldp+84,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[24]),32);
        tracep->fullIData(oldp+85,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[25]),32);
        tracep->fullIData(oldp+86,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[26]),32);
        tracep->fullIData(oldp+87,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[27]),32);
        tracep->fullIData(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[28]),32);
        tracep->fullIData(oldp+89,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[29]),32);
        tracep->fullIData(oldp+90,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[30]),32);
        tracep->fullIData(oldp+91,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[31]),32);
        tracep->fullBit(oldp+92,((0U == (vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC 
                                         + vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend))));
        tracep->fullBit(oldp+93,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead));
        tracep->fullBit(oldp+94,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemWrite));
        tracep->fullIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut),32);
        tracep->fullIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__MemWriteData),32);
        tracep->fullBit(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemRead));
        tracep->fullBit(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite));
        tracep->fullIData(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA),32);
        tracep->fullIData(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB),32);
        tracep->fullIData(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__ALUOut),32);
        tracep->fullIData(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__bypassOutB),32);
        tracep->fullBit(oldp+103,((0U == vlTOPp->toplevel__DOT__cpu__DOT__ALUOut)));
        tracep->fullBit(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__RegDst));
        tracep->fullBit(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__MemRead));
        tracep->fullBit(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__MemWrite));
        tracep->fullBit(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__MemToReg));
        tracep->fullBit(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__ALUSrc));
        tracep->fullBit(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc));
        tracep->fullBit(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__RegWrite));
        tracep->fullBit(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__Jump));
        tracep->fullBit(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__CPU_RegWrite));
        tracep->fullBit(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__Branch));
        tracep->fullBit(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid));
        tracep->fullBit(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex));
        tracep->fullBit(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem));
        tracep->fullBit(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__write_ifid));
        tracep->fullBit(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__write_pc));
        tracep->fullCData(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__ALUcntrl),3);
        tracep->fullBit(oldp+120,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                         >> 0x1fU))));
        tracep->fullSData(oldp+121,((0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                                >> 2U))),15);
        tracep->fullBit(oldp+122,(vlTOPp->clock));
        tracep->fullBit(oldp+123,(vlTOPp->reset));
        tracep->fullBit(oldp+124,(vlTOPp->MemWriteEnable));
        tracep->fullIData(oldp+125,(vlTOPp->MemAddr),32);
        tracep->fullIData(oldp+126,(vlTOPp->WriteData),32);
        tracep->fullIData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data
                                    [(0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                                 >> 2U))]),32);
        tracep->fullIData(oldp+128,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut
                                      : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Jump)
                                          ? ((0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr))
                                              ? (vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                                 + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)
                                              : ((0x1fU 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                     >> 0xfU)) 
                                                 + vlTOPp->toplevel__DOT__cpu__DOT__signExtend))
                                          : ((IData)(4U) 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__PC)))),32);
        tracep->fullBit(oldp+129,(0U));
        tracep->fullBit(oldp+130,(1U));
        tracep->fullIData(oldp+131,(0U),32);
        tracep->fullIData(oldp+132,(0x20U),32);
        tracep->fullCData(oldp+133,(0U),4);
        tracep->fullIData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__branch_alu__DOT__PC),32);
    }
}
