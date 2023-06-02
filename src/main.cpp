// A Medical Information System is designed to store and organize patient medical information, such as demographic and clinical data, lab results, and other relevant information using a C++ programming language. The system is designed to allow easy expansion, and efficient and secure payments using object-oriented programming techniques to ensure the data is stored, retrieved, and managed efficiently. The system can use encryption and authentication techniques to ensure the data is kept secure and private for a particular patient. 

// Technologies Required: C++ programming language, Object Oriented Programming (OOP), Encryption & Authentication and Database Management System (DBMS).
#include "Patient.hpp"
#include "Doctor.hpp"

#include "User.hpp"

#include <string>
#include <stdio.h>
#include <iostream>

int main(){

    // User newUser = User("Name", "Phone", "DOB", "PW", "Test1.txt");
    // Patient newPatient = Patient("New Name", "Phone", "DOB", "PAssword", "123456789");


    // Doctor newDoctor = Doctor("New Doctor", "Doc Phone", "dob", "paSSWORD", "123dd");

    Patient loginPatient = Patient("ZXt2hwPAQb", "PAssword");
    // Patient loginPatient = Patient("ZXt2hwPAQb", "password");
    std::cout << loginPatient.get_value("name") << std::endl;

    // newPatient.add_appt("Today");

    // newDoctor.login("WrongPassword");
    // newPatient.login("PAssword");
    // newPatient.login("AlredyLoggedIN");
    return 0;
}