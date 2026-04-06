#include "Interface.h"
#include "Department.h"
#include <iostream>
#include <cstring>

extern Department* Departments;
extern int DeptCount;

using namespace std;

Interface::~Interface() {}

bool Interface::ValidateRange(const int userInput, const int min, const int max) {
    if (userInput >= min and userInput <= max) {
        return true;
    }
    else {
        return false;
    }
}

bool Interface::ValidateSchedule(const char* Schedule) {
    if (Schedule == nullptr) {
        return false;
    }
    if (strlen(Schedule) != 3) {
        return false;
    }
    if (Schedule[0] == 'M' && Schedule[1] == '/' && Schedule[2] == 'W') {
        return true;
    }
    else if (Schedule[0] == 'T' && Schedule[1] == '/' && Schedule[2] == 'R') {
        return true;
    }
    else if (Schedule[0] == 'W' && Schedule[1] == '/' && Schedule[2] == 'F') {
        return true;
    }

    return false;
}

bool Interface::ValidatePositive(const double price) {
    if (price >= 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Interface::ValidateNotEmpty(const char* input) {
    if (input[0] != '\0') {
        return true;
    }
    else {
        return false;
    }
}

void Interface::Errors(const int num) {
    if (num == 1) {
        cout << "Invalid input. Please try again." << endl;
    }
    else if (num == 2) {
        cout << "Invalid schedule. Schedules must be 'M/W', 'T/R', or 'W/F'. Please try again." << endl;
    }
    else if (num == 3) {
        cout << "Invalid input. Can not be negative. Please try again. " << endl;
    }
    else if (num == 4) {
        cout << "Invalid input. Name must contain at least one character." << endl;
    }
}