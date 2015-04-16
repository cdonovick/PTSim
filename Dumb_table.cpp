#include "Dumb_table.h"

Dumb_table::Dumb_table(unsigned sz) : free_table(sz, 1){
}

Dumb_table::~Dumb_table(){
}
bool  Dumb_table::insert_address(unsigned place, unsigned size){
    while((size--) > 0){
        free_table[place-size] = INFO;
    }

    return true;
}

void Dumb_table::start(PID pid, unsigned address_space_size){
    unsigned sequence = 0;
    bool space = false;
    for(unsigned i = 0; i < free_table.size() && !space; ++i){
        if(free_table[i] == FREE) sequence += 1;
        else sequence = 0;

        if(sequence >= address_space_size){
            space = insert_address(i, address_space_size);
            memory[pid] = i-address_space_size;
        }
    }
}

void Dumb_table::terminate(PID pid){
    free_table[memory[pid]] = FREE;
    memory.erase(pid);
}
//need to init this cause Page_table is pure virtual.  

char Dumb_table::reference(PID pid, VPN vpn){
        return free_table[memory[pid]];
}
