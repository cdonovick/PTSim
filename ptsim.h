#ifndef PTSIM_H
#define PTSIM_H
#include <string>

class Page_table;

class PTSim {
    public:
        /*
         * Add pagetable to simulate
         */
        add_pt(Page_table p);
        
        /*
         * Read input file and simulate on page tables
         */
        read(std::string file);

        /*
         * Print the statistics from the most recent run
         */
        print(void);
};

#endif

