#include <string>
#include <stdio.h>
#include <iostream>

#define USER_HPP

class User
{
    private:
        std::string username;
        std::string phoneNum;
        std::string dob; // Look into how we can store dates
        std::string password;

        // std::string encryptPW(){};
        // std::string decryptPW(){};


    
    public:
        User(std::string name, std::string phone, std::string dob, std::string pw);
        ~User();
        // Name Functions
        void set_name(std::string name)
        {
            User::username = name;
        };
        // std::string get_name(){};

        // Phone Functions
        void set_phone(std::string phone)
        {
            User::phoneNum = phone;
        };
        // std::string get_phone(){};

        // Date of Birth Functions
        void set_dob(std::string dob)
        {
            User::dob = dob;
        };
        // std::string get_dob(){};

        // Password Functions
        void set_pw(std::string pw)
        {
            User::password = pw;
        };
        // bool check_pw(){};

        // bool user_login(){};

        void describe_user(){
            std::cout << "Name: " << username << "\nPhone: " << phoneNum << "\ndob: " << dob << "\nPW: " << password << std::endl;
        }
};

User::User(std::string name, std::string phone, std::string dob, std::string pw)
{
    set_name(name);
    set_phone(phone);
    set_dob(dob);
    set_pw(pw);
    describe_user();
}

User::~User()
{
}
