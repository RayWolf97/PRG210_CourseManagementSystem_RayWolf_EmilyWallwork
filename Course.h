#pragma once
#include <iostream>
#include <cstring>

class Course {
private:
    char CourseName[30];                                                      // stores the course name as a character array
    int CourseCode;                                                           // stores the unique course code (integer)
    char CourseSchedule[4];                                                   // stores the course schedule as a character array
    double CoursePrice;                                                       // stores the cost of the course

public:
    Course();                                                                 // Default constructor initializes empty course
    Course(const char* Name, int Code);                                       // Constructor initializes name and code   
    Course(const char* Name, int Code, char* Schedule, double Price);         // Constructor initializes all course details

    double GetCoursePrice() const;                                            // Returns the price of the course
    void Show() const;                                                        // Displays all course details
    void AddCourse(const char* Name, int Code, char* Schedule, double Price); // Adds a course to global array (not ideal for this project)
    void CourseList();                                                        // Displays list of all stored courses
    const char* GetCourseName() const;                                        // Returns the course name
    const char* GetCourseSchedule() const;                                    // Returns the course schedule
}; 