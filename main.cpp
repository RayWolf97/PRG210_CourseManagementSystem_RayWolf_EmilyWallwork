#include <iostream>
#include "Interface.h"
#include "AdminInterface.h"
#include "StudentInterface.h"
#include "Department.h"
#include <iostream>
#include <limits>

using namespace std;

Department* Departments = nullptr;
int DeptCount = 0;
const char* csvFile = "Courses.csv";

int main () {
    Interface* ui = nullptr;
    int UserInput;

    while (true) {
        cout << "Please select from the following options: " << endl;
        cout << "1. Student 2.Admin 3. Exit" << endl;
        while (!(cin >> UserInput)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (UserInput == 1) {
            ui = new StudentInterface();
            ui->Menu();
            delete ui;
            ui = nullptr;
        }
        else if (UserInput == 2) {
            ui = new AdminInterface();
            ui->Menu();
            delete ui;
            ui = nullptr;
        }
        else if (UserInput == 3) {
            break;
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }
    }
    delete[] Departments;
    Departments = nullptr;

    return 0;
}