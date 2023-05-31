// RISC-V SiMPLE SV -- testbench
// BSD 3-Clause License
// (c) 2019, Marek Materzok, University of Wrocław

#include "Vtoplevel.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <iomanip>
#include <memory>
#include <string>

double sc_time_stamp() { return 0; }

int main(int argc, const char **argv, const char **env)
{
    Verilated::commandArgs(argc, argv);
    bool verbose = false;
    const char *str;
    str = Verilated::commandArgsPlusMatch("verbose");
    if (str && str[0]) verbose = true;

    std::unique_ptr<Vtoplevel> top(new Vtoplevel);

    #if TRACE==1
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // Trace 99 levels of hierarchy (or see below)
    tfp->open("simx.vcd");
    #endif

    top->reset = 1;

    for (int time = 0; time < 100000; time++) {
        if (time > 9)
            top->reset = 1;
        else if (time > 4)
            top->reset = 0;
        top->clock = time & 1;
        top->eval();

        #if TRACE==1
        tfp->dump(time);
        #endif

        #if VERBOSE==1
        if (top->clock && time > 8) {
            std::cout << std::hex << std::setfill('0')
                      << "pc=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__PC << " "
                      << "inst=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__IFID_instr << " "
                      << "addr=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__EXMEM_ALUOut << " "
                      << "out=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData << " "
                      << "alu out=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__EXMEM_ALUOut << " "                      
                      << (top->toplevel__DOT__cpu__DOT__EXMEM_MemWrite ? "1" : "0") << " \n";
        }
        #endif

        if (top->toplevel__DOT__cpu__DOT__EXMEM_MemWrite && top->toplevel__DOT__cpu__DOT__EXMEM_ALUOut == 0xfffffff0) {
            if (top->toplevel__DOT__cpu__DOT__EXMEM_MemWriteData) {
                std::cout << "PASS" << std::endl;
                return 0;
            } else {
                std::cout << "FAIL" << std::endl;
                #if TRACE==1
                tfp->close();
                #endif
                return -1;
            }
        }
        
    }
    

    #if TRACE==1
    tfp->close();
    #endif

    std::cout << "TIMEOUT" << std::endl;

    return -1;
}