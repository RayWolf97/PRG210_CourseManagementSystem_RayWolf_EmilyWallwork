#include <iostream>
#include "Interface.h"
#include "AdminInterface.h"
#include "StudentInterface.h"
#include "Department.h"
#include <iostream>
#include <limits>

using namespace std;

Department* Departments = nullptr;                                // Global pointer to dynamic array of departments
int DeptCount = 0;                                                // Global variable tracking number of departments
const char* csvFile = "Courses.csv";                              // File path for saving/loading course data

int main () {                                                     // Entry point of the program 
    Interface* ui = nullptr;                                      // Pointer to base Interface for polymorphism
    int UserInput;                                                // Stores user menu selection

    while (true) {                                                // Main loop for program execution
        cout << "Please select from the following options: " << endl;
        cout << "1. Student 2.Admin 3. Exit" << endl;
        while (!(cin >> UserInput)) {                             // Validate numeric input
            cout << "Invalid input. Please enter a number: ";
            cin.clear();                                          // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Remove invalid input
        }
        if (UserInput == 1) {                                     // Student interface selected
            ui = new StudentInterface();                          // Create StudentInterface object
            ui->Menu();                                           // Call menu using polymorphism
            delete ui;                                            // Free memory
            ui = nullptr;                                         // Free memory
        }
        else if (UserInput == 2) {                                // Admin interface selected
            ui = new AdminInterface();                            // Create AdminInterface object
            ui->Menu();                                           // Call menu using polymorphism
            delete ui;                                            // Free memory
            ui = nullptr;                                         // Reset pointer
        }
        else if (UserInput == 3) {                                // Exit option selected
            break;                                                // Exit program loop
        }
        else {                                                    // Invalid input case
            cout << "Invalid input. Please try again." << endl;
        }
    }
    delete[] Departments;                                         // Free dynamically allocated departments array
    Departments = nullptr;                                        // Prevent dangling pointer

    return 0;                                                     // End program
}