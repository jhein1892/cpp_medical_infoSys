#ifndef PATIENT_H
#define PATIENT_H

#include "User.hpp"

class Patient : public User
{
    public:
        Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum);
        Patient(std::string id, std::string pw);
        ~Patient();

        std::string get_cardNum();
        void update_cardNum(std::string newNum);

        void add_appt(std::string date);
        void gen_report();

    protected:
        std::string subFolder = "/patients/";

    private:
        std::string cardNumber;
        std::string patientID;
        // std::string nextAppt;

        std::string genFileName();
        std::string genFileName(std::string id);
        void setPatientID();
        void setPatientID(std::string id);
        void genPayment();
};

#endif