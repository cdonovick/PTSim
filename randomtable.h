#ifndef RANDOMTABLE_H
#define RANDOMTABLE_H
#include "pagetablebase.h"
#include <random>

class RandomTable : public virtual PageTableBase {
    protected:
        std::default_random_engine gen;
        std::uniform_int_distribution<size_t> dis;

        void virtual start_cb(PID_t);
        void virtual terminate_cb(PID_t);
        void virtual reference_cb(Page_t);
        void virtual handle_fault(Page_t);
        Page_t virtual select_victem();

    public:
        RandomTable(size_t);

};
#endif

