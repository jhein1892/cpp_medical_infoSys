#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.hpp"
#include <string>

class Doctor : public User {
    public: 
        Doctor(std::string name, std::string phone, std::string dob, std::string pw, std::string id);
        ~Doctor();

        std::string get_id();

        void update_id(std::string id);
        
    private:
        std::string doctorID;
};

#endif