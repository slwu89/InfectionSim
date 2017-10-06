#include "human.hpp"

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

void human::get_memLoc(){
    std::cout << "human " << id << " at memory location: " << this << std::endl;
};
