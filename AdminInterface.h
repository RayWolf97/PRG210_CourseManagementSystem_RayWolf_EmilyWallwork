#pragma once
#include "Interface.h"
#include "Department.h"
#include "Course.h"
#include <iostream>
using namespace std;

class AdminInterface : public Interface {
    private:

    public:
    AdminInterface();       // Constructor: initializes AdminInterface object
    ~AdminInterface();      // Destructor: cleans up resources if needed

    void Menu() override;   // Displays admin menu and handles user interaction
    void DisplayDepts();    // Displays list of all departments
    void AddDepartment();   // Adds a new department to the system
    void AddCourse();       // Adds a new course to a selected department
    void SaveToCSV();       // Saves all departments and courses to CSV file
}; 