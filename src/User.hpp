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
        
    protected:
        std::string doctorListFile = "../files/doctors/doctors.txt";
        std::string filename;
        std::map<std::string, std::string> user_map;
        std::map<std::string, std::string> doctorList;
        bool loggedIn = false;

        // Updates user_map from file
        void update_map();

        // Updates user_map key
        void update_key(std::string key, std::string value);

        void set_filename(std::string file);
        void login(std::string inputPw);
        void describe_user();
        void getDoctorList();
        void save_file(std::string input_file, std::map<std::string, std::string> input_map);

        bool checkPassword(std::string inputPw);

        // Return value at key
        std::string get_value(std::string key);
        std::string genID(int length);

    private:
        std::string fileFolder = "../files/";
};

#endif