#ifndef LRUTABLE_H
#define LRUTABLE_H
#include "fifotable.h"

class LRUTable : public virtual FIFOTable {
        void virtual reference_cb(Page_t);

    public:
        LRUTable(size_t);
};

#endif

