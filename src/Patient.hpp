#ifndef PATIENT_H
#define PATIENT_H

#include "User.hpp"

class Patient : public User
{
    public:
        Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum);
        ~Patient();

        std::string get_cardNum();
        void update_cardNum(std::string newNum);

    private:
        std::string cardNumber;
        std::string patientID;

        std::string genFileName();
        void setPatientID();
};

#endif