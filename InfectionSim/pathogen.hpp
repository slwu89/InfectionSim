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

class pathogen_interface {
public:
    virtual ~pathogen_interface();
    virtual void fun() = 0;
};

class pathogen_implementation {
public:
    virtual ~pathogen_implementation();
    virtual void fun1() = 0;
};

class pathogen_bridge : public pathogen_interface {
protected:
    pathogen_implementation* p_implementation;
    
public:
    pathogen_bridge(pathogen_implementation* p_backend){
        p_implementation = p_backend;
    }
};



#endif /* pathogen_hpp */
