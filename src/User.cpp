#include "User.hpp"
#include <iostream>
#include <fstream>


User::User(std::string name, std::string phone, std::string dob, std::string pw, std::string fileName): filename(fileName)
{
    // Store input values into user_map variable
    user_map["name"] = name;
    user_map["phone"] = phone;
    user_map["DOB"] = dob;
    user_map["password"] = pw;   

    describe_user();

    gen_file();
};

User::~User(){};

// Name Functions
void User::set_name(std::string name)
{
    user_map["name"] = name;
    // Update File
};
std::string User::get_name() const 
{
    auto it = user_map.find("name");
    return it->second;
};

void User::set_filename(std::string file)
{
    filename = file;
    gen_file();
}

// Phone Functions
void User::set_phone(std::string phone)
{
    user_map["phone"] = phone;

    // Update File
};
std::string User::get_phone() const 
{
    auto it = user_map.find("phone");
    return it->second;
};

// Date of Birth Functions
void User::set_dob(std::string dob)
{
    user_map["DOB"] = dob;
    // Update File
};
std::string User::get_dob() const
{
    auto it = user_map.find("DOB");
    return it->second;
};

// Password Functions
void User::set_pw(std::string pw)
{
    user_map["password"] = pw;

    // Update File
};
// bool check_pw(){};
// bool user_login(){};

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

void User::gen_file(){
    if(!filename.empty()){
        std::string fullFile = fileFolder + filename;
        std::ofstream outFile(fullFile);
        if(!outFile.is_open()){
            std::cerr << "Error: Could not open File" << fullFile << std::endl;
        }

        for (const auto& p : user_map){
            outFile << p.first << ": " << p.second << std::endl;
        }

        outFile.close();
    } else {
        std::cerr << "No Filename detected" << std::endl;
    }
}

void User::describe_user(){
    
    std::cout << "Name: " << get_name() << "\nPhone: " << get_phone() << std::endl;
}

bool User::checkPassword(std::string inputPw){
    if(user_map["password"] == inputPw){
        return true;
    } else {
        return false;
    }
}