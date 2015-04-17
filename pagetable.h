#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H
#include <utility>

typedef unsigned int PID_t;
typedef unsigned int VPN_t;
typedef std::pair<PID_t, VPN_t> Page_t;

class PageTable{
    public:
        /*
         * Should return  1 for fault
         *                0 for in memory
         *               -1 for error
         */
        virtual char reference(PID_t, VPN_t) = 0;
        virtual void start(PID_t, size_t) = 0;
        virtual void terminate(PID_t) = 0;
};

#endif
