#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include<utility>
#include<unordered_map>

typedef int PID;
typedef int VPN;

class Page_table{
    public:
        /*
         * Should return  1 for fault
         *                0 for in memory
         *               -1 for error
         */
        virtual char reference(PID, VPN) = 0;
        virtual void start(PID, unsigned) = 0;
        virtual void terminate(PID) = 0;
};

#endif //FDSJKFNSD
