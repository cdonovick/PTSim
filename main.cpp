#include <string>
#include <exception>
#include <iostream>
#include "ptsim.h"
#include "Page_table.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Incorrect usage\n";
        return 1;
    }

    unsigned int frames;
    try {
        frames = std::stoi(argv[1]);
    } catch (std::exception &e) {
        std::cerr << "Bad arg: " << argv[1] << std::endl << e.what() << std::endl;
        return 1;
    }
    PTSim sim;
    /* construct page tables */
    /* call sim.add_pt(p) for each page table p */

    sim.simulate(argv[2]);
    sim.print();


	return 0;
}

