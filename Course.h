#pragma once
#include <iostream>
#include <cstring>

#pragma once

class Course {
private:
    char CourseName[30];             // stores the course name as a character array
    int CourseCode;                  // stores the unique course code (integer)
    char CourseSchedule[4];          // stores the course schedule as a character array
    double CoursePrice;                 // stores the cost of the course

public:
    Course();
    Course(const char* Name, int Code);
    Course(const char* Name, int Code, char* Schedule, double Price);

    double GetCoursePrice() const;
    void Show() const;
    void AddCourse(const char* Name, int Code, char* Schedule, double Price);
    void CourseList();
    const char* GetCourseName() const;
    const char* GetCourseSchedule() const;
}; 