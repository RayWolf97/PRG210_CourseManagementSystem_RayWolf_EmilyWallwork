#include <iostream>
#include <cstring>
#include "Department.h"
#include "Course.h"

extern Department* Departments;
extern int DeptCount;

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

Department::Department(const Department& other) {
    strcpy(DepName, other.DepName);
    TotalCourses = other.TotalCourses;
    if (other.TotalCourses > 0) {
        Courses = new Course[TotalCourses];
        for (int i = 0; i < TotalCourses; i++) {
            Courses[i] = other.Courses[i];
        }
    }
    else {
        Courses = nullptr;
    }
}

Department::~Department() {
    delete[] Courses;
    Courses = nullptr;
}

Department& Department::operator=(const Department& other) {
    if (this != &other) {
        delete[] Courses;
        strcpy(DepName, other.DepName);
        TotalCourses = other.TotalCourses;
        if (TotalCourses > 0) {
            Courses = new Course[TotalCourses];
            for (int i = 0; i < TotalCourses; i++) {
                Courses[i] = other.Courses[i];
            }
        }
        else {
            Courses = nullptr;
        }
    }
    return *this;
}

void Department::AddCourse(const Course c)
{
    Course* TempCourses = new Course[TotalCourses + 1];

    for (int i = 0; i < TotalCourses; i++) {
        TempCourses[i] = Courses[i];
    }
    TempCourses[TotalCourses] = c;
    delete[] Courses;
    Courses = TempCourses;
    TotalCourses++;
}

void Department::Show() {
    cout << "Department name: " << DepName << endl;
    cout << "Courses: " << endl;
    for (int i = 0; i < TotalCourses; i++) {
        cout << (i + 1) << ". ";
        Courses[i].Show();
    }
    cout << endl;
}

void Department::DisplayName() {
    cout << DepName << endl;
}

const char* Department::GetDepName() const{
    return DepName;
}

int Department::GetCourseCount() const{
    return TotalCourses;
}

const Course& Department::GetCourse(int index) const{
    return Courses[index];
}