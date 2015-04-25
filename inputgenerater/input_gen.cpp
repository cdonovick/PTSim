#include"input_gen.h"

void input_gen::generate(){
    unsigned pidGen = 0x00000000;
    unsigned prob_of_anything = num_starts+ ends + refs;
        std::set<fake_process> running;
    for(int i = 0; i < 5; ++i){
            fake_process p(++pidGen, ((std::rand()%frames)/mem_pressure)+1);
            running.insert(p);
            std::cout << "START " <<  std::to_string(p.pid) << " " << std::to_string(p.size) << std::endl;
    }

    
    for(unsigned i = 0; i < instructions; ++i){
      
        int total(0), t(0);
        int dice(std::rand()%prob_of_anything);
        auto it = running.begin();
        int add = rand()%running.size();
        std::advance(it, add);
        if(((total+=num_starts) > dice) || running.size() < 2){
            fake_process p(++pidGen, ((std::rand()%frames)/mem_pressure)+1);
            running.insert(p);

            std::cout << "START " <<  std::to_string(p.pid) << " " << std::to_string(p.size) << std::endl;
        }

        else if( (total+=refs) > dice){
            do{   
                t += std::rand()%(1000 - locality);
                t = t%(it->size);
                std::cout << "REFERENCE " << std::to_string(it->pid) <<  " " <<std::to_string(t) << std::endl;
            }while((std::rand()%1000) < locality);
        }
        else{
            std::cout << "TERMINATE " <<  std::to_string(it->pid) << std::endl;
            running.erase(it);
        }
    }
}
void input_gen::print_me(){
    for(auto it : output){
        std::cout << it << "\n" << std::endl;
    }
}
