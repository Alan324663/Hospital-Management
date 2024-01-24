#pragma once
#include <iostream>
#include <iomanip>
#include "Patient.cpp"

#include "DataInputValidation.cpp"

using namespace std;

class OutPatient : public Patient
{
private:
    string reason;

public:
    OutPatient() : Patient()
    {
        this->reason = "Unknown";
    }

    OutPatient(int id, const string &name, const string sex, const string reason) : Patient(id, name, sex)
    {
        setReason(this->reason);
    }

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

    void Display() override
    {
        cout << "In Patient: " << endl;
        cout << "-------------------------------------------------------------------\n";
        cout << "ID      Name        Sex           Reason \n";
        cout << "-------------------------------------------------------------------\n";
        // Implement the display logic for OutPatient
        Patient::Display(); // Optionally call the base class Display function
        cout << setw(20) << getReason() << endl;
    }

    void Input() override
    {
        Patient::Input();

        string reason;
        cout << "Please enter the reason: ";
        cin >> reason;

        setReason(reason);
    }
};
