#include "Patient.hpp"
#include <iostream>


Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw, genFileName()), cardNumber(cardNum)
{
    std::cout << get_cardNum() << std::endl;
};

Patient::~Patient(){};

std::string Patient::genFileName(){
    std::string fileName = "123.txt";
    std::string subFolder = "/patients/";

    std::string fullFile = subFolder + fileName;

    std::cout << subFolder << std::endl;
    return fullFile;

    // // const char* subFolder = "patients/";
    // const char* fileName = "123.txt";
    // char fullFile[100];
    // strcpy(fullFile, subFolder);
    // strcat(fullFile, fileName);
    // std::cout <<  subFolder << std::endl;
    // return fullFile;
}


std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}
