#include "Interface.h"
#include "Department.h"
#include "Course.h"
#include "AdminInterface.h"
#include <fstream>
#include <limits>
#include <iostream>

extern Department* Departments;
extern int DeptCount;

using namespace std;

AdminInterface::AdminInterface() {}                      // Default constructor: initializes the AdminInterface object

AdminInterface::~AdminInterface() {}                       // Destructor

void AdminInterface::Menu() {                             // Displays admin menu and handles user interaction
    cout << "Welcome Admin!" << endl;                     // Prints welcome message
    int UserInput;                                        // Stores user menu selection

    while (true) {                                        // Infinite loop to keep menu running
        cout << "Main menu." << endl;                     // Displays menu header
        cout << "Please select from the following options: " << endl; // Prompts user for input
        cout << "1.List Departments 2. Add Department 3.Add Course to Department 4.Save changes to CSV 5.Exit" << endl; // Displays menu options

        while (!(cin >> UserInput)) {                           // Validates numeric input
            cout << "Invalid input. Please enter a number: ";
            cin.clear();                                        // Clears error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Removes invalid input from buffer
            }                                                   // Reads user input

        if (ValidateRange(UserInput, 1, 5)) {                   // Validates input is within allowed range
            if (UserInput == 1) {                               // Option 1: List departments
                DisplayDepts();                                 // Calls function to display departments
            }
            else if (UserInput == 2) {                          // Option 2: Add department
                AddDepartment();
            }
            else if (UserInput == 3) {                          // Option 3: Add course to department
               AddCourse();                                     // Calls function to add a course
            }
            else if (UserInput == 4) {                          // Option 4: Save changes to CSV
                SaveToCSV();                                    // Calls function to save data to file
            }
            else if (UserInput == 5) {                          // Option 5: Exit program
                break;                                          // Exits the menu loop
            }
        }
        else {                                              // Invalid input case
            Errors(1);                                          // Displays error message for invalid input
        }
    }
}

void AdminInterface::DisplayDepts() {                  // Displays all departments with numbering
    if (Departments == nullptr || DeptCount == 0) {    // Checks if there are no departments to display
        cout << "No departments to list." << endl;     // Informs user that no departments exist
        return;                                        // Exits function early
    }

    cout << "Departments:" << endl;                    // Prints header
    for (int i = 0; i < DeptCount; i++) {              // Loops through all departments
        cout << (i + 1) << ". ";                       // Prints department number
        Departments[i].DisplayName();                  // Displays department name
    }
}

void AdminInterface::AddDepartment() {                   // Handles adding a new department
    cout << "Please enter new department name." << endl; // Prompts user for department name

    char UserDeptName[30];                               // Stores user input for department name
    cin.ignore(1000, '\n');                              // Clears input buffer before getline
    cin.getline(UserDeptName, 30);                       // Reads full department name input

    Department NewDept(UserDeptName);                                        // Creates new Department object

    Department* TempDepartments = new Department[DeptCount + 1];             // Allocates new array with increased size

    for (int i = 0; i < DeptCount; i++) {                                    // Copies existing departments into new array
        TempDepartments[i] = Departments[i];                                 // Assigns each department to temp array
    }
    TempDepartments[DeptCount] = NewDept;                                    // Adds new department to end of array
    delete[] Departments;                                                    // Deletes old departments array from memory
    Departments = TempDepartments;                                           // Updates pointer to new resized array
    DeptCount++;                                                             // Increments total department count
}

void AdminInterface::AddCourse() {                                           // Handles adding a course to a selected department
    int UserInput;                                                           // Stores user-selected department number
    while (true) {                                                           // Loop until valid input or exit
        DisplayDepts();                                                      // Displays list of departments
        cout << "Please enter the number of the Department you wish to add a course to. (0 to go back)" << endl;
        while (!(cin >> UserInput)) {                                        // Validates numeric input
        cout << "Invalid input. Please enter a number: ";
        cin.clear();                                                         // Clears error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n');                 // Removes invalid input from buffer
        }
        if (ValidateRange(UserInput, 0, DeptCount)){                         // Checks if input is within valid department range
            if (UserInput == 0) {                                            // Option to go back
                break;                                                       // Exits AddCourse function
            }
            else {                                                           // Valid department selected
                Departments[UserInput - 1].Show();                           // Displays selected department details
            }
                char UserCourseName[30];                                     // Stores course name input
                int UserCode;                                                // Stores course code input
                char UserSchedule[4];                                        // Stores course schedule input
                double UserPrice;                                            // Stores course price input
                cin.ignore(1000, '\n');                                      // Clears input buffer before getline
                while (true) {                                               // Loop until valid course name is entered
                    cout << "Please enter the new course name: ";            // Prompts user for course name
                    cin.getline(UserCourseName, 30);                         // Reads full course name
                    if (ValidateNotEmpty(UserCourseName)) {                  // Validates non-empty input
                        break;                                               // Exit loop if valid
                    }
                    else {                                                   // Invalid input case
                        Errors(1);                                           // Displays error message
                    }
                }
                while (true) {                                               // Loop until valid course code is entered
                    cout << "Please enter the new course code: ";
                    while (!(cin >> UserCode)) {                             // Validate numeric input
                        cout << "Invalid input. Please enter a number: ";
                        cin.clear();                                         // Clear error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove bad input
                    }
                    if (ValidatePositive(UserCode)) {                        // Check if code is valid (positive)
                        break;                                               // Exit loop if valid
                    }
                    else { 
                        Errors(3);                                  // Show error for invalid numeric value
                    }
                }
                cin.ignore(1000, '\n');                             // Clear buffer before using getline
                while (true) {                                      // Loop until valid schedule is entered
                    cout << "Please enter the new course schedule (M/W, T/R, W/F): ";
                    cin.getline(UserSchedule, 4);                   // Read schedule input
                    if (ValidateSchedule(UserSchedule)) {           // Validate schedule format
                        break;                                      // Exit loop if valid
                    }
                    else {
                        Errors(2);                                  // Show error for invalid schedule
                    }
                }
                

                while (true) {                                               // Loop until valid course price is entered
                    cout << "Please enter the new course price: ";
                    while (!(cin >> UserPrice)) {                            // Validate numeric input
                        cout << "Invalid input. Please enter a number: ";
                        cin.clear();                                         // Clear error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Remove bad input
                    }
                    if (ValidatePositive(UserPrice)) { // Check if price is valid (positive)
                        break;                         // Exit loop if valid
                    }
                    else {
                        Errors(3);                     // Show error for invalid price
                    }
                }
                Course NewCourse(UserCourseName, UserCode, UserSchedule, UserPrice); // Create new course object
                Departments[UserInput - 1].AddCourse(NewCourse);                     // Add course to selected department
                break;                                                               // Exit outer loop after adding course
        }
        else {             // Invalid department selection
            Errors(1);     // Show error message
        }
    }
}


void AdminInterface::SaveToCSV () {
    ofstream file("Courses.csv");                                     //opening a csv file to write to 
    file << "Total Departments: " << DeptCount <<endl;                //Writing the total number of depts to the file
    for (int i=0; i<DeptCount; i++) {                                 //interating over all the departments
        file << "Department " << i+1 << ": " 
        << Departments[i].GetDepName() << ", "                        //Writing the name of the dept to the file
        << "Number of courses: " 
        << Departments[i].GetCourseCount() << endl << 
        "Courses:" << endl;                                           //Writing the number of courses to the file
        for (int j=0; j<Departments[i].GetCourseCount(); j++) {       //Iterating over the courses in the dept
            const Course& c = Departments[i].GetCourse(j);            //Getting the course at index j
            file << c.GetCourseName()                                 //Writing the name to the file
            << ", " << c.GetCourseSchedule()                          //Writing the schedule to the file
            << ", " << c.GetCoursePrice() << endl;                    //Writing the Price to the file
        }
    }
    file.close();
}