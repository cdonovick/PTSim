#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include<utility>
#include<unordered_set>
typedef int PID;
typedef int VPN;

class Page_table{
    public:
        Page_table();
        virtual char reference(PID, VPN) = 0;
        virtual void start(PID, unsigned) = 0;
        virtual void terminate(PID) = 0;
};

#endif
