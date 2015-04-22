#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include<iostream>


typedef int bool;
#define true 1
#define false 0

#define INT_DIGITS 19		/* enough for 64 bit integer */

char * itoa(char *buf, int value) {
	sprintf(buf, "%d", value);
	return buf;
}

struct params{
	uint32_t A; 
	uint32_t L; 
	uint32_t P;
	uint32_t R; 
	uint32_t D; 
    
    params() : A(10000),L(5), P(5), R(5), D(5) {} 
} 

params p;

void use(){
	fprintf(stderr, "Memory generaton [-u] [-A <num of memory allocations>] [-L <Locality of memory allocations(1-10)>] [-P <pressure(1-10)>] 
            [-R <freq of references>] [-D <distribution of references(1-10)>]\n");
}


int main(int argc, char **argv){
	set_params(&p);
	int c;
	int n = 0;
	opterr=0;
	
    while((c=getopt(argc,argv,"uA:L:P:R:D:")) != -1){
		switch(c){
			case 'u':
				use();
				exit(1);	
			case 'A':
				n = atoi(optarg);
				if(n > 0 && n <= 200000000){
					p.N = n;
				}
				else{
					perror("the number of memory allocations needs to be less than 200000000 and greater than 0. Set to 10000 \n");
				}
				break;
			case 'L':
				n = atoi(optarg);
				if(n <=10 && n >=1){
					p.M = n;
				}
				else{
					perror("Locality must be a value from 1-10, set to 5");
				}
				break; 
			case 'P':
				n = atoi(optarg);
                if(n <=10 && n >=1){
					p.M = n;
				}
				else{
					perror("Locality must be a value from 1-10, set to 5");
				}
				break;
			case 'R':
				n = atoi(optarg);
                if(n <= 1000000 && n >= 1){
					p.M = n;
				}
				else{
					perror("Frequency needs to be between 0-1000000. Set to 5");
			    }
				break;
			case '?':
				fprintf(stderr, "Unknown argument: -%c \n", optopt);
				use();
				return -1;  
		}
	}

    std::map<uint32_t, uint32_t> memory;

    int pid = 0;

/*Just realized its 2:40 and I have an 8:30 tmrw morning. Pushing it anyway so you dont just do it */ 

    for(int i = 0; i< p.A; ++i){ 
        if(rand%1000000 < p.R){
            auto it = memory.begin();
            std::advance(it, (pid -(rand() % m.size()/p.P)) %m.sie());
            std::cout << "REFERENCE " << it->first << (rand()%(it->second) + 1)  << std::endl;;       
        }
        else{
            memory[pid] = (rand%10000 + 1)*p.N ;
            std::cout << "START " <<  ++pid << " " << memory[pid] << std::endl;
        }
    }

    
}
