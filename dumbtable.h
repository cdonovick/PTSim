#ifndef DUMBTABLE_H
#define DUMBTABLE_H
#include <unordered_map>
#include <set>
#include "pagetable.h"


class DumbTable : public PageTable
{
   private:
       size_t maxPages; 
       std::unordered_map<PID_t, size_t> maxAdressLookUp;
       std::set<Page_t> memory;
       
    public:
        DumbTable(size_t);
        char reference(PID_t, VPN_t);
        void start(PID_t, size_t);
        void terminate(PID_t);
};
#endif //DUMB_TABLE
