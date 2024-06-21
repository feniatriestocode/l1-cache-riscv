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
        tracep->declBit(c+317,"clock", false,-1);
        tracep->declBit(c+318,"reset", false,-1);
        tracep->declBit(c+317,"toplevel clock", false,-1);
        tracep->declBit(c+318,"toplevel reset", false,-1);
        tracep->declBit(c+1,"toplevel dmem_ren", false,-1);
        tracep->declBit(c+2,"toplevel dmem_wen", false,-1);
        tracep->declBit(c+3,"toplevel dmem_read_ready", false,-1);
        tracep->declBit(c+4,"toplevel dmem_write_done", false,-1);
        tracep->declBus(c+322,"toplevel dmem_block_address", false,-1, 5,0);
        tracep->declArray(c+234,"toplevel dmem_din", false,-1, 127,0);
        tracep->declArray(c+307,"toplevel dmem_dout", false,-1, 127,0);
        tracep->declBit(c+5,"toplevel imem_ren", false,-1);
        tracep->declBit(c+6,"toplevel imem_read_ready", false,-1);
        tracep->declBus(c+323,"toplevel imem_block_address", false,-1, 8,0);
        tracep->declArray(c+227,"toplevel imem_dout", false,-1, 127,0);
        tracep->declBit(c+317,"toplevel cpu clock", false,-1);
        tracep->declBit(c+318,"toplevel cpu reset", false,-1);
        tracep->declBit(c+5,"toplevel cpu ImemRen", false,-1);
        tracep->declBus(c+323,"toplevel cpu IblockAddr", false,-1, 8,0);
        tracep->declArray(c+227,"toplevel cpu ImemDout", false,-1, 127,0);
        tracep->declBit(c+6,"toplevel cpu ImemReadReady", false,-1);
        tracep->declBit(c+1,"toplevel cpu DmemRen", false,-1);
        tracep->declBit(c+2,"toplevel cpu DmemWen", false,-1);
        tracep->declBus(c+322,"toplevel cpu DblockAddress", false,-1, 5,0);
        tracep->declArray(c+234,"toplevel cpu DmemDin", false,-1, 127,0);
        tracep->declBit(c+3,"toplevel cpu DmemReadReady", false,-1);
        tracep->declBit(c+4,"toplevel cpu DmemWriteDone", false,-1);
        tracep->declArray(c+307,"toplevel cpu DmemDout", false,-1, 127,0);
        tracep->declBit(c+7,"toplevel cpu dcacheStall", false,-1);
        tracep->declBit(c+8,"toplevel cpu icacheStall", false,-1);
        tracep->declBit(c+9,"toplevel cpu pipelineDRen", false,-1);
        tracep->declBit(c+10,"toplevel cpu pipelineDWen", false,-1);
        tracep->declBit(c+238,"toplevel cpu pipelineIRen", false,-1);
        tracep->declBus(c+11,"toplevel cpu pipelineDAddr", false,-1, 9,0);
        tracep->declBus(c+12,"toplevel cpu pipelineIAddr", false,-1, 12,0);
        tracep->declBus(c+13,"toplevel cpu byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+239,"toplevel cpu pipelineDataIn", false,-1, 31,0);
        tracep->declBus(c+14,"toplevel cpu pipelineDataOut", false,-1, 31,0);
        tracep->declBus(c+240,"toplevel cpu pipelineInstrIn", false,-1, 31,0);
        tracep->declBus(c+15,"toplevel cpu iblockAddr", false,-1, 8,0);
        tracep->declBus(c+16,"toplevel cpu dblockAddr", false,-1, 5,0);
        tracep->declBit(c+241,"toplevel cpu icacheRen", false,-1);
        tracep->declBit(c+17,"toplevel cpu icacheMemWen", false,-1);
        tracep->declBit(c+242,"toplevel cpu icacheHit", false,-1);
        tracep->declArray(c+243,"toplevel cpu icacheDin", false,-1, 127,0);
        tracep->declArray(c+247,"toplevel cpu icacheDout", false,-1, 127,0);
        tracep->declBit(c+251,"toplevel cpu dcacheRen", false,-1);
        tracep->declBit(c+252,"toplevel cpu dcacheWen", false,-1);
        tracep->declBit(c+18,"toplevel cpu dcacheMemWen", false,-1);
        tracep->declBit(c+253,"toplevel cpu dcacheHit", false,-1);
        tracep->declBit(c+254,"toplevel cpu dcacheDirtyBit", false,-1);
        tracep->declArray(c+255,"toplevel cpu dcacheDin", false,-1, 127,0);
        tracep->declArray(c+234,"toplevel cpu dcacheDout", false,-1, 127,0);
        tracep->declBus(c+259,"toplevel cpu bytesAccess", false,-1, 15,0);
        tracep->declBit(c+317,"toplevel cpu pipeline clock", false,-1);
        tracep->declBit(c+318,"toplevel cpu pipeline reset", false,-1);
        tracep->declBit(c+7,"toplevel cpu pipeline dcache_stall", false,-1);
        tracep->declBit(c+8,"toplevel cpu pipeline icache_stall", false,-1);
        tracep->declBus(c+239,"toplevel cpu pipeline data_input", false,-1, 31,0);
        tracep->declBus(c+240,"toplevel cpu pipeline instruction_input", false,-1, 31,0);
        tracep->declBit(c+9,"toplevel cpu pipeline dcache_ren", false,-1);
        tracep->declBit(c+10,"toplevel cpu pipeline dcache_wen", false,-1);
        tracep->declBit(c+238,"toplevel cpu pipeline icache_ren", false,-1);
        tracep->declBus(c+11,"toplevel cpu pipeline dcache_addr", false,-1, 9,0);
        tracep->declBus(c+12,"toplevel cpu pipeline icache_addr", false,-1, 12,0);
        tracep->declBus(c+13,"toplevel cpu pipeline byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+14,"toplevel cpu pipeline data_output", false,-1, 31,0);
        tracep->declBus(c+240,"toplevel cpu pipeline IFID_instr", false,-1, 31,0);
        tracep->declBus(c+19,"toplevel cpu pipeline PC", false,-1, 31,0);
        tracep->declBus(c+20,"toplevel cpu pipeline IFID_PC", false,-1, 31,0);
        tracep->declBus(c+21,"toplevel cpu pipeline IDEX_PC", false,-1, 31,0);
        tracep->declBus(c+22,"toplevel cpu pipeline PCplus4", false,-1, 31,0);
        tracep->declBus(c+216,"toplevel cpu pipeline JumpAddress", false,-1, 31,0);
        tracep->declBus(c+217,"toplevel cpu pipeline PC_new", false,-1, 31,0);
        tracep->declBit(c+260,"toplevel cpu pipeline inA_is_PC", false,-1);
        tracep->declBit(c+23,"toplevel cpu pipeline branch_taken", false,-1);
        tracep->declBus(c+218,"toplevel cpu pipeline BranchInA", false,-1, 31,0);
        tracep->declBus(c+24,"toplevel cpu pipeline IDEX_signExtend", false,-1, 31,0);
        tracep->declBus(c+261,"toplevel cpu pipeline signExtend", false,-1, 31,0);
        tracep->declBus(c+219,"toplevel cpu pipeline rdA", false,-1, 31,0);
        tracep->declBus(c+220,"toplevel cpu pipeline rdB", false,-1, 31,0);
        tracep->declBus(c+25,"toplevel cpu pipeline IDEX_rdA", false,-1, 31,0);
        tracep->declBus(c+26,"toplevel cpu pipeline IDEX_rdB", false,-1, 31,0);
        tracep->declBus(c+27,"toplevel cpu pipeline IDEX_funct3", false,-1, 2,0);
        tracep->declBus(c+28,"toplevel cpu pipeline IDEX_funct7", false,-1, 6,0);
        tracep->declBus(c+29,"toplevel cpu pipeline IDEX_instr_rs2", false,-1, 4,0);
        tracep->declBus(c+30,"toplevel cpu pipeline IDEX_instr_rs1", false,-1, 4,0);
        tracep->declBus(c+31,"toplevel cpu pipeline IDEX_instr_rd", false,-1, 4,0);
        tracep->declBit(c+32,"toplevel cpu pipeline IDEX_RegDst", false,-1);
        tracep->declBit(c+33,"toplevel cpu pipeline IDEX_ALUSrc", false,-1);
        tracep->declBit(c+34,"toplevel cpu pipeline IDEX_inA_is_PC", false,-1);
        tracep->declBit(c+35,"toplevel cpu pipeline IDEX_Jump", false,-1);
        tracep->declBit(c+36,"toplevel cpu pipeline IDEX_JumpJALR", false,-1);
        tracep->declBus(c+37,"toplevel cpu pipeline IDEX_ALUcntrl", false,-1, 2,0);
        tracep->declBit(c+38,"toplevel cpu pipeline IDEX_MemRead", false,-1);
        tracep->declBit(c+39,"toplevel cpu pipeline IDEX_MemWrite", false,-1);
        tracep->declBit(c+40,"toplevel cpu pipeline IDEX_MemToReg", false,-1);
        tracep->declBit(c+41,"toplevel cpu pipeline IDEX_RegWrite", false,-1);
        tracep->declBus(c+42,"toplevel cpu pipeline EXMEM_funct3", false,-1, 2,0);
        tracep->declBus(c+43,"toplevel cpu pipeline MEMWB_funct3", false,-1, 2,0);
        tracep->declBus(c+44,"toplevel cpu pipeline EXMEM_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+45,"toplevel cpu pipeline EXMEM_ALUOut", false,-1, 31,0);
        tracep->declBus(c+46,"toplevel cpu pipeline EXMEM_BranchALUOut", false,-1, 31,0);
        tracep->declBit(c+47,"toplevel cpu pipeline EXMEM_Zero", false,-1);
        tracep->declBit(c+48,"toplevel cpu pipeline EXMEM_JumpJALR", false,-1);
        tracep->declBus(c+13,"toplevel cpu pipeline byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+49,"toplevel cpu pipeline EXMEM_MemWriteData", false,-1, 31,0);
        tracep->declBus(c+14,"toplevel cpu pipeline MemWriteData", false,-1, 31,0);
        tracep->declBit(c+9,"toplevel cpu pipeline EXMEM_MemRead", false,-1);
        tracep->declBit(c+10,"toplevel cpu pipeline EXMEM_MemWrite", false,-1);
        tracep->declBit(c+50,"toplevel cpu pipeline EXMEM_RegWrite", false,-1);
        tracep->declBit(c+51,"toplevel cpu pipeline EXMEM_MemToReg", false,-1);
        tracep->declBus(c+239,"toplevel cpu pipeline MEMWB_DMemOut", false,-1, 31,0);
        tracep->declBus(c+52,"toplevel cpu pipeline MEMWB_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+53,"toplevel cpu pipeline MEMWB_ALUOut", false,-1, 31,0);
        tracep->declBit(c+54,"toplevel cpu pipeline MEMWB_MemToReg", false,-1);
        tracep->declBit(c+55,"toplevel cpu pipeline MEMWB_RegWrite", false,-1);
        tracep->declBus(c+262,"toplevel cpu pipeline ALUInA", false,-1, 31,0);
        tracep->declBus(c+263,"toplevel cpu pipeline ALUInB", false,-1, 31,0);
        tracep->declBus(c+264,"toplevel cpu pipeline ALUOut", false,-1, 31,0);
        tracep->declBus(c+221,"toplevel cpu pipeline BranchALUOut", false,-1, 31,0);
        tracep->declBus(c+265,"toplevel cpu pipeline bypassOutA", false,-1, 31,0);
        tracep->declBus(c+266,"toplevel cpu pipeline bypassOutB", false,-1, 31,0);
        tracep->declBus(c+324,"toplevel cpu pipeline DMemOut", false,-1, 31,0);
        tracep->declBus(c+222,"toplevel cpu pipeline MemOut", false,-1, 31,0);
        tracep->declBus(c+267,"toplevel cpu pipeline wRegData", false,-1, 31,0);
        tracep->declBit(c+268,"toplevel cpu pipeline Zero", false,-1);
        tracep->declBit(c+269,"toplevel cpu pipeline RegDst", false,-1);
        tracep->declBit(c+270,"toplevel cpu pipeline MemRead", false,-1);
        tracep->declBit(c+271,"toplevel cpu pipeline MemWrite", false,-1);
        tracep->declBit(c+272,"toplevel cpu pipeline MemToReg", false,-1);
        tracep->declBit(c+273,"toplevel cpu pipeline ALUSrc", false,-1);
        tracep->declBit(c+56,"toplevel cpu pipeline PCSrc", false,-1);
        tracep->declBit(c+274,"toplevel cpu pipeline RegWrite", false,-1);
        tracep->declBit(c+275,"toplevel cpu pipeline Jump", false,-1);
        tracep->declBit(c+276,"toplevel cpu pipeline JumpJALR", false,-1);
        tracep->declBit(c+277,"toplevel cpu pipeline Branch", false,-1);
        tracep->declBit(c+57,"toplevel cpu pipeline IDEX_Branch", false,-1);
        tracep->declBit(c+58,"toplevel cpu pipeline EXMEM_Branch", false,-1);
        tracep->declBit(c+278,"toplevel cpu pipeline bubble_ifid", false,-1);
        tracep->declBit(c+279,"toplevel cpu pipeline bubble_idex", false,-1);
        tracep->declBit(c+59,"toplevel cpu pipeline bubble_exmem", false,-1);
        tracep->declBit(c+238,"toplevel cpu pipeline write_ifid", false,-1);
        tracep->declBit(c+325,"toplevel cpu pipeline write_idex", false,-1);
        tracep->declBit(c+325,"toplevel cpu pipeline write_exmem", false,-1);
        tracep->declBit(c+325,"toplevel cpu pipeline write_memwb", false,-1);
        tracep->declBit(c+280,"toplevel cpu pipeline write_pc", false,-1);
        tracep->declBus(c+281,"toplevel cpu pipeline opcode", false,-1, 6,0);
        tracep->declBus(c+282,"toplevel cpu pipeline funct3", false,-1, 2,0);
        tracep->declBus(c+283,"toplevel cpu pipeline ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+284,"toplevel cpu pipeline funct7", false,-1, 6,0);
        tracep->declBus(c+285,"toplevel cpu pipeline instr_rs1", false,-1, 4,0);
        tracep->declBus(c+286,"toplevel cpu pipeline instr_rs2", false,-1, 4,0);
        tracep->declBus(c+287,"toplevel cpu pipeline instr_rd", false,-1, 4,0);
        tracep->declBus(c+60,"toplevel cpu pipeline RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+61,"toplevel cpu pipeline ALUOp", false,-1, 3,0);
        tracep->declBus(c+62,"toplevel cpu pipeline bypassA", false,-1, 1,0);
        tracep->declBus(c+63,"toplevel cpu pipeline bypassB", false,-1, 1,0);
        tracep->declBus(c+288,"toplevel cpu pipeline imm_i", false,-1, 31,0);
        tracep->declBus(c+289,"toplevel cpu pipeline imm_s", false,-1, 31,0);
        tracep->declBus(c+290,"toplevel cpu pipeline imm_b", false,-1, 31,0);
        tracep->declBus(c+291,"toplevel cpu pipeline imm_u", false,-1, 31,0);
        tracep->declBus(c+292,"toplevel cpu pipeline imm_j", false,-1, 31,0);
        tracep->declBit(c+293,"toplevel cpu pipeline overflow", false,-1);
        tracep->declBit(c+64,"toplevel cpu pipeline stall_from_cache", false,-1);
        tracep->declBus(c+294,"toplevel cpu pipeline signExtendUnit instr", false,-1, 24,0);
        tracep->declBus(c+288,"toplevel cpu pipeline signExtendUnit imm_i", false,-1, 31,0);
        tracep->declBus(c+289,"toplevel cpu pipeline signExtendUnit imm_s", false,-1, 31,0);
        tracep->declBus(c+290,"toplevel cpu pipeline signExtendUnit imm_b", false,-1, 31,0);
        tracep->declBus(c+291,"toplevel cpu pipeline signExtendUnit imm_u", false,-1, 31,0);
        tracep->declBus(c+292,"toplevel cpu pipeline signExtendUnit imm_j", false,-1, 31,0);
        tracep->declBit(c+317,"toplevel cpu pipeline cpu_regs clock", false,-1);
        tracep->declBit(c+318,"toplevel cpu pipeline cpu_regs reset", false,-1);
        tracep->declBus(c+285,"toplevel cpu pipeline cpu_regs raA", false,-1, 4,0);
        tracep->declBus(c+286,"toplevel cpu pipeline cpu_regs raB", false,-1, 4,0);
        tracep->declBus(c+52,"toplevel cpu pipeline cpu_regs wa", false,-1, 4,0);
        tracep->declBit(c+55,"toplevel cpu pipeline cpu_regs wen", false,-1);
        tracep->declBus(c+267,"toplevel cpu pipeline cpu_regs wd", false,-1, 31,0);
        tracep->declBus(c+219,"toplevel cpu pipeline cpu_regs rdA", false,-1, 31,0);
        tracep->declBus(c+220,"toplevel cpu pipeline cpu_regs rdB", false,-1, 31,0);
        tracep->declBus(c+65,"toplevel cpu pipeline cpu_regs i", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+66+i*1,"toplevel cpu pipeline cpu_regs data", true,(i+0), 31,0);}}
        tracep->declBus(c+261,"toplevel cpu pipeline SignExtendSelector out", false,-1, 31,0);
        tracep->declBus(c+288,"toplevel cpu pipeline SignExtendSelector imm_i", false,-1, 31,0);
        tracep->declBus(c+289,"toplevel cpu pipeline SignExtendSelector imm_s", false,-1, 31,0);
        tracep->declBus(c+290,"toplevel cpu pipeline SignExtendSelector imm_b", false,-1, 31,0);
        tracep->declBus(c+291,"toplevel cpu pipeline SignExtendSelector imm_u", false,-1, 31,0);
        tracep->declBus(c+292,"toplevel cpu pipeline SignExtendSelector imm_j", false,-1, 31,0);
        tracep->declBus(c+281,"toplevel cpu pipeline SignExtendSelector opcode", false,-1, 6,0);
        tracep->declBit(c+269,"toplevel cpu pipeline control_main RegDst", false,-1);
        tracep->declBit(c+277,"toplevel cpu pipeline control_main Branch", false,-1);
        tracep->declBit(c+270,"toplevel cpu pipeline control_main MemRead", false,-1);
        tracep->declBit(c+271,"toplevel cpu pipeline control_main MemWrite", false,-1);
        tracep->declBit(c+272,"toplevel cpu pipeline control_main MemToReg", false,-1);
        tracep->declBit(c+273,"toplevel cpu pipeline control_main ALUSrc", false,-1);
        tracep->declBit(c+274,"toplevel cpu pipeline control_main RegWrite", false,-1);
        tracep->declBit(c+275,"toplevel cpu pipeline control_main Jump", false,-1);
        tracep->declBit(c+276,"toplevel cpu pipeline control_main JumpJALR", false,-1);
        tracep->declBit(c+260,"toplevel cpu pipeline control_main inA_is_PC", false,-1);
        tracep->declBus(c+283,"toplevel cpu pipeline control_main ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+281,"toplevel cpu pipeline control_main opcode", false,-1, 6,0);
        tracep->declBit(c+278,"toplevel cpu pipeline control_stall_id bubble_ifid", false,-1);
        tracep->declBit(c+279,"toplevel cpu pipeline control_stall_id bubble_idex", false,-1);
        tracep->declBit(c+59,"toplevel cpu pipeline control_stall_id bubble_exmem", false,-1);
        tracep->declBit(c+238,"toplevel cpu pipeline control_stall_id write_ifid", false,-1);
        tracep->declBit(c+325,"toplevel cpu pipeline control_stall_id write_idex", false,-1);
        tracep->declBit(c+325,"toplevel cpu pipeline control_stall_id write_exmem", false,-1);
        tracep->declBit(c+325,"toplevel cpu pipeline control_stall_id write_memwb", false,-1);
        tracep->declBit(c+280,"toplevel cpu pipeline control_stall_id write_pc", false,-1);
        tracep->declBus(c+285,"toplevel cpu pipeline control_stall_id ifid_rs", false,-1, 4,0);
        tracep->declBus(c+286,"toplevel cpu pipeline control_stall_id ifid_rt", false,-1, 4,0);
        tracep->declBus(c+31,"toplevel cpu pipeline control_stall_id idex_rd", false,-1, 4,0);
        tracep->declBit(c+38,"toplevel cpu pipeline control_stall_id idex_memread", false,-1);
        tracep->declBit(c+275,"toplevel cpu pipeline control_stall_id Jump", false,-1);
        tracep->declBit(c+56,"toplevel cpu pipeline control_stall_id PCSrc", false,-1);
        tracep->declBus(c+326,"toplevel cpu pipeline cpu_alu N", false,-1, 31,0);
        tracep->declBus(c+264,"toplevel cpu pipeline cpu_alu out", false,-1, 31,0);
        tracep->declBit(c+268,"toplevel cpu pipeline cpu_alu zero", false,-1);
        tracep->declBit(c+293,"toplevel cpu pipeline cpu_alu overflow", false,-1);
        tracep->declBus(c+262,"toplevel cpu pipeline cpu_alu inA", false,-1, 31,0);
        tracep->declBus(c+263,"toplevel cpu pipeline cpu_alu inB", false,-1, 31,0);
        tracep->declBus(c+61,"toplevel cpu pipeline cpu_alu op", false,-1, 3,0);
        tracep->declBus(c+264,"toplevel cpu pipeline cpu_alu out_val", false,-1, 31,0);
        tracep->declQuad(c+295,"toplevel cpu pipeline cpu_alu unsigned_sub", false,-1, 32,0);
        tracep->declBus(c+61,"toplevel cpu pipeline control_alu ALUOp", false,-1, 3,0);
        tracep->declBus(c+37,"toplevel cpu pipeline control_alu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+27,"toplevel cpu pipeline control_alu funct3", false,-1, 2,0);
        tracep->declBus(c+28,"toplevel cpu pipeline control_alu funct7", false,-1, 6,0);
        tracep->declBus(c+62,"toplevel cpu pipeline control_bypass_ex bypassA", false,-1, 1,0);
        tracep->declBus(c+63,"toplevel cpu pipeline control_bypass_ex bypassB", false,-1, 1,0);
        tracep->declBus(c+30,"toplevel cpu pipeline control_bypass_ex idex_rs1", false,-1, 4,0);
        tracep->declBus(c+29,"toplevel cpu pipeline control_bypass_ex idex_rs2", false,-1, 4,0);
        tracep->declBus(c+44,"toplevel cpu pipeline control_bypass_ex exmem_rd", false,-1, 4,0);
        tracep->declBus(c+52,"toplevel cpu pipeline control_bypass_ex memwb_rd", false,-1, 4,0);
        tracep->declBit(c+50,"toplevel cpu pipeline control_bypass_ex exmem_regwrite", false,-1);
        tracep->declBit(c+55,"toplevel cpu pipeline control_bypass_ex memwb_regwrite", false,-1);
        tracep->declBus(c+42,"toplevel cpu pipeline mem_write_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+49,"toplevel cpu pipeline mem_write_selector ALUin", false,-1, 31,0);
        tracep->declBus(c+98,"toplevel cpu pipeline mem_write_selector offset", false,-1, 1,0);
        tracep->declBus(c+13,"toplevel cpu pipeline mem_write_selector byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+14,"toplevel cpu pipeline mem_write_selector out", false,-1, 31,0);
        tracep->declBit(c+23,"toplevel cpu pipeline control_branch branch_taken", false,-1);
        tracep->declBus(c+42,"toplevel cpu pipeline control_branch funct3", false,-1, 2,0);
        tracep->declBit(c+58,"toplevel cpu pipeline control_branch Branch", false,-1);
        tracep->declBit(c+47,"toplevel cpu pipeline control_branch zero", false,-1);
        tracep->declBit(c+99,"toplevel cpu pipeline control_branch sign", false,-1);
        tracep->declBus(c+43,"toplevel cpu pipeline mem_read_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+239,"toplevel cpu pipeline mem_read_selector DMemOut", false,-1, 31,0);
        tracep->declBus(c+100,"toplevel cpu pipeline mem_read_selector byte_index", false,-1, 1,0);
        tracep->declBus(c+222,"toplevel cpu pipeline mem_read_selector out", false,-1, 31,0);
        tracep->declBus(c+297,"toplevel cpu pipeline mem_read_selector byte_sel", false,-1, 7,0);
        tracep->declBus(c+298,"toplevel cpu pipeline mem_read_selector half", false,-1, 15,0);
        tracep->declBit(c+317,"toplevel cpu icachecontroller2check clock", false,-1);
        tracep->declBit(c+318,"toplevel cpu icachecontroller2check reset", false,-1);
        tracep->declBit(c+238,"toplevel cpu icachecontroller2check ren", false,-1);
        tracep->declBus(c+12,"toplevel cpu icachecontroller2check addr", false,-1, 12,0);
        tracep->declBit(c+242,"toplevel cpu icachecontroller2check cacheHit", false,-1);
        tracep->declArray(c+247,"toplevel cpu icachecontroller2check cacheDout", false,-1, 127,0);
        tracep->declBit(c+6,"toplevel cpu icachecontroller2check memReadReady", false,-1);
        tracep->declArray(c+227,"toplevel cpu icachecontroller2check memDout", false,-1, 127,0);
        tracep->declBit(c+8,"toplevel cpu icachecontroller2check stall", false,-1);
        tracep->declBus(c+240,"toplevel cpu icachecontroller2check dout", false,-1, 31,0);
        tracep->declBus(c+15,"toplevel cpu icachecontroller2check BlockAddr", false,-1, 8,0);
        tracep->declBit(c+241,"toplevel cpu icachecontroller2check cacheRen", false,-1);
        tracep->declBit(c+17,"toplevel cpu icachecontroller2check cacheMemWen", false,-1);
        tracep->declArray(c+243,"toplevel cpu icachecontroller2check cacheDin", false,-1, 127,0);
        tracep->declBit(c+5,"toplevel cpu icachecontroller2check memRen", false,-1);
        tracep->declBus(c+101,"toplevel cpu icachecontroller2check blockOffset", false,-1, 3,0);
        tracep->declBus(c+327,"toplevel cpu icachecontroller2check IDLE", false,-1, 1,0);
        tracep->declBus(c+328,"toplevel cpu icachecontroller2check MEMREAD", false,-1, 1,0);
        tracep->declBus(c+329,"toplevel cpu icachecontroller2check MEMCACHE", false,-1, 1,0);
        tracep->declBus(c+102,"toplevel cpu icachecontroller2check state", false,-1, 1,0);
        tracep->declBus(c+223,"toplevel cpu icachecontroller2check next_state", false,-1, 1,0);
        tracep->declBit(c+317,"toplevel cpu Icache clk", false,-1);
        tracep->declBit(c+318,"toplevel cpu Icache rst", false,-1);
        tracep->declBit(c+241,"toplevel cpu Icache ren", false,-1);
        tracep->declBit(c+17,"toplevel cpu Icache memWen", false,-1);
        tracep->declArray(c+243,"toplevel cpu Icache dataIn", false,-1, 127,0);
        tracep->declBus(c+15,"toplevel cpu Icache blockAddr", false,-1, 8,0);
        tracep->declBit(c+242,"toplevel cpu Icache hit", false,-1);
        tracep->declArray(c+247,"toplevel cpu Icache dataOut", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+103+i*1,"toplevel cpu Icache valid_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+107+i*1,"toplevel cpu Icache status_col", true,(i+0), 1,0);}}
        tracep->declBus(c+111,"toplevel cpu Icache tag_col(0)(0)", false,-1, 6,0);
        tracep->declBus(c+112,"toplevel cpu Icache tag_col(0)(1)", false,-1, 6,0);
        tracep->declBus(c+113,"toplevel cpu Icache tag_col(1)(0)", false,-1, 6,0);
        tracep->declBus(c+114,"toplevel cpu Icache tag_col(1)(1)", false,-1, 6,0);
        tracep->declBus(c+115,"toplevel cpu Icache tag_col(2)(0)", false,-1, 6,0);
        tracep->declBus(c+116,"toplevel cpu Icache tag_col(2)(1)", false,-1, 6,0);
        tracep->declBus(c+117,"toplevel cpu Icache tag_col(3)(0)", false,-1, 6,0);
        tracep->declBus(c+118,"toplevel cpu Icache tag_col(3)(1)", false,-1, 6,0);
        tracep->declArray(c+119,"toplevel cpu Icache data_col(0)(0)", false,-1, 127,0);
        tracep->declArray(c+123,"toplevel cpu Icache data_col(0)(1)", false,-1, 127,0);
        tracep->declArray(c+127,"toplevel cpu Icache data_col(1)(0)", false,-1, 127,0);
        tracep->declArray(c+131,"toplevel cpu Icache data_col(1)(1)", false,-1, 127,0);
        tracep->declArray(c+135,"toplevel cpu Icache data_col(2)(0)", false,-1, 127,0);
        tracep->declArray(c+139,"toplevel cpu Icache data_col(2)(1)", false,-1, 127,0);
        tracep->declArray(c+143,"toplevel cpu Icache data_col(3)(0)", false,-1, 127,0);
        tracep->declArray(c+147,"toplevel cpu Icache data_col(3)(1)", false,-1, 127,0);
        tracep->declBus(c+151,"toplevel cpu Icache index", false,-1, 1,0);
        tracep->declBus(c+152,"toplevel cpu Icache tag", false,-1, 6,0);
        tracep->declBus(c+224,"toplevel cpu Icache i", false,-1, 31,0);
        tracep->declBus(c+153,"toplevel cpu Icache j", false,-1, 31,0);
        tracep->declBus(c+299,"toplevel cpu Icache hitReg", false,-1, 1,0);
        tracep->declBus(c+300,"toplevel cpu Icache blockToEvict", false,-1, 1,0);
        tracep->declBus(c+301,"toplevel cpu Icache mask", false,-1, 1,0);
        tracep->declBus(c+154,"toplevel cpu Icache statusFullOne", false,-1, 1,0);
        tracep->declBit(c+317,"toplevel cpu Dcntr clock", false,-1);
        tracep->declBit(c+318,"toplevel cpu Dcntr reset", false,-1);
        tracep->declBit(c+9,"toplevel cpu Dcntr ren", false,-1);
        tracep->declBit(c+10,"toplevel cpu Dcntr wen", false,-1);
        tracep->declBus(c+11,"toplevel cpu Dcntr addr", false,-1, 9,0);
        tracep->declBus(c+13,"toplevel cpu Dcntr byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+14,"toplevel cpu Dcntr din", false,-1, 31,0);
        tracep->declBit(c+253,"toplevel cpu Dcntr cacheHit", false,-1);
        tracep->declBit(c+254,"toplevel cpu Dcntr cacheDirtyBit", false,-1);
        tracep->declArray(c+234,"toplevel cpu Dcntr cacheDout", false,-1, 127,0);
        tracep->declBit(c+3,"toplevel cpu Dcntr memReadReady", false,-1);
        tracep->declBit(c+4,"toplevel cpu Dcntr memWriteDone", false,-1);
        tracep->declArray(c+307,"toplevel cpu Dcntr memDout", false,-1, 127,0);
        tracep->declBit(c+7,"toplevel cpu Dcntr stall", false,-1);
        tracep->declBus(c+239,"toplevel cpu Dcntr dout", false,-1, 31,0);
        tracep->declBus(c+16,"toplevel cpu Dcntr BlockAddr", false,-1, 5,0);
        tracep->declBit(c+251,"toplevel cpu Dcntr cacheRen", false,-1);
        tracep->declBit(c+252,"toplevel cpu Dcntr cacheWen", false,-1);
        tracep->declBit(c+18,"toplevel cpu Dcntr cacheMemWen", false,-1);
        tracep->declBus(c+259,"toplevel cpu Dcntr cacheBytesAccess", false,-1, 15,0);
        tracep->declArray(c+255,"toplevel cpu Dcntr cacheDin", false,-1, 127,0);
        tracep->declBit(c+1,"toplevel cpu Dcntr memRen", false,-1);
        tracep->declBit(c+2,"toplevel cpu Dcntr memWen", false,-1);
        tracep->declArray(c+234,"toplevel cpu Dcntr memDin", false,-1, 127,0);
        tracep->declBit(c+155,"toplevel cpu Dcntr pipeline_req", false,-1);
        tracep->declBit(c+156,"toplevel cpu Dcntr replace", false,-1);
        tracep->declBus(c+157,"toplevel cpu Dcntr blockOffset", false,-1, 3,0);
        tracep->declBus(c+330,"toplevel cpu Dcntr IDLE", false,-1, 2,0);
        tracep->declBus(c+331,"toplevel cpu Dcntr WRITEBACK", false,-1, 2,0);
        tracep->declBus(c+332,"toplevel cpu Dcntr MEMREAD", false,-1, 2,0);
        tracep->declBus(c+333,"toplevel cpu Dcntr MEMCACHE", false,-1, 2,0);
        tracep->declBus(c+334,"toplevel cpu Dcntr WRITEBACK_REPLACE", false,-1, 2,0);
        tracep->declBus(c+158,"toplevel cpu Dcntr state", false,-1, 2,0);
        tracep->declBus(c+225,"toplevel cpu Dcntr next_state", false,-1, 2,0);
        tracep->declBit(c+317,"toplevel cpu Dcache clk", false,-1);
        tracep->declBit(c+318,"toplevel cpu Dcache rst", false,-1);
        tracep->declBit(c+251,"toplevel cpu Dcache ren", false,-1);
        tracep->declBit(c+252,"toplevel cpu Dcache wen", false,-1);
        tracep->declBit(c+18,"toplevel cpu Dcache memWen", false,-1);
        tracep->declBus(c+259,"toplevel cpu Dcache bytesAccess", false,-1, 15,0);
        tracep->declBus(c+16,"toplevel cpu Dcache blockAddr", false,-1, 5,0);
        tracep->declArray(c+255,"toplevel cpu Dcache dataIn", false,-1, 127,0);
        tracep->declBit(c+253,"toplevel cpu Dcache hit", false,-1);
        tracep->declBit(c+254,"toplevel cpu Dcache dirtyBit", false,-1);
        tracep->declArray(c+234,"toplevel cpu Dcache dataOut", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+159+i*1,"toplevel cpu Dcache valid_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+163+i*1,"toplevel cpu Dcache dirty_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+167+i*1,"toplevel cpu Dcache status_col", true,(i+0), 1,0);}}
        tracep->declBus(c+171,"toplevel cpu Dcache tag_col(0)(0)", false,-1, 3,0);
        tracep->declBus(c+172,"toplevel cpu Dcache tag_col(0)(1)", false,-1, 3,0);
        tracep->declBus(c+173,"toplevel cpu Dcache tag_col(1)(0)", false,-1, 3,0);
        tracep->declBus(c+174,"toplevel cpu Dcache tag_col(1)(1)", false,-1, 3,0);
        tracep->declBus(c+175,"toplevel cpu Dcache tag_col(2)(0)", false,-1, 3,0);
        tracep->declBus(c+176,"toplevel cpu Dcache tag_col(2)(1)", false,-1, 3,0);
        tracep->declBus(c+177,"toplevel cpu Dcache tag_col(3)(0)", false,-1, 3,0);
        tracep->declBus(c+178,"toplevel cpu Dcache tag_col(3)(1)", false,-1, 3,0);
        tracep->declArray(c+179,"toplevel cpu Dcache data_col(0)(0)", false,-1, 127,0);
        tracep->declArray(c+183,"toplevel cpu Dcache data_col(0)(1)", false,-1, 127,0);
        tracep->declArray(c+187,"toplevel cpu Dcache data_col(1)(0)", false,-1, 127,0);
        tracep->declArray(c+191,"toplevel cpu Dcache data_col(1)(1)", false,-1, 127,0);
        tracep->declArray(c+195,"toplevel cpu Dcache data_col(2)(0)", false,-1, 127,0);
        tracep->declArray(c+199,"toplevel cpu Dcache data_col(2)(1)", false,-1, 127,0);
        tracep->declArray(c+203,"toplevel cpu Dcache data_col(3)(0)", false,-1, 127,0);
        tracep->declArray(c+207,"toplevel cpu Dcache data_col(3)(1)", false,-1, 127,0);
        tracep->declBus(c+211,"toplevel cpu Dcache index", false,-1, 1,0);
        tracep->declBus(c+212,"toplevel cpu Dcache tag", false,-1, 3,0);
        tracep->declBus(c+226,"toplevel cpu Dcache i", false,-1, 31,0);
        tracep->declBus(c+213,"toplevel cpu Dcache j", false,-1, 31,0);
        tracep->declBus(c+302,"toplevel cpu Dcache hitReg", false,-1, 1,0);
        tracep->declBus(c+303,"toplevel cpu Dcache blockToEvict", false,-1, 1,0);
        tracep->declBus(c+304,"toplevel cpu Dcache mask", false,-1, 1,0);
        tracep->declBus(c+214,"toplevel cpu Dcache statusFullOne", false,-1, 1,0);
        tracep->declBit(c+317,"toplevel Instruction_Mem clock", false,-1);
        tracep->declBit(c+318,"toplevel Instruction_Mem reset", false,-1);
        tracep->declBit(c+5,"toplevel Instruction_Mem ren", false,-1);
        tracep->declBus(c+323,"toplevel Instruction_Mem block_address", false,-1, 8,0);
        tracep->declBit(c+6,"toplevel Instruction_Mem ready", false,-1);
        tracep->declArray(c+227,"toplevel Instruction_Mem dout", false,-1, 127,0);
        tracep->declBit(c+231,"toplevel Instruction_Mem delayed", false,-1);
        tracep->declBit(c+305,"toplevel Instruction_Mem counter_reset", false,-1);
        tracep->declBus(c+232,"toplevel Instruction_Mem delay_counter", false,-1, 3,0);
        tracep->declBus(c+233,"toplevel Instruction_Mem i", false,-1, 31,0);
        tracep->declBus(c+335,"toplevel Instruction_Mem delay_cntr size", false,-1, 31,0);
        tracep->declBit(c+305,"toplevel Instruction_Mem delay_cntr reset", false,-1);
        tracep->declBit(c+317,"toplevel Instruction_Mem delay_cntr clk", false,-1);
        tracep->declBit(c+231,"toplevel Instruction_Mem delay_cntr hold", false,-1);
        tracep->declBus(c+232,"toplevel Instruction_Mem delay_cntr counter", false,-1, 3,0);
        tracep->declBit(c+317,"toplevel Data_Mem clock", false,-1);
        tracep->declBit(c+318,"toplevel Data_Mem reset", false,-1);
        tracep->declBit(c+1,"toplevel Data_Mem ren", false,-1);
        tracep->declBit(c+2,"toplevel Data_Mem wen", false,-1);
        tracep->declBus(c+322,"toplevel Data_Mem block_address", false,-1, 5,0);
        tracep->declArray(c+234,"toplevel Data_Mem din", false,-1, 127,0);
        tracep->declBit(c+3,"toplevel Data_Mem ready", false,-1);
        tracep->declBit(c+4,"toplevel Data_Mem done", false,-1);
        tracep->declArray(c+307,"toplevel Data_Mem dout", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+313+i*1,"toplevel Data_Mem temp_din", true,(i+0), 31,0);}}
        tracep->declBit(c+215,"toplevel Data_Mem flag", false,-1);
        tracep->declBit(c+319,"toplevel Data_Mem delayed", false,-1);
        tracep->declBit(c+306,"toplevel Data_Mem counter_reset", false,-1);
        tracep->declBus(c+320,"toplevel Data_Mem delay_counter", false,-1, 3,0);
        tracep->declBit(c+311,"toplevel Data_Mem temp_ready", false,-1);
        tracep->declBit(c+312,"toplevel Data_Mem temp_done", false,-1);
        tracep->declBus(c+321,"toplevel Data_Mem i", false,-1, 31,0);
        tracep->declBus(c+335,"toplevel Data_Mem delay_cntr size", false,-1, 31,0);
        tracep->declBit(c+306,"toplevel Data_Mem delay_cntr reset", false,-1);
        tracep->declBit(c+317,"toplevel Data_Mem delay_cntr clk", false,-1);
        tracep->declBit(c+319,"toplevel Data_Mem delay_cntr hold", false,-1);
        tracep->declBus(c+320,"toplevel Data_Mem delay_cntr counter", false,-1, 3,0);
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
    // Variables
    WData/*127:0*/ __Vtemp40[4];
    WData/*127:0*/ __Vtemp41[4];
    WData/*127:0*/ __Vtemp42[4];
    WData/*127:0*/ __Vtemp43[4];
    WData/*127:0*/ __Vtemp44[4];
    WData/*127:0*/ __Vtemp45[4];
    WData/*127:0*/ __Vtemp46[4];
    WData/*127:0*/ __Vtemp47[4];
    WData/*127:0*/ __Vtemp48[4];
    WData/*127:0*/ __Vtemp49[4];
    WData/*127:0*/ __Vtemp50[4];
    WData/*127:0*/ __Vtemp51[4];
    WData/*127:0*/ __Vtemp52[4];
    WData/*127:0*/ __Vtemp53[4];
    WData/*127:0*/ __Vtemp54[4];
    WData/*127:0*/ __Vtemp55[4];
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->toplevel__DOT__dmem_ren));
        tracep->fullBit(oldp+2,(vlTOPp->toplevel__DOT__dmem_wen));
        tracep->fullBit(oldp+3,(vlTOPp->toplevel__DOT__dmem_read_ready));
        tracep->fullBit(oldp+4,(vlTOPp->toplevel__DOT__dmem_write_done));
        tracep->fullBit(oldp+5,(vlTOPp->toplevel__DOT__imem_ren));
        tracep->fullBit(oldp+6,(vlTOPp->toplevel__DOT__imem_read_ready));
        tracep->fullBit(oldp+7,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheStall));
        tracep->fullBit(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__icacheStall));
        tracep->fullBit(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead));
        tracep->fullBit(oldp+10,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite));
        tracep->fullSData(oldp+11,((0x3ffU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),10);
        tracep->fullSData(oldp+12,((0x1fffU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),13);
        tracep->fullCData(oldp+13,((0xfU & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                             ? ((IData)(1U) 
                                                << 
                                                (3U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                             : ((1U 
                                                 == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                 ? 
                                                ((2U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                  ? 0xcU
                                                  : 3U)
                                                 : 0xfU)))),4);
        tracep->fullIData(oldp+14,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                     ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                         ? ((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                             ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                << 0x18U)
                                             : (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                << 0x10U))
                                         : ((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                             ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                << 8U)
                                             : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))
                                     : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                         ? ((0U == 
                                             (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                             ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                             : ((2U 
                                                 == 
                                                 (3U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                 ? 
                                                (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                 << 0x10U)
                                                 : 0U))
                                         : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))),32);
        tracep->fullSData(oldp+15,((0x1ffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                              >> 4U))),9);
        tracep->fullCData(oldp+16,((0x3fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                             >> 4U))),6);
        tracep->fullBit(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen));
        tracep->fullBit(oldp+18,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen));
        tracep->fullIData(oldp+19,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC),32);
        tracep->fullIData(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC),32);
        tracep->fullIData(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC),32);
        tracep->fullIData(oldp+22,(((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),32);
        tracep->fullBit(oldp+23,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
        tracep->fullIData(oldp+24,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend),32);
        tracep->fullIData(oldp+25,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA),32);
        tracep->fullIData(oldp+26,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB),32);
        tracep->fullCData(oldp+27,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3),3);
        tracep->fullCData(oldp+28,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7),7);
        tracep->fullCData(oldp+29,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2),5);
        tracep->fullCData(oldp+30,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1),5);
        tracep->fullCData(oldp+31,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd),5);
        tracep->fullBit(oldp+32,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst));
        tracep->fullBit(oldp+33,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc));
        tracep->fullBit(oldp+34,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC));
        tracep->fullBit(oldp+35,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump));
        tracep->fullBit(oldp+36,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR));
        tracep->fullCData(oldp+37,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl),3);
        tracep->fullBit(oldp+38,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead));
        tracep->fullBit(oldp+39,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite));
        tracep->fullBit(oldp+40,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg));
        tracep->fullBit(oldp+41,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite));
        tracep->fullCData(oldp+42,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3),3);
        tracep->fullCData(oldp+43,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3),3);
        tracep->fullCData(oldp+44,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr),5);
        tracep->fullIData(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut),32);
        tracep->fullIData(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut),32);
        tracep->fullBit(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero));
        tracep->fullBit(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR));
        tracep->fullIData(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData),32);
        tracep->fullBit(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
        tracep->fullBit(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
        tracep->fullCData(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr),5);
        tracep->fullIData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut),32);
        tracep->fullBit(oldp+54,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg));
        tracep->fullBit(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite));
        tracep->fullBit(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc));
        tracep->fullBit(oldp+57,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
        tracep->fullBit(oldp+58,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch));
        tracep->fullBit(oldp+59,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem));
        tracep->fullCData(oldp+60,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                                     ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                                     : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2))),5);
        tracep->fullCData(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp),4);
        tracep->fullCData(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA),2);
        tracep->fullCData(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB),2);
        tracep->fullBit(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache));
        tracep->fullIData(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i),32);
        tracep->fullIData(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0]),32);
        tracep->fullIData(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1]),32);
        tracep->fullIData(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2]),32);
        tracep->fullIData(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3]),32);
        tracep->fullIData(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4]),32);
        tracep->fullIData(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5]),32);
        tracep->fullIData(oldp+72,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6]),32);
        tracep->fullIData(oldp+73,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7]),32);
        tracep->fullIData(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8]),32);
        tracep->fullIData(oldp+75,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9]),32);
        tracep->fullIData(oldp+76,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[10]),32);
        tracep->fullIData(oldp+77,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[11]),32);
        tracep->fullIData(oldp+78,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[12]),32);
        tracep->fullIData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[13]),32);
        tracep->fullIData(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[14]),32);
        tracep->fullIData(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[15]),32);
        tracep->fullIData(oldp+82,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[16]),32);
        tracep->fullIData(oldp+83,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[17]),32);
        tracep->fullIData(oldp+84,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[18]),32);
        tracep->fullIData(oldp+85,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[19]),32);
        tracep->fullIData(oldp+86,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[20]),32);
        tracep->fullIData(oldp+87,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[21]),32);
        tracep->fullIData(oldp+88,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[22]),32);
        tracep->fullIData(oldp+89,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[23]),32);
        tracep->fullIData(oldp+90,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[24]),32);
        tracep->fullIData(oldp+91,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[25]),32);
        tracep->fullIData(oldp+92,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[26]),32);
        tracep->fullIData(oldp+93,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[27]),32);
        tracep->fullIData(oldp+94,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[28]),32);
        tracep->fullIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[29]),32);
        tracep->fullIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[30]),32);
        tracep->fullIData(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[31]),32);
        tracep->fullCData(oldp+98,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),2);
        tracep->fullBit(oldp+99,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                        >> 0x1fU))));
        tracep->fullCData(oldp+100,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)),2);
        tracep->fullCData(oldp+101,((0xfU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),4);
        tracep->fullCData(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state),2);
        tracep->fullCData(oldp+103,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0]),2);
        tracep->fullCData(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1]),2);
        tracep->fullCData(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2]),2);
        tracep->fullCData(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3]),2);
        tracep->fullCData(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0]),2);
        tracep->fullCData(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1]),2);
        tracep->fullCData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2]),2);
        tracep->fullCData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3]),2);
        tracep->fullCData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [0U][0U]),7);
        tracep->fullCData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [0U][1U]),7);
        tracep->fullCData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [1U][0U]),7);
        tracep->fullCData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [1U][1U]),7);
        tracep->fullCData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [2U][0U]),7);
        tracep->fullCData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [2U][1U]),7);
        tracep->fullCData(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [3U][0U]),7);
        tracep->fullCData(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [3U][1U]),7);
        __Vtemp40[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][0U];
        __Vtemp40[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][1U];
        __Vtemp40[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][2U];
        __Vtemp40[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][3U];
        tracep->fullWData(oldp+119,(__Vtemp40),128);
        __Vtemp41[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][0U];
        __Vtemp41[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][1U];
        __Vtemp41[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][2U];
        __Vtemp41[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][3U];
        tracep->fullWData(oldp+123,(__Vtemp41),128);
        __Vtemp42[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][0U];
        __Vtemp42[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][1U];
        __Vtemp42[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][2U];
        __Vtemp42[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][3U];
        tracep->fullWData(oldp+127,(__Vtemp42),128);
        __Vtemp43[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][0U];
        __Vtemp43[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][1U];
        __Vtemp43[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][2U];
        __Vtemp43[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][3U];
        tracep->fullWData(oldp+131,(__Vtemp43),128);
        __Vtemp44[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][0U];
        __Vtemp44[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][1U];
        __Vtemp44[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][2U];
        __Vtemp44[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][3U];
        tracep->fullWData(oldp+135,(__Vtemp44),128);
        __Vtemp45[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][0U];
        __Vtemp45[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][1U];
        __Vtemp45[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][2U];
        __Vtemp45[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][3U];
        tracep->fullWData(oldp+139,(__Vtemp45),128);
        __Vtemp46[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][0U];
        __Vtemp46[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][1U];
        __Vtemp46[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][2U];
        __Vtemp46[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][3U];
        tracep->fullWData(oldp+143,(__Vtemp46),128);
        __Vtemp47[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][0U];
        __Vtemp47[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][1U];
        __Vtemp47[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][2U];
        __Vtemp47[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][3U];
        tracep->fullWData(oldp+147,(__Vtemp47),128);
        tracep->fullCData(oldp+151,((3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                           >> 4U))),2);
        tracep->fullCData(oldp+152,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                              >> 6U))),7);
        tracep->fullIData(oldp+153,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j),32);
        tracep->fullCData(oldp+154,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne),2);
        tracep->fullBit(oldp+155,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead) 
                                    & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite))) 
                                   | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite) 
                                      & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead))))));
        tracep->fullBit(oldp+156,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__replace));
        tracep->fullCData(oldp+157,((0xfU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),4);
        tracep->fullCData(oldp+158,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state),3);
        tracep->fullCData(oldp+159,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0]),2);
        tracep->fullCData(oldp+160,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1]),2);
        tracep->fullCData(oldp+161,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2]),2);
        tracep->fullCData(oldp+162,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3]),2);
        tracep->fullCData(oldp+163,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0]),2);
        tracep->fullCData(oldp+164,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1]),2);
        tracep->fullCData(oldp+165,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2]),2);
        tracep->fullCData(oldp+166,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3]),2);
        tracep->fullCData(oldp+167,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0]),2);
        tracep->fullCData(oldp+168,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1]),2);
        tracep->fullCData(oldp+169,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2]),2);
        tracep->fullCData(oldp+170,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3]),2);
        tracep->fullCData(oldp+171,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [0U][0U]),4);
        tracep->fullCData(oldp+172,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [0U][1U]),4);
        tracep->fullCData(oldp+173,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [1U][0U]),4);
        tracep->fullCData(oldp+174,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [1U][1U]),4);
        tracep->fullCData(oldp+175,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [2U][0U]),4);
        tracep->fullCData(oldp+176,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [2U][1U]),4);
        tracep->fullCData(oldp+177,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [3U][0U]),4);
        tracep->fullCData(oldp+178,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [3U][1U]),4);
        __Vtemp48[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][0U];
        __Vtemp48[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][1U];
        __Vtemp48[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][2U];
        __Vtemp48[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][3U];
        tracep->fullWData(oldp+179,(__Vtemp48),128);
        __Vtemp49[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][0U];
        __Vtemp49[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][1U];
        __Vtemp49[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][2U];
        __Vtemp49[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][3U];
        tracep->fullWData(oldp+183,(__Vtemp49),128);
        __Vtemp50[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][0U];
        __Vtemp50[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][1U];
        __Vtemp50[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][2U];
        __Vtemp50[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][3U];
        tracep->fullWData(oldp+187,(__Vtemp50),128);
        __Vtemp51[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][0U];
        __Vtemp51[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][1U];
        __Vtemp51[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][2U];
        __Vtemp51[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][3U];
        tracep->fullWData(oldp+191,(__Vtemp51),128);
        __Vtemp52[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][0U];
        __Vtemp52[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][1U];
        __Vtemp52[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][2U];
        __Vtemp52[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][3U];
        tracep->fullWData(oldp+195,(__Vtemp52),128);
        __Vtemp53[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][0U];
        __Vtemp53[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][1U];
        __Vtemp53[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][2U];
        __Vtemp53[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][3U];
        tracep->fullWData(oldp+199,(__Vtemp53),128);
        __Vtemp54[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][0U];
        __Vtemp54[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][1U];
        __Vtemp54[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][2U];
        __Vtemp54[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][3U];
        tracep->fullWData(oldp+203,(__Vtemp54),128);
        __Vtemp55[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][0U];
        __Vtemp55[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][1U];
        __Vtemp55[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][2U];
        __Vtemp55[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][3U];
        tracep->fullWData(oldp+207,(__Vtemp55),128);
        tracep->fullCData(oldp+211,((3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                           >> 4U))),2);
        tracep->fullCData(oldp+212,((0xfU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                             >> 6U))),4);
        tracep->fullIData(oldp+213,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j),32);
        tracep->fullCData(oldp+214,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne),2);
        tracep->fullBit(oldp+215,(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag));
        tracep->fullIData(oldp+216,((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                     + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)),32);
        tracep->fullIData(oldp+217,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
                                      : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                                          ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                                          : ((IData)(4U) 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)))),32);
        tracep->fullIData(oldp+218,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC)),32);
        tracep->fullIData(oldp+219,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                          == (0x1fU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                 >> 0xfU)))) 
                                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                     [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                >> 0xfU))])),32);
        tracep->fullIData(oldp+220,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                          == (0x1fU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                 >> 0x14U)))) 
                                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                     [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                >> 0x14U))])),32);
        tracep->fullIData(oldp+221,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                       ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                       : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                                     + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend)),32);
        tracep->fullIData(oldp+222,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                      ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                          ? vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn
                                          : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                              ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half)
                                              : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))
                                      : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                          ? vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn
                                          : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                              ? ((0xffff0000U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half) 
                                                                    >> 0xfU)))) 
                                                     << 0x10U)) 
                                                 | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half))
                                              : ((0xffffff00U 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel) 
                                                                    >> 7U)))) 
                                                     << 8U)) 
                                                 | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))))),32);
        tracep->fullCData(oldp+223,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                      ? (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid) 
                                          & (~ (IData)(
                                                       (0U 
                                                        != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)))))
                                          ? 1U : 0U)
                                      : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                          ? ((IData)(vlTOPp->toplevel__DOT__imem_read_ready)
                                              ? 2U : 1U)
                                          : 0U))),2);
        tracep->fullIData(oldp+224,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i),32);
        tracep->fullCData(oldp+225,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
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
        tracep->fullIData(oldp+226,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i),32);
        tracep->fullWData(oldp+227,(vlTOPp->toplevel__DOT__imem_dout),128);
        tracep->fullBit(oldp+231,((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))));
        tracep->fullCData(oldp+232,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter),4);
        tracep->fullIData(oldp+233,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__i),32);
        tracep->fullWData(oldp+234,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout),128);
        tracep->fullBit(oldp+238,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
        tracep->fullIData(oldp+239,(vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn),32);
        tracep->fullIData(oldp+240,(vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn),32);
        tracep->fullBit(oldp+241,(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen));
        tracep->fullBit(oldp+242,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))));
        tracep->fullWData(oldp+243,(vlTOPp->toplevel__DOT__cpu__DOT__icacheDin),128);
        tracep->fullWData(oldp+247,(vlTOPp->toplevel__DOT__cpu__DOT__icacheDout),128);
        tracep->fullBit(oldp+251,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen));
        tracep->fullBit(oldp+252,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen));
        tracep->fullBit(oldp+253,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))));
        tracep->fullBit(oldp+254,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit));
        tracep->fullWData(oldp+255,(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin),128);
        tracep->fullSData(oldp+259,(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess),16);
        tracep->fullBit(oldp+260,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
        tracep->fullIData(oldp+261,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend),32);
        tracep->fullIData(oldp+262,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA),32);
        tracep->fullIData(oldp+263,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB),32);
        tracep->fullIData(oldp+264,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val),32);
        tracep->fullIData(oldp+265,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA),32);
        tracep->fullIData(oldp+266,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB),32);
        tracep->fullIData(oldp+267,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData),32);
        tracep->fullBit(oldp+268,((0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val)));
        tracep->fullBit(oldp+269,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
        tracep->fullBit(oldp+270,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
        tracep->fullBit(oldp+271,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
        tracep->fullBit(oldp+272,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
        tracep->fullBit(oldp+273,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
        tracep->fullBit(oldp+274,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
        tracep->fullBit(oldp+275,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
        tracep->fullBit(oldp+276,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
        tracep->fullBit(oldp+277,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
        tracep->fullBit(oldp+278,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid));
        tracep->fullBit(oldp+279,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex));
        tracep->fullBit(oldp+280,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc));
        tracep->fullCData(oldp+281,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)),7);
        tracep->fullCData(oldp+282,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                           >> 0xcU))),3);
        tracep->fullCData(oldp+283,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl),3);
        tracep->fullCData(oldp+284,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                              >> 0x19U))),7);
        tracep->fullCData(oldp+285,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+286,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+287,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                              >> 7U))),5);
        tracep->fullIData(oldp+288,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i),32);
        tracep->fullIData(oldp+289,(((0xfffff000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                                     ((0xfe0U & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                 >> 0x14U)) 
                                      | (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                  >> 7U))))),32);
        tracep->fullIData(oldp+290,(((0xfffff000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                                     ((0x800U & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                 << 4U)) 
                                      | ((0x7e0U & 
                                          (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                           >> 0x14U)) 
                                         | (0x1eU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                             >> 7U)))))),32);
        tracep->fullIData(oldp+291,((0xfffff000U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)),32);
        tracep->fullIData(oldp+292,(((0xfff00000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                      >> 0x1fU)))) 
                                       << 0x14U)) | 
                                     ((0xff000U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn) 
                                      | ((0x800U & 
                                          (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                           >> 9U)) 
                                         | ((0x7e0U 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                  >> 0x14U))))))),32);
        tracep->fullBit(oldp+293,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow));
        tracep->fullIData(oldp+294,((0x1ffffffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                   >> 7U))),25);
        tracep->fullQData(oldp+295,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub),33);
        tracep->fullCData(oldp+297,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel),8);
        tracep->fullSData(oldp+298,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half),16);
        tracep->fullCData(oldp+299,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg),2);
        tracep->fullCData(oldp+300,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict),2);
        tracep->fullCData(oldp+301,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask),2);
        tracep->fullCData(oldp+302,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg),2);
        tracep->fullCData(oldp+303,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict),2);
        tracep->fullCData(oldp+304,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask),2);
        tracep->fullBit(oldp+305,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset));
        tracep->fullBit(oldp+306,(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset));
        tracep->fullWData(oldp+307,(vlTOPp->toplevel__DOT__dmem_dout),128);
        tracep->fullBit(oldp+311,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready));
        tracep->fullBit(oldp+312,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
        tracep->fullIData(oldp+313,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0]),32);
        tracep->fullIData(oldp+314,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1]),32);
        tracep->fullIData(oldp+315,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2]),32);
        tracep->fullIData(oldp+316,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3]),32);
        tracep->fullBit(oldp+317,(vlTOPp->clock));
        tracep->fullBit(oldp+318,(vlTOPp->reset));
        tracep->fullBit(oldp+319,((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter))));
        tracep->fullCData(oldp+320,(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter),4);
        tracep->fullIData(oldp+321,(vlTOPp->toplevel__DOT__Data_Mem__DOT__i),32);
        tracep->fullCData(oldp+322,(vlTOPp->toplevel__DOT__dmem_block_address),6);
        tracep->fullSData(oldp+323,(vlTOPp->toplevel__DOT__imem_block_address),9);
        tracep->fullIData(oldp+324,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__DMemOut),32);
        tracep->fullBit(oldp+325,(1U));
        tracep->fullIData(oldp+326,(0x20U),32);
        tracep->fullCData(oldp+327,(0U),2);
        tracep->fullCData(oldp+328,(1U),2);
        tracep->fullCData(oldp+329,(2U),2);
        tracep->fullCData(oldp+330,(0U),3);
        tracep->fullCData(oldp+331,(1U),3);
        tracep->fullCData(oldp+332,(2U),3);
        tracep->fullCData(oldp+333,(3U),3);
        tracep->fullCData(oldp+334,(4U),3);
        tracep->fullIData(oldp+335,(4U),32);
    }
}
