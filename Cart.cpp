#include "Cart.h"
#include "Course.h"
#include "Department.h"
#include <iostream>
#include <cstring>
using namespace std;

extern Department* Departments;
extern int DeptCount;

using namespace std;

Cart::Cart() {                 // Default constructor: initializes cart with safe default values
    Courses=nullptr;           // No courses initially
    Schedules=nullptr;         // No schedule initially
    CartCount=0;               // No items iin cart initially
    CartTotalCost = 0.0;       // Total cost starts at zero
}

Cart::~Cart(){                                // Destructor: frees dynamically allocated memory
    for (int i =0; i < CartCount; i++) {      //iterating over all the items in the cart
        delete[] Schedules[i];                // Delete each individual schedule string
    }
    delete[] Schedules;                       // Delete array of schedule pointers
    delete[] Courses;                         // Delete array of courses
}

void Cart::AddCourse(const Course& c) {                 // Adds a new course to the cart
    Course* tempCourses = new Course[CartCount + 1];    // Allocate new course array with extra space
    char** tempSchedules = new char*[CartCount + 1];    // Allocate new schedule pointer array

    for (int i = 0; i < CartCount; i++) {            // Copy existing data into new arrays
        tempCourses[i] = Courses[i];                 // Copy course object
        tempSchedules[i] = new char[4];              // Allocate space for schedule string
        strcpy(tempSchedules[i], Schedules[i]);      // Copy existing schedule string into new array
    }
    tempCourses[CartCount] = c;                               // Add new course to end of course array
    tempSchedules[CartCount] = new char[4];                   // Allocate memory for new schedule string
    strcpy(tempSchedules[CartCount], c.GetCourseSchedule());  // Copy schedule from course into array

    for (int i = 0; i < CartCount; i++) {          // Loop through old schedules to free memory
        delete[] Schedules[i];                     // Delete each individual schedule string
    }
    delete[] Schedules;                            // Delete old schedule pointer array
    delete[] Courses;                              // Delete old course array
 
    Courses = tempCourses;                         // Update pointer to new course array
    Schedules = tempSchedules;                     // Update pointer to new schedule array

    CartCount++;                                   // Increment number of courses in cart
    CartTotalCost += c.GetCoursePrice() * 1.13;    // Add course price with 13% tax to total cost
}

void Cart::PrintCart() const {                     // Displays all courses currently in the cart
    if (CartCount == 0) {                          // Check if cart is empty
        cout << "No courses in the cart." << endl; // Inform user cart is empty
        return;                                    // Exit function early
    }
    cout << "Items in cart: " << endl;                              // Display header for cart items
    for (int i = 0; i < CartCount; i++) {                           // Loop through all courses in the cart
        cout << (i + 1) << ". ";                                    // Display item number
        Courses[i].Show();                                          // Display course details
    }
    cout << "Cart total $" << CartTotalCost << endl;                // Display total cost of cart
}

void Cart::EmptyCart() {                                            // Clears all items from the cart and frees memory
    for (int i = 0; i < CartCount; i++) {                           // Loop through schedules to delete each
        delete[] Schedules[i];                                      // Delete individual schedule strings
    }
    delete[] Schedules;                                             // Delete schedule pointer array
    delete[] Courses;                                               // Delete course array

    Schedules = nullptr;                                            // Reset schedules pointer
    Courses = nullptr;                                              // Reset courses pointer

    CartCount = 0;                                                  // Reset course count
    CartTotalCost = 0;                                              // Reset total cost
}

bool Cart::IsEmpty() const {                                        // Checks if the cart has no courses
    if (CartCount == 0) {                                           // If no courses are in the cart
        return true;                                                // Cart is empty
    }
    else {
        return false;                                               // Cart contains items
    }
}