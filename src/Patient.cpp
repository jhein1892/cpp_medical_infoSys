#include "Patient.hpp"
#include <iostream>

Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw), cardNumber(cardNum)
{
    Patient::print_cardNum();
};

Patient::~Patient(){};

void Patient::print_cardNum(){
    std::cout << cardNumber << std::endl;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}
