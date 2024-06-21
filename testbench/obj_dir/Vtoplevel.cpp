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
            VL_FATAL_MT("../src/pipelined/toplevel.v", 10, "",
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
            VL_FATAL_MT("../src/pipelined/toplevel.v", 10, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__2(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__2\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter 
        = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter;
    vlTOPp->__Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter 
        = ((IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset)
            ? 0U : (0xfU & ((IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delayed)
                             ? (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter)
                             : ((IData)(1U) + (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter)))));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__3(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__3\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    CData/*6:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    CData/*6:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31;
    CData/*6:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31;
    CData/*7:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v34;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3;
    CData/*0:0*/ __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    CData/*3:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    CData/*1:0*/ __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    CData/*3:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2;
    CData/*0:0*/ __Vdly__toplevel__DOT__Data_Mem__DOT__flag;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    WData/*127:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[4];
    WData/*127:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[4];
    WData/*127:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[4];
    WData/*127:0*/ __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[4];
    // Body
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8 = 0U;
    __Vdly__toplevel__DOT__Data_Mem__DOT__flag = vlTOPp->toplevel__DOT__Data_Mem__DOT__flag;
    vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v0 = 0U;
    vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v1 = 0U;
    vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v4 = 0U;
    vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v5 = 0U;
    vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v8 = 0U;
    vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v9 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4 = 0U;
    if ((1U & (~ (IData)(vlTOPp->reset)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__i = 0x20U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__icacheRen) {
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) {
                vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 4U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__icacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
                    }
                }
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__j = 2U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen) {
            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen) {
                vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
                }
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 4U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                    }
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 0x10U;
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                    }
                    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 0x10U;
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                        }
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j = 2U;
    }
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33 = 0U;
    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v34 = 0U;
    vlTOPp->toplevel__DOT__dmem_write_done = ((IData)(vlTOPp->reset) 
                                              & (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done));
    vlTOPp->toplevel__DOT__imem_read_ready = ((IData)(vlTOPp->reset) 
                                              & (0xfU 
                                                 == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter)));
    vlTOPp->toplevel__DOT__dmem_read_ready = ((IData)(vlTOPp->reset) 
                                              & (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready));
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__next_state)
            : 0U);
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero 
                = (0U == vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val);
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7 
                = (0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                            >> 0x19U));
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1 
                = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                            >> 0xfU));
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3 = 7U;
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut 
                = (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR)
                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA
                     : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC) 
                   + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend);
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 
                        = (0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                    >> 6U));
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 
                        = (0x7fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                    >> 6U));
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[0U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[0U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[1U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[1U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[2U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[2U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[3U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[3U];
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[0U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[0U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[1U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[1U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[2U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[2U];
                    __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[3U] 
                        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[3U];
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2 = 1U;
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA 
                = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                     & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                        == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                     >> 0xfU)))) & 
                    (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                    : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                   [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                              >> 0xfU))]);
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB 
                = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                     & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                        == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                     >> 0x14U)))) & 
                    (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))
                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                    : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data
                   [(0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                              >> 0x14U))]);
        }
    }
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr)))) {
            __Vdlyvval__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData;
            __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 = 1U;
            __Vdlyvdim0__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr;
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1 = 1U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__icacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 = 0U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0 
                    = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                             >> 4U));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 = 1U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2 
                    = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                             >> 4U));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                     >> 4U));
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                 >> 4U));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                     >> 4U));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut = 0U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state 
        = ((IData)(vlTOPp->reset) ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state)
            : 0U);
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead;
        }
    }
    if (vlTOPp->reset) {
        if ((1U & ((~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)) 
                   | (IData)(vlTOPp->toplevel__DOT__dmem_ren)))) {
            vlTOPp->toplevel__DOT__Data_Mem__DOT__i = 4U;
            vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v0 = 1U;
            __Vdly__toplevel__DOT__Data_Mem__DOT__flag = 0U;
            vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v1 = 1U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__flag)))) {
                vlTOPp->toplevel__DOT__Data_Mem__DOT__i = 4U;
                vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v4 
                    = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[0U];
                vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v4 = 1U;
                __Vdly__toplevel__DOT__Data_Mem__DOT__flag = 1U;
                vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v5 
                    = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[1U];
                vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v5 = 1U;
                vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v6 
                    = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[2U];
                vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v7 
                    = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[3U];
            }
        }
    } else {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__i = 4U;
        vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v8 = 1U;
        __Vdly__toplevel__DOT__Data_Mem__DOT__flag = 0U;
        vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v9 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen)))) {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen)))) {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 
                            = (0xfU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                       >> 6U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 
                            = (0xfU & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                       >> 6U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen)))) {
            if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen)))) {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                 >> 4U));
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                 >> 4U));
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4 = 1U;
    }
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen) {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 = 0U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0 
                    = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                             >> 4U));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                 >> 4U));
                }
            }
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 = 1U;
                __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 = 1U;
                __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2 
                    = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                             >> 4U));
                if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                 >> 4U));
                }
            }
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 = 0U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                 >> 4U));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 = 1U;
                    __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 = 1U;
                    __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6 
                        = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                 >> 4U));
                    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 = 1U;
                            __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 = 1U;
                            __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9 
                                = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                         >> 4U));
                        }
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                        if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne))) {
                            __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 = 1U;
                            __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 = 0U;
                            __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11 
                                = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                         >> 4U));
                        }
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12 = 1U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen)))) {
            if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen) {
                if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                         << 0x18U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                                           >> 8U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 = 8U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                         << 0x10U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                                           >> 0x10U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 = 0x10U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((8U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                         << 8U) | (
                                                   vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                                                   >> 0x18U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3 = 0x18U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x10U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4 = 0x20U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x20U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                         << 0x18U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                           >> 8U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5 = 0x28U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x40U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                         << 0x10U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                           >> 0x10U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6 = 0x30U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x80U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                         << 8U) | (
                                                   vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                                   >> 0x18U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7 = 0x38U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x100U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8 = 0x40U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x200U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                         << 0x18U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                           >> 8U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9 = 0x48U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x400U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                         << 0x10U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                           >> 0x10U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10 = 0x50U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x800U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                         << 8U) | (
                                                   vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                                   >> 0x18U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11 = 0x58U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x1000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12 = 0x60U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x2000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13 
                            = (0xffU & (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                        >> 8U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13 = 0x68U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x4000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14 
                            = (0xffU & (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                        >> 0x10U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14 = 0x70U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x8000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15 
                            = (0xffU & (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                        >> 0x18U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15 = 0x78U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
                if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16 = 0U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                         << 0x18U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                                           >> 8U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17 = 8U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                         << 0x10U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                                           >> 0x10U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18 = 0x10U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((8U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                         << 8U) | (
                                                   vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                                                   >> 0x18U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19 = 0x18U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x10U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20 = 0x20U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x20U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                         << 0x18U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                           >> 8U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21 = 0x28U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x40U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                         << 0x10U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                           >> 0x10U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22 = 0x30U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x80U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                         << 8U) | (
                                                   vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                                                   >> 0x18U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23 = 0x38U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x100U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24 = 0x40U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x200U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                         << 0x18U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                           >> 8U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25 = 0x48U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x400U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                         << 0x10U) 
                                        | (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                           >> 0x10U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26 = 0x50U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x800U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27 
                            = (0xffU & ((vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                         << 8U) | (
                                                   vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                                                   >> 0x18U)));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27 = 0x58U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x1000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28 
                            = (0xffU & vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U]);
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28 = 0x60U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x2000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29 
                            = (0xffU & (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                        >> 8U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29 = 0x68U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x4000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30 
                            = (0xffU & (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                        >> 0x10U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30 = 0x70U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((0x8000U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31 
                            = (0xffU & (vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                                        >> 0x18U));
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31 = 1U;
                        __Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31 = 0x78U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
            } else {
                if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
                    if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[0U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U];
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[1U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U];
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[2U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U];
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[3U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U];
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                    if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[0U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U];
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[1U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U];
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[2U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U];
                        __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[3U] 
                            = vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U];
                        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33 = 1U;
                        __Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33 
                            = (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U));
                    }
                }
            }
        }
    } else {
        __Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v34 = 1U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v1;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__tag_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[2U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[2U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[3U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col[3U][1U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[0U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[1U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][2U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[2U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0][0U][3U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v0[3U];
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[0U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[1U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][2U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[2U];
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1][1U][3U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v1[3U];
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__data_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[0U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[1U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[2U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col[3U][1U][3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v1)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__valid_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[__Vdlyvdim0__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[4U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[5U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[6U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[7U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[8U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[9U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xaU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xbU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xcU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xdU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xeU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0xfU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x10U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x11U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x12U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x13U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x14U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x15U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x16U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x17U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x18U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x19U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1aU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1bU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1cU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1dU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1eU] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_regs__DOT__data[0x1fU] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v1]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v2)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v3]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v4)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v5]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v6)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v7]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Icache__DOT__status_col__v8) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col[3U] = 0U;
    }
    vlTOPp->toplevel__DOT__Data_Mem__DOT__flag = __Vdly__toplevel__DOT__Data_Mem__DOT__flag;
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v0;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v1;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[2U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[2U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[3U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col[3U][1U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v1)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v1)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v2]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v3]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col__v4) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v0)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v1]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v2)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v3]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v4)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v5]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v6)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v7]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v8)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v9]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10] 
            = (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10] 
               | ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v10)));
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11] 
            = ((~ ((IData)(1U) << (IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11))) 
               & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
               [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v11]);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__status_col__v12) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col[3U] = 0U;
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v0);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v1);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v2);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v3);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v4);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v5);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v6);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v7);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v8);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v9);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v10);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v11);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v12);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v13);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v14);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15]
                          [0U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v15);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v16);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v17);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v18);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v19);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v20);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v21);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v22);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v23);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v24);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v25);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v26);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v27);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v28);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v29);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v30);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31) {
        VL_ASSIGNSEL_WIII(8,(IData)(__Vdlyvlsb__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31), 
                          vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                          [__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31]
                          [1U], __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v31);
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32][0U][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[0U];
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32][0U][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[1U];
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32][0U][2U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[2U];
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32][0U][3U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v32[3U];
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33][1U][0U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[0U];
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33][1U][1U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[1U];
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33][1U][2U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[2U];
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[__Vdlyvdim0__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33][1U][3U] 
            = __Vdlyvval__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v33[3U];
    }
    if (__Vdlyvset__toplevel__DOT__cpu__DOT__Dcache__DOT__data_col__v34) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[0U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[1U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[2U][1U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][0U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][0U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][0U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][0U][3U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][1U][0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][1U][1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][1U][2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col[3U][1U][3U] = 0U;
    }
    vlTOPp->toplevel__DOT__imem_ren = 0U;
    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
        vlTOPp->toplevel__DOT__imem_ren = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
            vlTOPp->toplevel__DOT__imem_ren = 1U;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__icacheStall = 0U;
    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
        vlTOPp->toplevel__DOT__cpu__DOT__icacheStall = 0U;
    } else {
        if ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
            vlTOPp->toplevel__DOT__cpu__DOT__icacheStall = 1U;
        } else {
            if ((2U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
                vlTOPp->toplevel__DOT__cpu__DOT__icacheStall = 1U;
            }
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen = 0U;
    if ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
        vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen = 0U;
    } else {
        if ((1U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
            if ((2U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))) {
                vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen = 1U;
            }
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Branch 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemToReg 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3 = 7U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC;
        }
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite = 0U;
    }
    if (vlTOPp->reset) {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr = 0U;
    }
    vlTOPp->__Vtableidx3 = vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state;
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheStall = 
        vlTOPp->__Vtable3_toplevel__DOT__cpu__DOT__dcacheStall
        [vlTOPp->__Vtableidx3];
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen = 
        vlTOPp->__Vtable3_toplevel__DOT__cpu__DOT__dcacheMemWen
        [vlTOPp->__Vtableidx3];
    vlTOPp->toplevel__DOT__dmem_ren = vlTOPp->__Vtable3_toplevel__DOT__dmem_ren
        [vlTOPp->__Vtableidx3];
    vlTOPp->toplevel__DOT__dmem_wen = vlTOPp->__Vtable3_toplevel__DOT__dmem_wen
        [vlTOPp->__Vtableidx3];
    vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__replace 
        = vlTOPp->__Vtable3_toplevel__DOT__cpu__DOT__Dcntr__DOT__replace
        [vlTOPp->__Vtableidx3];
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemWrite 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val;
        }
    }
    if (VL_UNLIKELY(((IData)(vlTOPp->toplevel__DOT__dmem_ren) 
                     & (IData)(vlTOPp->toplevel__DOT__dmem_wen)))) {
        VL_WRITEF("\nMemory ERROR (time %0#): ren and wen both active!\n\n",
                  64,VL_TIME_UNITED_Q(1));
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemToReg 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3 
                = (7U & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                         >> 0xcU));
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC = 0U;
    } else {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid) 
             & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr 
                = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst)
                    ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd)
                    : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2));
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__statusFullOne 
        = (3U & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                  [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                          >> 4U))]) & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                                        [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                >> 4U))]) 
                                       - (IData)(1U))));
    vlTOPp->__Vtableidx2 = (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Zero) 
                             << 5U) | ((0x10U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                 >> 0x1bU)) 
                                       | (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3) 
                                           << 1U) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_Branch))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken 
        = vlTOPp->__Vtable2_toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken
        [vlTOPp->__Vtableidx2];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_JumpJALR) 
           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__branch_taken));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp 
        = ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
            ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                ? 0U : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                         ? ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                             ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                 ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                     ? 4U : 3U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 
                                                   ((0U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7))
                                                     ? 6U
                                                     : 7U)
                                                    : 2U))
                             : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                 ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                     ? 9U : 8U) : (
                                                   (1U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 5U
                                                    : 0U)))
                         : 0xcU)) : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                                      ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                                          ? 0xbU : 
                                         ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                           ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                               ? 0xaU
                                               : 1U)
                                           : 1U)) : 
                                     ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUcntrl))
                                       ? 0U : ((4U 
                                                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 4U
                                                     : 3U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 
                                                    ((0U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7))
                                                      ? 6U
                                                      : 7U)
                                                     : 2U))
                                                : (
                                                   (2U 
                                                    & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 9U
                                                     : 8U)
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct3))
                                                     ? 5U
                                                     : 
                                                    ((0U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_funct7))
                                                      ? 0U
                                                      : 1U)))))));
    if (vlTOPp->reset) {
        if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc) 
             & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC_new;
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC = 0U;
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegWrite 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_RegDst 
                = vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst;
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA 
        = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr))) 
            & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr) 
               == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1)))
            ? 2U : ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr))) 
                     & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs1)))
                     ? 1U : 0U));
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd 
                = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                            >> 7U));
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2 = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache)))) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2 
                = (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                            >> 0x14U));
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem = 0U;
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_exmem = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__stall_from_cache 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheStall) 
           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheStall));
    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__statusFullOne 
        = (3U & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                  [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                          >> 4U))]) & ((~ vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                                        [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                                >> 4U))]) 
                                       - (IData)(1U))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB 
        = ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWrite) 
             & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr))) 
            & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_RegWriteAddr) 
               == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2)))
            ? 2U : ((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWrite) 
                      & (0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr))) 
                     & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_RegWriteAddr) 
                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rs2)))
                     ? 1U : 0U));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__4(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__4\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter 
        = ((IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset)
            ? 0U : (0xfU & ((IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delayed)
                             ? (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)
                             : ((IData)(1U) + (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)))));
    vlTOPp->toplevel__DOT__Data_Mem__DOT__delayed = 
        (0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter));
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__5(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__5\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v0;
    CData/*0:0*/ __Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0;
    CData/*5:0*/ __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v1;
    CData/*5:0*/ __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v2;
    CData/*5:0*/ __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v3;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v0;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v1;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v2;
    IData/*31:0*/ __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v3;
    // Body
    if (vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__i = 4U;
    }
    __Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0 = 0U;
    if (vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done) {
        __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v0 
            = vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din
            [0U];
        __Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0 = 1U;
        __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v0 
            = vlTOPp->toplevel__DOT__dmem_block_address;
        __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v1 
            = vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din
            [1U];
        __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v1 
            = vlTOPp->toplevel__DOT__dmem_block_address;
        __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v2 
            = vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din
            [2U];
        __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v2 
            = vlTOPp->toplevel__DOT__dmem_block_address;
        __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v3 
            = vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din
            [3U];
        __Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v3 
            = vlTOPp->toplevel__DOT__dmem_block_address;
    }
    if (__Vdlyvset__toplevel__DOT__Data_Mem__DOT__data__v0) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__data[__Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v0][0U] 
            = __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v0;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__data[__Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v1][1U] 
            = __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v1;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__data[__Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v2][2U] 
            = __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v2;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__data[__Vdlyvdim0__toplevel__DOT__Data_Mem__DOT__data__v3][3U] 
            = __Vdlyvval__toplevel__DOT__Data_Mem__DOT__data__v3;
    }
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__7(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__7\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter 
        = vlTOPp->__Vdly__toplevel__DOT__Instruction_Mem__DOT__delay_counter;
    vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delayed 
        = (0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter));
    if ((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))) {
        vlTOPp->toplevel__DOT__Instruction_Mem__DOT__i = 4U;
    }
    if ((0xfU == (IData)(vlTOPp->toplevel__DOT__Instruction_Mem__DOT__delay_counter))) {
        vlTOPp->toplevel__DOT__imem_dout[0U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[1U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[2U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[3U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[0U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
            [vlTOPp->toplevel__DOT__imem_block_address]
            [0U];
        vlTOPp->toplevel__DOT__imem_dout[1U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
            [vlTOPp->toplevel__DOT__imem_block_address]
            [1U];
        vlTOPp->toplevel__DOT__imem_dout[2U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
            [vlTOPp->toplevel__DOT__imem_block_address]
            [2U];
        vlTOPp->toplevel__DOT__imem_dout[3U] = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__data
            [vlTOPp->toplevel__DOT__imem_block_address]
            [3U];
    } else {
        vlTOPp->toplevel__DOT__imem_dout[0U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[1U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[2U] = 0U;
        vlTOPp->toplevel__DOT__imem_dout[3U] = 0U;
    }
}

VL_INLINE_OPT void Vtoplevel::_combo__TOP__8(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_combo__TOP__8\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen = (((IData)(vlTOPp->reset) 
                                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead)) 
                                                  & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite)));
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen = (((IData)(vlTOPp->reset) 
                                                   & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite)) 
                                                  & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead)));
    vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = (1U & ((~ (IData)(vlTOPp->reset)) | (~ (IData)(vlTOPp->toplevel__DOT__imem_ren))));
    if (vlTOPp->reset) {
        vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess 
            = (((~ ((IData)(0xfU) << (0xcU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))) 
                & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess)) 
               | ((0xfU & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                            ? ((IData)(1U) << (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                            : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
                                ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)
                                    ? 0xcU : 3U) : 0xfU))) 
                  << (0xcU & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut)));
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__bytesAccess = 0U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
        = ((IData)(vlTOPp->reset) ? vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[
           (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                  >> 2U))] : 0U);
    vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset 
        = (1U & (((~ (IData)(vlTOPp->reset)) | ((~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)) 
                                                & (~ (IData)(vlTOPp->toplevel__DOT__dmem_ren)))) 
                 | ((IData)(vlTOPp->toplevel__DOT__dmem_wen) 
                    & (IData)(vlTOPp->toplevel__DOT__dmem_ren))));
    if (vlTOPp->reset) {
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[0U] 
            = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen)
                ? vlTOPp->toplevel__DOT__imem_dout[0U]
                : 0U);
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[1U] 
            = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen)
                ? vlTOPp->toplevel__DOT__imem_dout[1U]
                : 0U);
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[2U] 
            = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen)
                ? vlTOPp->toplevel__DOT__imem_dout[2U]
                : 0U);
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[3U] 
            = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen)
                ? vlTOPp->toplevel__DOT__imem_dout[3U]
                : 0U);
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__icacheDin[3U] = 0U;
    }
    if (((IData)(vlTOPp->reset) & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen) 
                                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen)) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__mask = 3U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[0U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[1U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[2U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[3U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict = 0U;
    if (((IData)(vlTOPp->reset) & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheRen) 
                                    | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheWen)) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg 
            = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)) 
               | ((vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                   [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                           >> 4U))][0U] == (0xfU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                             >> 6U))) 
                  & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                  [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                          >> 4U))]));
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict 
            = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict)) 
               | ((3U == vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                   [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                           >> 4U))]) ? (0U == (1U & 
                                               vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                                               [(3U 
                                                 & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                    >> 4U))]))
                   : (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                             [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U))]))));
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg 
            = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)) 
               | (0xfffffffeU & (((vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__tag_col
                                   [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                           >> 4U))]
                                   [1U] == (0xfU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                             >> 6U))) 
                                  << 1U) & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                                 [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                         >> 4U))])));
        vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict 
            = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict)) 
               | (((3U == vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))]) ? (1U == (3U 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__status_col
                                                [(3U 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                                     >> 4U))]))
                    : (1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__valid_col
                              [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                      >> 4U))]))) << 1U));
        if ((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg))) {
            if ((1U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg) 
                       >> (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j)))) {
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[0U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][0U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[1U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][1U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[2U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][2U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[3U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][3U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit 
                    = (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                       [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                               >> 4U))]);
            }
            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
            if ((1U & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg) 
                       >> (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__j)))) {
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[0U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][0U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[1U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][1U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[2U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][2U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[3U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][3U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit 
                    = (1U & (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                             [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U))] >> 1U));
            }
        } else {
            if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[0U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][0U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[1U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][1U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[2U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][2U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[3U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][0U][3U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit 
                    = (1U & vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                       [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                               >> 4U))]);
            }
            vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__i = 2U;
            if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__blockToEvict))) {
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[0U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][0U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[1U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][1U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[2U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][2U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[3U] 
                    = vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__data_col
                    [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                            >> 4U))][1U][3U];
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit 
                    = (1U & (vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__dirty_col
                             [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                     >> 4U))] >> 1U));
            }
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex = 0U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex = 1U;
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_idex = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i 
        = ((0xfffff000U & ((- (IData)((1U & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                             >> 0x1fU)))) 
                           << 0xcU)) | (0xfffU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                  >> 0x14U)));
    vlTOPp->__Vtableidx1 = (0x7fU & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__RegDst
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemRead
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemWrite
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__MemToReg
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__ALUSrc
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__RegWrite
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Branch 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__Branch
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__Jump
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__JumpJALR
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__inA_is_PC
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl 
        = vlTOPp->__Vtable1_toplevel__DOT__cpu__DOT__pipeline__DOT__ALUcntrl
        [vlTOPp->__Vtableidx1];
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid = 1U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid = 0U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__next_state 
        = ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
            ? 0U : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                     ? ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                         ? (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite) 
                             & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead)))
                             ? 4U : 0U) : ((IData)(vlTOPp->toplevel__DOT__dmem_read_ready)
                                            ? 3U : 2U))
                     : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__state))
                         ? ((IData)(vlTOPp->toplevel__DOT__dmem_write_done)
                             ? 2U : 1U) : (((((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead) 
                                              & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite))) 
                                             | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWrite) 
                                                & (~ (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemRead)))) 
                                            & (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Dcache__DOT__hitReg)))))
                                            ? ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__dcacheDirtyBit)
                                                ? 1U
                                                : 2U)
                                            : 0U))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn 
        = ((IData)(vlTOPp->reset) ? vlTOPp->toplevel__DOT__cpu__DOT__dcacheDout[
           (3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                  >> 2U))] : 0U);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend 
        = ((0x40U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
            ? ((0x20U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                ? ((0x10U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                    ? 0U : ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                             ? ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                 ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                     ? ((1U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                         ? ((0xfff00000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                               >> 0x1fU)))) 
                                                << 0x14U)) 
                                            | ((0xff000U 
                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn) 
                                               | ((0x800U 
                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                      >> 9U)) 
                                                  | ((0x7e0U 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                         >> 0x14U)) 
                                                     | (0x1eU 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                           >> 0x14U))))))
                                         : 0U) : 0U)
                                 : 0U) : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                           ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i
                                                   : 0U)
                                               : 0U)
                                           : ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   ? 
                                                  ((0xfffff000U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                                      >> 0x1fU)))) 
                                                       << 0xcU)) 
                                                   | ((0x800U 
                                                       & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                          << 4U)) 
                                                      | ((0x7e0U 
                                                          & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                             >> 0x14U)) 
                                                         | (0x1eU 
                                                            & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                               >> 7U)))))
                                                   : 0U)
                                               : 0U))))
                : 0U) : ((0x20U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                          ? ((0x10U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                              ? ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                  ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                           ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   : 0U)
                                               : 0U)
                                           : 0U)) : 
                             ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                               ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                        ? 0U : ((2U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                 ? 
                                                ((1U 
                                                  & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                  ? 
                                                 ((0xfffff000U 
                                                   & ((- (IData)(
                                                                 (1U 
                                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                                     >> 0x1fU)))) 
                                                      << 0xcU)) 
                                                  | ((0xfe0U 
                                                      & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                         >> 0x14U)) 
                                                     | (0x1fU 
                                                        & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                           >> 7U))))
                                                  : 0U)
                                                 : 0U))))
                          : ((0x10U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                              ? ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                  ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                           ? ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   ? 
                                                  (0xfffff000U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   : 0U)
                                               : 0U)
                                           : ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                               ? ((1U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                   ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i
                                                   : 0U)
                                               : 0U)))
                              : ((8U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                  ? 0U : ((4U & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                           ? 0U : (
                                                   (2U 
                                                    & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                    ? 
                                                   ((1U 
                                                     & vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn)
                                                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__imm_i
                                                     : 0U)
                                                    : 0U))))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid = 0U;
    if ((1U & (~ ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
                  & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                      == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                   >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                                 == 
                                                 (0x1fU 
                                                  & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                                     >> 0x14U)))))))) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid = 1U;
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bubble_ifid = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 1U;
    if (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_MemRead) 
         & (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
             == (0x1fU & (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                          >> 0xfU))) | ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_instr_rd) 
                                        == (0x1fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipelineInstrIn 
                                             >> 0x14U)))))) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 0U;
    } else {
        if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump) {
            vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 1U;
        }
    }
    if (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc) {
        vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_pc = 1U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__icacheRen = ((IData)(vlTOPp->reset) 
                                                  & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel 
        = (0xffU & ((0U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut))
                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn
                     : ((1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut))
                         ? (vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn 
                            >> 8U) : ((2U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut))
                                       ? (vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn 
                                          >> 0x10U)
                                       : (vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn 
                                          >> 0x18U)))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half 
        = (0xffffU & ((2U & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut)
                       ? (vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn 
                          >> 0x10U) : vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC_new 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PCSrc)
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_BranchALUOut
            : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__Jump)
                ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IFID_PC 
                   + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__signExtend)
                : ((IData)(4U) + vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC)));
    if (((IData)(vlTOPp->reset) & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__mask = 3U;
    }
    if (((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
    }
    if (((IData)(vlTOPp->reset) & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen)))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__i = 2U;
    }
    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict = 0U;
    if (((IData)(vlTOPp->reset) & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheMemWen) 
                                   | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen)))) {
        if ((3U == vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
             [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                     >> 4U))])) {
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                             [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                     >> 4U))])));
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | ((1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__status_col
                              [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                      >> 4U))])) << 1U));
        } else {
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | (0U == (1U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                             [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                     >> 4U))])));
            vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict 
                = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__blockToEvict)) 
                   | ((1U == (3U & vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                              [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                      >> 4U))])) << 1U));
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[0U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[1U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[2U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[3U] = 0U;
    vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg = 0U;
    if (((IData)(vlTOPp->reset) & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icacheRen))) {
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg 
            = ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)) 
               | (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                  [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                          >> 4U))] & (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                      [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                              >> 4U))]
                                      [0U] == (0x7fU 
                                               & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                                  >> 6U)))));
        vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg 
            = ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)) 
               | (0xfffffffeU & (vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__valid_col
                                 [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                         >> 4U))] & 
                                 ((vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__tag_col
                                   [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                           >> 4U))]
                                   [1U] == (0x7fU & 
                                            (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                                             >> 6U))) 
                                  << 1U))));
        if ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[0U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][0U][0U];
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[1U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][0U][1U];
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[2U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][0U][2U];
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[3U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][0U][3U];
        }
        if ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg))) {
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[0U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][1U][0U];
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[1U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][1U][1U];
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[2U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][1U][2U];
            vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[3U] 
                = vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__data_col
                [(3U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__PC 
                        >> 4U))][1U][3U];
        }
    }
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_MemToReg)
            ? ((4U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                ? ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn
                    : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                        ? (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half)
                        : (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))
                : ((2U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                    ? vlTOPp->toplevel__DOT__cpu__DOT__pipelineDataIn
                    : ((1U & (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_funct3))
                        ? ((0xffff0000U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half) 
                                                          >> 0xfU)))) 
                                           << 0x10U)) 
                           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__half))
                        : ((0xffffff00U & ((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel) 
                                                          >> 7U)))) 
                                           << 8U)) 
                           | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__mem_read_selector__DOT__byte_sel)))))
            : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__MEMWB_ALUOut);
    vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__next_state 
        = ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
            ? (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__write_ifid) 
                & (~ (IData)((0U != (IData)(vlTOPp->toplevel__DOT__cpu__DOT__Icache__DOT__hitReg)))))
                ? 1U : 0U) : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__icachecontroller2check__DOT__state))
                               ? ((IData)(vlTOPp->toplevel__DOT__imem_read_ready)
                                   ? 2U : 1U) : 0U));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA 
        = ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA))
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdA
            : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassA))
                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB 
        = ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB))
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_rdB
            : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassB))
                ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__wRegData
                : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
        = ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_inA_is_PC)
            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_PC
            : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutA);
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB 
        = (((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_Jump) 
            | (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_JumpJALR))
            ? 4U : ((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_ALUSrc)
                     ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__IDEX_signExtend
                     : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__bypassOutB));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub 
        = (0x1ffffffffULL & ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                             - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__overflow 
        = (1U & (IData)((1ULL & (((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                   ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                      + (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                   : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                       ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                          - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                       : ((2U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                           ? (QData)((IData)(
                                                             (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                              ^ vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                           : ((3U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                               ? (QData)((IData)(
                                                                 (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                  | vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                               : ((4U 
                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                   ? (QData)((IData)(
                                                                     (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                      & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                    ? (QData)((IData)(
                                                                      (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                       << 
                                                                       (0x1fU 
                                                                        & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                     ? (QData)((IData)(
                                                                       (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                      ? (QData)((IData)(
                                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, 
                                                                                (0x1fU 
                                                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                       ? (QData)((IData)(
                                                                         (VL_LTS_III(1,32,32, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                           ? 1U
                                                                           : 0U)))
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                        ? (QData)((IData)(
                                                                          ((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                            < vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                            ? 1U
                                                                            : 0U)))
                                                        : 
                                                       ((0xaU 
                                                         == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                         ? (QData)((IData)(
                                                                           (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub 
                                                                            >> 1U)))
                                                         : 
                                                        ((0xbU 
                                                          == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                          ? 
                                                         ((QData)((IData)(
                                                                          (0xfffffU 
                                                                           & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB 
                                                                              >> 0xcU)))) 
                                                          << 0xcU)
                                                          : 
                                                         ((0xcU 
                                                           == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                                           + (QData)((IData)(
                                                                             (0xfffff000U 
                                                                              & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                           : 0ULL))))))))))))) 
                                 >> 0x20U))));
    vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__out_val 
        = (IData)((0x1ffffffffULL & ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                      ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                         + (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                      : ((1U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                          ? ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                             - (QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                          : ((2U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                              ? (QData)((IData)(
                                                                (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                 ^ vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                              : ((3U 
                                                  == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                  ? (QData)((IData)(
                                                                    (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                     | vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                   ? (QData)((IData)(
                                                                     (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                      & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)))
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                    ? (QData)((IData)(
                                                                      (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                       << 
                                                                       (0x1fU 
                                                                        & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                     ? (QData)((IData)(
                                                                       (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                        >> 
                                                                        (0x1fU 
                                                                         & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                      ? (QData)((IData)(
                                                                        VL_SHIFTRS_III(32,32,5, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, 
                                                                                (0x1fU 
                                                                                & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                       ? (QData)((IData)(
                                                                         (VL_LTS_III(1,32,32, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA, vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                           ? 1U
                                                                           : 0U)))
                                                       : 
                                                      ((9U 
                                                        == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                        ? (QData)((IData)(
                                                                          ((vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA 
                                                                            < vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB)
                                                                            ? 1U
                                                                            : 0U)))
                                                        : 
                                                       ((0xaU 
                                                         == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                         ? (QData)((IData)(
                                                                           (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__cpu_alu__DOT__unsigned_sub 
                                                                            >> 1U)))
                                                         : 
                                                        ((0xbU 
                                                          == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                          ? 
                                                         ((QData)((IData)(
                                                                          (0xfffffU 
                                                                           & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB 
                                                                              >> 0xcU)))) 
                                                          << 0xcU)
                                                          : 
                                                         ((0xcU 
                                                           == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUOp))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInA)) 
                                                           + (QData)((IData)(
                                                                             (0xfffff000U 
                                                                              & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__ALUInB))))
                                                           : 0ULL)))))))))))))));
}

VL_INLINE_OPT void Vtoplevel::_multiclk__TOP__9(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_multiclk__TOP__9\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready 
        = (((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
            & (IData)(vlTOPp->toplevel__DOT__dmem_ren)) 
           & (~ (IData)(vlTOPp->toplevel__DOT__dmem_wen)));
    vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_done 
        = (((0xfU == (IData)(vlTOPp->toplevel__DOT__Data_Mem__DOT__delay_counter)) 
            & (~ (IData)(vlTOPp->toplevel__DOT__dmem_ren))) 
           & (IData)(vlTOPp->toplevel__DOT__dmem_wen));
    if (vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__i = 4U;
    }
    if (vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_ready) {
        vlTOPp->toplevel__DOT__dmem_dout[0U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[1U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[2U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[3U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[0U] = vlTOPp->toplevel__DOT__Data_Mem__DOT__data
            [vlTOPp->toplevel__DOT__dmem_block_address]
            [0U];
        vlTOPp->toplevel__DOT__dmem_dout[1U] = vlTOPp->toplevel__DOT__Data_Mem__DOT__data
            [vlTOPp->toplevel__DOT__dmem_block_address]
            [1U];
        vlTOPp->toplevel__DOT__dmem_dout[2U] = vlTOPp->toplevel__DOT__Data_Mem__DOT__data
            [vlTOPp->toplevel__DOT__dmem_block_address]
            [2U];
        vlTOPp->toplevel__DOT__dmem_dout[3U] = vlTOPp->toplevel__DOT__Data_Mem__DOT__data
            [vlTOPp->toplevel__DOT__dmem_block_address]
            [3U];
    } else {
        vlTOPp->toplevel__DOT__dmem_dout[0U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[1U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[2U] = 0U;
        vlTOPp->toplevel__DOT__dmem_dout[3U] = 0U;
    }
}

VL_INLINE_OPT void Vtoplevel::_sequent__TOP__10(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_sequent__TOP__10\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v0) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0U] = 0U;
    }
    if (vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v1) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1U] = 0U;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2U] = 0U;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3U] = 0U;
    }
    if (vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v4) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0U] 
            = vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v4;
    }
    if (vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v5) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1U] 
            = vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v5;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2U] 
            = vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v6;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3U] 
            = vlTOPp->__Vdlyvval__toplevel__DOT__Data_Mem__DOT__temp_din__v7;
    }
    if (vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v8) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[0U] = 0U;
    }
    if (vlTOPp->__Vdlyvset__toplevel__DOT__Data_Mem__DOT__temp_din__v9) {
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[1U] = 0U;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[2U] = 0U;
        vlTOPp->toplevel__DOT__Data_Mem__DOT__temp_din[3U] = 0U;
    }
}

VL_INLINE_OPT void Vtoplevel::_combo__TOP__11(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_combo__TOP__11\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->reset) {
        if (vlTOPp->toplevel__DOT__cpu__DOT__dcacheMemWen) {
            vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] 
                = vlTOPp->toplevel__DOT__dmem_dout[0U];
            vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] 
                = vlTOPp->toplevel__DOT__dmem_dout[1U];
            vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] 
                = vlTOPp->toplevel__DOT__dmem_dout[2U];
            vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] 
                = vlTOPp->toplevel__DOT__dmem_dout[3U];
        } else {
            if (vlTOPp->toplevel__DOT__cpu__DOT__Dcntr__DOT__replace) {
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] = 0U;
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] = 0U;
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] = 0U;
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] = 0U;
                VL_ASSIGNSEL_WIII(32,(0x60U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                               << 3U)), vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin, 
                                  ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
                                        ? ((0U == (3U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                            : ((2U 
                                                == 
                                                (3U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                   << 0x10U)
                                                : 0U))
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData)));
            } else {
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] = 0U;
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] = 0U;
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] = 0U;
                vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] = 0U;
                VL_ASSIGNSEL_WIII(32,(0x60U & (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut 
                                               << 3U)), vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin, 
                                  ((0U == (IData)(vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_funct3))
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
                                        ? ((0U == (3U 
                                                   & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                            ? vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData
                                            : ((2U 
                                                == 
                                                (3U 
                                                 & vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_ALUOut))
                                                ? (vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData 
                                                   << 0x10U)
                                                : 0U))
                                        : vlTOPp->toplevel__DOT__cpu__DOT__pipeline__DOT__EXMEM_MemWriteData)));
            }
        }
    } else {
        vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[0U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[1U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[2U] = 0U;
        vlTOPp->toplevel__DOT__cpu__DOT__dcacheDin[3U] = 0U;
    }
}

void Vtoplevel::_eval(Vtoplevel__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtoplevel::_eval\n"); );
    Vtoplevel* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
        vlTOPp->__Vm_traceActivity[2U] = 1U;
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    vlTOPp->__Vm_traceActivity[3U] = 1U;
    if (((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
          | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset))))) {
        vlTOPp->_multiclk__TOP__9(vlSymsp);
        vlTOPp->__Vm_traceActivity[4U] = 1U;
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
        vlTOPp->__Vm_traceActivity[5U] = 1U;
    }
    vlTOPp->_combo__TOP__11(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset 
        = vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset;
    vlTOPp->__VinpClk__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    vlTOPp->__VinpClk__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset;
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
    __req |= ((vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[0] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[0]) | (vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[1] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[1]) | (vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[2] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[2]) | (vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[3] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[3])
         | (vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset)
         | (vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset));
    VL_DEBUG_IF( if(__req && ((vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[0] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[0]) | (vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[1] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[1]) | (vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[2] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[2]) | (vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[3] ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[3]))) VL_DBG_MSGF("        CHANGE: ../src/pipelined/cpu.v:34: toplevel.cpu.icacheDout\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset))) VL_DBG_MSGF("        CHANGE: ../src/memories/Imem.v:23: toplevel.Instruction_Mem.counter_reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset ^ vlTOPp->__Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset))) VL_DBG_MSGF("        CHANGE: ../src/memories/Dmem.v:28: toplevel.Data_Mem.counter_reset\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[0U] 
        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[0U];
    vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[1U] 
        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[1U];
    vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[2U] 
        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[2U];
    vlTOPp->__Vchglast__TOP__toplevel__DOT__cpu__DOT__icacheDout[3U] 
        = vlTOPp->toplevel__DOT__cpu__DOT__icacheDout[3U];
    vlTOPp->__Vchglast__TOP__toplevel__DOT__Instruction_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Instruction_Mem__DOT__counter_reset;
    vlTOPp->__Vchglast__TOP__toplevel__DOT__Data_Mem__DOT__counter_reset 
        = vlTOPp->toplevel__DOT__Data_Mem__DOT__counter_reset;
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
