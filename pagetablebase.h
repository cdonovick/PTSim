#ifndef PAGETABLEBASE_H
#define PAGETABLEBASE_H
#include "pagetable.h"
#include <utility>
#include <unordered_map>
#include <set>

class PageTableBase : public virtual PageTable {
    protected:
        size_t maxPages; 
        std::unordered_map<PID_t, size_t> maxAdressLookUp;
        std::set<Page_t> memory;
        
        void virtual start_cb(PID_t) = 0;
        void virtual terminate_cb(PID_t) = 0;
        void virtual reference_cb(Page_t) = 0;
        void virtual handle_fault(Page_t) = 0;
        Page_t virtual select_victem() = 0;

    public:
        PageTableBase(size_t);
        void start(PID_t, size_t);
        void terminate(PID_t);
        char reference(PID_t, VPN_t);
};

#endif
