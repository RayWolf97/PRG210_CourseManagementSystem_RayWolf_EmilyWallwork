#include "StudentInterface.h"
#include "Department.h"
#include "Course.h"
#include "Cart.h"
#include <iostream>
#include <limits>

extern Department* Departments;
extern int DeptCount;

using namespace std;

StudentInterface::StudentInterface() {}                                                             // Student Interface constructor 

StudentInterface::~StudentInterface() {}                                                            // Student Interface destructor

void StudentInterface::Menu() {                                                                     // Student Interface main menu
    int UserInput;                                                                                  // Integer variable to hold user input
    cout << "Welcome Student!" << endl;

    while (true) {                                                                                  // Loop to keep menu running
        cout << "Main menu." << endl;
        cout << "Please select from the following options: " << endl;
        cout << "1.Show Cart 2. Browse Departments 3. Exit." << endl;
        while (!(cin >> UserInput)) {                                                               // Validates numeric input
            cout << "Invalid input. Please enter a number: ";
            cin.clear();                                                                            // Clears error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                    // Removes invalid input from buffer
        }                                                                                           // Reads user input
        if (ValidateRange(UserInput, 1, 3)) {                                                       // Validates input is within allowed range
            if (UserInput == 1) {                                                                   
                ShowCartMenu();                                                                     // Option 1: Go to cart menu
            }
            else if (UserInput == 2) {
                BrowseDepts();                                                                      // Option 2: Browse departments
            }
            else if (UserInput == 3) {
                break;                                                                              // Option 3: Exit Student menu
            }
        }
        else {
            Errors(1);                                                                              // Displays invalid input error
        }
    }
}

void StudentInterface::ShowCartMenu() {
    int UserInput;                                                                                  // Integer variable to hold user input 

    while(true) {                                                                                   // Loop to keep menu running
        cout << "Cart menu." << endl;
        cout << "Please select from the following options: " << endl;
        cout << "1.List Courses 2. Checkout 3. Return to Main Menu." << endl;
        while (!(cin >> UserInput)) {                                                               // Validates numeric input
            cout << "Invalid input. Please enter a number: ";
            cin.clear();                                                                            // Clears error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');                                    // Removes invalid input from buffer    
        }                                                                                           // Reads user input
        if (ValidateRange(UserInput, 1, 3)) {                                                       // Validates input is within allowed range
            if (UserInput == 1) {
                StudentCart.PrintCart();                                                            // Option 1: Shows all courses in cart
            }
            else if (UserInput == 2) {
                if (StudentCart.IsEmpty()) {                                                        // Option 2: Checks if cart is empty
                    cout << "No items in the cart." << endl;
                }
                else {
                    cout << "Thank you for your purchase." << endl;
                    StudentCart.EmptyCart();                                                        // Option 3: Empties cart
                    break;                                                                          // Returns to previous menu
                }
            }
            else if (UserInput == 3) {
                break;                                                                              // Returns to previous menu
            }
        }
        else {
            Errors(1);                                                                              // Displays invalid input error
        }
    }   
}

void StudentInterface::BrowseDepts() {
    int UserInput;                                                                                  // Integer variable to hold user input

    while (true) {                                                                                  // Loop to keep menu running
        if (Departments == nullptr or DeptCount == 0) {                                             // Checks if no departments exist
            cout << "No departments available." << endl;
            return;                                                                                 // Exits function if empty
        }
        cout << "Departments: " << endl;
        for (int i = 0; i < DeptCount; i++) {                                                       // Iterates through departments
            cout << (i + 1) << ". ";                                                                // Prints department number
            Departments[i].DisplayName();                                                           // Prints department name
            cout << endl;
        }
        cout << "Please select from the following options: " << endl;
        cout << "1. List Courses of a department 2. Go back to Main Menu" << endl;
        while (!(cin >> UserInput)) {                                                               // Validates numeric input
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ValidateRange(UserInput, 1, 2)) {                                                       // Validates input is within allowed range
            if (UserInput == 1) {                                                                   // Option 1: List Courses of a department
                int DeptNum;                                                                        // Stores user selected department number 
                while (true) {
                    cout << "Enter department number [0 to go back]: ";
                    while (!(cin >> DeptNum)) {
                        cout << "Invalid input. Please enter a number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (ValidateRange(DeptNum, 0, DeptCount)) {
                        if (DeptNum == 0) {
                            break;                                                                  // Return to previous menu
                        }
                        else {
                            DeptCourseMenu(DeptNum - 1);                                            // Calls course menu for selected department
                            break;
                        }
                    }
                    else {
                        Errors(1);
                    }
                }
            }
            else if (UserInput == 2) {
                break;                                                                              // Return to previous menu
            }
        }
        else {
            Errors(1);
        }
    }
}

void StudentInterface::DeptCourseMenu(int deptIndex) {
    int UserInput;

    while (true) {
        cout << "Department: ";
        Departments[deptIndex].DisplayName();                                                       // Prints department name
        cout << endl;
        cout << "Courses: " << endl;

        if(Departments[deptIndex].GetCourseCount() == 0) {                                          // Checks if no courses exist
            cout << "No courses in ";
            Departments[deptIndex].DisplayName(); 
            cout << endl;
        }
        else {
            for (int i = 0; i < Departments[deptIndex].GetCourseCount(); i++) {                     // Loop through all courses in the selected department
                cout << (i + 1) << ". ";                                                            // Prints course number
                Departments[deptIndex].GetCourse(i).Show();                                         // Prints course details
            }
        }
        cout << "Please select from the following options: " << endl;
        cout << "1. Add to Cart a Course 2. Go back to Browse Departments Menu" << endl;
        while (!(cin >> UserInput)) {                                                               // Validates numeric input
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ValidateRange(UserInput, 1, 2)) {
            if (UserInput == 1) {
                int CourseNum;                                                                      // Stores user input Course number

                while (true) {
                    cout << "Enter Course by number to add to cart (0 to go back): ";
                    while (!(cin >> CourseNum)) {                                                   // Validates numeric input
                        cout << "Invalid input. Please enter a number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (ValidateRange(CourseNum, 0, Departments[deptIndex].GetCourseCount())) {
                        if (CourseNum == 0) {
                            break;                                                                  // Return to previous menu
                        }
                        else {
                            StudentCart.AddCourse(Departments[deptIndex].GetCourse(CourseNum - 1));
                            cout << "Course added to your cart." << endl;
                            break;
                        }
                    }
                    else {
                        Errors(1);
                    }
                }
            }
            else if (UserInput == 2) {
                break;
            }
        }
        else {
            Errors(1);
        }
    }
}