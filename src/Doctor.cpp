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
    updatePatients();
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

bool Doctor::check_availabiltiy(std::string date){
    // Can Just check if appointment_map has the relevant key
    for (auto it = appointment_map.begin(); it != appointment_map.end(); ++it){
        if(it->first == date){
            std::cout << "Unavailable, already an appointment on that day" << std::endl;
            return false;
        }
    }

    std::cout << "Available to book appointment" << std::endl;
    return true; 
}

bool Doctor::check_patient(std::string userID){
    for (int i = 0; i < patientList.size(); ++i){
        if(userID == patientList[i]){
            std::cout << patientList[i] << std::endl;
            return true;
        }
    }
    return false;
}

void Doctor::book_appointment(std::string userID, std::string date){
    // Check availability
    if(check_availabiltiy(date) && check_patient(userID)){
        appointment_map[date] = userID;
        std::cout << "Appointment was booked on " << date << " for " << userID << std::endl;
    } else {
        std::cout << "Sorry, we can't book an appointment for that day." << std::endl;
    }
}

void Doctor::save_appointments(){
    // Reverse the getAppointments
        // Turn map into Vectors
        // Turn vectors into strings
        // assign strings to right keys
        // Save right file
}



void Doctor::setDoctorID(std::string id){
    doctorID = id;
}

void Doctor::setDoctorID(){
    std::string randomID = User::genID(12);
    doctorID = randomID;
}

void Doctor::getAppointments(){
    std::vector<std::string> ids;
    std::vector<std::string> dates;

    for(auto it = user_map.begin(); it != user_map.end(); ++it){
        if(it->first == "appt_ids" || it->first == "appt_times"){
            std::stringstream ss(it->second);
            std::string apptInfo;

            while(std::getline(ss, apptInfo,',')){
                if(it->first == "appt_ids"){
                    ids.push_back(apptInfo);
                } else {
                    dates.push_back(apptInfo);
                }
            }
        } 
    }
    if(dates.size() == ids.size()){
        for(int i = 0; i != dates.size(); ++i){
            appointment_map[dates.at(i)] = ids.at(i);
        }

        // for(auto it = appointment_map.begin(); it != appointment_map.end(); ++it){
        //     std::cout << it->first << ": " << it->second << std::endl;
        // }

    } else {
        std::cerr << "Seems to be disparitiy between dates and Ids" << std::endl;
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