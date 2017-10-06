#ifndef house_hpp
#define house_hpp

#include <stdio.h>
#include <set>
#include <algorithm>
#include <iostream>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/boost_tuple.hpp>

#include "human.hpp"

class block;    // forward declare block


class house {
    // public members
public:
    house(const int &id_new);
    ~house();
    
    int                         get_id();
    
    void                        set_block_ptr(block* b);
    block*                      get_block_ptr();
    
    void                        add_human(human* h);
    void                        check_human(const int &h_id);
    int                         get_human_n();
    human*                      get_human(const int &h_id);
    
    void                        get_memLoc();
    
    // private members
private:
    
    int                         id;         // numeric id of house
    std::set<human*>            humans;     // list of people here now
    
    block*                      block_ptr;  // pointer to block
};

#endif /* house_hpp */
