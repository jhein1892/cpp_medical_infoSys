#include "Patient.hpp"
#include <iostream>

Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw, ""), cardNumber(cardNum)
{
    setPatientID();
    User::set_filename(genFileName());
};

Patient::~Patient(){};

std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}

std::string Patient::genFileName(){

    std::string fileName = patientID + ".txt";
    std::string subFolder = "/patients/";

    std::string fullFile = subFolder + fileName;

    std::cout << subFolder << std::endl;
    return fullFile;
}

void Patient::setPatientID(){
    std::string userID = User::genID(10);
    patientID = userID;
}

void Patient::genPayment(){
    std::cout << "Payment Processed on Card Number: " << cardNumber << std::endl;
    return;
}