#ifndef FIFOTABLE_H
#define FIFOTABLE_H
#include "pagetablebase.h"
#include <list>

class FIFOTable : public virtual PageTableBase {
    protected:
        std::list<Page_t> lqueue;

        void virtual start_cb(PID_t);
        void virtual terminate_cb(PID_t);
        void virtual reference_cb(Page_t);
        void virtual handle_fault(Page_t);
        Page_t virtual select_victem();

    public:
        FIFOTable(size_t);

};
#endif

