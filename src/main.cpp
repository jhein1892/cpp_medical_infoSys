// A Medical Information System is designed to store and organize patient medical information, such as demographic and clinical data, lab results, and other relevant information using a C++ programming language. The system is designed to allow easy expansion, and efficient and secure payments using object-oriented programming techniques to ensure the data is stored, retrieved, and managed efficiently. The system can use encryption and authentication techniques to ensure the data is kept secure and private for a particular patient. 

// Technologies Required: C++ programming language, Object Oriented Programming (OOP), Encryption & Authentication and Database Management System (DBMS).
#include "Patient.hpp"
#include "Doctor.hpp"
#include "User.hpp"
#include <string>
#include <stdio.h>
#include <iostream>

int main(){
    // Main function
    while(true)
    {
        std::string userType;
        while(true){
            std::cout << "Are you a Patient or are you a Doctor? " << std::endl;
            std::getline(std::cin, userType);
            if(userType == "Patient"){
                std::cout << "So you're a Patient" << std::endl;
                break;
            } else if(userType == "Doctor"){
                std::cout << "Ok you're a Doctor" << std::endl;
                break;
            } else {
                std::cout << "Sorry thats not a recoginized option" << std::endl;
            }
        }
        // Are you a patient or are you a Doctor

        // Are you logging in or are you Creating a new user?
        std::string acctType;
        while(true){
            std::cout << "Existing or new user? " <<std::endl;
            std::getline(std::cin, acctType);
            if(acctType == "New"){
                // Need name, phone, DOB, password
                std::string name;
                std::string phone;
                std::string dob;
                std::string password;
                std::string confirmPass;

                std::cout << "Please Enter your name: ";
                std::getline(std::cin, name);
                std::cout << "Please Enter your Phone Number: ";
                std::getline(std::cin, phone);
                std::cout << "Please Enter your Date of Birth: ";
                std::getline(std::cin, dob);
                std::cout << "Please Enter your password: ";
                std::getline(std::cin, password);

                if(userType == "Patient"){
                    // Need cardNum 
                    std::string cardNum;
                    std::cout << "Please Enter your Card Number: ";
                    std::getline(std::cin, cardNum);

                    // Create new Patient
                    Patient newPatient = Patient(name, phone, dob, password, cardNum);
                    break;
                }
                //Create new Doctor
                Doctor newDoctor = Doctor(name, phone, dob, password);
                break;
                

            } else if (acctType == "Existing"){
                // Need id, pw
                std::string id;
                std::string password;
                std::cout << "Please Enter your ID: ";
                std::getline(std::cin, id);
                std::cout << "Please Enter your password: ";
                std::getline(std::cin, password);

                if(userType == "Patient"){
                    // Login Patient
                    Patient loginPatient = Patient(id, password);
                    break;
                }
                // Login Doctor
                Doctor loginDoctor = Doctor(id, password); 
                break;

            } else {
                std::cout << "Sorry thats not a recoginized option" << std::endl;
            }
        }
        break;
    }




    // User newUser = User("Name", "Phone", "DOB", "PW", "Test1.txt");
    // Patient newPatient = Patient("New Name", "Phone", "DOB", "PAssword", "123456789");


    // Doctor newDoctor = Doctor("New Doctor", "Doc Phone", "dob", "paSSWORD", "123dd");

    // Doctor loginDoctor = Doctor("123dd", "paSSWORD");
    // loginDoctor.check_availabiltiy("2023/06/15");
    // loginDoctor.book_appointment("IXNclWCex6", "2023/06/15");

    // newDoctor.updatePatients();

    // newDoctor.dropPatient("IXNclWCex6");

    // Patient loginPatient = Patient("ZXt2hwPAQb", "PAssword");
    // loginPatient.checkDoctor();
    // Patient loginPatient = Patient("ZXt2hwPAQb", "password");
    // std::cout << loginPatient.get_value("name") << std::endl;

    // loginPatient.gen_report();

    // newPatient.add_appt("Today");

    // newDoctor.login("WrongPassword");
    // newPatient.login("PAssword");
    // newPatient.login("AlredyLoggedIN");
    return 0;
}