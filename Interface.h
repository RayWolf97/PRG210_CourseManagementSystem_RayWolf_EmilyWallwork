#pragma once
#include <iostream>
using namespace std;

class Interface {     
    public:
    virtual void Menu() = 0;                                                 // Pure virtual function for displaying menu (must be implemented by derived classes)
    virtual ~Interface();                                                    // Virtual destructor for proper cleanup of derived classes
    bool ValidateRange(const int userInput, const int min, const int max);   // Validates input is within a specified range
    bool ValidateSchedule(const char* Schedule);                             // Validates course schedule format
    bool ValidatePositive(const double price);                               // Validates value is non-negative
    bool ValidateNotEmpty(const char* input);                                // Validates string is not empty
    void Errors(const int num);                                              // Displays error messages based on error code
};