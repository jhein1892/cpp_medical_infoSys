#include "User.hpp"
#include <iostream>

class Patient : public User
{
    private:
        std::string cardNumber;
    public:
        Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum);
        ~Patient();
        void print_cardNum();
        void update_cardNum(std::string newNum);
};