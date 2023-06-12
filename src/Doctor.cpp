#include "Doctor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Doctor::Doctor(std::string name, std::string phone, std::string dob, std::string pw): 
User(name, phone, dob, pw, "") 
{
    setDoctorID();
    User::set_filename(genFileName());
    User::save_file(filename, user_map);
    loggedIn = true;
}

Doctor::Doctor(std::string id, std::string pw):
User(id, pw, "")
{
    User::set_filename(genFileName(id));

    User::login(pw);
    setDoctorID(id);
    User::update_map();
    getAppointments();
    // User::describe_user();
}

Doctor::~Doctor(){};

std::string Doctor::get_id()
{
    return doctorID;
}

void Doctor::update_id(std::string id){
    doctorID = id;
}

void Doctor::updatePatients(){
    getDoctorList();
    // Updates the patient list for this Doctor
    for(auto it = doctorList.begin(); it != doctorList.end(); ++it){
        if(it->first == doctorID){
            std::stringstream ss(it->second);
            std::string patID;
            while(std::getline(ss, patID, ',')){
                patientList.push_back(patID);
            }
        }
    }
};

void Doctor::dropPatient(std::string patientID){

    // Remove a patient from the list of patients.
    std::string patientString;
    for(int i = 0; i < patientList.size(); i++){
        if(patientID == patientList[i]){
            continue;
        } else {
            if(patientString.empty()){
                patientString = patientList[i];
            } else {
                patientString += "," + patientList[i]; 
            }
        }
    };

    for(auto it = doctorList.begin(); it != doctorList.end(); ++it){
        if(it->first == doctorID){
            it->second = patientString;
            }
        }

    User::save_file(doctorListFile, doctorList);
};

void Doctor::setDoctorID(std::string id){
    doctorID = id;
}

void Doctor::setDoctorID(){
    std::string randomID = User::genID(12);
    doctorID = randomID;
}

void Doctor::getAppointments(){
    for(auto it = user_map.begin(); it != user_map.end(); ++it){
        std::cout << it->first << ": " << it->second << std::endl;
    }
};

std::string Doctor::genFileName(){
    std::string fileName = get_id();

    std::string fullFile = subFolder + fileName + ".txt";
    std::cout << get_id() << std::endl;

    return fullFile;
}

std::string Doctor::genFileName(std::string id){
    std::string filename = id + ".txt";
    std::string fullFile = subFolder + filename;

    return fullFile;
}