#include <string>
#include <exception>
#include <iostream>
#include "ptsim.h"
#include "pagetable.h"
#include "dumbtable.h"
#include "fifotable.h"
#include "lrutable.h"
#include "randomtable.h"

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "Incorrect usage\n";
        return 1;
    } 

    size_t frames;
    try {
        frames = std::stoul(argv[1]);
    } catch (std::exception &e) {
        std::cerr << "Bad arg: " << argv[1] << std::endl << e.what() << std::endl;
        return 1;
    }
    PTSim sim;
    DumbTable d(frames);
    FIFOTable f(frames);
    LRUTable l(frames);
    RandomTable r(frames);

    sim.add_pt(d, "No replacement");
    sim.add_pt(f, "FIFO");
    sim.add_pt(l, "LRU");
    sim.add_pt(r, "Random");
    
    sim.simulate(argv[2]);
    sim.print();

	return 0;
}

