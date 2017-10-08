#include <iostream>
#include <vector>

#include "human.hpp"
#include "house.hpp"
#include "block.hpp"
#include "pathogen.hpp"

int main() {
    
    int nBlock = 2;
    int nHouse = 2;
    int nHuman = 5;
    
    std::vector<block*> city;
    city.reserve(nBlock);
    for(int i=0; i<nBlock; i++){
        std::cout << "block i: " << i << std::endl;
        block* b = new block(i);
        city.push_back(b);        
        for(int j=0; j<nHouse; j++){
            std::cout << "house j: " << j << std::endl;
            house* h = new house(j);
            city[i]->add_house(h);
            for(int k=0; k<nHuman; k++){
                std::cout << "human k: " << k << std::endl;
                human* p = new human(k);
                city[i]->get_house(j)->add_human(p);
            }
        }
    }
    
    // pathogens
    pathogen_abstract* usePathogen = 0;
    pathogen_implementation* p_vivax_implementation = new pathogen_p_vivax;
    pathogen_implementation* p_falciparum_implementation = new pathogen_p_falciparum;
    
    usePathogen = new pathogen(p_falciparum_implementation);
    city[0]->get_house(1)->get_human(3)->set_pathogen(usePathogen);
    city[0]->get_house(1)->get_human(3)->get_pathogen()->fun();
    
    
    usePathogen = new pathogen(p_vivax_implementation);
    city[0]->get_house(1)->get_human(4)->set_pathogen(usePathogen);
    city[0]->get_house(1)->get_human(4)->get_pathogen()->fun();
    

    return 0;
}
