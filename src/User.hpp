#ifndef USER_H
#define USER_H

#include <string>

class User
{
    private:
        std::string username;
        std::string phoneNum;
        std::string dob; // Look into how we can store dates
        std::string password;
        bool loggedIn = false;

        bool checkPassword(std::string inputPw);

        // std::string encryptPW(){};
        // std::string decryptPW(){};

    public:
        User(std::string name, std::string phone, std::string dob, std::string pw);
        ~User();
        
        // Name Functions
        void set_name(std::string name);
        std::string get_name() const;

        // Phone Functions
        void set_phone(std::string phone);
        std::string get_phone() const;

        // Date of Birth Functions
        void set_dob(std::string dob);
        std::string get_dob() const;

        // Password Functions
        void set_pw(std::string pw);
        // bool check_pw(){};

        // bool user_login(){};
        void login(std::string inputPw);


        void describe_user();


};

#endif