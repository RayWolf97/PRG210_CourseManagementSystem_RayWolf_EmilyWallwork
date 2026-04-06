#pragma once
#include <iostream>
using namespace std;

class Interface {
    public:
    virtual void Menu() = 0;
    virtual ~Interface();
    bool ValidateRange(const int userInput, const int min, const int max);
    bool ValidateSchedule(const char* Schedule);
    bool ValidatePositive(const double price);
    bool ValidateNotEmpty(const char* input);
    void Errors(const int num);
};