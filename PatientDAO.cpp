#pragma once
#include <iostream>
#include "Patient.cpp"
using namespace std;

class PatientDAO // abstract class for PatientCollector
{
public:
    virtual void addPatient(Patient *patient) = 0;
    virtual void viewPatient() = 0;
    virtual void updatePatient(Patient *patient) = 0;
    virtual void deletePatient(Patient *patient) = 0;
    virtual void sortPatient() = 0;
    virtual void searchPatient(Patient *patient) = 0;
    virtual void savePatient() = 0;
    virtual void loadPatient() = 0;
};
