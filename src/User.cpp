#include "User.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


User::User(std::string name, std::string phone, std::string dob, std::string pw, std::string fileName): filename(fileName)
{
    // Store input values into user_map variable
    user_map["name"] = name;
    user_map["phone"] = phone;
    user_map["DOB"] = dob;
    user_map["password"] = pw;   

    describe_user();

    gen_file();
};

User::~User(){};

void User::update_map(std::string key, std::string value){
    user_map[key] = value;
    return;
};

std::string User::get_value(std::string key){
    auto it = user_map.find(key);
    return it->second;
}

void User::set_filename(std::string file)
{
    filename = file;
    gen_file();
}

void User::login(std::string inputPw){
    if(loggedIn){
        std::cout << "Already Logged in" << std::endl;
        return;
    }
    
    if(checkPassword(inputPw)){
        loggedIn = true;
        std::cout << "User Logged in" << std::endl;
    } else {
        std::cout << "Incorrect Password, Please try again." << std::endl;
    }
}

void User::gen_file(){
    if(!filename.empty()){
        std::string fullFile = fileFolder + filename;
        std::ofstream outFile(fullFile);
        if(!outFile.is_open()){
            std::cerr << "Error: Could not open File" << fullFile << std::endl;
        }

        for (const auto& p : user_map){
            outFile << p.first << ": " << p.second << std::endl;
        }

        outFile.close();
    } else {
        std::cerr << "No Filename detected" << std::endl;
    }
}

void User::describe_user(){
    
    std::cout << "Name: " << get_value("name") << "\nPhone: " << get_value("phone") << std::endl;
}

std::string User::genID(int length){
    std::string characters = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string userID;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < length; i++){
        int randomIndex = std::rand() % characters.length();
        userID += characters[randomIndex];
    };
    std::cout << userID << std::endl;

    return userID;
}

bool User::checkPassword(std::string inputPw){
    if(user_map["password"] == inputPw){
        return true;
    } else {
        return false;
    }
}