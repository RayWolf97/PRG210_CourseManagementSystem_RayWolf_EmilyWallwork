#include "Course.h"
#include "Department.h"
#include <iostream>

extern Department* Departments;
extern int DeptCount;

using namespace std;

Course::Course() {
    strcpy(CourseName, "");
    CourseCode = 0;
    strcpy(CourseSchedule, "");
    CoursePrice = 0;

}

Course::Course(const char* Name, int Code) {
    strcpy(CourseName, Name);
    CourseCode = Code;
    strcpy(CourseSchedule, "");
    CoursePrice = 0;
}

Course::Course(const char* Name, int Code, char* Schedule, double Price) {
    strcpy(CourseName, Name);   
    CourseCode = Code;
    strcpy(CourseSchedule, Schedule);   
    CoursePrice = Price;
}

void Course::Show() const{
    cout<< "Course Name: " << CourseName << ", Course Code: " << CourseCode << ", Course Schedule: " << CourseSchedule << ", Course Price: " << CoursePrice << endl;
}  //Displaying all the information sotred about the course 

Course courses[100];   // creating an array of size 100 to store course objects in 
int count = 0;         // counting how many course objects there are, starting at 0

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
    for (int i = 0; i < count; i++) {        //iterating a for loop over the amount of course objects in the array, courses
        cout<< i+1 << ". ";                  //displaying the item number
        courses[i].Show();                   // displaying each iteration of courses after displaying the item number 
    };
} 

const char* Course::GetCourseName() const{
    return CourseName;
}

const char* Course::GetCourseSchedule() const{
    return CourseSchedule;
}