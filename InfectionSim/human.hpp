#ifndef human_hpp
#define human_hpp

#include <stdio.h>
#include <string>
#include <tuple>
#include <iostream>

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
    
    // home address: my house and block
    address                     get_home_address();
    void                        set_home_address(house* h, block* b);
    
    // current address: my house and block
    address                     get_current_address();
    void                        set_current_address(house* h, block* b);

    
    void                        get_memLoc();
    
private:
    
    int                         id;                 // id
    std::string                 state;              // life state
    
    address                     home_address;       // home address
    address                     current_address;    // current address
    
};


#endif /* human_hpp */
