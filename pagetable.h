#ifndef PAGETABLE_H
#define PAGETABLE_H
#define NDEBUG
#include <utility>
#include <cstddef>

typedef unsigned int PID_t;
typedef unsigned int VPN_t;
typedef std::pair<PID_t, VPN_t> Page_t;

class PageTable {

    public:
        virtual void start(PID_t, size_t) = 0;
        virtual void terminate(PID_t) = 0;
        virtual char reference(PID_t, VPN_t) = 0;
};

#endif
