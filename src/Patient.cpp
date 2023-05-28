#include "Patient.hpp"
#include <iostream>

Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw, genFileName()), cardNumber(cardNum)
{
    std::cout << get_cardNum() << std::endl;
};

Patient::~Patient(){};

std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}

std::string Patient::genFileName(){
    std::string userID = User::genID(10);
    std::string fileName = userID + ".txt";
    std::string subFolder = "/patients/";

    std::string fullFile = subFolder + fileName;

    std::cout << subFolder << std::endl;
    return fullFile;
}