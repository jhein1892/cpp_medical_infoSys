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
    update_key("cardNumber", cardNumber);
    User::save_file(filename, user_map);
    assignDoctor();

    controlPatient();
};

Patient::Patient(std::string id, std::string pw): User(id, pw, ""){
    setPatientID(id);
    User::set_filename(genFileName(id));
    User::login(pw);
    User::update_map();

    if(!checkDoctor()){
        assignDoctor();
    }

    controlPatient();

    // Try Logging in
}

Patient::~Patient(){};

std::string Patient::get_cardNum(){
    return cardNumber;
}

void Patient::update_cardNum(std::string newNum){
    std::cout << "Card number Updated from " << cardNumber << " to " << newNum << std::endl;
    cardNumber = newNum;
    update_key("cardNumber", newNum);
}

bool Patient::checkDoctor(){
    if(doctorID.empty()){
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
    } else {
        std::cout << "Doctor ID: " << doctorID << std::endl;
        return true;
    }
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

void Patient::bookAppt(std::string date){
    std::string doctorFile = "../files/doctors/" + doctorID + ".txt"; 
    std::ifstream inFile(doctorFile);
    std::string line;
    
    std::map <std::string, std::string> doc_map;
    std::vector<std::string> apptIDs;
    std::vector<std::string> apptDates;

    if(!inFile.is_open()){
        std::cerr << "Error: could not open file" << filename << std::endl;
    }

    // Go to the doctors file
    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            if(key == "appt_ids" || key == "appt_times"){
                std::stringstream ss(value);
                std::string apptInfo;
                while(std::getline(ss, apptInfo,',')){
                    if(key == "appt_ids"){
                        apptIDs.push_back(apptInfo);
                    } else {
                        apptDates.push_back(apptInfo);
                    }
                }
            }
            doc_map[key] = value;
        }
    }

    // go through appt_times, and see if we can book a time.
    if(apptIDs.size() == apptDates.size()){
        for(int i = 0; i < apptIDs.size(); ++i){
            if(apptDates.at(i) == date){
                std::cout << "Sorry this date is already booked" << std::endl;
                return;
            }
        }
        // If yes add in patientID and date
        apptIDs.push_back(patientID);
        apptDates.push_back(date);
    }

    std::string idString;
    std::string dateString;
    for(int i = 0; i < apptDates.size(); ++i){
        if(idString.empty()){
            idString = apptIDs.at(i);
            dateString = apptDates.at(i);
        } else {
            idString += "," + apptIDs.at(i);
            dateString += "," + apptDates.at(i);
        }
    }

    doc_map["appt_ids"] = idString;
    doc_map["appt_times"] = dateString;

    save_file(doctorFile, doc_map);

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
            std::cout << "r: generate report\nc: check doctor ID\np: generate payment\nu: update card info\nb: book appointment" << std::endl;
            std::cin >> userInput;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            bool isQuit = false;

            std::string newNum;
            std::string date;
            switch(userInput)
            {
                case 'r':
                    User::describe_user();
                    break;
                case 'c':
                    checkDoctor();
                    break;
                case 'p':
                    genPayment();
                    break;
                case 'u':
                    std::cout << "Please enter new card number: ";
                    std::getline(std::cin, newNum);
                    update_cardNum(newNum);
                    break;
                case 'b':
                    std::cout << "What day would you like to book: ";
                    std::getline(std::cin, date);
                    bookAppt(date);
                    break;
                case 'q':
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