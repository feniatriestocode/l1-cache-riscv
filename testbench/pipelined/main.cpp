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
    bool verbose = true;
    const char *str;
    str = Verilated::commandArgsPlusMatch("verbose");
    if (str && str[0]) verbose = true;

    
    Verilated::traceEverOn(true);
    std::unique_ptr<Vtoplevel> top(new Vtoplevel);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // Trace 99 levels of hierarchy (or see below)
    tfp->open("obj_dir/t_trace_ena_cc/simx.vcd");


    top->reset = 1;

    for (int time = 0; time < 50; time++) {
        if (time > 9)
            top->reset = 1;
        else if (time > 4)
            top->reset = 0;
        top->clock = time & 1;
        top->eval();
        tfp->dump(time);

        if (verbose && top->clock && time > 8) {
            std::cout << std::hex << std::setfill('0')
                      << "pc=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__PC << " "
                      << "inst=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__IFID_instr << " "
                      << "addr=" << std::setw(8) << top->MemAddr << " "
                      << "out=" << std::setw(8) << top->WriteData << " "
                      << "alu out=" << std::setw(8) << top->toplevel__DOT__cpu__DOT__EXMEM_ALUOut << " "                      
                      << (top->MemWriteEnable ? "1" : "0") << " \n";
        }

        if (top->MemWriteEnable && top->MemAddr == 0xfffffff0) {
            if (top->WriteData) {
                std::cout << "PASS" << std::endl;
                return 0;
            } else {
                std::cout << "FAIL" << std::endl;
                return -1;
            }
        }
    }

    tfp->close();

    std::cout << "TIMEOUT" << std::endl;

    return -1;
}
