#include "StudentInterface.h"
#include "Department.h"
#include "Course.h"
#include "Cart.h"
#include <iostream>
#include <limits>

extern Department* Departments;
extern int DeptCount;

using namespace std;

StudentInterface::StudentInterface() {}

StudentInterface::~StudentInterface() {}

void StudentInterface::Menu() {
    int UserInput;
    cout << "Welcome Student!" << endl;

    while (true) {
        cout << "Main menu." << endl;
        cout << "Please select from the following options: " << endl;
        cout << "1.Show Cart 2. Browse Departments 3. Exit." << endl;
        while (!(cin >> UserInput)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ValidateRange(UserInput, 1, 3)) {
            if (UserInput == 1) {
                ShowCartMenu();
            }
            else if (UserInput == 2) {
                BrowseDepts();
            }
            else if (UserInput == 3) {
                break;
            }
        }
        else {
            Errors(1);
        }
    }
}

void StudentInterface::ShowCartMenu() {
    int UserInput;

    while(true) {
        cout << "Cart menu." << endl;
        cout << "Please select from the following options: " << endl;
        cout << "1.List Courses 2. Checkout 3. Return to Main Menu." << endl;
        while (!(cin >> UserInput)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ValidateRange(UserInput, 1, 3)) {
            if (UserInput == 1) {
                StudentCart.PrintCart();
            }
            else if (UserInput == 2) {
                if (StudentCart.IsEmpty()) {
                    cout << "No items in the cart." << endl;
                }
                else {
                    cout << "Thank you for your purchase." << endl;
                    StudentCart.EmptyCart();
                    break;
                }
            }
            else if (UserInput == 3) {
                break;
            }
        }
        else {
            Errors(1);
        }
    }   
}

void StudentInterface::BrowseDepts() {
    int UserInput;

    while (true) {
        if (Departments == nullptr or DeptCount == 0) {
            cout << "No departments available." << endl;
            return;
        }
        cout << "Departments: " << endl;
        for (int i = 0; i < DeptCount; i++) {
            cout << (i + 1) << ". ";
            Departments[i].DisplayName();
            cout << endl;
        }
        cout << "Please select from the following options: " << endl;
        cout << "1. List Courses of a department 2. Go back to Main Menu" << endl;
        while (!(cin >> UserInput)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ValidateRange(UserInput, 1, 2)) {
            if (UserInput == 1) {
                int DeptNum;
                while (true) {
                    cout << "Enter department number [0 to go back]: ";
                    while (!(cin >> DeptNum)) {
                        cout << "Invalid input. Please enter a number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (ValidateRange(DeptNum, 0, DeptCount)) {
                        if (DeptNum == 0) {
                            break;
                        }
                        else {
                            DeptCourseMenu(DeptNum - 1);
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

void StudentInterface::DeptCourseMenu(int deptIndex) {
    int UserInput;

    while (true) {
        cout << "Department: ";
        Departments[deptIndex].DisplayName();
        cout << endl;
        cout << "Courses: " << endl;

        if(Departments[deptIndex].GetCourseCount() == 0) {
            cout << "No courses in ";
            Departments[deptIndex].DisplayName();
            cout << endl;
        }
        else {
            for (int i = 0; i < Departments[deptIndex].GetCourseCount(); i++) {
                cout << (i + 1) << ". ";
                Departments[deptIndex].GetCourse(i).Show();
            }
        }
        cout << "Please select from the following options: " << endl;
        cout << "1. Add to Cart a Course 2. Go back to Browse Departments Menu" << endl;
        while (!(cin >> UserInput)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (ValidateRange(UserInput, 1, 2)) {
            if (UserInput == 1) {
                int CourseNum;

                while (true) {
                    cout << "Enter Course by number to add to cart (0 to go back): ";
                    while (!(cin >> CourseNum)) {
                        cout << "Invalid input. Please enter a number: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    if (ValidateRange(CourseNum, 0, Departments[deptIndex].GetCourseCount())) {
                        if (CourseNum == 0) {
                            break;
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