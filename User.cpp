#include <string>

class User
{
private:
    std::string username;
    std::string phoneNum;
    std::string dob; // Look into how we can store dates
    std::string password;

    std::string encryptPW(){};
    std::string decryptPW(){};
    
public:
    User(/* args */);
    ~User();
    // Name Functions
    void set_name(){};
    std::string get_name(){};

    // Phone Functions
    void set_phone(){};
    std::string get_phone(){};

    // Date of Birth Functions
    void set_dob(){};
    std::string get_dob(){};

    // Password Functions
    void set_pw(){};
    bool check_pw(){};

    bool user_login(){};
};

User::User(/* args */)
{
}

User::~User()
{
}
