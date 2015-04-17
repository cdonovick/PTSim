#include "ptsim.h"

void PTSim::add_pt(PageTable &p, std::string name) {
    tables.emplace_back(p, name);
}

void PTSim::simulate(std::string file) {
    std::ifstream fin(file);
    PID_t pid;
    VPN_t vpn;
    unsigned size;
    char r;
    std::string cmd;
    for (fin >> cmd; fin.good() && !(fin.eof() || fin.fail() || fin.bad()); fin >> cmd) {
        if (cmd.substr(0, 5) == "START") {
            fin >> pid >> size;
            for (auto &p: tables) {
                p.self.start(pid, size);
            }
        } else if (cmd.substr(0, 9) == "TERMINATE") {
            fin >> pid;
            for (auto &p: tables) {
                p.self.terminate(pid);
            }

        } else if (cmd.substr(0, 9) == "REFERENCE") {
            fin >> pid >> vpn;
            for (auto &p: tables) {
                r = p.self.reference(pid, vpn);
                switch (r) {
                    case 1:
                        #ifndef NDEBUG
                        std::cout << p.name << ":  FAULT\n";
                        #endif
                        p.faults++;
                    case 0:
                        #ifndef NDEBUG
                        if (!r) {std::cout << p.name << ":  HIT\n";}
                        #endif
                        p.accesses++;
                        continue;
                    default:
                        std::cerr << "Bad vpn\n";
                        break;
                }
                break;
            }
        } else {
            std::cerr << "Bad instruction\n";
        }
    }
}


void PTSim::print(void) const {
    std::cout << "Page Fault Rates:\n";
    for (auto &p: tables) {
        std::cout << p.name << ": " << static_cast<double>(p.faults)/p.accesses << "%\n";
    }
}
