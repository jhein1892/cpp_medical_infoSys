#include "User.hpp"
#include <iostream>

User::User(std::string name, std::string phone, std::string dob, std::string pw): username(name),phoneNum(phone),dob(dob),password(pw) {
    describe_user();
};

User::~User(){};


// Name Functions
void User::set_name(std::string name){username = name;};
std::string User::get_name() const 
{
    return username;
};

// Phone Functions
void User::set_phone(std::string phone){phoneNum = phone;};
std::string User::get_phone() const 
{
    return phoneNum;
};

// Date of Birth Functions
void User::set_dob(std::string dob){dob = dob;};
std::string User::get_dob() const
{
    return dob;
};

// Password Functions
void User::set_pw(std::string pw){password = pw;};
// bool check_pw(){};

// bool user_login(){};

void User::describe_user(){
    std::cout << "Name: " << username << "\nPhone: " << phoneNum << "\ndob: " << dob << "\nPW: " << password << std::endl;
}