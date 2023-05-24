#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(std::string name, std::string phone, std::string dob, std::string pw, std::string id): User(name, phone, dob, pw), doctorID(id)
{
    std::cout << get_id() << std::endl;
}

Doctor::~Doctor(){};

std::string Doctor::get_id()
{
    return doctorID;
}

void Doctor::update_id(std::string id){
    doctorID = id;
}