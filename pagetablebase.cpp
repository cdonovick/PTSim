#include "pagetablebase.h"


PageTableBase::PageTableBase(size_t maxPages) : maxPages(maxPages) {}

char PageTableBase::reference(PID_t pid, VPN_t vpn) {
    if (maxAdressLookUp.at(pid) < vpn) {
        return -1;
    }
    
    Page_t p(pid, vpn);

    if (memory.count(p)) {
        reference_cb(p);
        return 0;
    }

    if (memory.size() == maxPages) {
        memory.erase(select_victem());
    }

    memory.insert(p);
    handle_fault(p);
    return 1;
}

void PageTableBase::start(PID_t pid, size_t maxAdress) {
    maxAdressLookUp.emplace(pid, maxAdress);
    start_cb(pid);
}


void PageTableBase::terminate(PID_t pid) {
    for (auto p = memory.begin(); p != memory.end(); ++p) {
        if (p->first == pid) {
            memory.erase(p);
        }     
    }

    maxAdressLookUp.erase(pid);
    terminate_cb(pid);
}


