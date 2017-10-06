#ifndef human_hpp
#define human_hpp

#include <stdio.h>
#include <string>
#include <iostream>

class human {
public:
    human(const int &id_new);
    ~human();
    
    int                         get_id();
    std::string                 get_state();
    void                        set_state(const std::string &state_new);
    
    void                        get_memLoc();
    
private:
    
    int                         id;         // id
    std::string                 state;      // life state
    
};


#endif /* human_hpp */
