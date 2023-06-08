#ifndef USER_H
#define USER_H

#include <string>
#include <map>

class User
{
    
    public:
        // Creating a new User
        User(std::string name, std::string phone, std::string dob, std::string pw, std::string fileName);

        // Logging into an existing User
        User(std::string id, std::string pw, std::string fileName);
        ~User();

        void update_map();

        void update_key(std::string key, std::string value);
        std::string get_value(std::string key);

        void set_filename(std::string file);

        void login(std::string inputPw);

        void describe_user();

    protected:
        std::map<std::string, std::string> user_map;
        bool loggedIn = false;

        void save_file();
        void save_file(std::string input_file, std::map<std::string, std::string> input_map);
        bool checkPassword(std::string inputPw);
        std::string genID(int length);

    private:
        std::string fileFolder = "../files/";
        std::string filename;

        // std::string encryptPW(){};
        // std::string decryptPW(){};

};

#endif