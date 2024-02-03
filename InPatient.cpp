#pragma once
#include <iostream>
#include <iomanip>
#include "Patient.cpp"
#include "DataInputValidation.cpp"

using namespace std;

class InPatient : public Patient // inheritance
{
private:
    string condition;

public:
    // constructor
    InPatient() : Patient()
    {
        this->condition = "Unknown";
    }

    InPatient(int id, const string name, const string sex, const string condition) : Patient(id, name, sex)
    {
        setCondition(condition);
    }
    // setter & getter
    void setCondition(const string &condition)
    {
        if (!condition.empty())
        {
            this->condition = condition;
        }
        else
        {
            throw BadInputException();
        }
    }

    string getCondition() const
    {
        return condition;
    }
    // polymorph fuction
        void display() override
    {
        cout << "In Patient: " << endl;
        cout << "-------------------------------------------------------------------\n";
        cout << "ID      Name        Sex           Condition \n";
        cout << "-------------------------------------------------------------------\n";
        // Implement the display logic for OutPatient
        Patient::display(); // Optionally call the base class Display function
        cout << setw(20) << getCondition() << endl;
    }

    void input() override
    {
        Patient::input();
        string condition;
        cout << "Please enter the condition: ";
        cin >> condition;
        setCondition(condition);
    }
};
