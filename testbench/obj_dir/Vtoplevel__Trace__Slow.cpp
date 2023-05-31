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
        tracep->declBit(c+136,"clock", false,-1);
        tracep->declBit(c+137,"reset", false,-1);
        tracep->declBit(c+138,"overflow", false,-1);
        tracep->declBit(c+136,"toplevel clock", false,-1);
        tracep->declBit(c+137,"toplevel reset", false,-1);
        tracep->declBit(c+138,"toplevel overflow", false,-1);
        tracep->declBit(c+136,"toplevel cpu clock", false,-1);
        tracep->declBit(c+137,"toplevel cpu reset", false,-1);
        tracep->declBit(c+138,"toplevel cpu overflow", false,-1);
        tracep->declBus(c+1,"toplevel cpu IFID_instr", false,-1, 31,0);
        tracep->declBus(c+2,"toplevel cpu PC", false,-1, 31,0);
        tracep->declBus(c+3,"toplevel cpu IFID_PC", false,-1, 31,0);
        tracep->declBus(c+4,"toplevel cpu IDEX_PC", false,-1, 31,0);
        tracep->declBus(c+5,"toplevel cpu PCplus4", false,-1, 31,0);
        tracep->declBus(c+6,"toplevel cpu JumpAddress", false,-1, 31,0);
        tracep->declBus(c+7,"toplevel cpu PC_new", false,-1, 31,0);
        tracep->declBus(c+139,"toplevel cpu instr", false,-1, 31,0);
        tracep->declBit(c+8,"toplevel cpu inA_is_PC", false,-1);
        tracep->declBit(c+9,"toplevel cpu branch_taken", false,-1);
        tracep->declBus(c+10,"toplevel cpu BranchInA", false,-1, 31,0);
        tracep->declBus(c+11,"toplevel cpu IDEX_signExtend", false,-1, 31,0);
        tracep->declBus(c+12,"toplevel cpu signExtend", false,-1, 31,0);
        tracep->declBus(c+13,"toplevel cpu rdA", false,-1, 31,0);
        tracep->declBus(c+14,"toplevel cpu rdB", false,-1, 31,0);
        tracep->declBus(c+15,"toplevel cpu IDEX_rdA", false,-1, 31,0);
        tracep->declBus(c+16,"toplevel cpu IDEX_rdB", false,-1, 31,0);
        tracep->declBus(c+17,"toplevel cpu IDEX_funct3", false,-1, 2,0);
        tracep->declBus(c+18,"toplevel cpu IDEX_funct7", false,-1, 6,0);
        tracep->declBus(c+19,"toplevel cpu IDEX_instr_rs2", false,-1, 4,0);
        tracep->declBus(c+20,"toplevel cpu IDEX_instr_rs1", false,-1, 4,0);
        tracep->declBus(c+21,"toplevel cpu IDEX_instr_rd", false,-1, 4,0);
        tracep->declBit(c+22,"toplevel cpu IDEX_RegDst", false,-1);
        tracep->declBit(c+23,"toplevel cpu IDEX_ALUSrc", false,-1);
        tracep->declBit(c+24,"toplevel cpu IDEX_inA_is_PC", false,-1);
        tracep->declBit(c+25,"toplevel cpu IDEX_Jump", false,-1);
        tracep->declBit(c+26,"toplevel cpu IDEX_JumpJALR", false,-1);
        tracep->declBus(c+27,"toplevel cpu IDEX_ALUcntrl", false,-1, 2,0);
        tracep->declBit(c+28,"toplevel cpu IDEX_MemRead", false,-1);
        tracep->declBit(c+29,"toplevel cpu IDEX_MemWrite", false,-1);
        tracep->declBit(c+30,"toplevel cpu IDEX_MemToReg", false,-1);
        tracep->declBit(c+31,"toplevel cpu IDEX_RegWrite", false,-1);
        tracep->declBus(c+32,"toplevel cpu EXMEM_funct3", false,-1, 2,0);
        tracep->declBus(c+33,"toplevel cpu MEMWB_funct3", false,-1, 2,0);
        tracep->declBus(c+34,"toplevel cpu EXMEM_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+35,"toplevel cpu EXMEM_ALUOut", false,-1, 31,0);
        tracep->declBus(c+36,"toplevel cpu EXMEM_BranchALUOut", false,-1, 31,0);
        tracep->declBit(c+37,"toplevel cpu EXMEM_Zero", false,-1);
        tracep->declBit(c+38,"toplevel cpu EXMEM_JumpJALR", false,-1);
        tracep->declBus(c+39,"toplevel cpu byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+40,"toplevel cpu EXMEM_MemWriteData", false,-1, 31,0);
        tracep->declBus(c+41,"toplevel cpu MemWriteData", false,-1, 31,0);
        tracep->declBit(c+42,"toplevel cpu EXMEM_MemRead", false,-1);
        tracep->declBit(c+43,"toplevel cpu EXMEM_MemWrite", false,-1);
        tracep->declBit(c+44,"toplevel cpu EXMEM_RegWrite", false,-1);
        tracep->declBit(c+45,"toplevel cpu EXMEM_MemToReg", false,-1);
        tracep->declBus(c+46,"toplevel cpu MEMWB_DMemOut", false,-1, 31,0);
        tracep->declBus(c+47,"toplevel cpu MEMWB_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+48,"toplevel cpu MEMWB_ALUOut", false,-1, 31,0);
        tracep->declBit(c+49,"toplevel cpu MEMWB_MemToReg", false,-1);
        tracep->declBit(c+50,"toplevel cpu MEMWB_RegWrite", false,-1);
        tracep->declBus(c+51,"toplevel cpu ALUInA", false,-1, 31,0);
        tracep->declBus(c+52,"toplevel cpu ALUInB", false,-1, 31,0);
        tracep->declBus(c+53,"toplevel cpu ALUOut", false,-1, 31,0);
        tracep->declBus(c+54,"toplevel cpu BranchALUOut", false,-1, 31,0);
        tracep->declBus(c+55,"toplevel cpu bypassOutA", false,-1, 31,0);
        tracep->declBus(c+56,"toplevel cpu bypassOutB", false,-1, 31,0);
        tracep->declBus(c+140,"toplevel cpu DMemOut", false,-1, 31,0);
        tracep->declBus(c+57,"toplevel cpu MemOut", false,-1, 31,0);
        tracep->declBus(c+58,"toplevel cpu wRegData", false,-1, 31,0);
        tracep->declBit(c+59,"toplevel cpu Zero", false,-1);
        tracep->declBit(c+60,"toplevel cpu RegDst", false,-1);
        tracep->declBit(c+61,"toplevel cpu MemRead", false,-1);
        tracep->declBit(c+62,"toplevel cpu MemWrite", false,-1);
        tracep->declBit(c+63,"toplevel cpu MemToReg", false,-1);
        tracep->declBit(c+64,"toplevel cpu ALUSrc", false,-1);
        tracep->declBit(c+65,"toplevel cpu PCSrc", false,-1);
        tracep->declBit(c+66,"toplevel cpu RegWrite", false,-1);
        tracep->declBit(c+67,"toplevel cpu Jump", false,-1);
        tracep->declBit(c+68,"toplevel cpu JumpJALR", false,-1);
        tracep->declBit(c+69,"toplevel cpu Branch", false,-1);
        tracep->declBit(c+70,"toplevel cpu IDEX_Branch", false,-1);
        tracep->declBit(c+71,"toplevel cpu EXMEM_Branch", false,-1);
        tracep->declBit(c+72,"toplevel cpu bubble_ifid", false,-1);
        tracep->declBit(c+73,"toplevel cpu bubble_idex", false,-1);
        tracep->declBit(c+74,"toplevel cpu bubble_exmem", false,-1);
        tracep->declBit(c+75,"toplevel cpu write_ifid", false,-1);
        tracep->declBit(c+141,"toplevel cpu write_idex", false,-1);
        tracep->declBit(c+141,"toplevel cpu write_exmem", false,-1);
        tracep->declBit(c+141,"toplevel cpu write_memwb", false,-1);
        tracep->declBit(c+76,"toplevel cpu write_pc", false,-1);
        tracep->declBus(c+77,"toplevel cpu opcode", false,-1, 6,0);
        tracep->declBus(c+78,"toplevel cpu funct3", false,-1, 2,0);
        tracep->declBus(c+79,"toplevel cpu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+80,"toplevel cpu funct7", false,-1, 6,0);
        tracep->declBus(c+81,"toplevel cpu instr_rs1", false,-1, 4,0);
        tracep->declBus(c+82,"toplevel cpu instr_rs2", false,-1, 4,0);
        tracep->declBus(c+83,"toplevel cpu instr_rd", false,-1, 4,0);
        tracep->declBus(c+84,"toplevel cpu RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+85,"toplevel cpu ALUOp", false,-1, 3,0);
        tracep->declBus(c+86,"toplevel cpu bypassA", false,-1, 1,0);
        tracep->declBus(c+87,"toplevel cpu bypassB", false,-1, 1,0);
        tracep->declBus(c+88,"toplevel cpu imm_i", false,-1, 31,0);
        tracep->declBus(c+89,"toplevel cpu imm_s", false,-1, 31,0);
        tracep->declBus(c+90,"toplevel cpu imm_b", false,-1, 31,0);
        tracep->declBus(c+91,"toplevel cpu imm_u", false,-1, 31,0);
        tracep->declBus(c+92,"toplevel cpu imm_j", false,-1, 31,0);
        tracep->declBit(c+137,"toplevel cpu cpu_IMem reset", false,-1);
        tracep->declBit(c+75,"toplevel cpu cpu_IMem ren", false,-1);
        tracep->declBus(c+93,"toplevel cpu cpu_IMem addr", false,-1, 13,0);
        tracep->declBus(c+139,"toplevel cpu cpu_IMem dout", false,-1, 31,0);
        tracep->declBus(c+94,"toplevel cpu signExtendUnit instr", false,-1, 24,0);
        tracep->declBus(c+88,"toplevel cpu signExtendUnit imm_i", false,-1, 31,0);
        tracep->declBus(c+89,"toplevel cpu signExtendUnit imm_s", false,-1, 31,0);
        tracep->declBus(c+90,"toplevel cpu signExtendUnit imm_b", false,-1, 31,0);
        tracep->declBus(c+91,"toplevel cpu signExtendUnit imm_u", false,-1, 31,0);
        tracep->declBus(c+92,"toplevel cpu signExtendUnit imm_j", false,-1, 31,0);
        tracep->declBit(c+136,"toplevel cpu cpu_regs clock", false,-1);
        tracep->declBit(c+137,"toplevel cpu cpu_regs reset", false,-1);
        tracep->declBus(c+81,"toplevel cpu cpu_regs raA", false,-1, 4,0);
        tracep->declBus(c+82,"toplevel cpu cpu_regs raB", false,-1, 4,0);
        tracep->declBus(c+47,"toplevel cpu cpu_regs wa", false,-1, 4,0);
        tracep->declBit(c+50,"toplevel cpu cpu_regs wen", false,-1);
        tracep->declBus(c+58,"toplevel cpu cpu_regs wd", false,-1, 31,0);
        tracep->declBus(c+13,"toplevel cpu cpu_regs rdA", false,-1, 31,0);
        tracep->declBus(c+14,"toplevel cpu cpu_regs rdB", false,-1, 31,0);
        tracep->declBus(c+95,"toplevel cpu cpu_regs i", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+96+i*1,"toplevel cpu cpu_regs data", true,(i+0), 31,0);}}
        tracep->declBus(c+12,"toplevel cpu SignExtendSelector out", false,-1, 31,0);
        tracep->declBus(c+88,"toplevel cpu SignExtendSelector imm_i", false,-1, 31,0);
        tracep->declBus(c+89,"toplevel cpu SignExtendSelector imm_s", false,-1, 31,0);
        tracep->declBus(c+90,"toplevel cpu SignExtendSelector imm_b", false,-1, 31,0);
        tracep->declBus(c+91,"toplevel cpu SignExtendSelector imm_u", false,-1, 31,0);
        tracep->declBus(c+92,"toplevel cpu SignExtendSelector imm_j", false,-1, 31,0);
        tracep->declBus(c+77,"toplevel cpu SignExtendSelector opcode", false,-1, 6,0);
        tracep->declBit(c+60,"toplevel cpu control_main RegDst", false,-1);
        tracep->declBit(c+69,"toplevel cpu control_main Branch", false,-1);
        tracep->declBit(c+61,"toplevel cpu control_main MemRead", false,-1);
        tracep->declBit(c+62,"toplevel cpu control_main MemWrite", false,-1);
        tracep->declBit(c+63,"toplevel cpu control_main MemToReg", false,-1);
        tracep->declBit(c+64,"toplevel cpu control_main ALUSrc", false,-1);
        tracep->declBit(c+66,"toplevel cpu control_main RegWrite", false,-1);
        tracep->declBit(c+67,"toplevel cpu control_main Jump", false,-1);
        tracep->declBit(c+68,"toplevel cpu control_main JumpJALR", false,-1);
        tracep->declBit(c+8,"toplevel cpu control_main inA_is_PC", false,-1);
        tracep->declBus(c+79,"toplevel cpu control_main ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+77,"toplevel cpu control_main opcode", false,-1, 6,0);
        tracep->declBit(c+72,"toplevel cpu control_stall_id bubble_ifid", false,-1);
        tracep->declBit(c+73,"toplevel cpu control_stall_id bubble_idex", false,-1);
        tracep->declBit(c+74,"toplevel cpu control_stall_id bubble_exmem", false,-1);
        tracep->declBit(c+75,"toplevel cpu control_stall_id write_ifid", false,-1);
        tracep->declBit(c+141,"toplevel cpu control_stall_id write_idex", false,-1);
        tracep->declBit(c+141,"toplevel cpu control_stall_id write_exmem", false,-1);
        tracep->declBit(c+141,"toplevel cpu control_stall_id write_memwb", false,-1);
        tracep->declBit(c+76,"toplevel cpu control_stall_id write_pc", false,-1);
        tracep->declBus(c+81,"toplevel cpu control_stall_id ifid_rs", false,-1, 4,0);
        tracep->declBus(c+82,"toplevel cpu control_stall_id ifid_rt", false,-1, 4,0);
        tracep->declBus(c+21,"toplevel cpu control_stall_id idex_rd", false,-1, 4,0);
        tracep->declBit(c+28,"toplevel cpu control_stall_id idex_memread", false,-1);
        tracep->declBit(c+67,"toplevel cpu control_stall_id Jump", false,-1);
        tracep->declBit(c+65,"toplevel cpu control_stall_id PCSrc", false,-1);
        tracep->declBus(c+142,"toplevel cpu cpu_alu N", false,-1, 31,0);
        tracep->declBus(c+53,"toplevel cpu cpu_alu out", false,-1, 31,0);
        tracep->declBit(c+59,"toplevel cpu cpu_alu zero", false,-1);
        tracep->declBit(c+138,"toplevel cpu cpu_alu overflow", false,-1);
        tracep->declBus(c+51,"toplevel cpu cpu_alu inA", false,-1, 31,0);
        tracep->declBus(c+52,"toplevel cpu cpu_alu inB", false,-1, 31,0);
        tracep->declBus(c+85,"toplevel cpu cpu_alu op", false,-1, 3,0);
        tracep->declBus(c+53,"toplevel cpu cpu_alu out_val", false,-1, 31,0);
        tracep->declQuad(c+128,"toplevel cpu cpu_alu unsigned_sub", false,-1, 32,0);
        tracep->declBus(c+85,"toplevel cpu control_alu ALUOp", false,-1, 3,0);
        tracep->declBus(c+27,"toplevel cpu control_alu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+17,"toplevel cpu control_alu funct3", false,-1, 2,0);
        tracep->declBus(c+18,"toplevel cpu control_alu funct7", false,-1, 6,0);
        tracep->declBus(c+86,"toplevel cpu control_bypass_ex bypassA", false,-1, 1,0);
        tracep->declBus(c+87,"toplevel cpu control_bypass_ex bypassB", false,-1, 1,0);
        tracep->declBus(c+20,"toplevel cpu control_bypass_ex idex_rs1", false,-1, 4,0);
        tracep->declBus(c+19,"toplevel cpu control_bypass_ex idex_rs2", false,-1, 4,0);
        tracep->declBus(c+34,"toplevel cpu control_bypass_ex exmem_rd", false,-1, 4,0);
        tracep->declBus(c+47,"toplevel cpu control_bypass_ex memwb_rd", false,-1, 4,0);
        tracep->declBit(c+44,"toplevel cpu control_bypass_ex exmem_regwrite", false,-1);
        tracep->declBit(c+50,"toplevel cpu control_bypass_ex memwb_regwrite", false,-1);
        tracep->declBus(c+32,"toplevel cpu mem_write_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+40,"toplevel cpu mem_write_selector ALUin", false,-1, 31,0);
        tracep->declBus(c+130,"toplevel cpu mem_write_selector offset", false,-1, 1,0);
        tracep->declBus(c+39,"toplevel cpu mem_write_selector byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+41,"toplevel cpu mem_write_selector out", false,-1, 31,0);
        tracep->declBit(c+136,"toplevel cpu cpu_DMem clock", false,-1);
        tracep->declBit(c+137,"toplevel cpu cpu_DMem reset", false,-1);
        tracep->declBit(c+42,"toplevel cpu cpu_DMem ren", false,-1);
        tracep->declBit(c+43,"toplevel cpu cpu_DMem wen", false,-1);
        tracep->declBus(c+39,"toplevel cpu cpu_DMem byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+131,"toplevel cpu cpu_DMem addr", false,-1, 14,0);
        tracep->declBus(c+41,"toplevel cpu cpu_DMem din", false,-1, 31,0);
        tracep->declBus(c+140,"toplevel cpu cpu_DMem dout", false,-1, 31,0);
        tracep->declBit(c+9,"toplevel cpu control_branch branch_taken", false,-1);
        tracep->declBus(c+32,"toplevel cpu control_branch funct3", false,-1, 2,0);
        tracep->declBit(c+71,"toplevel cpu control_branch Branch", false,-1);
        tracep->declBit(c+37,"toplevel cpu control_branch zero", false,-1);
        tracep->declBit(c+132,"toplevel cpu control_branch sign", false,-1);
        tracep->declBus(c+33,"toplevel cpu mem_read_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+46,"toplevel cpu mem_read_selector DMemOut", false,-1, 31,0);
        tracep->declBus(c+133,"toplevel cpu mem_read_selector byte_index", false,-1, 1,0);
        tracep->declBus(c+57,"toplevel cpu mem_read_selector out", false,-1, 31,0);
        tracep->declBus(c+134,"toplevel cpu mem_read_selector byte_sel", false,-1, 7,0);
        tracep->declBus(c+135,"toplevel cpu mem_read_selector half", false,-1, 15,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr),32);
        tracep->fullIData(oldp+2,(vlTOPp->toplevel__DOT__cpu__DOT__PC),32);
        tracep->fullIData(oldp+3,(vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC),32);
        tracep->fullIData(oldp+4,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC),32);
        tracep->fullIData(oldp+5,(((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__PC)),32);
        tracep->fullIData(oldp+6,((vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                   + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)),32);
        tracep->fullIData(oldp+7,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc)
                                    ? vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut
                                    : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Jump)
                                        ? (vlTOPp->toplevel__DOT__cpu__DOT__IFID_PC 
                                           + vlTOPp->toplevel__DOT__cpu__DOT__signExtend)
                                        : ((IData)(4U) 
                                           + vlTOPp->toplevel__DOT__cpu__DOT__PC)))),32);
        tracep->fullBit(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__inA_is_PC));
        tracep->fullBit(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__branch_taken));
        tracep->fullIData(oldp+10,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_JumpJALR)
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__bypassOutA
                                     : vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC)),32);
        tracep->fullIData(oldp+11,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend),32);
        tracep->fullIData(oldp+12,(vlTOPp->toplevel__DOT__cpu__DOT__signExtend),32);
        tracep->fullIData(oldp+13,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite) 
                                      & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                         == (0x1fU 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 0xfU)))) 
                                     & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
                                     : vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data
                                    [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                               >> 0xfU))])),32);
        tracep->fullIData(oldp+14,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite) 
                                      & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr) 
                                         == (0x1fU 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                >> 0x14U)))) 
                                     & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr)))
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__wRegData
                                     : vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data
                                    [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                               >> 0x14U))])),32);
        tracep->fullIData(oldp+15,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdA),32);
        tracep->fullIData(oldp+16,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_rdB),32);
        tracep->fullCData(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct3),3);
        tracep->fullCData(oldp+18,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_funct7),7);
        tracep->fullCData(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2),5);
        tracep->fullCData(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs1),5);
        tracep->fullCData(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd),5);
        tracep->fullBit(oldp+22,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst));
        tracep->fullBit(oldp+23,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUSrc));
        tracep->fullBit(oldp+24,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_inA_is_PC));
        tracep->fullBit(oldp+25,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Jump));
        tracep->fullBit(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_JumpJALR));
        tracep->fullCData(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_ALUcntrl),3);
        tracep->fullBit(oldp+28,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemRead));
        tracep->fullBit(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemWrite));
        tracep->fullBit(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_MemToReg));
        tracep->fullBit(oldp+31,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegWrite));
        tracep->fullCData(oldp+32,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_funct3),3);
        tracep->fullCData(oldp+33,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3),3);
        tracep->fullCData(oldp+34,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWriteAddr),5);
        tracep->fullIData(oldp+35,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut),32);
        tracep->fullIData(oldp+36,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_BranchALUOut),32);
        tracep->fullBit(oldp+37,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Zero));
        tracep->fullBit(oldp+38,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_JumpJALR));
        tracep->fullCData(oldp+39,(vlTOPp->toplevel__DOT__cpu__DOT__byte_select_vector),4);
        tracep->fullIData(oldp+40,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData),32);
        tracep->fullIData(oldp+41,(vlTOPp->toplevel__DOT__cpu__DOT__MemWriteData),32);
        tracep->fullBit(oldp+42,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemRead));
        tracep->fullBit(oldp+43,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemWrite));
        tracep->fullBit(oldp+44,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_RegWrite));
        tracep->fullBit(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_MemToReg));
        tracep->fullIData(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut),32);
        tracep->fullCData(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWriteAddr),5);
        tracep->fullIData(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut),32);
        tracep->fullBit(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_MemToReg));
        tracep->fullBit(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_RegWrite));
        tracep->fullIData(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__ALUInA),32);
        tracep->fullIData(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__ALUInB),32);
        tracep->fullIData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_alu__DOT__out_val),32);
        tracep->fullIData(oldp+54,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_JumpJALR)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__bypassOutA
                                      : vlTOPp->toplevel__DOT__cpu__DOT__IDEX_PC) 
                                    + vlTOPp->toplevel__DOT__cpu__DOT__IDEX_signExtend)),32);
        tracep->fullIData(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__bypassOutA),32);
        tracep->fullIData(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__bypassOutB),32);
        tracep->fullIData(oldp+57,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                     ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut
                                         : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                             ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half)
                                             : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel)))
                                     : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                         ? vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_DMemOut
                                         : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_funct3))
                                             ? ((0xffff0000U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half) 
                                                                   >> 0xfU)))) 
                                                    << 0x10U)) 
                                                | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half))
                                             : ((0xffffff00U 
                                                 & ((- (IData)(
                                                               (1U 
                                                                & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel) 
                                                                   >> 7U)))) 
                                                    << 8U)) 
                                                | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel)))))),32);
        tracep->fullIData(oldp+58,(vlTOPp->toplevel__DOT__cpu__DOT__wRegData),32);
        tracep->fullBit(oldp+59,((0U == vlTOPp->toplevel__DOT__cpu__DOT__cpu_alu__DOT__out_val)));
        tracep->fullBit(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__RegDst));
        tracep->fullBit(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__MemRead));
        tracep->fullBit(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__MemWrite));
        tracep->fullBit(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__MemToReg));
        tracep->fullBit(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__ALUSrc));
        tracep->fullBit(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__PCSrc));
        tracep->fullBit(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__RegWrite));
        tracep->fullBit(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__Jump));
        tracep->fullBit(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__JumpJALR));
        tracep->fullBit(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__Branch));
        tracep->fullBit(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_Branch));
        tracep->fullBit(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_Branch));
        tracep->fullBit(oldp+72,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_ifid));
        tracep->fullBit(oldp+73,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_idex));
        tracep->fullBit(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__bubble_exmem));
        tracep->fullBit(oldp+75,(vlTOPp->toplevel__DOT__cpu__DOT__write_ifid));
        tracep->fullBit(oldp+76,(vlTOPp->toplevel__DOT__cpu__DOT__write_pc));
        tracep->fullCData(oldp+77,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)),7);
        tracep->fullCData(oldp+78,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__ALUcntrl),3);
        tracep->fullCData(oldp+80,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x19U))),7);
        tracep->fullCData(oldp+81,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+82,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+83,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                             >> 7U))),5);
        tracep->fullCData(oldp+84,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_RegDst)
                                     ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rd)
                                     : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IDEX_instr_rs2))),5);
        tracep->fullCData(oldp+85,(vlTOPp->toplevel__DOT__cpu__DOT__ALUOp),4);
        tracep->fullCData(oldp+86,(vlTOPp->toplevel__DOT__cpu__DOT__bypassA),2);
        tracep->fullCData(oldp+87,(vlTOPp->toplevel__DOT__cpu__DOT__bypassB),2);
        tracep->fullIData(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__imm_i),32);
        tracep->fullIData(oldp+89,(((0xfffff000U & 
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
        tracep->fullIData(oldp+90,(((0xfffff000U & 
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
        tracep->fullIData(oldp+91,((0xfffff000U & vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr)),32);
        tracep->fullIData(oldp+92,(((0xfff00000U & 
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
        tracep->fullSData(oldp+93,((0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                                               >> 2U))),14);
        tracep->fullIData(oldp+94,((0x1ffffffU & (vlTOPp->toplevel__DOT__cpu__DOT__IFID_instr 
                                                  >> 7U))),25);
        tracep->fullIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__i),32);
        tracep->fullIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[0]),32);
        tracep->fullIData(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[1]),32);
        tracep->fullIData(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[2]),32);
        tracep->fullIData(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[3]),32);
        tracep->fullIData(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[4]),32);
        tracep->fullIData(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[5]),32);
        tracep->fullIData(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[6]),32);
        tracep->fullIData(oldp+103,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[7]),32);
        tracep->fullIData(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[8]),32);
        tracep->fullIData(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[9]),32);
        tracep->fullIData(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[10]),32);
        tracep->fullIData(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[11]),32);
        tracep->fullIData(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[12]),32);
        tracep->fullIData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[13]),32);
        tracep->fullIData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[14]),32);
        tracep->fullIData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[15]),32);
        tracep->fullIData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[16]),32);
        tracep->fullIData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[17]),32);
        tracep->fullIData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[18]),32);
        tracep->fullIData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[19]),32);
        tracep->fullIData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[20]),32);
        tracep->fullIData(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[21]),32);
        tracep->fullIData(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[22]),32);
        tracep->fullIData(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[23]),32);
        tracep->fullIData(oldp+120,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[24]),32);
        tracep->fullIData(oldp+121,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[25]),32);
        tracep->fullIData(oldp+122,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[26]),32);
        tracep->fullIData(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[27]),32);
        tracep->fullIData(oldp+124,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[28]),32);
        tracep->fullIData(oldp+125,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[29]),32);
        tracep->fullIData(oldp+126,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[30]),32);
        tracep->fullIData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_regs__DOT__data[31]),32);
        tracep->fullQData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__cpu_alu__DOT__unsigned_sub),33);
        tracep->fullCData(oldp+130,((3U & vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut)),2);
        tracep->fullSData(oldp+131,((0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                                >> 2U))),15);
        tracep->fullBit(oldp+132,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+133,((3U & vlTOPp->toplevel__DOT__cpu__DOT__MEMWB_ALUOut)),2);
        tracep->fullCData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__byte_sel),8);
        tracep->fullSData(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__mem_read_selector__DOT__half),16);
        tracep->fullBit(oldp+136,(vlTOPp->clock));
        tracep->fullBit(oldp+137,(vlTOPp->reset));
        tracep->fullBit(oldp+138,(vlTOPp->overflow));
        tracep->fullIData(oldp+139,((((IData)(vlTOPp->reset) 
                                      & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__write_ifid))
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__cpu_IMem__DOT__data
                                     [(0x3fffU & (vlTOPp->toplevel__DOT__cpu__DOT__PC 
                                                  >> 2U))]
                                      : 0U)),32);
        tracep->fullIData(oldp+140,(((IData)(vlTOPp->reset)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__cpu_DMem__DOT__data
                                     [(0x7fffU & (vlTOPp->toplevel__DOT__cpu__DOT__EXMEM_ALUOut 
                                                  >> 2U))]
                                      : 0U)),32);
        tracep->fullBit(oldp+141,(1U));
        tracep->fullIData(oldp+142,(0x20U),32);
    }
}
