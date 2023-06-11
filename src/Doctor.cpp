#include "Doctor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Doctor::Doctor(std::string name, std::string phone, std::string dob, std::string pw, std::string id): 
User(name, phone, dob, pw, ""), doctorID(id) 
{
    User::set_filename(genFileName());
    std::cout << get_id() << std::endl;
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

std::string Doctor::genFileName(){
    std::string fileName = get_id();
    std::string subFolder = "/doctors/";

    std::string fullFile = subFolder + fileName + ".txt";
    std::cout << get_id() << std::endl;

    return fullFile;
}