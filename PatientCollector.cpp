#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Patient.cpp"
#include "InPatient.cpp"
#include "OutPatient.cpp"
#include "PatientDAO.cpp"
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

enum
{
    FINDID = 1,
    FINDNAME
};

enum
{
    SORTID = 1,
    SORTNAME
};

class PatientCollector : public PatientDAO
{
private:
    vector<Patient *> patients;

public:
    ~PatientCollector()
    {
        for (auto &sick : patients)
        {
            delete sick;
        }
    }

    void addPatient(Patient *Patients)
    {
        patients.push_back(Patients);
    }

    void viewPatient()
    {
        for (const auto &it : patients)
        {
            try
            {
                it->Display();
                cout << endl;
            }
            catch (const std::exception &e)
            {
                cerr << "Exception: " << e.what() << endl;
            }
        }

        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }

    void updatePatient(Patient *sick)
    {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case FINDID:
        {
            char performChoice;

            int patientID;
            cout << "Enter ID: ";
            cin >> patientID;
            auto it = find_if(patients.begin(), patients.end(),
                              [patientID](const Patient *sick)
                              { return sick->getId() == patientID; });
            do
            {
                if (it != patients.end())
                {
                    // Display the information before edition
                    cout << "Patient information to be updated:\n";
                    (*it)->Display(); // Use (*it) instead of sick

                    // Confirm modification
                    cout << "Do you want to modify this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')

                    {
                        int choice;
                        cout << "==========EDIT MENU==========" << endl;
                        cout << "1. Patient ID" << endl;
                        cout << "2. Name" << endl;
                        cout << "3. Reason/Condition" << endl;
                        cout << "4. Back" << endl;
                        cout << "Enter choice(1-4)-> ";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                        {
                            int new_id;
                            cout << "Enter new ID: ";
                            cin >> new_id;

                            (*it)->setId(new_id);
                            cout << "Patient ID changed successfully" << endl;
                        }
                        break;
                        case 2:
                        {
                            string new_name;
                            cout << "Enter new name: ";
                            cin >> new_name;

                            (*it)->setName(new_name);
                            cout << "Name changed successfully" << endl;
                        }
                        break;
                        case 3:
                            if (typeid(**it) == typeid(OutPatient))
                            {
                                string newReason;
                                cout << "Enter new reason: ";
                                cin >> newReason;
                                dynamic_cast<OutPatient *>(*it)->setReason(newReason);
                                cout << "Reason updated successfully.\n";
                            }
                            else if (typeid(**it) == typeid(InPatient))
                            {
                                string newCondition;
                                cout << "Enter new Condition ";
                                cin >> newCondition;
                                dynamic_cast<InPatient *>(*it)->setCondition(newCondition);
                                cout << "Condition updated successfully.\n";
                            }
                            else
                            {
                                // Unknown Patient
                                cout << "Error: Unknown Patient.\n";
                            }
                            break;
                        case 4: // break out to main menu
                            break;
                        default:
                            cout << "Invalid Choice. Please try again" << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Patient is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                }
            } while (performChoice == 'y' || performChoice == 'Y');
        }
        break;
        case FINDNAME:
        {
            char performChoice;
            do
            {
                string name;
                cout << "Enter name: ";
                cin >> name;
                auto it = find_if(patients.begin(), patients.end(),
                                  [name](const Patient *sick)
                                  { return sick->getName() == name; });
                if (it != patients.end())
                {
                    // Display the information before edition
                    cout << "Patient information to be updated:\n";
                    (*it)->Display(); // Use (*it) instead of sick

                    // Confirm modification
                    cout << "Do you want to modify this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                    {
                        int choice;
                        cout << "==========EDIT MENU==========" << endl;
                        cout << "1. Patient ID" << endl;
                        cout << "2.	Name" << endl;
                        cout << "3.	Condition/Reason" << endl;
                        cout << "4. Back" << endl;
                        cout << "Enter choice(1-4)-> ";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                        {
                            int new_id;
                            cout << "Enter new ID: ";
                            cin >> new_id;

                            (*it)->setId(new_id);
                            cout << "Patient ID changed successfully" << endl;
                        }
                        break;
                        case 2:
                        {
                            string new_name;
                            cout << "Enter new name: ";
                            cin >> new_name;

                            (*it)->setName(new_name);
                            cout << "Name changed successfully" << endl;
                        }
                        break;
                        case 3:
                            if (typeid(**it) == typeid(OutPatient))
                            {
                                string newReason;
                                cout << "Enter new reason: ";
                                cin >> newReason;
                                dynamic_cast<OutPatient *>(*it)->setReason(newReason);
                                cout << "Reason updated successfully.\n";
                            }
                            else if (typeid(**it) == typeid(InPatient))
                            {
                                string newCondition;
                                cout << "Enter new Condition ";
                                cin >> newCondition;
                                dynamic_cast<InPatient *>(*it)->setCondition(newCondition);
                                cout << "Condition updated successfully.\n";
                            }
                            else
                            {
                                // Unknown Patient
                                cout << "Error: Unknown Patient.\n";
                            }
                            break;
                        case 4: // break out to main menu
                            break;
                        default:
                            cout << "Invalid Choice. Please try again" << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Patient is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                }
            } while (performChoice == 'y' || performChoice == 'Y');
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    void deletePatient(Patient *sick)
    {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case FINDID:
        {
            char performChoice;
            int patientID;
            cout << "Enter ID: ";
            cin >> patientID;
            auto it = find_if(patients.begin(), patients.end(),
                              [patientID](const Patient *sick)
                              { return sick->getId() == patientID; });
            do
            {
                if (it != patients.end())
                {
                    // Display the information before deletion
                    cout << "Patient information to be deleted:\n";
                    (*it)->Display(); // Use (*it) instead of sick

                    // Confirm deletion
                    cout << "Do you want to delete this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                    {
                        patients.erase(it);
                        cout << "Patient deleted successfully." << endl;
                    }
                }
                else
                {
                    cout << "Patient is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                }
            } while (performChoice == 'y' || performChoice == 'Y');
            break;
        }
        case FINDNAME:
        {
            char performChoice;
            do
            {
                string name;
                cout << "Enter name: ";
                cin >> name;
                auto it = find_if(patients.begin(), patients.end(),
                                  [name](const Patient *sick)
                                  { return sick->getName() == name; });
                if (it != patients.end())
                {
                    // Display the information before deletion
                    cout << "Patient information to be deleted:\n";
                    (*it)->Display(); // Use (*it) instead of sick

                    // Confirm deletion
                    cout << "Do you want to delete this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                    {
                        patients.erase(it);
                        cout << "Patient deleted successfully." << endl;
                    }
                }
                else
                {
                    cout << "Patient is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                }
            } while (performChoice == 'y' || performChoice == 'Y');
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    void sortPatient()
    {
        int choice;
        cout << "==========SORT MENU==========" << endl;
        cout << "1. Sort by ID" << endl;
        cout << "2. Sort by name" << endl;
        cout << "Enter choice(1-2)-> ";
        cin >> choice;
        switch (choice)
        {
        case SORTID:
            sort(patients.begin(), patients.end(),
                 [](const Patient *a, const Patient *b)
                 { return a->getId() < b->getId(); });
            cout << "Sorted by ID successfully" << endl;
            break;
        case SORTNAME:
            sort(patients.begin(), patients.end(),
                 [](const Patient *a, const Patient *b)
                 { return a->getName() < b->getName(); });
            cout << "Sorted by name successfully" << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    void searchPatient(Patient *sick)
    {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case FINDID:
        {
            int patientID;
            cout << "Enter ID: ";
            cin >> patientID;
            auto it = find_if(patients.begin(), patients.end(),
                              [patientID](const Patient *sick)
                              { return sick->getId() == patientID; });
            if (it != patients.end())
            {
                (*it)->Display();
                cout << endl;
            }
            else
            {
                cout << "Patient is not found" << endl;
            }
            break;
        }
        case FINDNAME:
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(patients.begin(), patients.end(),
                              [name](const Patient *sick)
                              { return sick->getName() == name; });
            if (it != patients.end())
            {
                (*it)->Display();
                cout << endl;
            }
            else
            {
                cout << "Patient is not found" << endl;
            }
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    void savePatient()
    {
        ofstream outputFile("Patient.dat", ios::out | ios::binary);

        if (!outputFile.is_open())
        {
            cout << "Error in creating file...\n";
            exit(1);
        }
        else
        {
            for (const auto &accountPtr : patients)
            {
                outputFile.write(reinterpret_cast<char *>(accountPtr), sizeof(Patient));
            }

            cout << "File saved successfully" << endl;
        }

        outputFile.close();
    }

    void loadPatient()
    {
        ifstream inputFile("Patient.dat", ios::in | ios::binary);
        if (!inputFile.is_open())
        {
            cout << "Error in opening file...\n";
            exit(1);
        }

        try
        {
            while (true)
            {
                Patient *sick = new Patient();
                if (!inputFile.read(reinterpret_cast<char *>(sick), sizeof(Patient)))
                {
                    // Reached end of file
                    delete sick; // Clean up the dynamically allocated memory
                    break;
                }

                addPatient(sick);
                cout << "File loaded successfully" << endl;
            }
        }
        catch (const std::exception &e)
        {
            cerr << "Exception: " << e.what() << endl;
        }

        inputFile.close();
    }
};
