#include <iostream>
#include <cstring>
#include "Department.h"
#include "Course.h"

extern Department* Departments;
extern int DeptCount;

using namespace std;

Department::Department()                                          // Default constructor
{
    strcpy(DepName, "No name");                                   // Sets department name as 'No name' using strcpy to copy the character arrays
    Courses = nullptr;                                            // no courses initially
    TotalCourses = 0;                                             // Sets total courses to 0
}

Department::Department(const char* dn)                            // Constructor with department name perameter
{
    strcpy(DepName, dn);                                          // copies department name
    Courses = nullptr;                                            // No courses initially 
    TotalCourses = 0;                                             //Sets total courses to 0
}

Department::Department(const Department& other) {                 // Copy constructor performs deep copy
    strcpy(DepName, other.DepName);                               // Copy department name
    TotalCourses = other.TotalCourses;                            // Copy course count
    if (other.TotalCourses > 0) {                                 // If there are courses to copy
        Courses = new Course[TotalCourses];                       // Allocate new course array
        for (int i = 0; i < TotalCourses; i++) {                  // Copy each course
            Courses[i] = other.Courses[i]; 
        }
    }
    else {
        Courses = nullptr;                                        // Set to nullptr if no courses
    }
}

Department::~Department() {                                       // Destructor frees dynamically allocated memory
    delete[] Courses;                                             // Delete course array
    Courses = nullptr;                                            // Prevent dangling pointer
}

Department& Department::operator=(const Department& other) {      // Assignment operator for deep copy
    if (this != &other) {                                         // Prevent self-assignment
        delete[] Courses;                                         // Free existing memory
        strcpy(DepName, other.DepName);                           // Copy department name
        TotalCourses = other.TotalCourses;                        // Copy course count
        if (TotalCourses > 0) {                                   // If there are courses to copy
            Courses = new Course[TotalCourses];                   // Allocate new array
            for (int i = 0; i < TotalCourses; i++) {              // Copy each course
                Courses[i] = other.Courses[i]; 
            }
        }
        else {
            Courses = nullptr;                                    // Set to nullptr if no courses
        }
    }
    return *this;                                                 // Return current object
}

void Department::AddCourse(const Course c)                        // Adds a new course to the department
{
    Course* TempCourses = new Course[TotalCourses + 1];           // Allocate new array with extra space

    for (int i = 0; i < TotalCourses; i++) {                      // Copy existing courses
        TempCourses[i] = Courses[i];     
    }
    TempCourses[TotalCourses] = c;                                // Add new course at end
    delete[] Courses;                                             // Delete old course array
    Courses = TempCourses;                                        // Update pointer to new array
    TotalCourses++;                                               // Increment course count
}

void Department::Show() {                                         // Displays department details and all courses
    cout << "Department name: " << DepName << endl; 
    cout << "Courses: " << endl;
    for (int i = 0; i < TotalCourses; i++) {                      // Loop through all courses
        cout << (i + 1) << ". ";                                  // Print course number
        Courses[i].Show();                                        // Display course details
    }
    cout << endl;                                                 // Print spacing line
}

void Department::DisplayName() {                                  // Displays only department name
    cout << DepName << endl;                                      // Print department name
}

const char* Department::GetDepName() const{                       // Returns department name
    return DepName;
}

int Department::GetCourseCount() const{                           // Returns total number of courses
    return TotalCourses;
}

const Course& Department::GetCourse(int index) const{             // Returns reference to a specific course
    return Courses[index];
}