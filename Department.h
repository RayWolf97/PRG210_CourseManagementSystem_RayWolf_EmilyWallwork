#pragma once
#include "Course.h"
#include <iostream>
using namespace std;

class Department
{
    private:
    char DepName[30];    // Character array to hold the department name, max 30 characters
    Course* Courses;     // Course object pointer to hold the array of courses through dynamically alocated memory
    int TotalCourses;    // Integer value of the total number of courses in department

    public:
    Department();                           // Default constructor
    Department(const char* dn);             // Constructor with department name
    Department(const Department& other);    // Copy constructor: creates a deep copy of another Department object (including its courses)
    ~Department();                          // Destructor: releases dynamically allocated memory for the courses array
    
    Department& operator=(const Department& other); // Assignment operator: performs deep copy to safely assign one Department to another

    void AddCourse(const Course c);                 // Adds a new course to the department, resizing the internal array if needed
    void Show();                                    // Displays all details of the department including its courses
    void DisplayName();                             // Displays only the department name
    const char* GetDepName() const;                 // Returns the name of the department (read-only)
    int GetCourseCount() const;                     // Returns the total number of courses in the department
    const Course& GetCourse(int index) const;       // Returns a reference to a specific course by index (read-only)
};