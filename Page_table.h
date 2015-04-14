#ifndef PAGE_TABLE
#define PAGE_TABLE

#include<utility>
#include<unordered_set>
typedef int PID;
typedef int VPN;

class Page_table{
    public:
        virtual Page_table(unsigned);
        virtual bool reference(PID, VPN) = 0;
        virtual void start(PID, unsigned) = 0;
        virtual void terminate(PID) = 0;
}

#endif PAGE_TABLE
