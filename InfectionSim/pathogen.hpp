#ifndef pathogen_hpp
#define pathogen_hpp

class human; // forward declare human

#include <stdio.h>
#include <iostream>

// implemented interface
class pathogen_abstract {
public:
    virtual void fun() = 0;
};

// internal implementation
class pathogen_implementation {
public:
    virtual void fun_impl() = 0;
};

// bridge
class pathogen_bridge : public pathogen_abstract {
protected:
    pathogen_implementation* p_implementation;

public:
    pathogen_bridge(pathogen_implementation* p_backend){
        p_implementation = p_backend;
    }
};

// pathogen class
class pathogen : public pathogen_bridge {
public:
    pathogen(pathogen_implementation* p_backend) : pathogen_bridge(p_backend) {}
    
    void fun(){
        std::cout << "pathogen strain ";
        p_implementation->fun_impl();
    }
};

// p. falciparum
class pathogen_p_falciparum : public pathogen_implementation {
public:
    void fun_impl(){
        std::cout << "plasmodium falciparum" << std::endl;
    }
};

// p. vivax
class pathogen_p_vivax : public pathogen_implementation {
public:
    void fun_impl(){
        std::cout << "plasmodium vivax" << std::endl;
    }
    
};


#endif /* pathogen_hpp */
