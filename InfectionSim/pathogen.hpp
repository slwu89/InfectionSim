#ifndef pathogen_hpp
#define pathogen_hpp

#include <stdio.h>
#include <iostream>

#include "debug.hpp"

class human; // forward declare human

// implemented interface
class pathogen_abstract {
public:
    virtual void                    fun() = 0;
    virtual void                    set_human_ptr(human* h) = 0;
    virtual human*                  get_human_ptr() = 0;
    virtual void                    inf_human() = 0;
protected:
    std::string                     species;
    human*                          human_ptr;
};

// internal implementation
class pathogen_implementation {
public:
    virtual void                    fun_impl() = 0;
    virtual void                    set_human_ptr_impl(human* h) = 0;
    virtual human*                  get_human_ptr_impl() = 0;
    virtual void                    inf_human_impl() = 0;
protected:
    std::string                     species;
    human*                          human_ptr;
};

// bridge
class pathogen_bridge : public pathogen_abstract {
public:
                                    pathogen_bridge(pathogen_implementation* p_backend);
                        
protected:
    pathogen_implementation*        p_implementation;
};

// pathogen class that we interact with
class pathogen : public pathogen_bridge {
public:
                                    pathogen(pathogen_implementation* p_backend);
    
    void                            fun();
    
    void                            set_human_ptr(human* h);
    human*                          get_human_ptr();
    
    void                            inf_human();
};

// p. falciparum
class pathogen_p_falciparum : public pathogen_implementation {
public:
                                    pathogen_p_falciparum();
    
    void                            fun_impl();
    
    void                            set_human_ptr_impl(human* h);
    human*                          get_human_ptr_impl();
    
    void                            inf_human_impl();
    
private:
    int                             x_p_falciparum = 10;
};

// p. vivax
class pathogen_p_vivax : public pathogen_implementation {
public:
                                    pathogen_p_vivax();
    
    void                            fun_impl();
    
    void                            set_human_ptr_impl(human* h);
    human*                          get_human_ptr_impl();
    
    void                            inf_human_impl();
    
private:
    int                             x_p_vivax = 20;
};


#endif /* pathogen_hpp */
