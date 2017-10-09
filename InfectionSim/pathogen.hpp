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










//#ifndef pathogen_hpp
//#define pathogen_hpp
//
//#include <stdio.h>
//#include <iostream>
//
//class human; // forward declare human
//#include "human.hpp"
//
//// implemented interface
//class pathogen_abstract {
//    friend class human;
//protected:
//    std::string         species;
//    human*              human_ptr;
//public:
//    virtual void fun() = 0;
//    virtual void set_human_ptr(human* h) = 0;
//    virtual human* get_human_ptr() = 0;
//};
//
//// internal implementation
//class pathogen_implementation {
//    friend class human;
//protected:
//    std::string         species;
//    human*              human_ptr;
//public:
//    virtual void fun_impl() = 0;
//    virtual void set_human_ptr_impl(human* h) = 0;
//    virtual human* get_human_ptr_impl() = 0;
//};
//
//// bridge
//class pathogen_bridge : public pathogen_abstract {
//protected:
//    pathogen_implementation* p_implementation;
//
//public:
//    pathogen_bridge(pathogen_implementation* p_backend){
//        p_implementation = p_backend;
//    }
//};
//
//// pathogen class that we interact with
//class pathogen : public pathogen_bridge {
//public:
//    pathogen(pathogen_implementation* p_backend) : pathogen_bridge(p_backend) {
//        std::cout << "object of class pathogen being born at memory location: " << this << std::endl;
//    };
//
//    void fun(){
//        std::cout << "pathogen species ";
//        p_implementation->fun_impl();
//    };
//
//    void set_human_ptr(human* h){
//        p_implementation->set_human_ptr_impl(h);
//    };
//
//    human* get_human_ptr(){
//        return(p_implementation->get_human_ptr_impl());
//    };
//};
//
//// p. falciparum
//class pathogen_p_falciparum : public pathogen_implementation {
//protected:
//    int x_p_falciparum = 10;
//public:
//    pathogen_p_falciparum(){
//        species = "p.falciparum";
//    };
//
//    void fun_impl(){
//        std::cout << species << " value of x: " << x_p_falciparum << std::endl;
//    };
//
//    void set_human_ptr_impl(human* h){
//        human_ptr = h;
//    }
//
//    human* get_human_ptr_impl(){
//        return(human_ptr);
//    }
//};
//
//// p. vivax
//class pathogen_p_vivax : public pathogen_implementation {
//protected:
//    int x_p_vivax = 20;
//public:
//    pathogen_p_vivax(){
//        species = "p.vivax";
//    };
//
//    void fun_impl(){
//        std::cout << species << " value of x: " << x_p_vivax << std::endl;
//    }
//
//    void set_human_ptr_impl(human* h){
//        human_ptr = h;
//    }
//
//    human* get_human_ptr_impl(){
//        return(human_ptr);
//    }
//};
//
//
//#endif /* pathogen_hpp */
