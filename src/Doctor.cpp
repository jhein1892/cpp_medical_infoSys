#include "Doctor.hpp"
#include <iostream>

Doctor::Doctor(std::string name, std::string phone, std::string dob, std::string pw, std::string id): 
User(name, phone, dob, pw, ""), doctorID(id) 
{
    User::set_filename(genFileName());
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

std::string Doctor::genFileName(){
    std::string fileName = get_id();
    std::string subFolder = "/doctors/";

    std::string fullFile = subFolder + fileName + ".txt";
    std::cout << get_id() << std::endl;

    return fullFile;
}