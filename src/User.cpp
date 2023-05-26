#include "User.hpp"
#include <iostream>
#include <fstream>


User::User(std::string name, std::string phone, std::string dob, std::string pw, std::string* fileName): 
username(name),phoneNum(phone),dob(dob),password(pw),filename(fileName) 
{
    // Store input values into user_map variable
    user_map["name"] = name;
    user_map["phone"] = phone;
    user_map["DOB"] = dob;
    user_map["password"] = pw;
    // std::cout << filename << std::endl;
    std::string fullFileName = fileFolder + *filename;
    std::cout << *filename << std::endl;
    // printf("Filename: %s", c_str(*filename));
    std::ofstream outFile(fullFileName);
    if(!outFile.is_open()){
        std::cerr << "Error: Could not open File" << fullFileName << std::endl;
    }

    for (const auto& p : user_map){
        outFile << p.first << ": " << p.second << std::endl;
    }

    outFile.close();
};

User::~User(){};

bool User::checkPassword(std::string inputPw){
    if(user_map["password"] == inputPw){
        return true;
    } else {
        return false;
    }
}


// Name Functions
void User::set_name(std::string name)
{
    user_map["name"] = name;
    // Update File
};
std::string User::get_name() const 
{
    return username;
};

// Phone Functions
void User::set_phone(std::string phone)
{
    user_map["phone"] = phone;

    // Update File
};
std::string User::get_phone() const 
{
    return phoneNum;
};

// Date of Birth Functions
void User::set_dob(std::string dob)
{
    user_map["DOB"] = dob;
    // Update File
};
std::string User::get_dob() const
{
    return dob;
};

// Password Functions
void User::set_pw(std::string pw)
{
    user_map["password"] = pw;

    // Update File
};
// bool check_pw(){};

void User::login(std::string inputPw){
    if(loggedIn){
        std::cout << "Already Logged in" << std::endl;
        return;
    }
    
    if(checkPassword(inputPw)){
        loggedIn = true;
        std::cout << "User Logged in" << std::endl;
    } else {
        std::cout << "Incorrect Password, Please try again." << std::endl;
    }
}


// bool user_login(){};

void User::describe_user(){
    std::cout << "Name: " << username << "\nPhone: " << phoneNum << "\ndob: " << dob << "\nPW: " << password << std::endl;
}