#ifndef USER_H
#define USER_H

#include <string>
#include <map>

class User
{
    
    public:
        User(std::string name, std::string phone, std::string dob, std::string pw, std::string fileName);
        ~User();

        void update_map(std::string key, std::string value);
        std::string get_value(std::string key);
        
        // Name Functions
        // void set_name(std::string name);
        // std::string get_name() const;

        void set_filename(std::string file);

        // Phone Functions
        // void set_phone(std::string phone);
        // std::string get_phone() const;

        // Date of Birth Functions
        // void set_dob(std::string dob);
        // std::string get_dob() const;

        // Password Functions
        // void set_pw(std::string pw);
        // bool check_pw(){};

        // bool user_login(){};
        void login(std::string inputPw);


        void describe_user();


    protected:
        std::map<std::string, std::string> user_map;
        bool loggedIn = false;

        void gen_file();
        bool checkPassword(std::string inputPw);
        std::string genID(int length);

    private:
        std::string fileFolder = "../files/";
        std::string filename;




        // std::string encryptPW(){};
        // std::string decryptPW(){};


};

#endif