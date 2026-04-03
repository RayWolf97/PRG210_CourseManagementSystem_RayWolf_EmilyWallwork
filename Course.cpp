#include "Course.h"
#include <iostream>
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

Course::Course(const char* Name, int Code, char* Schedule, int Price) {
    strcpy(CourseName, Name);   
    CourseCode = Code;
    strcpy(CourseSchedule, Schedule);   
    CoursePrice = Price;
}

void Course::Show() const{
    cout<< "Course Name: " << CourseName << ", Course Code: " << CourseCode << ", Course Schedule: " << CourseSchedule << ", Course Price" << CoursePrice << endl;
}

Course courses[100];   // creating an array of size 100 to store course objects in 
int count = 0;         // counting how many course objects there are, starting at 0

void Course::AddCourse(const char* Name, int Code, char* Schedule, int Price){
    if (count<100){                             //make sure there is room in the array for the new course
        Course(Name, Code, Schedule, Price);    //create a new course object using the provided parameters
        count++;                                //increase the course count by 1
    }
}

void Course::CourseList(){
    for (int i = 0; i < count; i++) {        //iterating a for loop over the amount of course objects in the array, courses
        cout<< i+1 << endl;                  //displaying the item number
    };
} //change