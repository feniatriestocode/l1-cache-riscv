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
        tracep->declBit(c+321,"clock", false,-1);
        tracep->declBit(c+322,"reset", false,-1);
        tracep->declBit(c+321,"toplevel clock", false,-1);
        tracep->declBit(c+322,"toplevel reset", false,-1);
        tracep->declBit(c+1,"toplevel dmem_ren", false,-1);
        tracep->declBit(c+2,"toplevel dmem_wen", false,-1);
        tracep->declBit(c+3,"toplevel dmem_read_ready", false,-1);
        tracep->declBit(c+4,"toplevel dmem_write_done", false,-1);
        tracep->declBus(c+286,"toplevel dmem_block_address", false,-1, 5,0);
        tracep->declArray(c+258,"toplevel dmem_din", false,-1, 127,0);
        tracep->declArray(c+317,"toplevel dmem_dout", false,-1, 127,0);
        tracep->declBit(c+5,"toplevel imem_ren", false,-1);
        tracep->declBit(c+334,"toplevel imem_read_ready", false,-1);
        tracep->declBus(c+6,"toplevel imem_block_address", false,-1, 8,0);
        tracep->declArray(c+313,"toplevel imem_dout", false,-1, 127,0);
        tracep->declBit(c+7,"toplevel imem_ready", false,-1);
        tracep->declBit(c+321,"toplevel cpu clock", false,-1);
        tracep->declBit(c+322,"toplevel cpu reset", false,-1);
        tracep->declBit(c+5,"toplevel cpu ImemRen", false,-1);
        tracep->declBus(c+6,"toplevel cpu IblockAddr", false,-1, 8,0);
        tracep->declArray(c+313,"toplevel cpu ImemDout", false,-1, 127,0);
        tracep->declBit(c+334,"toplevel cpu ImemReadReady", false,-1);
        tracep->declBit(c+1,"toplevel cpu DmemRen", false,-1);
        tracep->declBit(c+2,"toplevel cpu DmemWen", false,-1);
        tracep->declBus(c+286,"toplevel cpu DblockAddress", false,-1, 5,0);
        tracep->declArray(c+258,"toplevel cpu DmemDin", false,-1, 127,0);
        tracep->declBit(c+3,"toplevel cpu DmemReadReady", false,-1);
        tracep->declBit(c+4,"toplevel cpu DmemWriteDone", false,-1);
        tracep->declArray(c+317,"toplevel cpu DmemDout", false,-1, 127,0);
        tracep->declBit(c+335,"toplevel cpu ren", false,-1);
        tracep->declBit(c+336,"toplevel cpu wen", false,-1);
        tracep->declBus(c+337,"toplevel cpu addr", false,-1, 9,0);
        tracep->declBus(c+248,"toplevel cpu byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+338,"toplevel cpu din", false,-1, 31,0);
        tracep->declBit(c+339,"toplevel cpu cacheHit", false,-1);
        tracep->declBit(c+340,"toplevel cpu cacheDirtyBit", false,-1);
        tracep->declArray(c+341,"toplevel cpu cacheDout", false,-1, 127,0);
        tracep->declBit(c+345,"toplevel cpu memReadReady", false,-1);
        tracep->declBit(c+346,"toplevel cpu memWriteDone", false,-1);
        tracep->declArray(c+347,"toplevel cpu memDout", false,-1, 127,0);
        tracep->declBit(c+351,"toplevel cpu stall", false,-1);
        tracep->declBus(c+352,"toplevel cpu dout", false,-1, 31,0);
        tracep->declBus(c+353,"toplevel cpu BlockAddr", false,-1, 5,0);
        tracep->declBit(c+354,"toplevel cpu cacheRen", false,-1);
        tracep->declBit(c+355,"toplevel cpu cacheWen", false,-1);
        tracep->declBit(c+356,"toplevel cpu cacheMemWen", false,-1);
        tracep->declBus(c+357,"toplevel cpu cacheBytesAccess", false,-1, 15,0);
        tracep->declArray(c+358,"toplevel cpu cacheDin", false,-1, 127,0);
        tracep->declBit(c+362,"toplevel cpu memRen", false,-1);
        tracep->declBit(c+363,"toplevel cpu memWen", false,-1);
        tracep->declArray(c+364,"toplevel cpu memDin", false,-1, 127,0);
        tracep->declBit(c+368,"toplevel cpu dcache_stall", false,-1);
        tracep->declBit(c+369,"toplevel cpu icache_stall", false,-1);
        tracep->declBit(c+370,"toplevel cpu dcache_ren", false,-1);
        tracep->declBit(c+371,"toplevel cpu dcache_wen", false,-1);
        tracep->declArray(c+372,"toplevel cpu dcache_output", false,-1, 127,0);
        tracep->declBus(c+376,"toplevel cpu dcache_addr", false,-1, 5,0);
        tracep->declArray(c+377,"toplevel cpu dcache_input", false,-1, 127,0);
        tracep->declBit(c+240,"toplevel cpu DcacheRen", false,-1);
        tracep->declBit(c+241,"toplevel cpu DcacheWen", false,-1);
        tracep->declBit(c+8,"toplevel cpu DcacheMemWen", false,-1);
        tracep->declBus(c+262,"toplevel cpu DcacheBytesAccess", false,-1, 15,0);
        tracep->declBus(c+381,"toplevel cpu DcacheBlockAddr", false,-1, 5,0);
        tracep->declArray(c+263,"toplevel cpu DcacheDin", false,-1, 127,0);
        tracep->declBit(c+267,"toplevel cpu DcacheHit", false,-1);
        tracep->declBit(c+268,"toplevel cpu DcacheDirtyBit", false,-1);
        tracep->declArray(c+258,"toplevel cpu DcacheDout", false,-1, 127,0);
        tracep->declBit(c+242,"toplevel cpu IcacheRen", false,-1);
        tracep->declBit(c+9,"toplevel cpu IcacheMemWen", false,-1);
        tracep->declBus(c+382,"toplevel cpu IcacheBlockAddr", false,-1, 8,0);
        tracep->declArray(c+269,"toplevel cpu IcacheDin", false,-1, 127,0);
        tracep->declBit(c+273,"toplevel cpu IcacheHit", false,-1);
        tracep->declBit(c+383,"toplevel cpu IcacheDirtyBit", false,-1);
        tracep->declArray(c+274,"toplevel cpu IcacheDout", false,-1, 127,0);
        tracep->declBit(c+10,"toplevel cpu DcacheStall", false,-1);
        tracep->declBit(c+11,"toplevel cpu IcacheStall", false,-1);
        tracep->declBit(c+323,"toplevel cpu DpipelineOutput", false,-1);
        tracep->declBit(c+324,"toplevel cpu IpipelineOutput", false,-1);
        tracep->declBit(c+287,"toplevel cpu DcacheAddr", false,-1);
        tracep->declBit(c+12,"toplevel cpu IcacheAddr", false,-1);
        tracep->declBit(c+249,"toplevel cpu DcacheInput", false,-1);
        tracep->declBit(c+321,"toplevel cpu pipeline clock", false,-1);
        tracep->declBit(c+322,"toplevel cpu pipeline reset", false,-1);
        tracep->declBit(c+10,"toplevel cpu pipeline dcache_stall", false,-1);
        tracep->declBit(c+11,"toplevel cpu pipeline icache_stall", false,-1);
        tracep->declBus(c+325,"toplevel cpu pipeline dcache_output", false,-1, 31,0);
        tracep->declBus(c+326,"toplevel cpu pipeline icache_output", false,-1, 31,0);
        tracep->declBit(c+240,"toplevel cpu pipeline dcache_ren", false,-1);
        tracep->declBit(c+241,"toplevel cpu pipeline dcache_wen", false,-1);
        tracep->declBit(c+242,"toplevel cpu pipeline icache_ren", false,-1);
        tracep->declBus(c+288,"toplevel cpu pipeline dcache_addr", false,-1, 5,0);
        tracep->declBus(c+13,"toplevel cpu pipeline icache_addr", false,-1, 8,0);
        tracep->declBus(c+248,"toplevel cpu pipeline byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+250,"toplevel cpu pipeline dcache_input", false,-1, 31,0);
        tracep->declBus(c+14,"toplevel cpu pipeline IFID_instr", false,-1, 31,0);
        tracep->declBus(c+15,"toplevel cpu pipeline PC", false,-1, 31,0);
        tracep->declBus(c+16,"toplevel cpu pipeline IFID_PC", false,-1, 31,0);
        tracep->declBus(c+17,"toplevel cpu pipeline IDEX_PC", false,-1, 31,0);
        tracep->declBus(c+18,"toplevel cpu pipeline PCplus4", false,-1, 31,0);
        tracep->declBus(c+19,"toplevel cpu pipeline JumpAddress", false,-1, 31,0);
        tracep->declBus(c+251,"toplevel cpu pipeline PC_new", false,-1, 31,0);
        tracep->declBus(c+326,"toplevel cpu pipeline instr", false,-1, 31,0);
        tracep->declBit(c+20,"toplevel cpu pipeline inA_is_PC", false,-1);
        tracep->declBit(c+289,"toplevel cpu pipeline branch_taken", false,-1);
        tracep->declBus(c+252,"toplevel cpu pipeline BranchInA", false,-1, 31,0);
        tracep->declBus(c+21,"toplevel cpu pipeline IDEX_signExtend", false,-1, 31,0);
        tracep->declBus(c+22,"toplevel cpu pipeline signExtend", false,-1, 31,0);
        tracep->declBus(c+23,"toplevel cpu pipeline rdA", false,-1, 31,0);
        tracep->declBus(c+24,"toplevel cpu pipeline rdB", false,-1, 31,0);
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
        tracep->declBus(c+290,"toplevel cpu pipeline EXMEM_ALUOut", false,-1, 31,0);
        tracep->declBus(c+45,"toplevel cpu pipeline EXMEM_BranchALUOut", false,-1, 31,0);
        tracep->declBit(c+46,"toplevel cpu pipeline EXMEM_Zero", false,-1);
        tracep->declBit(c+47,"toplevel cpu pipeline EXMEM_JumpJALR", false,-1);
        tracep->declBus(c+248,"toplevel cpu pipeline byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+48,"toplevel cpu pipeline EXMEM_MemWriteData", false,-1, 31,0);
        tracep->declBus(c+250,"toplevel cpu pipeline MemWriteData", false,-1, 31,0);
        tracep->declBit(c+49,"toplevel cpu pipeline EXMEM_MemRead", false,-1);
        tracep->declBit(c+50,"toplevel cpu pipeline EXMEM_MemWrite", false,-1);
        tracep->declBit(c+51,"toplevel cpu pipeline EXMEM_RegWrite", false,-1);
        tracep->declBit(c+52,"toplevel cpu pipeline EXMEM_MemToReg", false,-1);
        tracep->declBus(c+53,"toplevel cpu pipeline MEMWB_DMemOut", false,-1, 31,0);
        tracep->declBus(c+54,"toplevel cpu pipeline MEMWB_RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+55,"toplevel cpu pipeline MEMWB_ALUOut", false,-1, 31,0);
        tracep->declBit(c+56,"toplevel cpu pipeline MEMWB_MemToReg", false,-1);
        tracep->declBit(c+57,"toplevel cpu pipeline MEMWB_RegWrite", false,-1);
        tracep->declBus(c+291,"toplevel cpu pipeline ALUInA", false,-1, 31,0);
        tracep->declBus(c+292,"toplevel cpu pipeline ALUInB", false,-1, 31,0);
        tracep->declBus(c+293,"toplevel cpu pipeline ALUOut", false,-1, 31,0);
        tracep->declBus(c+253,"toplevel cpu pipeline BranchALUOut", false,-1, 31,0);
        tracep->declBus(c+294,"toplevel cpu pipeline bypassOutA", false,-1, 31,0);
        tracep->declBus(c+295,"toplevel cpu pipeline bypassOutB", false,-1, 31,0);
        tracep->declBus(c+325,"toplevel cpu pipeline DMemOut", false,-1, 31,0);
        tracep->declBus(c+58,"toplevel cpu pipeline MemOut", false,-1, 31,0);
        tracep->declBus(c+59,"toplevel cpu pipeline wRegData", false,-1, 31,0);
        tracep->declBit(c+296,"toplevel cpu pipeline Zero", false,-1);
        tracep->declBit(c+60,"toplevel cpu pipeline RegDst", false,-1);
        tracep->declBit(c+61,"toplevel cpu pipeline MemRead", false,-1);
        tracep->declBit(c+62,"toplevel cpu pipeline MemWrite", false,-1);
        tracep->declBit(c+63,"toplevel cpu pipeline MemToReg", false,-1);
        tracep->declBit(c+64,"toplevel cpu pipeline ALUSrc", false,-1);
        tracep->declBit(c+297,"toplevel cpu pipeline PCSrc", false,-1);
        tracep->declBit(c+65,"toplevel cpu pipeline RegWrite", false,-1);
        tracep->declBit(c+66,"toplevel cpu pipeline Jump", false,-1);
        tracep->declBit(c+67,"toplevel cpu pipeline JumpJALR", false,-1);
        tracep->declBit(c+68,"toplevel cpu pipeline Branch", false,-1);
        tracep->declBit(c+69,"toplevel cpu pipeline IDEX_Branch", false,-1);
        tracep->declBit(c+70,"toplevel cpu pipeline EXMEM_Branch", false,-1);
        tracep->declBit(c+298,"toplevel cpu pipeline bubble_ifid", false,-1);
        tracep->declBit(c+299,"toplevel cpu pipeline bubble_idex", false,-1);
        tracep->declBit(c+300,"toplevel cpu pipeline bubble_exmem", false,-1);
        tracep->declBit(c+71,"toplevel cpu pipeline write_ifid", false,-1);
        tracep->declBit(c+384,"toplevel cpu pipeline write_idex", false,-1);
        tracep->declBit(c+384,"toplevel cpu pipeline write_exmem", false,-1);
        tracep->declBit(c+384,"toplevel cpu pipeline write_memwb", false,-1);
        tracep->declBit(c+301,"toplevel cpu pipeline write_pc", false,-1);
        tracep->declBus(c+72,"toplevel cpu pipeline opcode", false,-1, 6,0);
        tracep->declBus(c+73,"toplevel cpu pipeline funct3", false,-1, 2,0);
        tracep->declBus(c+74,"toplevel cpu pipeline ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+75,"toplevel cpu pipeline funct7", false,-1, 6,0);
        tracep->declBus(c+76,"toplevel cpu pipeline instr_rs1", false,-1, 4,0);
        tracep->declBus(c+77,"toplevel cpu pipeline instr_rs2", false,-1, 4,0);
        tracep->declBus(c+78,"toplevel cpu pipeline instr_rd", false,-1, 4,0);
        tracep->declBus(c+79,"toplevel cpu pipeline RegWriteAddr", false,-1, 4,0);
        tracep->declBus(c+80,"toplevel cpu pipeline ALUOp", false,-1, 3,0);
        tracep->declBus(c+81,"toplevel cpu pipeline bypassA", false,-1, 1,0);
        tracep->declBus(c+82,"toplevel cpu pipeline bypassB", false,-1, 1,0);
        tracep->declBus(c+83,"toplevel cpu pipeline imm_i", false,-1, 31,0);
        tracep->declBus(c+84,"toplevel cpu pipeline imm_s", false,-1, 31,0);
        tracep->declBus(c+85,"toplevel cpu pipeline imm_b", false,-1, 31,0);
        tracep->declBus(c+86,"toplevel cpu pipeline imm_u", false,-1, 31,0);
        tracep->declBus(c+87,"toplevel cpu pipeline imm_j", false,-1, 31,0);
        tracep->declBit(c+302,"toplevel cpu pipeline overflow", false,-1);
        tracep->declBit(c+303,"toplevel cpu pipeline stall_from_cache", false,-1);
        tracep->declBus(c+88,"toplevel cpu pipeline signExtendUnit instr", false,-1, 24,0);
        tracep->declBus(c+83,"toplevel cpu pipeline signExtendUnit imm_i", false,-1, 31,0);
        tracep->declBus(c+84,"toplevel cpu pipeline signExtendUnit imm_s", false,-1, 31,0);
        tracep->declBus(c+85,"toplevel cpu pipeline signExtendUnit imm_b", false,-1, 31,0);
        tracep->declBus(c+86,"toplevel cpu pipeline signExtendUnit imm_u", false,-1, 31,0);
        tracep->declBus(c+87,"toplevel cpu pipeline signExtendUnit imm_j", false,-1, 31,0);
        tracep->declBit(c+321,"toplevel cpu pipeline cpu_regs clock", false,-1);
        tracep->declBit(c+322,"toplevel cpu pipeline cpu_regs reset", false,-1);
        tracep->declBus(c+76,"toplevel cpu pipeline cpu_regs raA", false,-1, 4,0);
        tracep->declBus(c+77,"toplevel cpu pipeline cpu_regs raB", false,-1, 4,0);
        tracep->declBus(c+54,"toplevel cpu pipeline cpu_regs wa", false,-1, 4,0);
        tracep->declBit(c+57,"toplevel cpu pipeline cpu_regs wen", false,-1);
        tracep->declBus(c+59,"toplevel cpu pipeline cpu_regs wd", false,-1, 31,0);
        tracep->declBus(c+23,"toplevel cpu pipeline cpu_regs rdA", false,-1, 31,0);
        tracep->declBus(c+24,"toplevel cpu pipeline cpu_regs rdB", false,-1, 31,0);
        tracep->declBus(c+89,"toplevel cpu pipeline cpu_regs i", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+90+i*1,"toplevel cpu pipeline cpu_regs data", true,(i+0), 31,0);}}
        tracep->declBus(c+22,"toplevel cpu pipeline SignExtendSelector out", false,-1, 31,0);
        tracep->declBus(c+83,"toplevel cpu pipeline SignExtendSelector imm_i", false,-1, 31,0);
        tracep->declBus(c+84,"toplevel cpu pipeline SignExtendSelector imm_s", false,-1, 31,0);
        tracep->declBus(c+85,"toplevel cpu pipeline SignExtendSelector imm_b", false,-1, 31,0);
        tracep->declBus(c+86,"toplevel cpu pipeline SignExtendSelector imm_u", false,-1, 31,0);
        tracep->declBus(c+87,"toplevel cpu pipeline SignExtendSelector imm_j", false,-1, 31,0);
        tracep->declBus(c+72,"toplevel cpu pipeline SignExtendSelector opcode", false,-1, 6,0);
        tracep->declBit(c+60,"toplevel cpu pipeline control_main RegDst", false,-1);
        tracep->declBit(c+68,"toplevel cpu pipeline control_main Branch", false,-1);
        tracep->declBit(c+61,"toplevel cpu pipeline control_main MemRead", false,-1);
        tracep->declBit(c+62,"toplevel cpu pipeline control_main MemWrite", false,-1);
        tracep->declBit(c+63,"toplevel cpu pipeline control_main MemToReg", false,-1);
        tracep->declBit(c+64,"toplevel cpu pipeline control_main ALUSrc", false,-1);
        tracep->declBit(c+65,"toplevel cpu pipeline control_main RegWrite", false,-1);
        tracep->declBit(c+66,"toplevel cpu pipeline control_main Jump", false,-1);
        tracep->declBit(c+67,"toplevel cpu pipeline control_main JumpJALR", false,-1);
        tracep->declBit(c+20,"toplevel cpu pipeline control_main inA_is_PC", false,-1);
        tracep->declBus(c+74,"toplevel cpu pipeline control_main ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+72,"toplevel cpu pipeline control_main opcode", false,-1, 6,0);
        tracep->declBit(c+298,"toplevel cpu pipeline control_stall_id bubble_ifid", false,-1);
        tracep->declBit(c+299,"toplevel cpu pipeline control_stall_id bubble_idex", false,-1);
        tracep->declBit(c+300,"toplevel cpu pipeline control_stall_id bubble_exmem", false,-1);
        tracep->declBit(c+71,"toplevel cpu pipeline control_stall_id write_ifid", false,-1);
        tracep->declBit(c+384,"toplevel cpu pipeline control_stall_id write_idex", false,-1);
        tracep->declBit(c+384,"toplevel cpu pipeline control_stall_id write_exmem", false,-1);
        tracep->declBit(c+384,"toplevel cpu pipeline control_stall_id write_memwb", false,-1);
        tracep->declBit(c+301,"toplevel cpu pipeline control_stall_id write_pc", false,-1);
        tracep->declBus(c+76,"toplevel cpu pipeline control_stall_id ifid_rs", false,-1, 4,0);
        tracep->declBus(c+77,"toplevel cpu pipeline control_stall_id ifid_rt", false,-1, 4,0);
        tracep->declBus(c+31,"toplevel cpu pipeline control_stall_id idex_rd", false,-1, 4,0);
        tracep->declBit(c+38,"toplevel cpu pipeline control_stall_id idex_memread", false,-1);
        tracep->declBit(c+66,"toplevel cpu pipeline control_stall_id Jump", false,-1);
        tracep->declBit(c+297,"toplevel cpu pipeline control_stall_id PCSrc", false,-1);
        tracep->declBus(c+385,"toplevel cpu pipeline cpu_alu N", false,-1, 31,0);
        tracep->declBus(c+293,"toplevel cpu pipeline cpu_alu out", false,-1, 31,0);
        tracep->declBit(c+296,"toplevel cpu pipeline cpu_alu zero", false,-1);
        tracep->declBit(c+302,"toplevel cpu pipeline cpu_alu overflow", false,-1);
        tracep->declBus(c+291,"toplevel cpu pipeline cpu_alu inA", false,-1, 31,0);
        tracep->declBus(c+292,"toplevel cpu pipeline cpu_alu inB", false,-1, 31,0);
        tracep->declBus(c+80,"toplevel cpu pipeline cpu_alu op", false,-1, 3,0);
        tracep->declBus(c+293,"toplevel cpu pipeline cpu_alu out_val", false,-1, 31,0);
        tracep->declQuad(c+304,"toplevel cpu pipeline cpu_alu unsigned_sub", false,-1, 32,0);
        tracep->declBus(c+80,"toplevel cpu pipeline control_alu ALUOp", false,-1, 3,0);
        tracep->declBus(c+37,"toplevel cpu pipeline control_alu ALUcntrl", false,-1, 2,0);
        tracep->declBus(c+27,"toplevel cpu pipeline control_alu funct3", false,-1, 2,0);
        tracep->declBus(c+28,"toplevel cpu pipeline control_alu funct7", false,-1, 6,0);
        tracep->declBus(c+81,"toplevel cpu pipeline control_bypass_ex bypassA", false,-1, 1,0);
        tracep->declBus(c+82,"toplevel cpu pipeline control_bypass_ex bypassB", false,-1, 1,0);
        tracep->declBus(c+30,"toplevel cpu pipeline control_bypass_ex idex_rs1", false,-1, 4,0);
        tracep->declBus(c+29,"toplevel cpu pipeline control_bypass_ex idex_rs2", false,-1, 4,0);
        tracep->declBus(c+44,"toplevel cpu pipeline control_bypass_ex exmem_rd", false,-1, 4,0);
        tracep->declBus(c+54,"toplevel cpu pipeline control_bypass_ex memwb_rd", false,-1, 4,0);
        tracep->declBit(c+51,"toplevel cpu pipeline control_bypass_ex exmem_regwrite", false,-1);
        tracep->declBit(c+57,"toplevel cpu pipeline control_bypass_ex memwb_regwrite", false,-1);
        tracep->declBus(c+42,"toplevel cpu pipeline mem_write_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+48,"toplevel cpu pipeline mem_write_selector ALUin", false,-1, 31,0);
        tracep->declBus(c+306,"toplevel cpu pipeline mem_write_selector offset", false,-1, 1,0);
        tracep->declBus(c+248,"toplevel cpu pipeline mem_write_selector byte_select_vector", false,-1, 3,0);
        tracep->declBus(c+250,"toplevel cpu pipeline mem_write_selector out", false,-1, 31,0);
        tracep->declBit(c+289,"toplevel cpu pipeline control_branch branch_taken", false,-1);
        tracep->declBus(c+42,"toplevel cpu pipeline control_branch funct3", false,-1, 2,0);
        tracep->declBit(c+70,"toplevel cpu pipeline control_branch Branch", false,-1);
        tracep->declBit(c+46,"toplevel cpu pipeline control_branch zero", false,-1);
        tracep->declBit(c+307,"toplevel cpu pipeline control_branch sign", false,-1);
        tracep->declBus(c+43,"toplevel cpu pipeline mem_read_selector mem_select", false,-1, 2,0);
        tracep->declBus(c+53,"toplevel cpu pipeline mem_read_selector DMemOut", false,-1, 31,0);
        tracep->declBus(c+122,"toplevel cpu pipeline mem_read_selector byte_index", false,-1, 1,0);
        tracep->declBus(c+58,"toplevel cpu pipeline mem_read_selector out", false,-1, 31,0);
        tracep->declBus(c+123,"toplevel cpu pipeline mem_read_selector byte_sel", false,-1, 7,0);
        tracep->declBus(c+124,"toplevel cpu pipeline mem_read_selector half", false,-1, 15,0);
        tracep->declBit(c+321,"toplevel cpu icachecontroller2check clock", false,-1);
        tracep->declBit(c+322,"toplevel cpu icachecontroller2check reset", false,-1);
        tracep->declBit(c+242,"toplevel cpu icachecontroller2check ren", false,-1);
        tracep->declBus(c+125,"toplevel cpu icachecontroller2check addr", false,-1, 12,0);
        tracep->declBit(c+273,"toplevel cpu icachecontroller2check cacheHit", false,-1);
        tracep->declArray(c+274,"toplevel cpu icachecontroller2check cacheDout", false,-1, 127,0);
        tracep->declBit(c+334,"toplevel cpu icachecontroller2check memReadReady", false,-1);
        tracep->declArray(c+313,"toplevel cpu icachecontroller2check memDout", false,-1, 127,0);
        tracep->declBit(c+11,"toplevel cpu icachecontroller2check stall", false,-1);
        tracep->declBus(c+327,"toplevel cpu icachecontroller2check dout", false,-1, 31,0);
        tracep->declBus(c+6,"toplevel cpu icachecontroller2check BlockAddr", false,-1, 8,0);
        tracep->declBit(c+242,"toplevel cpu icachecontroller2check cacheRen", false,-1);
        tracep->declBit(c+9,"toplevel cpu icachecontroller2check cacheMemWen", false,-1);
        tracep->declArray(c+269,"toplevel cpu icachecontroller2check cacheDin", false,-1, 127,0);
        tracep->declBit(c+5,"toplevel cpu icachecontroller2check memRen", false,-1);
        tracep->declBus(c+126,"toplevel cpu icachecontroller2check blockOffset", false,-1, 3,0);
        tracep->declBus(c+386,"toplevel cpu icachecontroller2check IDLE", false,-1, 1,0);
        tracep->declBus(c+387,"toplevel cpu icachecontroller2check MEMREAD", false,-1, 1,0);
        tracep->declBus(c+388,"toplevel cpu icachecontroller2check MEMCACHE", false,-1, 1,0);
        tracep->declBus(c+127,"toplevel cpu icachecontroller2check state", false,-1, 1,0);
        tracep->declBus(c+243,"toplevel cpu icachecontroller2check next_state", false,-1, 1,0);
        tracep->declBit(c+321,"toplevel cpu Icache clk", false,-1);
        tracep->declBit(c+322,"toplevel cpu Icache rst", false,-1);
        tracep->declBit(c+242,"toplevel cpu Icache ren", false,-1);
        tracep->declBit(c+9,"toplevel cpu Icache memWen", false,-1);
        tracep->declArray(c+269,"toplevel cpu Icache dataIn", false,-1, 127,0);
        tracep->declBus(c+6,"toplevel cpu Icache blockAddr", false,-1, 8,0);
        tracep->declBit(c+273,"toplevel cpu Icache hit", false,-1);
        tracep->declArray(c+274,"toplevel cpu Icache dataOut", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+128+i*1,"toplevel cpu Icache valid_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+132+i*1,"toplevel cpu Icache status_col", true,(i+0), 1,0);}}
        tracep->declBus(c+136,"toplevel cpu Icache tag_col(0)(0)", false,-1, 6,0);
        tracep->declBus(c+137,"toplevel cpu Icache tag_col(0)(1)", false,-1, 6,0);
        tracep->declBus(c+138,"toplevel cpu Icache tag_col(1)(0)", false,-1, 6,0);
        tracep->declBus(c+139,"toplevel cpu Icache tag_col(1)(1)", false,-1, 6,0);
        tracep->declBus(c+140,"toplevel cpu Icache tag_col(2)(0)", false,-1, 6,0);
        tracep->declBus(c+141,"toplevel cpu Icache tag_col(2)(1)", false,-1, 6,0);
        tracep->declBus(c+142,"toplevel cpu Icache tag_col(3)(0)", false,-1, 6,0);
        tracep->declBus(c+143,"toplevel cpu Icache tag_col(3)(1)", false,-1, 6,0);
        tracep->declArray(c+144,"toplevel cpu Icache data_col(0)(0)", false,-1, 127,0);
        tracep->declArray(c+148,"toplevel cpu Icache data_col(0)(1)", false,-1, 127,0);
        tracep->declArray(c+152,"toplevel cpu Icache data_col(1)(0)", false,-1, 127,0);
        tracep->declArray(c+156,"toplevel cpu Icache data_col(1)(1)", false,-1, 127,0);
        tracep->declArray(c+160,"toplevel cpu Icache data_col(2)(0)", false,-1, 127,0);
        tracep->declArray(c+164,"toplevel cpu Icache data_col(2)(1)", false,-1, 127,0);
        tracep->declArray(c+168,"toplevel cpu Icache data_col(3)(0)", false,-1, 127,0);
        tracep->declArray(c+172,"toplevel cpu Icache data_col(3)(1)", false,-1, 127,0);
        tracep->declBus(c+176,"toplevel cpu Icache index", false,-1, 1,0);
        tracep->declBus(c+177,"toplevel cpu Icache tag", false,-1, 6,0);
        tracep->declBus(c+244,"toplevel cpu Icache i", false,-1, 31,0);
        tracep->declBus(c+178,"toplevel cpu Icache j", false,-1, 31,0);
        tracep->declBus(c+278,"toplevel cpu Icache hitReg", false,-1, 1,0);
        tracep->declBus(c+279,"toplevel cpu Icache blockToEvict", false,-1, 1,0);
        tracep->declBus(c+280,"toplevel cpu Icache mask", false,-1, 1,0);
        tracep->declBus(c+179,"toplevel cpu Icache statusFullOne", false,-1, 1,0);
        tracep->declBit(c+321,"toplevel cpu Dcntr clock", false,-1);
        tracep->declBit(c+322,"toplevel cpu Dcntr reset", false,-1);
        tracep->declBit(c+240,"toplevel cpu Dcntr ren", false,-1);
        tracep->declBit(c+241,"toplevel cpu Dcntr wen", false,-1);
        tracep->declBus(c+308,"toplevel cpu Dcntr addr", false,-1, 9,0);
        tracep->declBus(c+248,"toplevel cpu Dcntr byteSelectVector", false,-1, 3,0);
        tracep->declBus(c+254,"toplevel cpu Dcntr din", false,-1, 31,0);
        tracep->declBit(c+267,"toplevel cpu Dcntr cacheHit", false,-1);
        tracep->declBit(c+268,"toplevel cpu Dcntr cacheDirtyBit", false,-1);
        tracep->declArray(c+258,"toplevel cpu Dcntr cacheDout", false,-1, 127,0);
        tracep->declBit(c+3,"toplevel cpu Dcntr memReadReady", false,-1);
        tracep->declBit(c+4,"toplevel cpu Dcntr memWriteDone", false,-1);
        tracep->declArray(c+317,"toplevel cpu Dcntr memDout", false,-1, 127,0);
        tracep->declBit(c+10,"toplevel cpu Dcntr stall", false,-1);
        tracep->declBus(c+328,"toplevel cpu Dcntr dout", false,-1, 31,0);
        tracep->declBus(c+286,"toplevel cpu Dcntr BlockAddr", false,-1, 5,0);
        tracep->declBit(c+240,"toplevel cpu Dcntr cacheRen", false,-1);
        tracep->declBit(c+241,"toplevel cpu Dcntr cacheWen", false,-1);
        tracep->declBit(c+8,"toplevel cpu Dcntr cacheMemWen", false,-1);
        tracep->declBus(c+262,"toplevel cpu Dcntr cacheBytesAccess", false,-1, 15,0);
        tracep->declArray(c+263,"toplevel cpu Dcntr cacheDin", false,-1, 127,0);
        tracep->declBit(c+1,"toplevel cpu Dcntr memRen", false,-1);
        tracep->declBit(c+2,"toplevel cpu Dcntr memWen", false,-1);
        tracep->declArray(c+258,"toplevel cpu Dcntr memDin", false,-1, 127,0);
        tracep->declBit(c+245,"toplevel cpu Dcntr pipeline_req", false,-1);
        tracep->declBit(c+180,"toplevel cpu Dcntr replace", false,-1);
        tracep->declBus(c+309,"toplevel cpu Dcntr blockOffset", false,-1, 3,0);
        tracep->declBus(c+389,"toplevel cpu Dcntr IDLE", false,-1, 2,0);
        tracep->declBus(c+390,"toplevel cpu Dcntr WRITEBACK", false,-1, 2,0);
        tracep->declBus(c+391,"toplevel cpu Dcntr MEMREAD", false,-1, 2,0);
        tracep->declBus(c+392,"toplevel cpu Dcntr MEMCACHE", false,-1, 2,0);
        tracep->declBus(c+393,"toplevel cpu Dcntr WRITEBACK_REPLACE", false,-1, 2,0);
        tracep->declBus(c+181,"toplevel cpu Dcntr state", false,-1, 2,0);
        tracep->declBus(c+246,"toplevel cpu Dcntr next_state", false,-1, 2,0);
        tracep->declBit(c+321,"toplevel cpu Dcache clk", false,-1);
        tracep->declBit(c+322,"toplevel cpu Dcache rst", false,-1);
        tracep->declBit(c+240,"toplevel cpu Dcache ren", false,-1);
        tracep->declBit(c+241,"toplevel cpu Dcache wen", false,-1);
        tracep->declBit(c+8,"toplevel cpu Dcache memWen", false,-1);
        tracep->declBus(c+262,"toplevel cpu Dcache bytesAccess", false,-1, 15,0);
        tracep->declBus(c+286,"toplevel cpu Dcache blockAddr", false,-1, 5,0);
        tracep->declArray(c+263,"toplevel cpu Dcache dataIn", false,-1, 127,0);
        tracep->declBit(c+267,"toplevel cpu Dcache hit", false,-1);
        tracep->declBit(c+268,"toplevel cpu Dcache dirtyBit", false,-1);
        tracep->declArray(c+258,"toplevel cpu Dcache dataOut", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+182+i*1,"toplevel cpu Dcache valid_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+186+i*1,"toplevel cpu Dcache dirty_col", true,(i+0), 1,0);}}
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+190+i*1,"toplevel cpu Dcache status_col", true,(i+0), 1,0);}}
        tracep->declBus(c+194,"toplevel cpu Dcache tag_col(0)(0)", false,-1, 3,0);
        tracep->declBus(c+195,"toplevel cpu Dcache tag_col(0)(1)", false,-1, 3,0);
        tracep->declBus(c+196,"toplevel cpu Dcache tag_col(1)(0)", false,-1, 3,0);
        tracep->declBus(c+197,"toplevel cpu Dcache tag_col(1)(1)", false,-1, 3,0);
        tracep->declBus(c+198,"toplevel cpu Dcache tag_col(2)(0)", false,-1, 3,0);
        tracep->declBus(c+199,"toplevel cpu Dcache tag_col(2)(1)", false,-1, 3,0);
        tracep->declBus(c+200,"toplevel cpu Dcache tag_col(3)(0)", false,-1, 3,0);
        tracep->declBus(c+201,"toplevel cpu Dcache tag_col(3)(1)", false,-1, 3,0);
        tracep->declArray(c+202,"toplevel cpu Dcache data_col(0)(0)", false,-1, 127,0);
        tracep->declArray(c+206,"toplevel cpu Dcache data_col(0)(1)", false,-1, 127,0);
        tracep->declArray(c+210,"toplevel cpu Dcache data_col(1)(0)", false,-1, 127,0);
        tracep->declArray(c+214,"toplevel cpu Dcache data_col(1)(1)", false,-1, 127,0);
        tracep->declArray(c+218,"toplevel cpu Dcache data_col(2)(0)", false,-1, 127,0);
        tracep->declArray(c+222,"toplevel cpu Dcache data_col(2)(1)", false,-1, 127,0);
        tracep->declArray(c+226,"toplevel cpu Dcache data_col(3)(0)", false,-1, 127,0);
        tracep->declArray(c+230,"toplevel cpu Dcache data_col(3)(1)", false,-1, 127,0);
        tracep->declBus(c+310,"toplevel cpu Dcache index", false,-1, 1,0);
        tracep->declBus(c+311,"toplevel cpu Dcache tag", false,-1, 3,0);
        tracep->declBus(c+247,"toplevel cpu Dcache i", false,-1, 31,0);
        tracep->declBus(c+234,"toplevel cpu Dcache j", false,-1, 31,0);
        tracep->declBus(c+394,"toplevel cpu Dcache m", false,-1, 31,0);
        tracep->declBus(c+281,"toplevel cpu Dcache hitReg", false,-1, 1,0);
        tracep->declBus(c+282,"toplevel cpu Dcache blockToEvict", false,-1, 1,0);
        tracep->declBus(c+283,"toplevel cpu Dcache mask", false,-1, 1,0);
        tracep->declBus(c+312,"toplevel cpu Dcache statusFullOne", false,-1, 1,0);
        tracep->declBit(c+321,"toplevel Instruction_Mem clock", false,-1);
        tracep->declBit(c+322,"toplevel Instruction_Mem reset", false,-1);
        tracep->declBit(c+5,"toplevel Instruction_Mem ren", false,-1);
        tracep->declBus(c+6,"toplevel Instruction_Mem block_address", false,-1, 8,0);
        tracep->declBit(c+7,"toplevel Instruction_Mem ready", false,-1);
        tracep->declArray(c+313,"toplevel Instruction_Mem dout", false,-1, 127,0);
        tracep->declBit(c+255,"toplevel Instruction_Mem delayed", false,-1);
        tracep->declBit(c+284,"toplevel Instruction_Mem counter_reset", false,-1);
        tracep->declBus(c+256,"toplevel Instruction_Mem delay_counter", false,-1, 3,0);
        tracep->declBus(c+257,"toplevel Instruction_Mem i", false,-1, 31,0);
        tracep->declBus(c+395,"toplevel Instruction_Mem delay_cntr size", false,-1, 31,0);
        tracep->declBit(c+284,"toplevel Instruction_Mem delay_cntr reset", false,-1);
        tracep->declBit(c+321,"toplevel Instruction_Mem delay_cntr clk", false,-1);
        tracep->declBit(c+255,"toplevel Instruction_Mem delay_cntr hold", false,-1);
        tracep->declBus(c+256,"toplevel Instruction_Mem delay_cntr counter", false,-1, 3,0);
        tracep->declBit(c+321,"toplevel Data_Mem clock", false,-1);
        tracep->declBit(c+322,"toplevel Data_Mem reset", false,-1);
        tracep->declBit(c+1,"toplevel Data_Mem ren", false,-1);
        tracep->declBit(c+2,"toplevel Data_Mem wen", false,-1);
        tracep->declBus(c+286,"toplevel Data_Mem block_address", false,-1, 5,0);
        tracep->declArray(c+258,"toplevel Data_Mem din", false,-1, 127,0);
        tracep->declBit(c+3,"toplevel Data_Mem ready", false,-1);
        tracep->declBit(c+4,"toplevel Data_Mem done", false,-1);
        tracep->declArray(c+317,"toplevel Data_Mem dout", false,-1, 127,0);
        {int i; for (i=0; i<4; i++) {
                tracep->declBus(c+235+i*1,"toplevel Data_Mem temp_din", true,(i+0), 31,0);}}
        tracep->declBit(c+239,"toplevel Data_Mem flag", false,-1);
        tracep->declBit(c+329,"toplevel Data_Mem delayed", false,-1);
        tracep->declBit(c+285,"toplevel Data_Mem counter_reset", false,-1);
        tracep->declBus(c+330,"toplevel Data_Mem delay_counter", false,-1, 3,0);
        tracep->declBit(c+331,"toplevel Data_Mem temp_ready", false,-1);
        tracep->declBit(c+332,"toplevel Data_Mem temp_done", false,-1);
        tracep->declBus(c+333,"toplevel Data_Mem i", false,-1, 31,0);
        tracep->declBus(c+395,"toplevel Data_Mem delay_cntr size", false,-1, 31,0);
        tracep->declBit(c+285,"toplevel Data_Mem delay_cntr reset", false,-1);
        tracep->declBit(c+321,"toplevel Data_Mem delay_cntr clk", false,-1);
        tracep->declBit(c+329,"toplevel Data_Mem delay_cntr hold", false,-1);
        tracep->declBus(c+330,"toplevel Data_Mem delay_cntr counter", false,-1, 3,0);
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
    WData/*127:0*/ __Vtemp56[4];
    WData/*127:0*/ __Vtemp57[4];
    WData/*127:0*/ __Vtemp58[4];
    WData/*127:0*/ __Vtemp59[4];
    WData/*127:0*/ __Vtemp60[4];
    WData/*127:0*/ __Vtemp61[4];
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->toplevel__DOT__dmem_ren));
        tracep->fullBit(oldp+2,(vlTOPp->toplevel__DOT__dmem_wen));
        tracep->fullBit(oldp+3,(vlTOPp->toplevel__DOT__dmem_read_ready));
        tracep->fullBit(oldp+4,(vlTOPp->toplevel__DOT__dmem_write_done));
        tracep->fullBit(oldp+5,(vlTOPp->toplevel__DOT__imem_ren));
        tracep->fullSData(oldp+6,(0U),9);
        tracep->fullBit(oldp+7,(vlTOPp->toplevel__DOT__imem_ready));
        tracep->fullBit(oldp+8,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheMemWen));
        tracep->fullBit(oldp+9,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheMemWen));
        tracep->fullBit(oldp+10,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheStall));
        tracep->fullBit(oldp+11,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheStall));
        tracep->fullBit(oldp+12,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)));
        tracep->fullSData(oldp+13,((0x1ffU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),9);
        tracep->fullIData(oldp+14,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr),32);
        tracep->fullIData(oldp+15,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC),32);
        tracep->fullIData(oldp+16,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC),32);
        tracep->fullIData(oldp+17,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC),32);
        tracep->fullIData(oldp+18,(((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),32);
        tracep->fullIData(oldp+19,((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                    + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)),32);
        tracep->fullBit(oldp+20,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC));
        tracep->fullIData(oldp+21,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend),32);
        tracep->fullIData(oldp+22,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend),32);
        tracep->fullIData(oldp+23,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                      & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                         == (0x1fU 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0xfU)))) 
                                     & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                     : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                    [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                               >> 0xfU))])),32);
        tracep->fullIData(oldp+24,(((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                                      & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                                         == (0x1fU 
                                             & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                >> 0x14U)))) 
                                     & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                                     : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                                    [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                               >> 0x14U))])),32);
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
        tracep->fullIData(oldp+45,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut),32);
        tracep->fullBit(oldp+46,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero));
        tracep->fullBit(oldp+47,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR));
        tracep->fullIData(oldp+48,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData),32);
        tracep->fullBit(oldp+49,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead));
        tracep->fullBit(oldp+50,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite));
        tracep->fullBit(oldp+51,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite));
        tracep->fullBit(oldp+52,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg));
        tracep->fullIData(oldp+53,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_DMemOut),32);
        tracep->fullCData(oldp+54,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr),5);
        tracep->fullIData(oldp+55,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut),32);
        tracep->fullBit(oldp+56,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg));
        tracep->fullBit(oldp+57,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite));
        tracep->fullIData(oldp+58,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
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
        tracep->fullIData(oldp+59,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData),32);
        tracep->fullBit(oldp+60,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst));
        tracep->fullBit(oldp+61,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead));
        tracep->fullBit(oldp+62,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite));
        tracep->fullBit(oldp+63,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg));
        tracep->fullBit(oldp+64,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc));
        tracep->fullBit(oldp+65,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite));
        tracep->fullBit(oldp+66,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump));
        tracep->fullBit(oldp+67,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR));
        tracep->fullBit(oldp+68,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch));
        tracep->fullBit(oldp+69,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch));
        tracep->fullBit(oldp+70,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch));
        tracep->fullBit(oldp+71,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
        tracep->fullCData(oldp+72,((0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),7);
        tracep->fullCData(oldp+73,((7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+74,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl),3);
        tracep->fullCData(oldp+75,((0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0x19U))),7);
        tracep->fullCData(oldp+76,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+77,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+78,((0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                             >> 7U))),5);
        tracep->fullCData(oldp+79,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                                     ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                                     : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2))),5);
        tracep->fullCData(oldp+80,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp),4);
        tracep->fullCData(oldp+81,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA),2);
        tracep->fullCData(oldp+82,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB),2);
        tracep->fullIData(oldp+83,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i),32);
        tracep->fullIData(oldp+84,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0xfe0U 
                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                       >> 0x14U)) 
                                                   | (0x1fU 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                         >> 7U))))),32);
        tracep->fullIData(oldp+85,(((0xfffff000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                     >> 0x1fU)))) 
                                      << 0xcU)) | (
                                                   (0x800U 
                                                    & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                       << 4U)) 
                                                   | ((0x7e0U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                          >> 0x14U)) 
                                                      | (0x1eU 
                                                         & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                            >> 7U)))))),32);
        tracep->fullIData(oldp+86,((0xfffff000U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr)),32);
        tracep->fullIData(oldp+87,(((0xfff00000U & 
                                     ((- (IData)((1U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                     >> 0x1fU)))) 
                                      << 0x14U)) | 
                                    ((0xff000U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr) 
                                     | ((0x800U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                   >> 9U)) 
                                        | ((0x7e0U 
                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                               >> 0x14U)) 
                                           | (0x1eU 
                                              & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                 >> 0x14U))))))),32);
        tracep->fullIData(oldp+88,((0x1ffffffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_instr 
                                                  >> 7U))),25);
        tracep->fullIData(oldp+89,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i),32);
        tracep->fullIData(oldp+90,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0]),32);
        tracep->fullIData(oldp+91,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1]),32);
        tracep->fullIData(oldp+92,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2]),32);
        tracep->fullIData(oldp+93,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3]),32);
        tracep->fullIData(oldp+94,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4]),32);
        tracep->fullIData(oldp+95,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5]),32);
        tracep->fullIData(oldp+96,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6]),32);
        tracep->fullIData(oldp+97,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7]),32);
        tracep->fullIData(oldp+98,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8]),32);
        tracep->fullIData(oldp+99,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9]),32);
        tracep->fullIData(oldp+100,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[10]),32);
        tracep->fullIData(oldp+101,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[11]),32);
        tracep->fullIData(oldp+102,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[12]),32);
        tracep->fullIData(oldp+103,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[13]),32);
        tracep->fullIData(oldp+104,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[14]),32);
        tracep->fullIData(oldp+105,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[15]),32);
        tracep->fullIData(oldp+106,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[16]),32);
        tracep->fullIData(oldp+107,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[17]),32);
        tracep->fullIData(oldp+108,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[18]),32);
        tracep->fullIData(oldp+109,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[19]),32);
        tracep->fullIData(oldp+110,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[20]),32);
        tracep->fullIData(oldp+111,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[21]),32);
        tracep->fullIData(oldp+112,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[22]),32);
        tracep->fullIData(oldp+113,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[23]),32);
        tracep->fullIData(oldp+114,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[24]),32);
        tracep->fullIData(oldp+115,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[25]),32);
        tracep->fullIData(oldp+116,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[26]),32);
        tracep->fullIData(oldp+117,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[27]),32);
        tracep->fullIData(oldp+118,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[28]),32);
        tracep->fullIData(oldp+119,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[29]),32);
        tracep->fullIData(oldp+120,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[30]),32);
        tracep->fullIData(oldp+121,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[31]),32);
        tracep->fullCData(oldp+122,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)),2);
        tracep->fullCData(oldp+123,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel),8);
        tracep->fullSData(oldp+124,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half),16);
        tracep->fullSData(oldp+125,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),13);
        tracep->fullCData(oldp+126,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)),4);
        tracep->fullCData(oldp+127,(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state),2);
        tracep->fullCData(oldp+128,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0]),2);
        tracep->fullCData(oldp+129,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1]),2);
        tracep->fullCData(oldp+130,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2]),2);
        tracep->fullCData(oldp+131,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3]),2);
        tracep->fullCData(oldp+132,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0]),2);
        tracep->fullCData(oldp+133,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1]),2);
        tracep->fullCData(oldp+134,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2]),2);
        tracep->fullCData(oldp+135,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3]),2);
        tracep->fullCData(oldp+136,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [0U][0U]),7);
        tracep->fullCData(oldp+137,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [0U][1U]),7);
        tracep->fullCData(oldp+138,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [1U][0U]),7);
        tracep->fullCData(oldp+139,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [1U][1U]),7);
        tracep->fullCData(oldp+140,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [2U][0U]),7);
        tracep->fullCData(oldp+141,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [2U][1U]),7);
        tracep->fullCData(oldp+142,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [3U][0U]),7);
        tracep->fullCData(oldp+143,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                    [3U][1U]),7);
        __Vtemp46[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][0U];
        __Vtemp46[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][1U];
        __Vtemp46[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][2U];
        __Vtemp46[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][0U][3U];
        tracep->fullWData(oldp+144,(__Vtemp46),128);
        __Vtemp47[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][0U];
        __Vtemp47[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][1U];
        __Vtemp47[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][2U];
        __Vtemp47[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [0U][1U][3U];
        tracep->fullWData(oldp+148,(__Vtemp47),128);
        __Vtemp48[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][0U];
        __Vtemp48[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][1U];
        __Vtemp48[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][2U];
        __Vtemp48[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][0U][3U];
        tracep->fullWData(oldp+152,(__Vtemp48),128);
        __Vtemp49[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][0U];
        __Vtemp49[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][1U];
        __Vtemp49[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][2U];
        __Vtemp49[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [1U][1U][3U];
        tracep->fullWData(oldp+156,(__Vtemp49),128);
        __Vtemp50[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][0U];
        __Vtemp50[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][1U];
        __Vtemp50[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][2U];
        __Vtemp50[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][0U][3U];
        tracep->fullWData(oldp+160,(__Vtemp50),128);
        __Vtemp51[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][0U];
        __Vtemp51[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][1U];
        __Vtemp51[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][2U];
        __Vtemp51[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [2U][1U][3U];
        tracep->fullWData(oldp+164,(__Vtemp51),128);
        __Vtemp52[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][0U];
        __Vtemp52[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][1U];
        __Vtemp52[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][2U];
        __Vtemp52[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][0U][3U];
        tracep->fullWData(oldp+168,(__Vtemp52),128);
        __Vtemp53[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][0U];
        __Vtemp53[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][1U];
        __Vtemp53[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][2U];
        __Vtemp53[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
            [3U][1U][3U];
        tracep->fullWData(oldp+172,(__Vtemp53),128);
        tracep->fullCData(oldp+176,(0U),2);
        tracep->fullCData(oldp+177,(0U),7);
        tracep->fullIData(oldp+178,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j),32);
        tracep->fullCData(oldp+179,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne),2);
        tracep->fullBit(oldp+180,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__replace));
        tracep->fullCData(oldp+181,(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state),3);
        tracep->fullCData(oldp+182,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0]),2);
        tracep->fullCData(oldp+183,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1]),2);
        tracep->fullCData(oldp+184,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2]),2);
        tracep->fullCData(oldp+185,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3]),2);
        tracep->fullCData(oldp+186,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0]),2);
        tracep->fullCData(oldp+187,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1]),2);
        tracep->fullCData(oldp+188,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2]),2);
        tracep->fullCData(oldp+189,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3]),2);
        tracep->fullCData(oldp+190,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0]),2);
        tracep->fullCData(oldp+191,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1]),2);
        tracep->fullCData(oldp+192,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2]),2);
        tracep->fullCData(oldp+193,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3]),2);
        tracep->fullCData(oldp+194,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [0U][0U]),4);
        tracep->fullCData(oldp+195,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [0U][1U]),4);
        tracep->fullCData(oldp+196,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [1U][0U]),4);
        tracep->fullCData(oldp+197,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [1U][1U]),4);
        tracep->fullCData(oldp+198,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [2U][0U]),4);
        tracep->fullCData(oldp+199,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [2U][1U]),4);
        tracep->fullCData(oldp+200,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [3U][0U]),4);
        tracep->fullCData(oldp+201,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                    [3U][1U]),4);
        __Vtemp54[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][0U];
        __Vtemp54[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][1U];
        __Vtemp54[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][2U];
        __Vtemp54[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][0U][3U];
        tracep->fullWData(oldp+202,(__Vtemp54),128);
        __Vtemp55[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][0U];
        __Vtemp55[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][1U];
        __Vtemp55[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][2U];
        __Vtemp55[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [0U][1U][3U];
        tracep->fullWData(oldp+206,(__Vtemp55),128);
        __Vtemp56[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][0U];
        __Vtemp56[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][1U];
        __Vtemp56[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][2U];
        __Vtemp56[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][0U][3U];
        tracep->fullWData(oldp+210,(__Vtemp56),128);
        __Vtemp57[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][0U];
        __Vtemp57[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][1U];
        __Vtemp57[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][2U];
        __Vtemp57[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [1U][1U][3U];
        tracep->fullWData(oldp+214,(__Vtemp57),128);
        __Vtemp58[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][0U];
        __Vtemp58[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][1U];
        __Vtemp58[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][2U];
        __Vtemp58[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][0U][3U];
        tracep->fullWData(oldp+218,(__Vtemp58),128);
        __Vtemp59[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][0U];
        __Vtemp59[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][1U];
        __Vtemp59[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][2U];
        __Vtemp59[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [2U][1U][3U];
        tracep->fullWData(oldp+222,(__Vtemp59),128);
        __Vtemp60[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][0U];
        __Vtemp60[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][1U];
        __Vtemp60[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][2U];
        __Vtemp60[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][0U][3U];
        tracep->fullWData(oldp+226,(__Vtemp60),128);
        __Vtemp61[0U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][0U];
        __Vtemp61[1U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][1U];
        __Vtemp61[2U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][2U];
        __Vtemp61[3U] = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
            [3U][1U][3U];
        tracep->fullWData(oldp+230,(__Vtemp61),128);
        tracep->fullIData(oldp+234,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j),32);
        tracep->fullIData(oldp+235,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0]),32);
        tracep->fullIData(oldp+236,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1]),32);
        tracep->fullIData(oldp+237,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2]),32);
        tracep->fullIData(oldp+238,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3]),32);
        tracep->fullBit(oldp+239,(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag));
        tracep->fullBit(oldp+240,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen));
        tracep->fullBit(oldp+241,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen));
        tracep->fullBit(oldp+242,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen));
        tracep->fullCData(oldp+243,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                      ? (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__IcacheRen) 
                                          & (~ (IData)(
                                                       (0U 
                                                        != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)))))
                                          ? 1U : 0U)
                                      : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                                          ? ((IData)(vlTOPp->toplevel__DOT__imem_read_ready)
                                              ? 2U : 1U)
                                          : 0U))),2);
        tracep->fullIData(oldp+244,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i),32);
        tracep->fullBit(oldp+245,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen) 
                                    & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen))) 
                                   | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheWen) 
                                      & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__DcacheRen))))));
        tracep->fullCData(oldp+246,(((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                      ? 0U : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                                               ? ((1U 
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
                                               : ((1U 
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
        tracep->fullIData(oldp+247,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i),32);
        tracep->fullCData(oldp+248,((0xfU & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
        tracep->fullBit(oldp+249,((1U & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
                                              : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData)))));
        tracep->fullIData(oldp+250,(((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
        tracep->fullIData(oldp+251,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
                                      : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                                          ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                                          : ((IData)(4U) 
                                             + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)))),32);
        tracep->fullIData(oldp+252,(((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                      : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC)),32);
        tracep->fullIData(oldp+253,((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                                       ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                                       : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                                     + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend)),32);
        tracep->fullIData(oldp+254,((1U & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                            ? ((2U 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                ? (
                                                   (1U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                    ? 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 0x18U)
                                                    : 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 0x10U))
                                                : (
                                                   (1U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                                    ? 
                                                   (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                    << 8U)
                                                    : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData))
                                            : ((1U 
                                                == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                                ? (
                                                   (0U 
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
        tracep->fullBit(oldp+255,((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))));
        tracep->fullCData(oldp+256,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter),4);
        tracep->fullIData(oldp+257,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__i),32);
        tracep->fullWData(oldp+258,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout),128);
        tracep->fullSData(oldp+262,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBytesAccess),16);
        tracep->fullWData(oldp+263,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDin),128);
        tracep->fullBit(oldp+267,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))));
        tracep->fullBit(oldp+268,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheDirtyBit));
        tracep->fullWData(oldp+269,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDin),128);
        tracep->fullBit(oldp+273,((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))));
        tracep->fullWData(oldp+274,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout),128);
        tracep->fullCData(oldp+278,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg),2);
        tracep->fullCData(oldp+279,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict),2);
        tracep->fullCData(oldp+280,(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask),2);
        tracep->fullCData(oldp+281,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg),2);
        tracep->fullCData(oldp+282,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict),2);
        tracep->fullCData(oldp+283,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask),2);
        tracep->fullBit(oldp+284,(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset));
        tracep->fullBit(oldp+285,(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset));
        tracep->fullCData(oldp+286,(0U),6);
        tracep->fullBit(oldp+287,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)));
        tracep->fullCData(oldp+288,((0x3fU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),6);
        tracep->fullBit(oldp+289,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
        tracep->fullIData(oldp+290,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut),32);
        tracep->fullIData(oldp+291,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA),32);
        tracep->fullIData(oldp+292,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB),32);
        tracep->fullIData(oldp+293,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val),32);
        tracep->fullIData(oldp+294,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA),32);
        tracep->fullIData(oldp+295,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB),32);
        tracep->fullBit(oldp+296,((0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val)));
        tracep->fullBit(oldp+297,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc));
        tracep->fullBit(oldp+298,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid));
        tracep->fullBit(oldp+299,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex));
        tracep->fullBit(oldp+300,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem));
        tracep->fullBit(oldp+301,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc));
        tracep->fullBit(oldp+302,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow));
        tracep->fullBit(oldp+303,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache));
        tracep->fullQData(oldp+304,(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub),33);
        tracep->fullCData(oldp+306,((3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),2);
        tracep->fullBit(oldp+307,((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                         >> 0x1fU))));
        tracep->fullSData(oldp+308,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),10);
        tracep->fullCData(oldp+309,((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)),4);
        tracep->fullCData(oldp+310,(0U),2);
        tracep->fullCData(oldp+311,(0U),4);
        tracep->fullCData(oldp+312,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne),2);
        tracep->fullWData(oldp+313,(vlTOPp->toplevel__DOT__imem_dout),128);
        tracep->fullWData(oldp+317,(vlTOPp->toplevel__DOT__dmem_dout),128);
        tracep->fullBit(oldp+321,(vlTOPp->clock));
        tracep->fullBit(oldp+322,(vlTOPp->reset));
        tracep->fullBit(oldp+323,(((IData)(vlTOPp->reset)
                                    ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout[0U])
                                    : 0U)));
        tracep->fullBit(oldp+324,(((IData)(vlTOPp->reset)
                                    ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U])
                                    : 0U)));
        tracep->fullIData(oldp+325,(((IData)(vlTOPp->reset)
                                      ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout[0U])
                                      : 0U)),32);
        tracep->fullIData(oldp+326,(((IData)(vlTOPp->reset)
                                      ? (1U & vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U])
                                      : 0U)),32);
        tracep->fullIData(oldp+327,(((IData)(vlTOPp->reset)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__IcacheDout[0U]
                                      : 0U)),32);
        tracep->fullIData(oldp+328,(((IData)(vlTOPp->reset)
                                      ? vlTOPp->toplevel__DOT__cpu__DOT__DcacheDout[0U]
                                      : 0U)),32);
        tracep->fullBit(oldp+329,((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter))));
        tracep->fullCData(oldp+330,(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter),4);
        tracep->fullBit(oldp+331,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready));
        tracep->fullBit(oldp+332,(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
        tracep->fullIData(oldp+333,(vlTOPp->toplevel__DOT__Data_Mem__DOT__i),32);
        tracep->fullBit(oldp+334,(vlTOPp->toplevel__DOT__imem_read_ready));
        tracep->fullBit(oldp+335,(vlTOPp->toplevel__DOT__cpu__DOT__ren));
        tracep->fullBit(oldp+336,(vlTOPp->toplevel__DOT__cpu__DOT__wen));
        tracep->fullSData(oldp+337,(vlTOPp->toplevel__DOT__cpu__DOT__addr),10);
        tracep->fullIData(oldp+338,(vlTOPp->toplevel__DOT__cpu__DOT__din),32);
        tracep->fullBit(oldp+339,(vlTOPp->toplevel__DOT__cpu__DOT__cacheHit));
        tracep->fullBit(oldp+340,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDirtyBit));
        tracep->fullWData(oldp+341,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDout),128);
        tracep->fullBit(oldp+345,(vlTOPp->toplevel__DOT__cpu__DOT__memReadReady));
        tracep->fullBit(oldp+346,(vlTOPp->toplevel__DOT__cpu__DOT__memWriteDone));
        tracep->fullWData(oldp+347,(vlTOPp->toplevel__DOT__cpu__DOT__memDout),128);
        tracep->fullBit(oldp+351,(vlTOPp->toplevel__DOT__cpu__DOT__stall));
        tracep->fullIData(oldp+352,(vlTOPp->toplevel__DOT__cpu__DOT__dout),32);
        tracep->fullCData(oldp+353,(vlTOPp->toplevel__DOT__cpu__DOT__BlockAddr),6);
        tracep->fullBit(oldp+354,(vlTOPp->toplevel__DOT__cpu__DOT__cacheRen));
        tracep->fullBit(oldp+355,(vlTOPp->toplevel__DOT__cpu__DOT__cacheWen));
        tracep->fullBit(oldp+356,(vlTOPp->toplevel__DOT__cpu__DOT__cacheMemWen));
        tracep->fullSData(oldp+357,(vlTOPp->toplevel__DOT__cpu__DOT__cacheBytesAccess),16);
        tracep->fullWData(oldp+358,(vlTOPp->toplevel__DOT__cpu__DOT__cacheDin),128);
        tracep->fullBit(oldp+362,(vlTOPp->toplevel__DOT__cpu__DOT__memRen));
        tracep->fullBit(oldp+363,(vlTOPp->toplevel__DOT__cpu__DOT__memWen));
        tracep->fullWData(oldp+364,(vlTOPp->toplevel__DOT__cpu__DOT__memDin),128);
        tracep->fullBit(oldp+368,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_stall));
        tracep->fullBit(oldp+369,(vlTOPp->toplevel__DOT__cpu__DOT__icache_stall));
        tracep->fullBit(oldp+370,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_ren));
        tracep->fullBit(oldp+371,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_wen));
        tracep->fullWData(oldp+372,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_output),128);
        tracep->fullCData(oldp+376,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_addr),6);
        tracep->fullWData(oldp+377,(vlTOPp->toplevel__DOT__cpu__DOT__dcache_input),128);
        tracep->fullCData(oldp+381,(vlTOPp->toplevel__DOT__cpu__DOT__DcacheBlockAddr),6);
        tracep->fullSData(oldp+382,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheBlockAddr),9);
        tracep->fullBit(oldp+383,(vlTOPp->toplevel__DOT__cpu__DOT__IcacheDirtyBit));
        tracep->fullBit(oldp+384,(1U));
        tracep->fullIData(oldp+385,(0x20U),32);
        tracep->fullCData(oldp+386,(0U),2);
        tracep->fullCData(oldp+387,(1U),2);
        tracep->fullCData(oldp+388,(2U),2);
        tracep->fullCData(oldp+389,(0U),3);
        tracep->fullCData(oldp+390,(1U),3);
        tracep->fullCData(oldp+391,(2U),3);
        tracep->fullCData(oldp+392,(3U),3);
        tracep->fullCData(oldp+393,(4U),3);
        tracep->fullIData(oldp+394,(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__m),32);
        tracep->fullIData(oldp+395,(4U),32);
    }
}
