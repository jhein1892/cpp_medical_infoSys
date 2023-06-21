#ifndef DOCTOR_H
#define DOCTOR_H

#include "User.hpp"
#include <string>
#include <vector>

class Doctor : public User {
    public: 
        Doctor(std::string name, std::string phone, std::string dob, std::string pw);
        Doctor(std::string id, std::string pw);
        ~Doctor();

    protected:
        std::string subFolder = "/doctors/";

    private:
        std::map <std::string, std::string> appointment_map;
        std::vector<std::string> patientList;
        std::string doctorID;

        void update_id(std::string id);
        void updatePatients();
        void dropPatient(std::string patientID);
        void book_appointment(std::string userID, std::string date);
        void save_appointments();
        void setDoctorID(std::string id);
        void setDoctorID();
        void getAppointments();
        
        bool check_availabiltiy(std::string date);
        bool check_patient(std::string userID);

        std::string get_id();
        std::string genFileName();
        std::string genFileName(std::string id);
        
        void controlDoctor(); 

};

#endif