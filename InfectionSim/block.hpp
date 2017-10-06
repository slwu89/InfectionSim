#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <set>
#include <algorithm>
#include <iostream>

#include "house.hpp"
#include "human.hpp"

class block {
public:
    block(const int &id_new);
    ~block();
    
    void                        add_house(house* h);
    int                         get_house_n();
    house*                      get_house(const int &h_id);
    
    
private:
    
    int                         id;         // numeric id of block
    std::set<house*>            houses;     // list of houses

};

#endif /* block_hpp */
