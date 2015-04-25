#ifndef __name_collision_wh__
#define __name_collision_whaat__

#include <cstdlib>
#include <iterator>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <set>
#include "fake_process.cpp"
#include"params.cpp"
#include <iostream>
#include <vector>

struct input_gen{
    //lets people chose how much pressure they want to put on the system. In reality could run it with 
    //any frame size
    
    std::vector<std::string> output;
    
    unsigned frames;
    //total number of instructions 
    unsigned instructions;

    //mem_pressure is set when compared to frame size
    unsigned mem_pressure;
    //refs, start, end are set on a scale relative to each other
    unsigned num_starts; 
    unsigned ends;
    unsigned refs;
    //scale of 0-10;
    unsigned locality; //on a scale frome 0-10
    

    input_gen();
    input_gen(params p) : frames(p.F), instructions(p.I),  mem_pressure(p.P), num_starts(p.S),
    ends(p.S), refs(p.R), locality(p.L) {}

    //to generate stuff
    void generate();
    void print_me();
};



#endif //fake_process
