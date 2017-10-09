//
//  pathogen.cpp
//  InfectionSim
//
//  Created by Sean Wu on 10/8/17.
//  Copyright © 2017 Sean Wu. All rights reserved.
//

#include "pathogen.hpp"
#include "human.hpp"


// pathogen_bridge

pathogen_bridge::pathogen_bridge(pathogen_implementation* p_backend){
    p_implementation = p_backend;
};

// pathogen

pathogen::pathogen(pathogen_implementation* p_backend) : pathogen_bridge(p_backend) {
        std::cout << "object of class pathogen being born at memory location: " << this << std::endl;
};

void pathogen::fun(){
    std::cout << "pathogen species ";
    p_implementation->fun_impl();
}

void pathogen::set_human_ptr(human* h){
    p_implementation->set_human_ptr_impl(h);
};

human* pathogen::get_human_ptr(){
    return(p_implementation->get_human_ptr_impl());
};

void pathogen::inf_human(){
    p_implementation->inf_human_impl();
}


// p. falciparum

pathogen_p_falciparum::pathogen_p_falciparum(){
    species = "p.falciparum";
};

void pathogen_p_falciparum::fun_impl(){
    std::cout << species << " value of x: " << x_p_falciparum << std::endl;
};

void pathogen_p_falciparum::set_human_ptr_impl(human* h){
    human_ptr = h;
}

human* pathogen_p_falciparum::get_human_ptr_impl(){
    return(human_ptr);
}

void pathogen_p_falciparum::inf_human_impl(){
    human_ptr->set_inf(true);
};

// p. vivax

pathogen_p_vivax::pathogen_p_vivax(){
    species = "p.vivax";
};

void pathogen_p_vivax::fun_impl(){
    std::cout << species << " value of x: " << x_p_vivax << std::endl;
};

void pathogen_p_vivax::set_human_ptr_impl(human* h){
    human_ptr = h;
}

human* pathogen_p_vivax::get_human_ptr_impl(){
    return(human_ptr);
}

void pathogen_p_vivax::inf_human_impl(){
    human_ptr->set_inf(true);
};

