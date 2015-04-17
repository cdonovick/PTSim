#ifndef PTSIM_H
#define PTSIM_H
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include "pagetable.h"

class PTSim {
public:
    /*
     * Add pagetable to simulate
     */
    void add_pt(PageTable &p, std::string name);
    
    /*
     * Read input file and simulate on page tables
     */
    void simulate(std::string file);

    /*
     * Print the statistics from the most recent run
     */
    void print(void) const;
private:
    struct pt_wrapper {
        pt_wrapper(PageTable &self, std::string name) :
            self(self), name(name), accesses(0), faults(0) {}

        PageTable &self;
        std::string name;
        unsigned int accesses;
        unsigned int faults;
    };

    std::vector<pt_wrapper> tables;
};

#endif

