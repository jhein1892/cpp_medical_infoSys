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
    User::save_file(filename, user_map);
    assignDoctor();
};

Patient::Patient(std::string id, std::string pw): User(id, pw, ""){
    setPatientID(id);
    User::set_filename(genFileName(id));
    User::login(pw);
    User::update_map();

    if(!checkDoctor()){
        assignDoctor();
    }



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

bool Patient::checkDoctor(){

    getDoctorList();
    for(auto it = doctorList.begin(); it != doctorList.end(); ++it){
        std::stringstream ss(it->second);
        std::string patID;
        while(std::getline(ss, patID, ',')){
            if((patID == patientID) == 1){
                setDoctorID(it->first);
                std::cout << "Doctor ID: " << it->first << std::endl;
                return true;
            }
        }
    };

    std::cout << "Patient not assigned to Doctor yet" << std::endl;
    return false;
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

void Patient::setDoctorID(std::string id){
    doctorID = id;
}

void Patient::genPayment(){
    std::cout << "Payment Processed on Card Number: " << cardNumber << std::endl;
    return;
}

void Patient::assignDoctor(){
    std::map <std::string, int> doctorCount;

    getDoctorList();

    for(auto it = doctorList.begin(); it != doctorList.end(); ++it){
        std::stringstream ss(it->second);
        std::string patID;
        int count = 0;

        while(std::getline(ss, patID, ',')){
            ++count;
        }
        doctorCount[it->first] = count;
    }

    // Working on updating the list of Patients in the proper file.
    int currentLow = doctorCount.begin()->second;
    std::string currentKey = doctorCount.begin()->first;

    for(auto it = doctorCount.begin(); it != doctorCount.end(); ++it){
        if(it->second < currentLow){
            currentLow = it->second;
            currentKey = it->first;
        } else {
            continue;
        }
    }

    setDoctorID(currentKey);

    if(currentLow > 0){
        doctorList[currentKey] = doctorList[currentKey] + "," + patientID;
    } else {
        doctorList[currentKey] = patientID;
    }

    save_file(doctorListFile, doctorList);
};

void Patient::controlPatient(){
    while(true){
        if(loggedIn){
            char userInput;
            std::cout << "r: generate report\nc: check doctor ID\np: generate payment\nn: next appointment\nb: book appointment" << std::endl;
            std::cin >> userInput;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool isQuit = false;

            switch(userInput)
            {
                case 'r':
                    // gen report
                    break;
                case 'c':
                    // check doctor
                    break;
                case 'p':
                    // gen payment
                    break;
                case 'n':
                    // next appointment
                    break;
                case 'b':
                    // book appointment
                    break;
                case 'q':
                    // Quit
                    isQuit = true;
                    break;
            }

            if(isQuit){
                break;
            }
        } else {
            if(!user_map.empty()){
                auto tempPW = user_map.find("Password");
                login(tempPW->second);
            } else {
                std::cout << "User Map is empty for some reason" << std::endl;
                break;
            }
        }
    }

    std::cout << "Logging out" << std::endl;
}