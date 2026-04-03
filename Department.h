#pragma once
#include <iostream>
using namespace std;

class Department
{
    private:
    char DepName[30]; // Character array to hold the department name, max 30 characters
    Course* Courses; // Course object pointer to hold the array of courses through dynamically alocated memory
    int TotalCourses; // Integer value of the total number of courses in department

    public:
    Department(); // Default constructor
    Department(char* dn); // Constructor with department name
    void AddCourse(const Course c);
    ~Department();
};