#include "Interface.h"
#include "Department.h"
#include <iostream>
#include <cstring>

extern Department* Departments;
extern int DeptCount;

using namespace std;

Interface::~Interface() {}                                              // Virtual destructor for base class

bool Interface::ValidateRange(const int userInput, const int min, const int max) {  // Checks if input is within valid range  
    if (userInput >= min and userInput <= max) {                        // Valid range check
        return true;                                                    // Input valid
    }
    else {
        return false;                                                   // Input invalid
    }
}

bool Interface::ValidateSchedule(const char* Schedule) {                // Validates course schedule format
    if (Schedule == nullptr) {                                          // Check for null pointer
        return false;                                                   // Invalid if null
    }
    if (strlen(Schedule) != 3) {                                        // Check length (must be like M/W)
        return false;                                                   // Invalid lenth
    }
    if (Schedule[0] == 'M' && Schedule[1] == '/' && Schedule[2] == 'W') {       // Check M/W format
        return true;
    }
    else if (Schedule[0] == 'T' && Schedule[1] == '/' && Schedule[2] == 'R') {  // Check T/R format
        return true;
    }
    else if (Schedule[0] == 'W' && Schedule[1] == '/' && Schedule[2] == 'F') {  // Check W/F format
        return true;
    }

    return false;                                                       // Return false if no valid format matched
}

bool Interface::ValidatePositive(const double price) {                  // Checks if value is non-negative
    if (price >= 0) {                                                   // Valid if zero or positive
        return true;
    }
    else {
        return false;                                                   // Invalid if negative
    }
}

bool Interface::ValidateNotEmpty(const char* input) {                   // Checks if string is not empty
    if (input[0] != '\0') {                                             // First character is not null terminator
        return true;                                                    // String is not empty
    }
    else {
        return false;                                                   // String is empty 
    }
}

void Interface::Errors(const int num) {                                 // Displays error messages based on code
    if (num == 1) {                                                     // General invalid input
        cout << "Invalid input. Please try again." << endl;    
    }
    else if (num == 2) {                                                // Invalid schedule format 
        cout << "Invalid schedule. Schedules must be 'M/W', 'T/R', or 'W/F'. Please try again." << endl;
    }
    else if (num == 3) {                                                // Negative value error
        cout << "Invalid input. Can not be negative. Please try again. " << endl;
    }
    else if (num == 4) {                                                // Empty name error
        cout << "Invalid input. Name must contain at least one character." << endl;
    }
}