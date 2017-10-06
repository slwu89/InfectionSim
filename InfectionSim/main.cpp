#include <iostream>

#include "human.hpp"
#include "house.hpp"
#include "block.hpp"

int main() {
    
    human x(1);
    x.get_memLoc();
    
    house house1(1,1);
    std::cout << "made a house, id: " << house1.get_id() << " " << std::endl;
    house1.get_memLoc();
    
    for(size_t i=1; i<=10; i++){
        human* h = new human((int)(i));
        house1.add_human(h);
    }
    
    house1.check_human(10);
    std::cout << "returning human by reference " << std::endl;
    house1.get_human(10)->get_memLoc();
    std::cout << "end sim" << std::endl;
    
    block block1(1);
    house* h = new house(1,1);
    block1.add_house(h);
    
    
    return 0;
}
