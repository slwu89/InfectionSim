//
//  pathogen.hpp
//  InfectionSim
//
//  Created by Sean Wu on 10/6/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#ifndef pathogen_hpp
#define pathogen_hpp

class human; // forward declare human

#include <stdio.h>

class pathogen {
public:
    ~pathogen();
    human*                          get_human_ptr(){return(human_ptr);}
    
protected:
    human*                          human_ptr;
};



#endif /* pathogen_hpp */
