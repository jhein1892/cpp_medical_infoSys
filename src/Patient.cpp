#include "Patient.hpp"
#include <iostream>


Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw, genFileName()), cardNumber(cardNum)
{
    std::cout << get_cardNum() << std::endl;
};

Patient::~Patient(){};

char* Patient::genFileName(){
    const char* fileName = "123.txt";
    char fullFile[100];
    strcpy(fullFile, subFolder);
    strcat(fullFile, fileName);
    // char fileName = subFolder + "123.txt";
    // fullFile = &fileName;
    printf("Full File name is %s\n", subFolder);
    // std::cout <<  fullFile << std::endl;
    return fullFile;
}


std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}
