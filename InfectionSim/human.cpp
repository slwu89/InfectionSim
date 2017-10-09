#include "human.hpp"

// properties of human
human::human(const int &id_new){
    id = id_new;
    std::cout << "human " << id << " being born at memory location: " << this << std::endl;
};

human::~human(){
    std::cout << "human " << id << " getting killed at memory location: " << this << std::endl;
};

int human::get_id(){
    return(id);
};

std::string human::get_state(){
    return(state);
};

void human::set_state(const std::string &state_new){
    state = state_new;
};

bool human::get_inf(){
    return(inf);
};

void human::set_inf(const bool &i){
    inf = i;
};


// address
address human::get_home_address(){
    return(home_address);
};

void human::set_home_address(house* h, block* b){
    std::get<0>(home_address) = h;
    std::get<1>(home_address) = b;
};

address human::get_current_address(){
    return(current_address);
};

void human::set_current_address(house* h, block* b){
    std::get<0>(current_address) = h;
    std::get<1>(current_address) = b;
};

// pathogen
pathogen_abstract* human::get_pathogen(){
    return(pathogen_ptr);
}

void human::set_pathogen(pathogen_abstract* p){
    p->set_human_ptr(this);
    pathogen_ptr = p;
}

//debug
void human::get_memLoc(){
    std::cout << "human " << id << " at memory location: " << this << std::endl;
};
