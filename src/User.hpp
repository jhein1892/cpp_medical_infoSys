#ifndef USER_H
#define USER_H

#include <string>
#include <map>

class User
{
    
    public:
        User(std::string name, std::string phone, std::string dob, std::string pw, std::string fileName);
        ~User();
        
        // Name Functions
        void set_name(std::string name);
        std::string get_name() const;

        void set_filename(std::string file);
        std::string get_filename() const;

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

        void gen_file();

        void describe_user();


    private:
        std::map<std::string, std::string> user_map;
        std::string fileFolder = "../files/";
        std::string filename;

        bool loggedIn = false;

        bool checkPassword(std::string inputPw);

        // std::string encryptPW(){};
        // std::string decryptPW(){};


};

#endif