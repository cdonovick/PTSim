#include "dumbtable.h"

DumbTable::DumbTable(size_t maxPages) : maxPages(maxPages) {}

char DumbTable::reference(PID_t pid, VPN_t vpn) {
    if (maxAdressLookUp.at(pid) < vpn) {
        return -1;
    }
    
    Page_t p(pid, vpn);

    if (memory.count(p)) {
        return 0;
    }

    if (memory.size() <= maxPages) {
        memory.insert(p);
    }

    return 1;
}

void DumbTable::start(PID_t pid, size_t maxAdress) {
    maxAdressLookUp.emplace(pid, maxAdress);
}


void DumbTable::terminate(PID_t pid) {
    for (auto p = memory.begin(); p != memory.end(); ++p) {
        if (p->first == pid) {
            memory.erase(p);
        }     
    }

    maxAdressLookUp.erase(pid);
}


