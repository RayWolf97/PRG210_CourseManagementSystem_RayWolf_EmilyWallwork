#pragma once
#include "Interface.h"
#include "Department.h"
#include "Cart.h"
#include <iostream>
using namespace std;

class StudentInterface : public Interface {
    private:
    Cart StudentCart;                           // Cart object to store users cart

    public:
    StudentInterface();                         // Student Interface constructor 
    ~StudentInterface();                        // Student Interface destructor
    
    void Menu() override;                       // Student Interface main menu
    void ShowCartMenu();                        // Displays Cart Menu options (list, checkout, return)
    void BrowseDepts();                         // Displays departments and provides options to view courses
    void DeptCourseMenu(int deptIndex);         // Displays courses for a user selected department and allows user to add it to their cart
};