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
        tracep->declBit(c+362,"clock", false,-1);
        tracep->declBit(c+363,"reset", false,-1);
        tracep->declBit(c+362,"toplevel clock", false,-1);
        tracep->declBit(c+363,"toplevel reset", false,-1);
        tracep->declBit(c+376,"toplevel dmem_ren", false,-1);
        tracep->declBit(c+377,"toplevel dmem_wen", false,-1);
        tracep->declBit(c+87,"toplevel dmem_ready", false,-1);
        tracep->declBit(c+88,"toplevel dmem_done", false,-1);
        tracep->declQuad(c+378,"toplevel dmem_block_address", false,-1, 63,0);
        tracep->declQuad(c+380,"toplevel dmem_din", false,-1, 63,0);
        tracep->declQuad(c+364,"toplevel dmem_dout", false,-1, 63,0);
        tracep->declBit(c+382,"toplevel imem_ren", false,-1);
        tracep->declBit(c+89,"toplevel imem_ready", false,-1);
        tracep->declBus(c+383,"toplevel imem_block_address", false,-1, 7,0);
        tracep->declQuad(c+350,"toplevel imem_dout", false,-1, 63,0);
        tracep->declBit(c+362,"toplevel cpu clock", false,-1);
        tracep->declBit(c+363,"toplevel cpu reset", false,-1);
        tracep->declBit(c+382,"toplevel cpu imem_ren", false,-1);
        tracep->declBus(c+383,"toplevel cpu imem_block_address", false,-1, 7,0);
        tracep->declQuad(c+350,"toplevel cpu imem_dout", false,-1, 63,0);
        tracep->declBit(c+89,"toplevel cpu imem_ready", false,-1);
        tracep->declBit(c+376,"toplevel cpu dmem_ren", false,-1);
        tracep->declBit(c+377,"toplevel cpu dmem_wen", false,-1);
        tracep->declBus(c+384,"toplevel cpu dmem_block_address", false,-1, 6,0);
        tracep->declBus(c+385,"toplevel cpu dmem_din", false,-1, 31,0);
        tracep->declBit(c+87,"toplevel cpu dmem_ready", false,-1);
        tracep->declBit(c+88,"toplevel cpu dmem_done", false,-1);
        tracep->declBus(c+366,"toplevel cpu dmem_dout", false,-1, 31,0);
        tracep->declBit(c+386,"toplevel cpu ren", false,-1);
        tracep->declBit(c+387,"toplevel cpu wen", false,-1);
        tracep->declBus(c+388,"toplevel cpu addr", false,-1, 6,0);
        tracep->declBus(c+389,"toplevel cpu byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+390,"toplevel cpu din", false,-1, 31,0);
        tracep->declBit(c+391,"toplevel cpu cacheHit", false,-1);
        tracep->declBit(c+392,"toplevel cpu cacheDirtyBit", false,-1);
        tracep->declQuad(c+393,"toplevel cpu cacheDout", false,-1, 63,0);
        tracep->declBit(c+395,"toplevel cpu memReadReady", false,-1);
        tracep->declBit(c+396,"toplevel cpu memWriteDone", false,-1);
        tracep->declQuad(c+397,"toplevel cpu memDout", false,-1, 63,0);
        tracep->declBit(c+90,"toplevel cpu stall", false,-1);
        tracep->declBus(c+367,"toplevel cpu dout", false,-1, 31,0);
        tracep->declBus(c+399,"toplevel cpu BlockAddr", false,-1, 3,0);
        tracep->declBit(c+368,"toplevel cpu cacheRen", false,-1);
        tracep->declBit(c+369,"toplevel cpu cacheWen", false,-1);
        tracep->declBit(c+91,"toplevel cpu cacheMemWen", false,-1);
        tracep->declBus(c+66,"toplevel cpu cacheBytesAccess", false,-1, 7,0);
        tracep->declQuad(c+67,"toplevel cpu cacheDin", false,-1, 63,0);
        tracep->declBit(c+92,"toplevel cpu memRen", false,-1);
        tracep->declBit(c+93,"toplevel cpu memWen", false,-1);
        tracep->declQuad(c+393,"toplevel cpu memDin", false,-1, 63,0);
        tracep->declBit(c+400,"toplevel cpu dcache_stall", false,-1);
        tracep->declBit(c+401,"toplevel cpu icache_stall", false,-1);
        tracep->declBit(c+402,"toplevel cpu dcache_ren", false,-1);
        tracep->declBit(c+403,"toplevel cpu dcache_wen", false,-1);
        tracep->declQuad(c+404,"toplevel cpu dcache_output", false,-1, 63,0);
        tracep->declBus(c+406,"toplevel cpu dcache_addr", false,-1, 3,0);
        tracep->declQuad(c+407,"toplevel cpu dcache_input", false,-1, 63,0);
        tracep->declBit(c+409,"toplevel cpu DcacheRen", false,-1);
        tracep->declBit(c+410,"toplevel cpu DcacheWen", false,-1);
        tracep->declBit(c+411,"toplevel cpu DcacheMemWen", false,-1);
        tracep->declBus(c+412,"toplevel cpu DcacheBytesAccess", false,-1, 7,0);
        tracep->declBus(c+413,"toplevel cpu DcacheBlockAddr", false,-1, 3,0);
        tracep->declQuad(c+414,"toplevel cpu DcacheDin", false,-1, 63,0);
        tracep->declBit(c+69,"toplevel cpu DcacheHit", false,-1);
        tracep->declBit(c+70,"toplevel cpu DcacheDirtyBit", false,-1);
        tracep->declQuad(c+71,"toplevel cpu DcacheDout", false,-1, 63,0);
        tracep->declBit(c+416,"toplevel cpu IcacheRen", false,-1);
        tracep->declBit(c+417,"toplevel cpu IcacheMemWen", false,-1);
        tracep->declBus(c+418,"toplevel cpu IcacheBlockAddr", false,-1, 3,0);
        tracep->declArray(c+419,"toplevel cpu IcacheDin", false,-1, 127,0);
        tracep->declBit(c+73,"toplevel cpu IcacheHit", false,-1);
        tracep->declBit(c+423,"toplevel cpu IcacheDirtyBit", false,-1);
        tracep->declArray(c+74,"toplevel cpu IcacheDout", false,-1, 127,0);
        tracep->declBit(c+362,"toplevel cpu pipeline clock", false,-1);
        tracep->declBit(c+363,"toplevel cpu pipeline reset", false,-1);
        tracep->declBit(c+400,"toplevel cpu pipeline dcache_stall", false,-1);
        tracep->declBit(c+401,"toplevel cpu pipeline icache_stall", false,-1);
        tracep->declBus(c+424,"toplevel cpu pipeline dcache_output", false,-1, 31,0);
        tracep->declBit(c+402,"toplevel cpu pipeline dcache_ren", false,-1);
        tracep->declBit(c+403,"toplevel cpu pipeline dcache_wen", false,-1);
        tracep->declBus(c+406,"toplevel cpu pipeline dcache_addr", false,-1, 3,0);
        tracep->declBus(c+389,"toplevel cpu pipeline byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+425,"toplevel cpu pipeline dcache_input", false,-1, 31,0);
        tracep->declBus(c+94,"toplevel cpu pipeline IFID_instr", false,-1, 31,0);
        tracep->declBus(c+95,"toplevel cpu pipeline PC", false,-1, 31,0);
        tracep->declBus(c+96,"toplevel cpu pipeline IFID_PC", false,-1, 31,0);
        tracep->declBus(c+97,"toplevel cpu pipeline IDEX_PC", false,-1, 31,0);
        tracep->declBus(c+98,"toplevel cpu pipeline PCplus4", false,-1, 31,0);
        tracep->declBus(c+99,"toplevel cpu pipeline JumpAddress", false,-1, 31,0);
        tracep->declBus(c+100,"toplevel cpu pipeline PC_new", false,-1, 31,0);
        tracep->declBus(c+426,"toplevel cpu pipeline instr", false,-1, 31,0);
        tracep->declBit(c+101,"toplevel cpu pipeline inA_is_PC", false,-1);
        tracep->declBit(c+102,"toplevel cpu pipeline branch_taken", false,-1);
        tracep->declBus(c+103,"toplevel cpu pipeline BranchInA", false,-1, 31,0);
        tracep->declBus(c+104,"toplevel cpu pipeline IDEX_signExtend", false,-1, 31,0);
        tracep->declBus(c+105,"toplevel cpu pipeline signExtend", false,-1, 31,0);
        tracep->declBus(c+106,"toplevel cpu pipeline rdA", false,-1, 31,0);
        tracep->declBus(c+107,"toplevel cpu pipeline rdB", false,-1, 31,0);
        tracep->declBus(c+108,"toplevel cpu pipeline IDEX_rdA", false,-1, 31,0);
        tracep->declBus(c+109,"toplevel cpu pipeline IDEX_rdB", false,-1, 31,0);
        tracep->declBus(c+110,"toplevel cpu pipeline IDEX_funct3", false,-1, 2,0);
        tracep->declBus(c+111,"toplevel cpu pipeline IDEX_funct7", false,-1, 6,0);
        tracep->declBus(c+112,"toplevel cpu pipeline IDEX_instr_rs2", false,-1, 4,0);
        tracep->declBus(c+113,"toplevel cpu pipeline IDEX_instr_rs1", false,-1, 4,0);
        tracep->declBus(c+114,"toplevel cpu pipeline IDEX_instr_rd", false,-1, 4,0);
        tracep->declBit(c+115,"toplevel cpu pipeline IDEX_RegDst", false,-1);
        tracep->declBit(c+116,"toplevel cpu pipeline IDEX_ALUSrc", false,-1);
        tracep->declBit(c+117,"toplevel cpu pipeline IDEX_inA_is_PC", false,-1);
        tracep->declBit(c+118,"toplevel cpu pipeline IDEX_Jump", false,-1);
        tracep->declBit(c+119,"toplevel cpu pipeline IDEX_JumpJALR", false,-1);
        tracep->declBus(c+120,"toplevel cpu pipeline IDEX_ALUcntrl", false,-1, 2,0);
        tracep->declBit(c+121,"toplevel cpu pipeline IDEX_MemRead", false,-1);
        tracep->declBit(c+122,"toplevel cpu pipeline IDEX_MemWrite", false,-1);
        tracep->declBit(c+123,"toplevel cpu pipeline IDEX_MemToReg", false,-1);
        tracep->declBit(c+124,"toplevel cpu pipeline IDEX_RegWrite", false,-1);
        tracep->declBus(c+125,"toplevel cpu pipeline EXMEM_funct3", false,-1, 2,0);
        tracep->declBus(c+126,"toplevel cpu pipeline MEMWB_funct3", false,-1, 2,0);
        tracep->declBus(c+127,"toplevel cpu pipeline EXMEM_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+128,"toplevel cpu pipeline EXMEM_ALUOut", false,-1, 31,0);
        tracep->declBus(c+129,"toplevel cpu pipeline EXMEM_BranchALUOut", false,-1, 31,0);
        tracep->declBit(c+130,"toplevel cpu pipeline EXMEM_Zero", false,-1);
        tracep->declBit(c+131,"toplevel cpu pipeline EXMEM_JumpJALR", false,-1);
        tracep->declBus(c+132,"toplevel cpu pipeline byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+133,"toplevel cpu pipeline EXMEM_MemWriteData", false,-1, 31,0);
        tracep->declBus(c+134,"toplevel cpu pipeline MemWriteData", false,-1, 31,0);
        tracep->declBit(c+135,"toplevel cpu pipeline EXMEM_MemRead", false,-1);
        tracep->declBit(c+136,"toplevel cpu pipeline EXMEM_MemWrite", false,-1);
        tracep->declBit(c+137,"toplevel cpu pipeline EXMEM_RegWrite", false,-1);
        tracep->declBit(c+138,"toplevel cpu pipeline EXMEM_MemToReg", false,-1);
        tracep->declBus(c+139,"toplevel cpu pipeline MEMWB_DMemOut", false,-1, 31,0);
        tracep->declBus(c+140,"toplevel cpu pipeline MEMWB_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+141,"toplevel cpu pipeline MEMWB_ALUOut", false,-1, 31,0);
        tracep->declBit(c+142,"toplevel cpu pipeline MEMWB_MemToReg", false,-1);
        tracep->declBit(c+143,"toplevel cpu pipeline MEMWB_RegWrite", false,-1);
        tracep->declBus(c+144,"toplevel cpu pipeline ALUInA", false,-1, 31,0);
        tracep->declBus(c+145,"toplevel cpu pipeline ALUInB", false,-1, 31,0);
        tracep->declBus(c+146,"toplevel cpu pipeline ALUOut", false,-1, 31,0);
        tracep->declBus(c+147,"toplevel cpu pipeline BranchALUOut", false,-1, 31,0);
        tracep->declBus(c+148,"toplevel cpu pipeline bypassOutA", false,-1, 31,0);
        tracep->declBus(c+149,"toplevel cpu pipeline bypassOutB", false,-1, 31,0);
        tracep->declBus(c+427,"toplevel cpu pipeline DMemOut", false,-1, 31,0);
        tracep->declBus(c+150,"toplevel cpu pipeline MemOut", false,-1, 31,0);
        tracep->declBus(c+151,"toplevel cpu pipeline wRegData", false,-1, 31,0);
        tracep->declBit(c+152,"toplevel cpu pipeline Zero", false,-1);
        tracep->declBit(c+153,"toplevel cpu pipeline RegDst", false,-1);
        tracep->declBit(c+154,"toplevel cpu pipeline MemRead", false,-1);
        tracep->declBit(c+155,"toplevel cpu pipeline MemWrite", false,-1);
        tracep->declBit(c+156,"toplevel cpu pipeline MemToReg", false,-1);
        tracep->declBit(c+157,"toplevel cpu pipeline ALUSrc", false,-1);
        tracep->declBit(c+158,"toplevel cpu pipeline PCSrc", false,-1);
        tracep->declBit(c+159,"toplevel cpu pipeline RegWrite", false,-1);
        tracep->declBit(c+160,"toplevel cpu pipeline Jump", false,-1);
        tracep->declBit(c+161,"toplevel cpu pipeline JumpJALR", false,-1);
        tracep->declBit(c+162,"toplevel cpu pipeline Branch", false,-1);
        tracep->declBit(c+163,"toplevel cpu pipeline IDEX_Branch", false,-1);
        tracep->declBit(c+164,"toplevel cpu pipeline EXMEM_Branch", false,-1);
        tracep->declBit(c+165,"toplevel cpu pipeline bubble_ifid", false,-1);
        tracep->declBit(c+166,"toplevel cpu pipeline bubble_idex", false,-1);
        tracep->declBit(c+167,"toplevel cpu pipeline bubble_exmem", false,-1);
        tracep->declBit(c+168,"toplevel cpu pipeline write_ifid", false,-1);
        tracep->declBit(c+428,"toplevel cpu pipeline write_idex", false,-1);
        tracep->declBit(c+428,"toplevel cpu pipeline write_exmem", false,-1);
        tracep->declBit(c+428,"toplevel cpu pipeline write_memwb", false,-1);
        tracep->declBit(c+169,"toplevel cpu pipeline write_pc", false,-1);
        tracep->declBus(c+170,"toplevel cpu pipeline opcode", false,-1, 6,0);
        tracep->declBus(c+171,"toplevel cpu pipeline funct3", false,-1, 2,0);
        tracep->declBus(c+172,"toplevel cpu pipeline ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+173,"toplevel cpu pipeline funct7", false,-1, 6,0);
        tracep->declBus(c+174,"toplevel cpu pipeline instr_rs1", false,-1, 4,0);
        tracep->declBus(c+175,"toplevel cpu pipeline instr_rs2", false,-1, 4,0);
        tracep->declBus(c+176,"toplevel cpu pipeline instr_rd", false,-1, 4,0);
        tracep->declBus(c+177,"toplevel cpu pipeline RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+178,"toplevel cpu pipeline ALUOp", false,-1, 3,0);
        tracep->declBus(c+179,"toplevel cpu pipeline bypassA", false,-1, 1,0);
        tracep->declBus(c+180,"toplevel cpu pipeline bypassB", false,-1, 1,0);
        tracep->declBus(c+181,"toplevel cpu pipeline imm_i", false,-1, 31,0);
        tracep->declBus(c+182,"toplevel cpu pipeline imm_s", false,-1, 31,0);
        tracep->declBus(c+183,"toplevel cpu pipeline imm_b", false,-1, 31,0);
        tracep->declBus(c+184,"toplevel cpu pipeline imm_u", false,-1, 31,0);
        tracep->declBus(c+185,"toplevel cpu pipeline imm_j", false,-1, 31,0);
        tracep->declBit(c+186,"toplevel cpu pipeline overflow", false,-1);
        tracep->declBit(c+1,"toplevel cpu pipeline stall_from_cache", false,-1);
        tracep->declBus(c+187,"toplevel cpu pipeline signExtendUnit instr", false,-1, 24,0);
        tracep->declBus(c+181,"toplevel cpu pipeline signExtendUnit imm_i", false,-1, 31,0);
        tracep->declBus(c+182,"toplevel cpu pipeline signExtendUnit imm_s", false,-1, 31,0);
        tracep->declBus(c+183,"toplevel cpu pipeline signExtendUnit imm_b", false,-1, 31,0);
        tracep->declBus(c+184,"toplevel cpu pipeline signExtendUnit imm_u", false,-1, 31,0);
        tracep->declBus(c+185,"toplevel cpu pipeline signExtendUnit imm_j", false,-1, 31,0);
        tracep->declBit(c+362,"toplevel cpu pipeline cpu_regs clock", false,-1);
        tracep->declBit(c+363,"toplevel cpu pipeline cpu_regs reset", false,-1);
        tracep->declBus(c+174,"toplevel cpu pipeline cpu_regs raA", false,-1, 4,0);
        tracep->declBus(c+175,"toplevel cpu pipeline cpu_regs raB", false,-1, 4,0);
        tracep->declBus(c+140,"toplevel cpu pipeline cpu_regs wa", false,-1, 4,0);
        tracep->declBit(c+143,"toplevel cpu pipeline cpu_regs wen", false,-1);
        tracep->declBus(c+151,"toplevel cpu pipeline cpu_regs wd", false,-1, 31,0);
        tracep->declBus(c+106,"toplevel cpu pipeline cpu_regs rdA", false,-1, 31,0);
        tracep->declBus(c+107,"toplevel cpu pipeline cpu_regs rdB", false,-1, 31,0);
        tracep->declBus(c+188,"toplevel cpu pipeline cpu_regs i", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+189+i*1,"toplevel cpu pipeline cpu_regs data", true,(i+0), 31,0);}}
        tracep->declBus(c+105,"toplevel cpu pipeline SignExtendSelector out", false,-1, 31,0);
        tracep->declBus(c+181,"toplevel cpu pipeline SignExtendSelector imm_i", false,-1, 31,0);
        tracep->declBus(c+182,"toplevel cpu pipeline SignExtendSelector imm_s", false,-1, 31,0);
        tracep->declBus(c+183,"toplevel cpu pipeline SignExtendSelector imm_b", false,-1, 31,0);
        tracep->declBus(c+184,"toplevel cpu pipeline SignExtendSelector imm_u", false,-1, 31,0);
        tracep->declBus(c+185,"toplevel cpu pipeline SignExtendSelector imm_j", false,-1, 31,0);
        tracep->declBus(c+170,"toplevel cpu pipeline SignExtendSelector opcode", false,-1, 6,0);
        tracep->declBit(c+153,"toplevel cpu pipeline control_main RegDst", false,-1);
        tracep->declBit(c+162,"toplevel cpu pipeline control_main Branch", false,-1);
        tracep->declBit(c+154,"toplevel cpu pipeline control_main MemRead", false,-1);
        tracep->declBit(c+155,"toplevel cpu pipeline control_main MemWrite", false,-1);
        tracep->declBit(c+156,"toplevel cpu pipeline control_main MemToReg", false,-1);
        tracep->declBit(c+157,"toplevel cpu pipeline control_main ALUSrc", false,-1);
        tracep->declBit(c+159,"toplevel cpu pipeline control_main RegWrite", false,-1);
        tracep->declBit(c+160,"toplevel cpu pipeline control_main Jump", false,-1);
        tracep->declBit(c+161,"toplevel cpu pipeline control_main JumpJALR", false,-1);
        tracep->declBit(c+101,"toplevel cpu pipeline control_main inA_is_PC", false,-1);
        tracep->declBus(c+172,"toplevel cpu pipeline control_main ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+170,"toplevel cpu pipeline control_main opcode", false,-1, 6,0);
        tracep->declBit(c+165,"toplevel cpu pipeline control_stall_id bubble_ifid", false,-1);
        tracep->declBit(c+166,"toplevel cpu pipeline control_stall_id bubble_idex", false,-1);
        tracep->declBit(c+167,"toplevel cpu pipeline control_stall_id bubble_exmem", false,-1);
        tracep->declBit(c+168,"toplevel cpu pipeline control_stall_id write_ifid", false,-1);
        tracep->declBit(c+428,"toplevel cpu pipeline control_stall_id write_idex", false,-1);
        tracep->declBit(c+428,"toplevel cpu pipeline control_stall_id write_exmem", false,-1);
        tracep->declBit(c+428,"toplevel cpu pipeline control_stall_id write_memwb", false,-1);
        tracep->declBit(c+169,"toplevel cpu pipeline control_stall_id write_pc", false,-1);
        tracep->declBus(c+174,"toplevel cpu pipeline control_stall_id ifid_rs", false,-1, 4,0);
        tracep->declBus(c+175,"toplevel cpu pipeline control_stall_id ifid_rt", false,-1, 4,0);
        tracep->declBus(c+114,"toplevel cpu pipeline control_stall_id idex_rd", false,-1, 4,0);
        tracep->declBit(c+121,"toplevel cpu pipeline control_stall_id idex_memread", false,-1);
        tracep->declBit(c+160,"toplevel cpu pipeline control_stall_id Jump", false,-1);
        tracep->declBit(c+158,"toplevel cpu pipeline control_stall_id PCSrc", false,-1);
        tracep->declBus(c+429,"toplevel cpu pipeline cpu_alu N", false,-1, 31,0);
        tracep->declBus(c+146,"toplevel cpu pipeline cpu_alu out", false,-1, 31,0);
        tracep->declBit(c+152,"toplevel cpu pipeline cpu_alu zero", false,-1);
        tracep->declBit(c+186,"toplevel cpu pipeline cpu_alu overflow", false,-1);
        tracep->declBus(c+144,"toplevel cpu pipeline cpu_alu inA", false,-1, 31,0);
        tracep->declBus(c+145,"toplevel cpu pipeline cpu_alu inB", false,-1, 31,0);
        tracep->declBus(c+178,"toplevel cpu pipeline cpu_alu op", false,-1, 3,0);
        tracep->declBus(c+146,"toplevel cpu pipeline cpu_alu out_val", false,-1, 31,0);
        tracep->declQuad(c+221,"toplevel cpu pipeline cpu_alu unsigned_sub", false,-1, 32,0);
        tracep->declBus(c+178,"toplevel cpu pipeline control_alu ALUOp", false,-1, 3,0);
        tracep->declBus(c+120,"toplevel cpu pipeline control_alu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+110,"toplevel cpu pipeline control_alu funct3", false,-1, 2,0);
        tracep->declBus(c+111,"toplevel cpu pipeline control_alu funct7", false,-1, 6,0);
        tracep->declBus(c+179,"toplevel cpu pipeline control_bypass_ex bypassA", false,-1, 1,0);
        tracep->declBus(c+180,"toplevel cpu pipeline control_bypass_ex bypassB", false,-1, 1,0);
        tracep->declBus(c+113,"toplevel cpu pipeline control_bypass_ex idex_rs1", false,-1, 4,0);
        tracep->declBus(c+112,"toplevel cpu pipeline control_bypass_ex idex_rs2", false,-1, 4,0);
        tracep->declBus(c+127,"toplevel cpu pipeline control_bypass_ex exmem_rd", false,-1, 4,0);
        tracep->declBus(c+140,"toplevel cpu pipeline control_bypass_ex memwb_rd", false,-1, 4,0);
        tracep->declBit(c+137,"toplevel cpu pipeline control_bypass_ex exmem_regwrite", false,-1);
        tracep->declBit(c+143,"toplevel cpu pipeline control_bypass_ex memwb_regwrite", false,-1);
        tracep->declBus(c+125,"toplevel cpu pipeline mem_write_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+133,"toplevel cpu pipeline mem_write_selector ALUin", false,-1, 31,0);
        tracep->declBus(c+223,"toplevel cpu pipeline mem_write_selector offset", false,-1, 1,0);
        tracep->declBus(c+132,"toplevel cpu pipeline mem_write_selector byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+134,"toplevel cpu pipeline mem_write_selector out", false,-1, 31,0);
        tracep->declBit(c+102,"toplevel cpu pipeline control_branch branch_taken", false,-1);
        tracep->declBus(c+125,"toplevel cpu pipeline control_branch funct3", false,-1, 2,0);
        tracep->declBit(c+164,"toplevel cpu pipeline control_branch Branch", false,-1);
        tracep->declBit(c+130,"toplevel cpu pipeline control_branch zero", false,-1);
        tracep->declBit(c+224,"toplevel cpu pipeline control_branch sign", false,-1);
        tracep->declBus(c+126,"toplevel cpu pipeline mem_read_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+139,"toplevel cpu pipeline mem_read_selector DMemOut", false,-1, 31,0);
        tracep->declBus(c+225,"toplevel cpu pipeline mem_read_selector byte_index", false,-1, 1,0);
        tracep->declBus(c+150,"toplevel cpu pipeline mem_read_selector out", false,-1, 31,0);
        tracep->declBus(c+226,"toplevel cpu pipeline mem_read_selector byte_sel", false,-1, 7,0);
        tracep->declBus(c+227,"toplevel cpu pipeline mem_read_selector half", false,-1, 15,0);
        tracep->declBit(c+362,"toplevel cpu Icache clk", false,-1);
        tracep->declBit(c+363,"toplevel cpu Icache rst", false,-1);
        tracep->declBit(c+416,"toplevel cpu Icache ren", false,-1);
        tracep->declBit(c+417,"toplevel cpu Icache memWen", false,-1);
        tracep->declArray(c+419,"toplevel cpu Icache dataIn", false,-1, 127,0);
        tracep->declBus(c+418,"toplevel cpu Icache blockAddr", false,-1, 3,0);
        tracep->declBit(c+73,"toplevel cpu Icache hit", false,-1);
        tracep->declArray(c+74,"toplevel cpu Icache dataOut", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+228+i*1,"toplevel cpu Icache valid_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+232+i*1,"toplevel cpu Icache status_col", true,(i+0), 1,0);}}
        tracep->declBus(c+236,"toplevel cpu Icache tag_col(0)(0)", false,-1, 1,0);
        tracep->declBus(c+237,"toplevel cpu Icache tag_col(0)(1)", false,-1, 1,0);
        tracep->declBus(c+238,"toplevel cpu Icache tag_col(1)(0)", false,-1, 1,0);
        tracep->declBus(c+239,"toplevel cpu Icache tag_col(1)(1)", false,-1, 1,0);
        tracep->declBus(c+240,"toplevel cpu Icache tag_col(2)(0)", false,-1, 1,0);
        tracep->declBus(c+241,"toplevel cpu Icache tag_col(2)(1)", false,-1, 1,0);
        tracep->declBus(c+242,"toplevel cpu Icache tag_col(3)(0)", false,-1, 1,0);
        tracep->declBus(c+243,"toplevel cpu Icache tag_col(3)(1)", false,-1, 1,0);
        tracep->declArray(c+244,"toplevel cpu Icache data_col(0)(0)", false,-1, 127,0);
        tracep->declArray(c+248,"toplevel cpu Icache data_col(0)(1)", false,-1, 127,0);
        tracep->declArray(c+252,"toplevel cpu Icache data_col(1)(0)", false,-1, 127,0);
        tracep->declArray(c+256,"toplevel cpu Icache data_col(1)(1)", false,-1, 127,0);
        tracep->declArray(c+260,"toplevel cpu Icache data_col(2)(0)", false,-1, 127,0);
        tracep->declArray(c+264,"toplevel cpu Icache data_col(2)(1)", false,-1, 127,0);
        tracep->declArray(c+268,"toplevel cpu Icache data_col(3)(0)", false,-1, 127,0);
        tracep->declArray(c+272,"toplevel cpu Icache data_col(3)(1)", false,-1, 127,0);
        tracep->declBus(c+430,"toplevel cpu Icache index", false,-1, 1,0);
        tracep->declBus(c+431,"toplevel cpu Icache tag", false,-1, 1,0);
        tracep->declBus(c+370,"toplevel cpu Icache i", false,-1, 31,0);
        tracep->declBus(c+276,"toplevel cpu Icache j", false,-1, 31,0);
        tracep->declBus(c+78,"toplevel cpu Icache hitReg", false,-1, 1,0);
        tracep->declBus(c+79,"toplevel cpu Icache blockToEvict", false,-1, 1,0);
        tracep->declBus(c+80,"toplevel cpu Icache mask", false,-1, 1,0);
        tracep->declBus(c+277,"toplevel cpu Icache statusFullOne", false,-1, 1,0);
        tracep->declBit(c+362,"toplevel cpu Dcache clk", false,-1);
        tracep->declBit(c+363,"toplevel cpu Dcache rst", false,-1);
        tracep->declBit(c+409,"toplevel cpu Dcache ren", false,-1);
        tracep->declBit(c+410,"toplevel cpu Dcache wen", false,-1);
        tracep->declBit(c+411,"toplevel cpu Dcache memWen", false,-1);
        tracep->declBus(c+412,"toplevel cpu Dcache bytesAccess", false,-1, 7,0);
        tracep->declBus(c+413,"toplevel cpu Dcache blockAddr", false,-1, 3,0);
        tracep->declQuad(c+414,"toplevel cpu Dcache dataIn", false,-1, 63,0);
        tracep->declBit(c+69,"toplevel cpu Dcache hit", false,-1);
        tracep->declBit(c+70,"toplevel cpu Dcache dirtyBit", false,-1);
        tracep->declQuad(c+71,"toplevel cpu Dcache dataOut", false,-1, 63,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+278+i*1,"toplevel cpu Dcache valid_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+282+i*1,"toplevel cpu Dcache dirty_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+286+i*1,"toplevel cpu Dcache status_col", true,(i+0), 1,0);}}
        tracep->declBus(c+290,"toplevel cpu Dcache tag_col(0)(0)", false,-1, 1,0);
        tracep->declBus(c+291,"toplevel cpu Dcache tag_col(0)(1)", false,-1, 1,0);
        tracep->declBus(c+292,"toplevel cpu Dcache tag_col(1)(0)", false,-1, 1,0);
        tracep->declBus(c+293,"toplevel cpu Dcache tag_col(1)(1)", false,-1, 1,0);
        tracep->declBus(c+294,"toplevel cpu Dcache tag_col(2)(0)", false,-1, 1,0);
        tracep->declBus(c+295,"toplevel cpu Dcache tag_col(2)(1)", false,-1, 1,0);
        tracep->declBus(c+296,"toplevel cpu Dcache tag_col(3)(0)", false,-1, 1,0);
        tracep->declBus(c+297,"toplevel cpu Dcache tag_col(3)(1)", false,-1, 1,0);
        tracep->declQuad(c+298,"toplevel cpu Dcache data_col(0)(0)", false,-1, 63,0);
        tracep->declQuad(c+300,"toplevel cpu Dcache data_col(0)(1)", false,-1, 63,0);
        tracep->declQuad(c+302,"toplevel cpu Dcache data_col(1)(0)", false,-1, 63,0);
        tracep->declQuad(c+304,"toplevel cpu Dcache data_col(1)(1)", false,-1, 63,0);
        tracep->declQuad(c+306,"toplevel cpu Dcache data_col(2)(0)", false,-1, 63,0);
        tracep->declQuad(c+308,"toplevel cpu Dcache data_col(2)(1)", false,-1, 63,0);
        tracep->declQuad(c+310,"toplevel cpu Dcache data_col(3)(0)", false,-1, 63,0);
        tracep->declQuad(c+312,"toplevel cpu Dcache data_col(3)(1)", false,-1, 63,0);
        tracep->declBus(c+432,"toplevel cpu Dcache index", false,-1, 1,0);
        tracep->declBus(c+433,"toplevel cpu Dcache tag", false,-1, 1,0);
        tracep->declBus(c+371,"toplevel cpu Dcache i", false,-1, 31,0);
        tracep->declBus(c+372,"toplevel cpu Dcache j", false,-1, 31,0);
        tracep->declBus(c+81,"toplevel cpu Dcache m", false,-1, 31,0);
        tracep->declBus(c+314,"toplevel cpu Dcache l", false,-1, 31,0);
        tracep->declBus(c+82,"toplevel cpu Dcache hitReg", false,-1, 1,0);
        tracep->declBus(c+83,"toplevel cpu Dcache blockToEvict", false,-1, 1,0);
        tracep->declBus(c+84,"toplevel cpu Dcache mask", false,-1, 1,0);
        tracep->declBus(c+315,"toplevel cpu Dcache statusFullOne", false,-1, 1,0);
        tracep->declBit(c+362,"toplevel cpu Dcntr clock", false,-1);
        tracep->declBit(c+363,"toplevel cpu Dcntr reset", false,-1);
        tracep->declBit(c+386,"toplevel cpu Dcntr ren", false,-1);
        tracep->declBit(c+387,"toplevel cpu Dcntr wen", false,-1);
        tracep->declBus(c+388,"toplevel cpu Dcntr addr", false,-1, 6,0);
        tracep->declBus(c+389,"toplevel cpu Dcntr byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+390,"toplevel cpu Dcntr din", false,-1, 31,0);
        tracep->declBit(c+391,"toplevel cpu Dcntr cacheHit", false,-1);
        tracep->declBit(c+392,"toplevel cpu Dcntr cacheDirtyBit", false,-1);
        tracep->declQuad(c+393,"toplevel cpu Dcntr cacheDout", false,-1, 63,0);
        tracep->declBit(c+395,"toplevel cpu Dcntr memReadReady", false,-1);
        tracep->declBit(c+396,"toplevel cpu Dcntr memWriteDone", false,-1);
        tracep->declQuad(c+397,"toplevel cpu Dcntr memDout", false,-1, 63,0);
        tracep->declBit(c+90,"toplevel cpu Dcntr stall", false,-1);
        tracep->declBus(c+367,"toplevel cpu Dcntr dout", false,-1, 31,0);
        tracep->declBus(c+399,"toplevel cpu Dcntr BlockAddr", false,-1, 3,0);
        tracep->declBit(c+368,"toplevel cpu Dcntr cacheRen", false,-1);
        tracep->declBit(c+369,"toplevel cpu Dcntr cacheWen", false,-1);
        tracep->declBit(c+91,"toplevel cpu Dcntr cacheMemWen", false,-1);
        tracep->declBus(c+66,"toplevel cpu Dcntr cacheBytesAccess", false,-1, 7,0);
        tracep->declQuad(c+67,"toplevel cpu Dcntr cacheDin", false,-1, 63,0);
        tracep->declBit(c+92,"toplevel cpu Dcntr memRen", false,-1);
        tracep->declBit(c+93,"toplevel cpu Dcntr memWen", false,-1);
        tracep->declQuad(c+393,"toplevel cpu Dcntr memDin", false,-1, 63,0);
        tracep->declBit(c+434,"toplevel cpu Dcntr pipeline_req", false,-1);
        tracep->declBus(c+435,"toplevel cpu Dcntr blockOffset", false,-1, 2,0);
        tracep->declBus(c+436,"toplevel cpu Dcntr IDLE", false,-1, 2,0);
        tracep->declBus(c+437,"toplevel cpu Dcntr WRITEBACK", false,-1, 2,0);
        tracep->declBus(c+438,"toplevel cpu Dcntr MEMREAD", false,-1, 2,0);
        tracep->declBus(c+439,"toplevel cpu Dcntr MEMCACHE", false,-1, 2,0);
        tracep->declBus(c+440,"toplevel cpu Dcntr WRITEBACK_REPLACE", false,-1, 2,0);
        tracep->declBus(c+316,"toplevel cpu Dcntr state", false,-1, 2,0);
        tracep->declBus(c+317,"toplevel cpu Dcntr next_state", false,-1, 2,0);
        tracep->declBit(c+362,"toplevel Instruction_Mem clock", false,-1);
        tracep->declBit(c+363,"toplevel Instruction_Mem reset", false,-1);
        tracep->declBit(c+382,"toplevel Instruction_Mem ren", false,-1);
        tracep->declBus(c+441,"toplevel Instruction_Mem block_address", false,-1, 3,0);
        tracep->declBit(c+89,"toplevel Instruction_Mem ready", false,-1);
        tracep->declArray(c+352,"toplevel Instruction_Mem dout", false,-1, 127,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declArray(c+2+i*4,"toplevel Instruction_Mem data", true,(i+0), 127,0);}}
        tracep->declBit(c+356,"toplevel Instruction_Mem delayed", false,-1);
        tracep->declBit(c+85,"toplevel Instruction_Mem counter_reset", false,-1);
        tracep->declBus(c+357,"toplevel Instruction_Mem delay_counter", false,-1, 3,0);
        tracep->declBus(c+442,"toplevel Instruction_Mem delay_cntr size", false,-1, 31,0);
        tracep->declBit(c+85,"toplevel Instruction_Mem delay_cntr reset", false,-1);
        tracep->declBit(c+362,"toplevel Instruction_Mem delay_cntr clk", false,-1);
        tracep->declBit(c+356,"toplevel Instruction_Mem delay_cntr hold", false,-1);
        tracep->declBus(c+357,"toplevel Instruction_Mem delay_cntr counter", false,-1, 3,0);
        tracep->declBit(c+362,"toplevel Data_Mem clock", false,-1);
        tracep->declBit(c+363,"toplevel Data_Mem reset", false,-1);
        tracep->declBit(c+376,"toplevel Data_Mem ren", false,-1);
        tracep->declBit(c+377,"toplevel Data_Mem wen", false,-1);
        tracep->declBus(c+443,"toplevel Data_Mem block_address", false,-1, 3,0);
        tracep->declQuad(c+380,"toplevel Data_Mem din", false,-1, 63,0);
        tracep->declBit(c+87,"toplevel Data_Mem ready", false,-1);
        tracep->declBit(c+88,"toplevel Data_Mem done", false,-1);
        tracep->declQuad(c+364,"toplevel Data_Mem dout", false,-1, 63,0);
        {int i; for (i=0; i<16; i++) {
                tracep->declQuad(c+318+i*2,"toplevel Data_Mem data", true,(i+0), 63,0);}}
        tracep->declQuad(c+373,"toplevel Data_Mem temp_din", false,-1, 63,0);
        tracep->declBit(c+375,"toplevel Data_Mem flag", false,-1);
        tracep->declBit(c+358,"toplevel Data_Mem delayed", false,-1);
        tracep->declBit(c+86,"toplevel Data_Mem counter_reset", false,-1);
        tracep->declBus(c+359,"toplevel Data_Mem delay_counter", false,-1, 3,0);
        tracep->declBit(c+360,"toplevel Data_Mem temp_ready", false,-1);
        tracep->declBit(c+361,"toplevel Data_Mem temp_done", false,-1);
        tracep->declBus(c+442,"toplevel Data_Mem delay_cntr size", false,-1, 31,0);
        tracep->declBit(c+86,"toplevel Data_Mem delay_cntr reset", false,-1);
        tracep->declBit(c+362,"toplevel Data_Mem delay_cntr clk", false,-1);
        tracep->declBit(c+358,"toplevel Data_Mem delay_cntr hold", false,-1);
        tracep->declBus(c+359,"toplevel Data_Mem delay_cntr counter", false,-1, 3,0);
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
    WData/*127:0*/ __Vtemp15[4];
    WData/*127:0*/ __Vtemp16[4];
    WData/*127:0*/ __Vtemp17[4];
    WData/*127:0*/ __Vtemp18[4];
    WData/*127:0*/ __Vtemp19[4];
    WData/*127:0*/ __Vtemp20[4];
    WData/*127:0*/ __Vtemp21[4];
    WData/*127:0*/ __Vtemp22[4];
    WData/*127:0*/ __Vtemp30[4];
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache));
        tracep->fullWData(oldp+2,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[0]),128);
        tracep->fullWData(oldp+6,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[1]),128);
        tracep->fullWData(oldp+10,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[2]),128);
        tracep->fullWData(oldp+14,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[3]),128);
        tracep->fullWData(oldp+18,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[4]),128);
        tracep->fullWData(oldp+22,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[5]),128);
        tracep->fullWData(oldp+26,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[6]),128);
        tracep->fullWData(oldp+30,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[7]),128);
        tracep->fullWData(oldp+34,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[8]),128);
        tracep->fullWData(oldp+38,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[9]),128);
        tracep->fullWData(oldp+42,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[10]),128);
        tracep->fullWData(oldp+46,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[11]),128);
        tracep->fullWData(oldp+50,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[12]),128);
        tracep->fullWData(oldp+54,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[13]),128);
        tracep->fullWData(oldp+58,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[14]),128);
        tracep->fullWData(oldp+62,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data[15]),128);
        tracep->fullCData(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess),8);
        tracep->fullQData(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDin),64);
        tracep->fullBit(oldp+69,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))));
        tracep->fullBit(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit));
        tracep->fullQData(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout),64);
        tracep->fullBit(oldp+73,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))));
        tracep->fullWData(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout),128);
        tracep->fullCData(oldp+78,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg),2);
        tracep->fullCData(oldp+79,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict),2);
        tracep->fullCData(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask),2);
        tracep->fullIData(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__m),32);
        tracep->fullCData(oldp+82,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg),2);
        tracep->fullCData(oldp+83,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict),2);
        tracep->fullCData(oldp+84,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask),2);
        tracep->fullBit(oldp+85,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset));
        tracep->fullBit(oldp+86,(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset));
        tracep->fullBit(oldp+87,(vlTOPp->toplevel__DOT__dmem_ready));
        tracep->fullBit(oldp+88,(vlTOPp->toplevel__DOT__dmem_done));
        tracep->fullBit(oldp+89,(vlTOPp->toplevel__DOT__imem_ready));
        tracep->fullBit(oldp+90,(vlTOPp->toplevel__DOT__cpu__DOT__stall));
        tracep->fullBit(oldp+91,(vlTOPp->toplevel__DOT__cpu__DOT__cacheMemWen));
        tracep->fullBit(oldp+92,(vlTOPp->toplevel__DOT__cpu__DOT__memRen));
        tracep->fullBit(oldp+93,(vlTOPp->toplevel__DOT__cpu__DOT__memWen));
        tracep->fullIData(oldp+94,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr),32);
        tracep->fullIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC),32);
        tracep->fullIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC),32);
        tracep->fullIData(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC),32);
        tracep->fullIData(oldp+98,(((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),32);
        tracep->fullIData(oldp+99,((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                    + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)),32);
        tracep->fullIData(oldp+100,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
                                      : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                                          ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                                          : ((IData)(4U) 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)))),32);
        tracep->fullBit(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
        tracep->fullBit(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
        tracep->fullIData(oldp+103,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC)),32);
        tracep->fullIData(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend),32);
        tracep->fullIData(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend),32);
        tracep->fullIData(oldp+106,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                          == (0x1fU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0xfU)))) 
                                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                     [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0xfU))])),32);
        tracep->fullIData(oldp+107,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                          == (0x1fU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0x14U)))) 
                                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                     [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x14U))])),32);
        tracep->fullIData(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA),32);
        tracep->fullIData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB),32);
        tracep->fullCData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3),3);
        tracep->fullCData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7),7);
        tracep->fullCData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2),5);
        tracep->fullCData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1),5);
        tracep->fullCData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd),5);
        tracep->fullBit(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst));
        tracep->fullBit(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc));
        tracep->fullBit(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC));
        tracep->fullBit(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump));
        tracep->fullBit(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR));
        tracep->fullCData(oldp+120,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl),3);
        tracep->fullBit(oldp+121,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead));
        tracep->fullBit(oldp+122,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite));
        tracep->fullBit(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg));
        tracep->fullBit(oldp+124,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite));
        tracep->fullCData(oldp+125,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3),3);
        tracep->fullCData(oldp+126,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3),3);
        tracep->fullCData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr),5);
        tracep->fullIData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut),32);
        tracep->fullIData(oldp+129,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut),32);
        tracep->fullBit(oldp+130,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero));
        tracep->fullBit(oldp+131,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR));
        tracep->fullCData(oldp+132,((0xfU & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
        tracep->fullIData(oldp+133,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData),32);
        tracep->fullIData(oldp+134,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
        tracep->fullBit(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead));
        tracep->fullBit(oldp+136,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite));
        tracep->fullBit(oldp+137,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
        tracep->fullBit(oldp+138,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
        tracep->fullIData(oldp+139,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut),32);
        tracep->fullCData(oldp+140,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr),5);
        tracep->fullIData(oldp+141,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut),32);
        tracep->fullBit(oldp+142,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg));
        tracep->fullBit(oldp+143,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite));
        tracep->fullIData(oldp+144,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA),32);
        tracep->fullIData(oldp+145,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB),32);
        tracep->fullIData(oldp+146,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val),32);
        tracep->fullIData(oldp+147,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                       ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                       : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                                     + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend)),32);
        tracep->fullIData(oldp+148,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA),32);
        tracep->fullIData(oldp+149,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB),32);
        tracep->fullIData(oldp+150,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                      ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                          ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
                                          : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                              ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half)
                                              : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))
                                      : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                                          ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut
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
        tracep->fullIData(oldp+151,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData),32);
        tracep->fullBit(oldp+152,((0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val)));
        tracep->fullBit(oldp+153,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
        tracep->fullBit(oldp+154,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
        tracep->fullBit(oldp+155,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
        tracep->fullBit(oldp+156,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
        tracep->fullBit(oldp+157,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
        tracep->fullBit(oldp+158,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc));
        tracep->fullBit(oldp+159,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
        tracep->fullBit(oldp+160,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
        tracep->fullBit(oldp+161,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
        tracep->fullBit(oldp+162,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
        tracep->fullBit(oldp+163,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
        tracep->fullBit(oldp+164,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch));
        tracep->fullBit(oldp+165,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid));
        tracep->fullBit(oldp+166,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex));
        tracep->fullBit(oldp+167,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem));
        tracep->fullBit(oldp+168,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
        tracep->fullBit(oldp+169,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc));
        tracep->fullCData(oldp+170,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),7);
        tracep->fullCData(oldp+171,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                           >> 0xcU))),3);
        tracep->fullCData(oldp+172,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl),3);
        tracep->fullCData(oldp+173,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                              >> 0x19U))),7);
        tracep->fullCData(oldp+174,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                              >> 0xfU))),5);
        tracep->fullCData(oldp+175,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                              >> 0x14U))),5);
        tracep->fullCData(oldp+176,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                              >> 7U))),5);
        tracep->fullCData(oldp+177,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                                      ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                                      : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2))),5);
        tracep->fullCData(oldp+178,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp),4);
        tracep->fullCData(oldp+179,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA),2);
        tracep->fullCData(oldp+180,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB),2);
        tracep->fullIData(oldp+181,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i),32);
        tracep->fullIData(oldp+182,(((0xfffff000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                                     ((0xfe0U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0x14U)) 
                                      | (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 7U))))),32);
        tracep->fullIData(oldp+183,(((0xfffff000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                      >> 0x1fU)))) 
                                       << 0xcU)) | 
                                     ((0x800U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 << 4U)) 
                                      | ((0x7e0U & 
                                          (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                           >> 0x14U)) 
                                         | (0x1eU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 7U)))))),32);
        tracep->fullIData(oldp+184,((0xfffff000U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),32);
        tracep->fullIData(oldp+185,(((0xfff00000U & 
                                      ((- (IData)((1U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                      >> 0x1fU)))) 
                                       << 0x14U)) | 
                                     ((0xff000U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr) 
                                      | ((0x800U & 
                                          (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                           >> 9U)) 
                                         | ((0x7e0U 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x14U)) 
                                            | (0x1eU 
                                               & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 0x14U))))))),32);
        tracep->fullBit(oldp+186,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow));
        tracep->fullIData(oldp+187,((0x1ffffffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 7U))),25);
        tracep->fullIData(oldp+188,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i),32);
        tracep->fullIData(oldp+189,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0]),32);
        tracep->fullIData(oldp+190,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1]),32);
        tracep->fullIData(oldp+191,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2]),32);
        tracep->fullIData(oldp+192,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3]),32);
        tracep->fullIData(oldp+193,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4]),32);
        tracep->fullIData(oldp+194,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5]),32);
        tracep->fullIData(oldp+195,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6]),32);
        tracep->fullIData(oldp+196,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7]),32);
        tracep->fullIData(oldp+197,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8]),32);
        tracep->fullIData(oldp+198,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9]),32);
        tracep->fullIData(oldp+199,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[10]),32);
        tracep->fullIData(oldp+200,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[11]),32);
        tracep->fullIData(oldp+201,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[12]),32);
        tracep->fullIData(oldp+202,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[13]),32);
        tracep->fullIData(oldp+203,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[14]),32);
        tracep->fullIData(oldp+204,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[15]),32);
        tracep->fullIData(oldp+205,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[16]),32);
        tracep->fullIData(oldp+206,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[17]),32);
        tracep->fullIData(oldp+207,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[18]),32);
        tracep->fullIData(oldp+208,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[19]),32);
        tracep->fullIData(oldp+209,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[20]),32);
        tracep->fullIData(oldp+210,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[21]),32);
        tracep->fullIData(oldp+211,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[22]),32);
        tracep->fullIData(oldp+212,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[23]),32);
        tracep->fullIData(oldp+213,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[24]),32);
        tracep->fullIData(oldp+214,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[25]),32);
        tracep->fullIData(oldp+215,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[26]),32);
        tracep->fullIData(oldp+216,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[27]),32);
        tracep->fullIData(oldp+217,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[28]),32);
        tracep->fullIData(oldp+218,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[29]),32);
        tracep->fullIData(oldp+219,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[30]),32);
        tracep->fullIData(oldp+220,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[31]),32);
        tracep->fullQData(oldp+221,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub),33);
        tracep->fullCData(oldp+223,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),2);
        tracep->fullBit(oldp+224,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                         >> 0x1fU))));
        tracep->fullCData(oldp+225,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)),2);
        tracep->fullCData(oldp+226,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel),8);
        tracep->fullSData(oldp+227,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half),16);
        tracep->fullCData(oldp+228,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0]),2);
        tracep->fullCData(oldp+229,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1]),2);
        tracep->fullCData(oldp+230,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2]),2);
        tracep->fullCData(oldp+231,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3]),2);
        tracep->fullCData(oldp+232,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0]),2);
        tracep->fullCData(oldp+233,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1]),2);
        tracep->fullCData(oldp+234,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2]),2);
        tracep->fullCData(oldp+235,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3]),2);
        tracep->fullCData(oldp+236,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [0U][0U]),2);
        tracep->fullCData(oldp+237,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [0U][1U]),2);
        tracep->fullCData(oldp+238,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [1U][0U]),2);
        tracep->fullCData(oldp+239,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [1U][1U]),2);
        tracep->fullCData(oldp+240,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [2U][0U]),2);
        tracep->fullCData(oldp+241,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [2U][1U]),2);
        tracep->fullCData(oldp+242,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [3U][0U]),2);
        tracep->fullCData(oldp+243,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [3U][1U]),2);
        __Vtemp15[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][0U];
        __Vtemp15[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][1U];
        __Vtemp15[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][2U];
        __Vtemp15[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][3U];
        tracep->fullWData(oldp+244,(__Vtemp15),128);
        __Vtemp16[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][0U];
        __Vtemp16[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][1U];
        __Vtemp16[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][2U];
        __Vtemp16[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][3U];
        tracep->fullWData(oldp+248,(__Vtemp16),128);
        __Vtemp17[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][0U];
        __Vtemp17[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][1U];
        __Vtemp17[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][2U];
        __Vtemp17[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][3U];
        tracep->fullWData(oldp+252,(__Vtemp17),128);
        __Vtemp18[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][0U];
        __Vtemp18[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][1U];
        __Vtemp18[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][2U];
        __Vtemp18[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][3U];
        tracep->fullWData(oldp+256,(__Vtemp18),128);
        __Vtemp19[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][0U];
        __Vtemp19[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][1U];
        __Vtemp19[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][2U];
        __Vtemp19[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][3U];
        tracep->fullWData(oldp+260,(__Vtemp19),128);
        __Vtemp20[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][0U];
        __Vtemp20[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][1U];
        __Vtemp20[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][2U];
        __Vtemp20[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][3U];
        tracep->fullWData(oldp+264,(__Vtemp20),128);
        __Vtemp21[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][0U];
        __Vtemp21[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][1U];
        __Vtemp21[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][2U];
        __Vtemp21[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][3U];
        tracep->fullWData(oldp+268,(__Vtemp21),128);
        __Vtemp22[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][0U];
        __Vtemp22[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][1U];
        __Vtemp22[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][2U];
        __Vtemp22[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][3U];
        tracep->fullWData(oldp+272,(__Vtemp22),128);
        tracep->fullIData(oldp+276,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j),32);
        tracep->fullCData(oldp+277,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne),2);
        tracep->fullCData(oldp+278,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0]),2);
        tracep->fullCData(oldp+279,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1]),2);
        tracep->fullCData(oldp+280,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2]),2);
        tracep->fullCData(oldp+281,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3]),2);
        tracep->fullCData(oldp+282,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0]),2);
        tracep->fullCData(oldp+283,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1]),2);
        tracep->fullCData(oldp+284,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2]),2);
        tracep->fullCData(oldp+285,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3]),2);
        tracep->fullCData(oldp+286,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0]),2);
        tracep->fullCData(oldp+287,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1]),2);
        tracep->fullCData(oldp+288,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2]),2);
        tracep->fullCData(oldp+289,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3]),2);
        tracep->fullCData(oldp+290,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [0U][0U]),2);
        tracep->fullCData(oldp+291,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [0U][1U]),2);
        tracep->fullCData(oldp+292,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [1U][0U]),2);
        tracep->fullCData(oldp+293,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [1U][1U]),2);
        tracep->fullCData(oldp+294,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [2U][0U]),2);
        tracep->fullCData(oldp+295,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [2U][1U]),2);
        tracep->fullCData(oldp+296,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [3U][0U]),2);
        tracep->fullCData(oldp+297,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [3U][1U]),2);
        tracep->fullQData(oldp+298,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [0U][0U]),64);
        tracep->fullQData(oldp+300,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [0U][1U]),64);
        tracep->fullQData(oldp+302,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [1U][0U]),64);
        tracep->fullQData(oldp+304,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [1U][1U]),64);
        tracep->fullQData(oldp+306,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [2U][0U]),64);
        tracep->fullQData(oldp+308,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [2U][1U]),64);
        tracep->fullQData(oldp+310,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [3U][0U]),64);
        tracep->fullQData(oldp+312,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                                    [3U][1U]),64);
        tracep->fullIData(oldp+314,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__l),32);
        tracep->fullCData(oldp+315,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne),2);
        tracep->fullCData(oldp+316,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state),3);
        tracep->fullCData(oldp+317,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state),3);
        tracep->fullQData(oldp+318,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[0]),64);
        tracep->fullQData(oldp+320,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[1]),64);
        tracep->fullQData(oldp+322,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[2]),64);
        tracep->fullQData(oldp+324,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[3]),64);
        tracep->fullQData(oldp+326,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[4]),64);
        tracep->fullQData(oldp+328,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[5]),64);
        tracep->fullQData(oldp+330,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[6]),64);
        tracep->fullQData(oldp+332,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[7]),64);
        tracep->fullQData(oldp+334,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[8]),64);
        tracep->fullQData(oldp+336,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[9]),64);
        tracep->fullQData(oldp+338,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[10]),64);
        tracep->fullQData(oldp+340,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[11]),64);
        tracep->fullQData(oldp+342,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[12]),64);
        tracep->fullQData(oldp+344,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[13]),64);
        tracep->fullQData(oldp+346,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[14]),64);
        tracep->fullQData(oldp+348,(vlTOPp->toplevel__DOT__Data_Mem__DOT__data[15]),64);
        tracep->fullQData(oldp+350,((((QData)((IData)(
                                                      ((0xfU 
                                                        == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))
                                                        ? 
                                                       vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                                                       [
                                                       (0xfU 
                                                        & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][1U]
                                                        : 0U))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((0xfU 
                                                                    == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))
                                                                    ? 
                                                                   vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                                                                   [
                                                                   (0xfU 
                                                                    & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][0U]
                                                                    : 0U))))),64);
        if ((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))) {
            __Vtemp30[0U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                [(0xfU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][0U];
            __Vtemp30[1U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                [(0xfU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][1U];
            __Vtemp30[2U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                [(0xfU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][2U];
            __Vtemp30[3U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
                [(0xfU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))][3U];
        } else {
            __Vtemp30[0U] = 0U;
            __Vtemp30[1U] = 0U;
            __Vtemp30[2U] = 0U;
            __Vtemp30[3U] = 0U;
        }
        tracep->fullWData(oldp+352,(__Vtemp30),128);
        tracep->fullBit(oldp+356,((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))));
        tracep->fullCData(oldp+357,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter),4);
        tracep->fullBit(oldp+358,((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter))));
        tracep->fullCData(oldp+359,(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter),4);
        tracep->fullBit(oldp+360,((((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                    & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                   & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)))));
        tracep->fullBit(oldp+361,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
        tracep->fullBit(oldp+362,(vlTOPp->clock));
        tracep->fullBit(oldp+363,(vlTOPp->reset));
        tracep->fullQData(oldp+364,(((((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                       & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                      & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)))
                                      ? vlTOPp->toplevel__DOT__Data_Mem__DOT__data
                                     [(0xfU & (IData)((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))))]
                                      : 0ULL)),64);
        tracep->fullIData(oldp+366,((IData)(((((0xfU 
                                                == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
                                               & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
                                              & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)))
                                              ? vlTOPp->toplevel__DOT__Data_Mem__DOT__data
                                             [(0xfU 
                                               & (IData)((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))))]
                                              : 0ULL))),32);
        tracep->fullIData(oldp+367,(((IData)(vlTOPp->reset)
                                      ? (IData)((vlTOPp->toplevel__DOT__cpu__DOT__cacheDout 
                                                 >> 
                                                 (0x38U 
                                                  & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                                     << 3U))))
                                      : 0U)),32);
        tracep->fullBit(oldp+368,((((IData)(vlTOPp->reset) 
                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren)) 
                                   & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen)))));
        tracep->fullBit(oldp+369,((((IData)(vlTOPp->reset) 
                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen)) 
                                   & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren)))));
        tracep->fullIData(oldp+370,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i),32);
        tracep->fullIData(oldp+371,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i),32);
        tracep->fullIData(oldp+372,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j),32);
        tracep->fullQData(oldp+373,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din),64);
        tracep->fullBit(oldp+375,(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag));
        tracep->fullBit(oldp+376,(vlTOPp->toplevel__DOT__dmem_ren));
        tracep->fullBit(oldp+377,(vlTOPp->toplevel__DOT__dmem_wen));
        tracep->fullQData(oldp+378,((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))),64);
        tracep->fullQData(oldp+380,((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_din))),64);
        tracep->fullBit(oldp+382,(vlTOPp->toplevel__DOT__imem_ren));
        tracep->fullCData(oldp+383,(vlTOPp->toplevel__DOT__imem_block_address),8);
        tracep->fullCData(oldp+384,(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address),7);
        tracep->fullIData(oldp+385,(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_din),32);
        tracep->fullBit(oldp+386,(vlTOPp->toplevel__DOT__cpu__DOT__ren));
        tracep->fullBit(oldp+387,(vlTOPp->toplevel__DOT__cpu__DOT__wen));
        tracep->fullCData(oldp+388,(vlTOPp->toplevel__DOT__cpu__DOT__addr),7);
        tracep->fullCData(oldp+389,(vlTOPp->toplevel__DOT__cpu__DOT__byteSelectVector),4);
        tracep->fullIData(oldp+390,(vlTOPp->toplevel__DOT__cpu__DOT__din),32);
        tracep->fullBit(oldp+391,(vlTOPp->toplevel__DOT__cpu__DOT__cacheHit));
        tracep->fullBit(oldp+392,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDirtyBit));
        tracep->fullQData(oldp+393,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDout),64);
        tracep->fullBit(oldp+395,(vlTOPp->toplevel__DOT__cpu__DOT__memReadReady));
        tracep->fullBit(oldp+396,(vlTOPp->toplevel__DOT__cpu__DOT__memWriteDone));
        tracep->fullQData(oldp+397,(vlTOPp->toplevel__DOT__cpu__DOT__memDout),64);
        tracep->fullCData(oldp+399,((0xfU & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr) 
                                             >> 3U))),4);
        tracep->fullBit(oldp+400,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_stall));
        tracep->fullBit(oldp+401,(vlTOPp->toplevel__DOT__cpu__DOT__icache_stall));
        tracep->fullBit(oldp+402,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_ren));
        tracep->fullBit(oldp+403,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_wen));
        tracep->fullQData(oldp+404,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_output),64);
        tracep->fullCData(oldp+406,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_addr),4);
        tracep->fullQData(oldp+407,((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT____Vcellout__pipeline__dcache_input))),64);
        tracep->fullBit(oldp+409,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen));
        tracep->fullBit(oldp+410,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen));
        tracep->fullBit(oldp+411,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen));
        tracep->fullCData(oldp+412,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess),8);
        tracep->fullCData(oldp+413,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr),4);
        tracep->fullQData(oldp+414,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin),64);
        tracep->fullBit(oldp+416,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen));
        tracep->fullBit(oldp+417,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen));
        tracep->fullCData(oldp+418,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr),4);
        tracep->fullWData(oldp+419,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin),128);
        tracep->fullBit(oldp+423,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDirtyBit));
        tracep->fullIData(oldp+424,((IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcache_output)),32);
        tracep->fullIData(oldp+425,(vlTOPp->toplevel__DOT__cpu__DOT____Vcellout__pipeline__dcache_input),32);
        tracep->fullIData(oldp+426,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__instr),32);
        tracep->fullIData(oldp+427,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__DMemOut),32);
        tracep->fullBit(oldp+428,(1U));
        tracep->fullIData(oldp+429,(0x20U),32);
        tracep->fullCData(oldp+430,((3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr))),2);
        tracep->fullCData(oldp+431,((3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr) 
                                           >> 2U))),2);
        tracep->fullCData(oldp+432,((3U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr))),2);
        tracep->fullCData(oldp+433,((3U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr) 
                                           >> 2U))),2);
        tracep->fullBit(oldp+434,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren) 
                                    & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen))) 
                                   | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__wen) 
                                      & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__ren))))));
        tracep->fullCData(oldp+435,((7U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__addr))),3);
        tracep->fullCData(oldp+436,(0U),3);
        tracep->fullCData(oldp+437,(1U),3);
        tracep->fullCData(oldp+438,(2U),3);
        tracep->fullCData(oldp+439,(3U),3);
        tracep->fullCData(oldp+440,(4U),3);
        tracep->fullCData(oldp+441,((0xfU & (IData)(vlTOPp->toplevel__DOT__imem_block_address))),4);
        tracep->fullIData(oldp+442,(4U),32);
        tracep->fullCData(oldp+443,((0xfU & (IData)((QData)((IData)(vlTOPp->toplevel__DOT____Vcellout__cpu__dmem_block_address))))),4);
    }
}
