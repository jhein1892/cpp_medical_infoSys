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

    Patient::assignDoctor();
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
    // Do same logic as checkDoctor, go through the file, check the number of patients assigned to each doctor
    std::ifstream inFile("../files/doctors/doctors.txt");
    std::string line;
    std::map <std::string, int> doctorCount;

    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            std::stringstream ss(value);
            std::string patID;

            int count = 0;

            while(std::getline(ss, patID, ',')){
                // This is where the logic is going to change from the checkDoctor function
                ++count;

            }
            doctorCount[key] = count;
        }
    }
    // Doctor with the least amount of patients is the one we are going to assign new one to.

    for(auto it = doctorCount.begin(); it != doctorCount.end(); ++it){
        std::cout << it->first << ": " << it->second << std::endl;
    }


};

void Patient::setDoctorID(std::string id){
    doctorID = id;
}

void Patient::checkDoctor(){

    // I should look into moving this to another function, and actually putting the doctor patient list into a vector. Maybe move into the Users class...
    std::ifstream inFile("../files/doctors/doctors.txt");
    std::string line;
    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            std::stringstream ss(value);
            std::string patID;
            
            while(std::getline(ss, patID, ',')){
                if((patID == patientID) == 1){
                    // std::cout << ("sphere" == "sphere") << std::endl;
                    std::cout << key << std::endl;
                    std::cout << patID << patientID << std::endl;
                    setDoctorID(key);
                    return;
                }
            }
        }
    }

    std::cout << "Patient not assigned to Doctor yet" << std::endl;

}