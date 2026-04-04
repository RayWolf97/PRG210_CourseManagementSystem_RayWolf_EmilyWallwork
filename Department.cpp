#include <iostream>
#include <cstring>
#include "Department.h"
#include "Course.h"
using namespace std;

Department::Department() // Default constructor
{
    strcpy(DepName, "No name"); // Sets department name as 'No name' using strcpy to copy the character arrays
    Courses = nullptr;
    TotalCourses = 0; // Sets total courses to 0
}

Department::Department(const char* dn) // Constructor with department name perameter
{
    strcpy(DepName, dn);
    Courses = nullptr;
    TotalCourses = 0; //Sets total courses to 0
}

void Department::AddCourse(const Course c)
{
    if (TotalCourses != 0){
        Course* TempCourses = new Course[TotalCourses];
        for (int i = 0; i < TotalCourses; i++){
            TempCourses[i] = Courses[i];
        } 
        delete[] Courses;
        Courses = new Course[TotalCourses + 1];
        for (int i = 0; i < TotalCourses; i++){
            Courses[i] = TempCourses[i];
        }
        delete[] TempCourses;
        TempCourses = nullptr;
        Courses[TotalCourses] = c;
        TotalCourses++;
    }
    else {
        Courses = new Course[1];
        Courses[0] = c;
        TotalCourses = 1;
    }
}

void Department::Show() {
    cout << "Department name: " << DepName << endl;
    cout << "Courses: " << endl;
    for (int i = 0; i < TotalCourses; i++) {
        Courses[i].Show();
        cout << endl;
    }
}

Department::~Department() {
    delete[] Courses;
    Courses = nullptr;
    cout << "Deconstuctor successful" << endl;
}