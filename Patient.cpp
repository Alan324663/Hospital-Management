#pragma once
#include <iostream>
#include <iomanip>
#include "BadInputException.cpp"
#include "DataInputValidation.cpp"

using namespace std;

class Patient
{
private:
    int id;
    string name;
    string sex;
    DataInputValidation dataValidator;

public:
    Patient()
    {
        this->id = 0;
        this->name = "Unknown";
        this->sex = "Not Clarified";
    }

    Patient(int id, const string name, const string sex)
    {
        setId(id);
        setName(name);
        setSex(sex);
    }

    void setId(int id)
    {
        if (id > 0)
        {
            this->id = id;
        }
        else
        {
            throw BadInputException();
        }
    }

    int getId() const
    {
        return id;
    }

    void setName(const string &name)
    {
        if (!name.empty())
        {
            this->name = name;
        }
        else
        {
            throw BadInputException();
        }
    }

    string getName() const
    {
        return name;
    }

    void setSex(const string &sex)
    {
        if (!sex.empty())
        {
            this->sex = sex;
        }
        else
        {
            throw BadInputException();
        }
    }

    string getSex() const
    {
        return sex;
    }

    virtual void Display()
    {
        cout << setw(1) << getId() << setw(11) << getName() << setw(10) << getSex();
    }

    virtual void Input()
    {
        int ID = dataValidator.input_PatientID();
        setId(ID);

        string name = dataValidator.input_name();
        setName(name);

        string sex = dataValidator.input_sex();
        setSex(sex);
    }
};
