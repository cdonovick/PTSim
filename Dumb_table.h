#ifndef DUMB_TABLE
#define DUMB_TABLE

#include<unordered_map>
#include<vector>
#include "Page_table.h"

#define FREE 1
#define INFO 0

class Dumb_table : public Page_table
{
    private:
        std::unordered_map<unsigned, unsigned> memory;
        std::vector<bool> free_table;
        bool insert_address(unsigned, unsigned);
    public:
        Dumb_table(unsigned);
        ~Dumb_table();
        char reference(PID, VPN);
        void start(PID, unsigned);
        void terminate(PID);
};
#endif //DUMB_TABLE
