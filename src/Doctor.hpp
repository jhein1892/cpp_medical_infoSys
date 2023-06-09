#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.hpp"
#include <string>
#include <vector>

class Doctor : public User {
    public: 
        Doctor(std::string name, std::string phone, std::string dob, std::string pw, std::string id);
        ~Doctor();

        std::string get_id();

        void update_id(std::string id);

        void updatePatients();
        void dropPatient();



        // bool check_availabiltiy
        // void book_appointment(std::string userID)

    private:
        std::string doctorID;
        std::string genFileName();

        std::vector<std::string> patientList;
};

#endif