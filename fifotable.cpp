#include "fifotable.h"

FIFOTable::FIFOTable(size_t maxPages) : PageTableBase(maxPages) { }

void FIFOTable::start_cb(PID_t pid) { }

void FIFOTable::terminate_cb(PID_t pid) {
    for (auto p = lqueue.begin(); p != lqueue.end();) {
        if (p->first == pid) {
            p = lqueue.erase(p);
        } else {
            ++p;
        }
    }
}

void FIFOTable::reference_cb(Page_t page) { }
void FIFOTable::handle_fault(Page_t page) { 
    lqueue.push_back(page);
}

Page_t FIFOTable::select_victem() {
    Page_t temp = lqueue.front();
    lqueue.pop_front();
    return temp;
}
