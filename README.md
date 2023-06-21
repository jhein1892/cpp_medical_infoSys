# C++ Medical Info System

This project consists of three classes files: User, Doctor, and Patient. These classes are used to build a program for managing user, doctor, and patient information.

## User
The User class, which represents a user in the system. 

The User class also has member variables and functions that handle operations such as updating the user map from a file, updating keys, setting the filename, logging in, describing the user, retrieving the list of doctors, saving files, and more.

## Doctor
The Doctor class extends the User class. This class represents a doctor in the system.

The Doctor class inherits the protected and private member variables and functions from the User class. It also introduces additional functions specific to doctors, such as updating the doctor ID, updating the list of patients, booking appointments, saving appointments, checking availability, and more.

## Patient
The Patient class also extends the User class, representing a patient in the system.

The Patient class inherits the protected and private member variables and functions from the User class. It includes additional functions specific to patients, such as updating the card number, generating payments, booking appointments, assigning doctors, and more.

### Dependencies

This project has dependencies on the standard C++ library headers, including <samp>string</samp>, <samp>map</samp>, and <samp>vector</samp>. Make sure these dependencies are available and properly included in your project.