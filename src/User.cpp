#include "User.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

// New User 
User::User(std::string name, std::string phone, std::string dob, std::string pw, std::string fileName): filename(fileName)
{
    // Store input values into user_map variable
    user_map["name"] = name;
    user_map["phone"] = phone;
    user_map["DOB"] = dob;
    user_map["password"] = pw;

    loggedIn = true;

    save_file(filename, user_map);
};

// Login Existing User
User::User(std::string id, std::string pw, std::string fileName){};

User::~User(){};

void User::update_map(){

    std::ifstream inFile(filename);
    std::string line;

    if(!inFile.is_open()){
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }

    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            update_key(key, value);
        }
    }
    inFile.close();
}

void User::update_key(std::string key, std::string value){
    if(loggedIn){
        user_map[key] = value;
        save_file(filename, user_map);
    } else {
        std::cout << "Please Login to update values" << std::endl;
    }
        return;
};

std::string User::get_value(std::string key){
    if(loggedIn){
        auto it = user_map.find(key);
        return it->second;
    } else {
        return "Please Login to see this value";
    }
}

void User::set_filename(std::string file)
{
    filename = fileFolder + file;
    std::cout << "In Set_filename" << file << std::endl;
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

void User::describe_user(){
    for(auto it = user_map.begin(); it != user_map.end(); ++it){
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

void User::save_file(std::string input_file, std::map<std::string, std::string> input_map){
    if(!filename.empty()){
        // std::string fullFile = fileFolder + filename;
        std::ofstream outFile(input_file);
        if(!outFile.is_open()){
            std::cerr << "Error: Could not open File" << input_file << std::endl;
        }

        for (const auto& p : input_map){
            outFile << p.first << ":" << p.second << std::endl;
        }
        outFile.close();
    } 
    else {
        std::cerr << "No Filename detected" << std::endl;
    }
}

bool User::checkPassword(std::string inputPw){
    // If logged in, check map
    if(loggedIn){ 
        if(user_map["password"] == inputPw){
            return true;
        } else {
            return false;
        }
    } 

    // If not logged in will need to reference file
    else {
        std::ifstream inFile(filename);
        std::string line;

        if(!inFile.is_open()){
            std::cerr << "Error: Could not open file " << filename << std::endl;
        }

        while(std::getline(inFile, line)){
            std::size_t pos = line.find(":");
            if(pos != std::string::npos){
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);

                if(key == "password"){
                    if ((value == inputPw) == 0){
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
        inFile.close();
    }

    return false;
}

void User::getDoctorList(){
    std::ifstream inFile(doctorListFile);
    std::string line;
    while(std::getline(inFile, line)){
        std::size_t pos = line.find(":");
        if(pos != std::string::npos){
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            doctorList[key] = value;
        }
    }
};

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