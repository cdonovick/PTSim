#include "randomtable.h"


RandomTable::RandomTable(size_t maxPages) : PageTableBase(maxPages), dis(0, maxPages) { 
    std::random_device rd;
    gen.seed(rd());
}


void RandomTable::start_cb(PID_t pid) { }

void RandomTable::terminate_cb(PID_t pid) { }

void RandomTable::reference_cb(Page_t page) { }
void RandomTable::handle_fault(Page_t page) { }

Page_t RandomTable::select_victem() {
    auto it = memory.begin();
    std::advance(it, dis(gen));
    return *it;
}
