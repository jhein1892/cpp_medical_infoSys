#include "Patient.hpp"
#include <iostream>


Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw, genFileName()), cardNumber(cardNum)
{
    std::cout << get_cardNum() << std::endl;
};

Patient::~Patient(){};

std::string* Patient::genFileName(){
    std::string* fullFile;
    std::string fileName = subFolder + "123.txt";
    fullFile = &fileName;
    printf("Full File name is %p\n", fullFile);
    // std::cout <<  fullFile << std::endl;
    return fullFile;
}


std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}
