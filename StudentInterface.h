#pragma once
#include "Interface.h"
#include "Department.h"
#include "Cart.h"
#include <iostream>
using namespace std;

class StudentInterface : public Interface {
    private:
    Cart StudentCart;

    public:
    StudentInterface();
    ~StudentInterface();
    
    void Menu() override;
    void ShowCartMenu();
    void BrowseDepts();
    void DeptCourseMenu(int deptIndex);
};