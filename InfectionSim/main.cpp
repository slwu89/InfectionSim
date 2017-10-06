#include <iostream>
#include <vector>

#include "human.hpp"
#include "house.hpp"
#include "block.hpp"


int main() {
    
    int nBlock = 2;
    int nHouse = 2;
    int nHuman = 5;
    
    std::vector<block> city;
    city.reserve(nBlock);
    for(int i=0; i<nBlock; i++){
        std::cout << "block i: " << i << std::endl;
        city.push_back(block(i));
        
        for(int j=0; j<nHouse; j++){
            std::cout << "house j: " << j << std::endl;
            house* h = new house(j);
            city[i].add_house(h);
            
            for(int k=0; k<nHuman; k++){
                std::cout << "human k: " << k << std::endl;
                human* p = new human(k);
                city[i].get_house(j)->add_human(p);
            }
        }
    }
    
    
    

    return 0;
}
