#include "Course.h"
#include "Department.h"
#include <iostream>

extern Department* Departments;
extern int DeptCount;

using namespace std;

Course::Course() {                                                         // Default constructor initializes empty course
    strcpy(CourseName, "");                                                // Set course name to empty string
    CourseCode = 0;                                                        // Initialize course code to 0
    strcpy(CourseSchedule, "");                                            // Set schedule to empty string
    CoursePrice = 0;                                                       // Initialize price to 0

}

Course::Course(const char* Name, int Code) {                               // Constructor initializes name and code
    strcpy(CourseName, Name);                                              // Copy provided name
    CourseCode = Code;                                                     // Set course code
    strcpy(CourseSchedule, "");                                            // Initialize schedule as empty
    CoursePrice = 0;                                                       // Initialize price to 0
}

Course::Course(const char* Name, int Code, char* Schedule, double Price) { // Full constructor initializes all fields
    strcpy(CourseName, Name);                                              // Copy course name
    CourseCode = Code;                                                     // Set course code
    strcpy(CourseSchedule, Schedule);                                      // Copy schedule
    CoursePrice = Price;                                                   // Set course price
}

void Course::Show() const{                                                 // Displays all course details
    cout<< "Course Name: " << CourseName << ", Course Code: " << CourseCode << ", Course Schedule: " << CourseSchedule << ", Course Price: " << CoursePrice << endl;
}                                                                          //Displaying all the information sotred about the course 

Course courses[100];                                                       // Global array storing up to 100 courses 
int count = 0;                                                             // counting how many course objects there are, starting at 0

void Course::AddCourse(const char* Name, int Code, char* Schedule, double Price){
    if (count<100){                                                                     //make sure there is room in the array for the new course
        courses[count] = Course(Name, Code, Schedule, Price);                           //create a new course object using the provided parameters to store at the index count
        count++;                                                                        //increase the course count by 1
    }
}

double Course::GetCoursePrice() const{
    return CoursePrice;
}

void Course::CourseList(){
    for (int i = 0; i < count; i++) {             //iterating a for loop over the amount of course objects in the array, courses
        cout<< i+1 << ". ";                       //displaying the item number
        courses[i].Show();                        // displaying each iteration of courses after displaying the item number 
    };
} 

const char* Course::GetCourseName() const{        // Returns course name
    return CourseName;
}

const char* Course::GetCourseSchedule() const{    // Returns course schedule
    return CourseSchedule;
}