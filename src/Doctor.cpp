#include "Doctor.hpp"
#include <iostream>

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
    //  Run through the doctor list

    // For each line in txt file
        // If it->first is doctorID
        // Split it->seconds and for each patient ID we wil add it to a vector that hold all ids
};

void Doctor::dropPatient(){
    // Remove a patient from the list of patients.
    // Take id which is passed in, and iterate through patientID vector, once we get it, we are going to remove the id and resize the vector.
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