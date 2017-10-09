#ifndef human_hpp
#define human_hpp

#include <stdio.h>
#include <string>
#include <tuple>
#include <iostream>

#include "debug.hpp"

#include "pathogen.hpp"

class house; // forward declare house
class block; // forward declare block
typedef std::tuple<house*,block*> address;

class human {
public:
    human(const int &id_new);
    ~human();
    
    int                         get_id();
    std::string                 get_state();
    void                        set_state(const std::string &state_new);
    bool                        get_inf();
    void                        set_inf(const bool &i);
    
    // home address: my house and block
    address                     get_home_address();
    void                        set_home_address(house* h, block* b);
    house*                      get_home_house();
    block*                      get_home_block();
    
    // current address: my house and block
    address                     get_current_address();
    void                        set_current_address(house* h, block* b);
    house*                      get_current_house();
    block*                      get_current_block();
    
    // pathogen: pathogens infecting me
    pathogen_abstract*          get_pathogen();
    void                        set_pathogen(pathogen_abstract* p);
    
    void                        get_memLoc();
    
private:
    
    int                         id;                 // id
    std::string                 state;              // my life state
    bool                        inf;                // my infection status
    
    address                     home_address;       // home address
    address                     current_address;    // current address
    
    pathogen_abstract*          pathogen_ptr;
    
};


#endif /* human_hpp */
