#include "User.hpp"
#include <iostream>

class Patient : public User
{
    public:
        Patient(std::string name, std::string phone, std::string dob, std::string pw, std::string cardNum): 
            User(name, phone, dob, pw), cardNumber(cardNum)
        {
            print_cardNum();
        };

        void print_cardNum(){
            std::cout << cardNumber << std::endl;
        }

    private:
        std::string cardNumber;
};