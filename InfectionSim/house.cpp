#include "house.hpp"
#include "block.hpp"

/*
    constructor & destructor
*/

house::house(const int &id_new){
    id = id_new;
    #ifdef DEBUG_INFSIM
    std::cout << "house " << id << " being born at memory location: " << this << std::endl;
    #endif
};

house::~house(){
    for(auto it=humans.begin(); it!=humans.end(); it++){
        delete *it;
    }
    humans.clear();
    #ifdef DEBUG_INFSIM
    std::cout << "house " << id <<  " getting killed at memory location: " << this << std::endl;
    #endif
};


/*
    basic accessors
*/

int house::get_id(){
    return(id);
};


void house::set_block_ptr(block* b){
    block_ptr = b;
};

block* house::get_block_ptr(){
    return(block_ptr);
};


/*
 stuff for humans
 */

void house::add_human(human* h){
    h->set_home_address(this,block_ptr);
    h->set_current_address(this,block_ptr);
    humans.insert(h);
};

void house::check_human(const int &h_id){
    auto it = std::find_if(humans.begin(), humans.end(), [h_id](human* h){ return h->get_id()==h_id; });
    if(it != humans.end()){
        std::cout << "found the human: " << (*it)->get_id() << " in house " << id << " and block " << block_ptr->get_id() << std::endl;
    } else {
        std::cout << "human not found in house " << id << std::endl;
    }
    
};

int house::get_human_n(){
    return((int)(humans.size()));
};

human* house::get_human(const int &h_id){
    auto it = std::find_if(humans.begin(), humans.end(), [h_id](human* h){ return h->get_id()==h_id; });
    if(it != humans.end()){
        return (*it);
    } else {
        return nullptr;
    }
};


/*
 debugging
 */

void house::get_memLoc(){
    std::cout << "i'm an object of class house at memory location: " << this << std::endl;
};
