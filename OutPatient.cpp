#pragma once
#include <iostream>
#include <iomanip>
#include "Patient.cpp"

#include "DataInputValidation.cpp"

using namespace std;

class OutPatient : public Patient // inherit from Patient
{
private:
    string reason;

public:
    // constructor
    OutPatient() : Patient()
    {
        this->reason = "Unknown";
    }

    OutPatient(int id, const string &name, const string sex, const string reason) : Patient(id, name, sex)
    {
        setReason(reason);
    }
    // setter & getter
    void setReason(const string &reason)
    {
        if (!reason.empty())
        {
            this->reason = reason;
        }
        else
        {
            throw BadInputException();
        }
    }

    string getReason() const
    {
        return this->reason;
    }
    // polymorph function
     void display() override
    {
        cout << "Out Patient: " << endl;
        cout << "-------------------------------------------------------------------\n";
        cout << "ID      Name        Sex           Reason \n";
        cout << "-------------------------------------------------------------------\n";
        // Implement the display logic for OutPatient
        Patient::display(); // Optionally call the base class Display function
        cout << setw(20) << getReason() << endl;
    }

    void input() override
    {
        Patient::input();

        string reason;
        cout << "Please enter the reason: ";
        cin >> reason;

        setReason(reason);
    }
};
