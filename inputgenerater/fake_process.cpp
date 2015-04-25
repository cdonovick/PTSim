#ifndef __fake__process__
#define __fake__process__

struct fake_process{
    unsigned pid;
    unsigned size;
    fake_process(unsigned _pid, unsigned _size) : pid(_pid), size(_size) {}
   
    bool operator<(const fake_process & rhs) const{
        return (size< rhs.size);
    } 
    bool operator==(const fake_process & rhs) const{
        return (pid== rhs.pid);
    }
};

#endif //dfa

