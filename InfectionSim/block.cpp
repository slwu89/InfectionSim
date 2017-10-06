#include "block.hpp"

/*
 constructor & destructor
 */

block::block(const int &id_new){
    id = id_new;
    std::cout << "i'm an object of class block being born at memory location: " << this << std::endl;
};

block::~block(){
    houses.clear();
    std::cout << "i'm an object of class block getting killed at memory location: " << this << std::endl;
};

/*
 basic accessors
 */
int block::get_id(){
    return(id);
}


/*
 house stuff
 */

void block::add_house(house* h){
    h->set_block_ptr(this);
    h->set_block_id(id);
    houses.insert(h);
};

int block::get_house_n(){
    return((int)(houses.size()));
};

house* block::get_house(const int &h_id){
    auto it = std::find_if(houses.begin(), houses.end(), [h_id](house* h){ return h->get_id()==h_id; });
    if(it != houses.end()){
        return (*it);
    } else {
        return nullptr;
    }
};
