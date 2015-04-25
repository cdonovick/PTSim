#ifndef __paramss__
#define __paramss__

struct params{
    int I;
	int F; 
	int P; 
	int R;
	int S; 
	int  L; 
    bool operator==(const params & rhs){
        return I == rhs.I;    
    }
    params() : I(10000), F(1000), P(10), R(10), S(1), L(500)   {} 
    
};

#endif ///
