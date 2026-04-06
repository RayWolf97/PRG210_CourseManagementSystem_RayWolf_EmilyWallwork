#pragma once
#include <iostream>
#include <cstring>
#include "Course.h"

class Cart {
private:
    Course* Courses;              // dynamically allocated array of Course objects
    char** Schedules;              // dynamically allocated array of C-style strings
    int CartCount;                // number of courses in the cart
    double CartTotalCost;         // total cost 

public:
    Cart();                   // default constructor initializes empty cart 
    ~Cart();                  // destructor frees all dynamically allocated memory

    void AddCourse(const Course& c) ;
    void PrintCart() const;
    void EmptyCart();
    bool IsEmpty() const;
};