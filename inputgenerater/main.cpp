#include<getopt.h>
#include "input_gen.h"
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

char * itoa(char *buf, int value) {
	sprintf(buf, "%d", value);
	return buf;
}
 

void use(){
	fprintf(stderr, "Memory generaton [-u] [-I <# instructions>] [-F Frames] [-P <memory pressure - relative to frames>] [-R <freq of references>] [-S <freq of starts/terminaters>]  [-L <Locality of references(1-1000)>]\n");
}


int main(int argc, char **argv){
	params p;
    int c;
	int n = 0;
	opterr=0;
	
    while((c=getopt(argc,argv,"uA:L:P:R:D:")) != -1){
		switch(c){
			case 'u':
				use();
				exit(1);	
			case 'I':
				n = atoi(optarg);
				break;
			case 'F':
				n = atoi(optarg);
				if(n > 0){
					p.F = n;
				}
				else{
					perror("need atleast 1 frame");
				}
				break; 
			case 'P':
				n = atoi(optarg);
                if(n >= 0){
					p.P = n;
				}
				else{
					perror("pressure cannot be negative");
				}
				break;
			case 'R':
				n = atoi(optarg);
                if(n >= 0){
					p.R = n;
				}
				else{
					perror("ref freq cannot be negative");
			    }
				break;
			case 'S':
				n = atoi(optarg);
                if(n >= 0){
					p.S = n;
				}
				else{
					perror("ref freq cannot be negative");
			    }	
           	case 'L':
				n = atoi(optarg);
                if(n >= 0 && n < 1000){
					p.L = n;
				}
				else{
					perror("ref freq cannot be negative or more than 1000");
			    } case '?':
				fprintf(stderr, "Unknown argument: -%c \n", optopt);
				use();
				return -1;  
		}
	}
    
    if(p.P > p.F) {
        perror("pressure cannot be more than frames");
    }


    input_gen a(p);
    a.generate();
}

