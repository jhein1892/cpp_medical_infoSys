#include "Doctor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Doctor::Doctor(std::string name, std::string phone, std::string dob, std::string pw, std::string id): 
User(name, phone, dob, pw, ""), doctorID(id) 
{
    User::set_filename(genFileName());
    std::cout << get_id() << std::endl;
    // Make sure to add new doctor to doctor:patient list
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

    // This is going to establish the list of patients that the doctor has
    std::ifstream inFile("../files/doctors/doctors.txt");
    std::string line;
    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            std::stringstream ss(value);
            std::string patID;
            // If it->first is doctorID
            if(key == doctorID){
                // Split it->seconds and for each patient ID we wil add it to a vector that hold all ids
                while(std::getline(ss, patID, ',')){
                    // Push new ID to to patientList vector
                    patientList.push_back(patID);
                }
            }
        }
    }

    
};

void Doctor::dropPatient(std::string patientID){

    // std::cout << patientID << std::endl;
    // std::cout << "Starting with: " << std::endl;
    // for(int i = 0; i < patientList.size(); i++){
    //     std::cout << patientList[i] << std::endl;
    // }


    // Remove a patient from the list of patients.
    for(int i = 0; i < patientList.size(); i++){
        if(patientID == patientList[i]){
            patientList.erase(patientList.begin() + i);
        }
    }

    std::string patientString;

    for(int i = 0; i < patientList.size(); i++){
        if(patientString.empty()){
            patientString = patientList[i];
        } else {
            patientString += "," + patientList[i]; 
        }
    }

    std::cout << patientString << std::endl;


    // At this point we need to re-write the dotors.txt file to hold the right info.
        // So we will need to create a map with the update values (find a way of turning a vector into a string)
};

std::string Doctor::genFileName(){
    std::string fileName = get_id();
    std::string subFolder = "/doctors/";

    std::string fullFile = subFolder + fileName + ".txt";
    std::cout << get_id() << std::endl;

    return fullFile;
}