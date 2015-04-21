#include "lrutable.h"


LRUTable::LRUTable(size_t maxPages) : PageTableBase(maxPages), FIFOTable(maxPages) { }

void LRUTable::reference_cb(Page_t page) { 
    for (auto p = lqueue.begin(); p != lqueue.end(); ++p) {
        if (*p == page) {
            lqueue.splice(lqueue.end(), lqueue, p);
            break;
        }
    }
}
