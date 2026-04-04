#include <iostream>
#include "Course.h"
#include "Department.h"
using namespace std;

int main() {
    Department test1;
    Department test2("Test2");
    Course math("Math", 123);
    Course gym("Gym", 456, "M/W", 20);
    Course art;
    test2.AddCourse(math);
    test2.AddCourse(gym);
    test1.AddCourse(art);
    test1.Show();
    test2.Show();
    cout << "Hello Emily. <3 Happy birthday!" << endl;
    return 0;
}