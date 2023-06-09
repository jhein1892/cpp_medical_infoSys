#ifndef PATIENT_H
#define PATIENT_H

#include "User.hpp"

class Patient : public User
{
    public:
        Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum);
        Patient(std::string id, std::string pw);
        ~Patient();
        
    protected:
        std::string subFolder = "/patients/";

    private:
        std::string cardNumber;
        std::string patientID;
        std::string doctorID;

        void update_cardNum(std::string newNum);
        void setPatientID();
        void setPatientID(std::string id);
        void setDoctorID(std::string id);
        void genPayment();
        void bookAppt(std::string date);
        void assignDoctor();

        bool checkDoctor();

        std::string get_cardNum();
        std::string genFileName();
        std::string genFileName(std::string id);

        void controlPatient();
};

#endif