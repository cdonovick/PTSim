#include "ptsim.h"

void PTSim::add_pt(Page_table p, std::string name) {
    tables.push_back(pt_wrapper {&p, name, 0, 0});
}

void PTSim::simulate(std::string file) {
    std::ifstream fin(file);
    PID pid;
    VPN vpn;
    unsigned size;
    char r;
    std::string cmd;
    for (fin >> cmd; fin.good() && !(fin.eof() || fin.fail() || fin.bad()); fin >> cmd) {
        if (cmd.substr(0, 5) == "START") {
            fin >> pid >> size;
            for (auto p: tables) {
                p.self->start(pid, size);
            }
        } else if (cmd.substr(0, 9) == "TERMINATE") {
            fin >> pid;
            for (auto p: tables) {
                p.self->terminate(pid);
            }

        } else if (cmd.substr(0, 9) == "REFERENCE") {
            fin >> pid >> vpn;
            for (auto p: tables) {
                r = p.self->reference(pid, vpn);
                switch (r) {
                    case 1:
                        p.faults++;
                    case 0:
                        p.accesses++;
                        continue;
                    default:
                        std::cerr << "Bad vpn\n";
                        break;
                }
                break;
            }
        }
    }
}


void PTSim::print(void) {
    std::cout << "Page Fault Rates:\n";
    for (auto p: tables) {
        std::cout << p.name << ": " << ((double)p.faults)/p.accesses << "%\n";
    }
}
