#include "Patient.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

Patient::Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
    User(name, phone, dob, pw, ""), cardNumber(cardNum)
{
    setPatientID();
    User::set_filename(genFileName());
    User::save_file();
};

Patient::Patient(std::string id, std::string pw): User(id, pw, ""){
    setPatientID(id);
    User::set_filename(genFileName(id));
    User::login(pw);
    User::update_map();
    // Try Logging in
}

Patient::~Patient(){};

std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    cardNumber = newNum;
}

void Patient::add_appt(std::string date){
    User::update_key("next_appt", date);
    
    // Get Date from input

    // Check Corresponsiding Doctors schedule to see if there is already appointment

        // If no, add appt to patients appt var, add patient id to Doctors appt file

        // If yes, ask for a new date/time
    return;
}

void Patient::gen_report(){
    User::describe_user();
    // Similar to a describe User function: Provide general info about Patient, also provide a description of their appointment schedule.

    return;
}

std::string Patient::genFileName(){

    std::string fileName = patientID + ".txt";
    // std::string subFolder = "/patients/";

    std::string fullFile = subFolder + fileName;

    std::cout << subFolder << std::endl;
    return fullFile;
}

std::string Patient::genFileName(std::string id){

    std::string fileName = id + ".txt";
    // std::string subFolder = "/patients/";

    std::string fullFile = subFolder + fileName;

    // std::cout << fullFile << std::endl;
    return fullFile;
}

void Patient::setPatientID(){
    std::string userID = User::genID(10);
    patientID = userID;
}

void Patient::setPatientID(std::string id){
    patientID = id;
}

void Patient::genPayment(){
    std::cout << "Payment Processed on Card Number: " << cardNumber << std::endl;
    return;
}

void Patient::assignDoctor(){
    // So when we get a new patient, we need to assign a new Doctor to it.

    // Should I have questions to pick the best one? Or should I just pick the doctor with the least amount of patients?
};

void Patient::checkDoctor(){
    std::ifstream inFile("../files/doctors/doctors.txt");
    std::string line;

    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            std::stringstream ss(value);
            std::string patentID;
            while(std::getline(ss, patientID, ',')){
                std::cout << patientID << std::endl;
            }

            std::cout << key << value << std::endl;
        }
    }
}