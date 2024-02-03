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
                it->display();
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
        system("cls");
    }

    void updatePatient(Patient *sick)
    {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID(Start from 1 digit)" << endl;
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
            cout << "Enter ID(Start from 1 digit): ";
            cin >> patientID;
            system("cls");
            auto it = find_if(patients.begin(), patients.end(),
                              [patientID](const Patient *sick)
                              { return sick->getId() == patientID; });
            do
            {
                if (it != patients.end())
                {
                    // Display the information before edition
                    cout << "Patient information to be updated:\n";
                    (*it)->display(); // Use (*it) instead of sick

                    // Confirm modification
                    cout << "Do you want to modify this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                        system("cls");
                    {
                        int choice;
                        cout << "==========EDIT MENU==========" << endl;
                        cout << "1. Patient ID(Start from 1 digit)" << endl;
                        cout << "2. Name" << endl;
                        cout << "3. Reason/Condition" << endl;
                        cout << "4. Back" << endl;
                        cout << "Enter choice(1-4)-> ";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                        {
                            system("cls");
                            int new_id;
                            cout << "Enter new ID(Start from 1 digit): ";
                            cin >> new_id;

                            (*it)->setId(new_id);
                            cout << "Patient ID changed successfully" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                            cin.get();
                            system("cls");
                        }
                        break;
                        case 2:
                        {
                            system("cls");
                            string new_name;
                            cout << "Enter new name: ";
                            cin >> new_name;

                            (*it)->setName(new_name);
                            cout << "Name changed successfully" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                            cin.get();
                            system("cls");
                        }
                        break;
                        case 3:
                            if (typeid(**it) == typeid(OutPatient))
                            {
                                system("cls");
                                string newReason;
                                cout << "Enter new reason: ";
                                cin >> newReason;
                                dynamic_cast<OutPatient *>(*it)->setReason(newReason);
                                cout << "Reason updated successfully.\n";
                                cout << "Press any key to continue...";
                                cin.ignore();
                                cin.get();
                                system("cls");
                            }
                            else if (typeid(**it) == typeid(InPatient))
                            {
                                system("cls");
                                string newCondition;
                                cout << "Enter new Condition ";
                                cin >> newCondition;
                                dynamic_cast<InPatient *>(*it)->setCondition(newCondition);
                                cout << "Condition updated successfully.\n";
                                cout << "Press any key to continue...";
                                cin.ignore();
                                cin.get();
                                system("cls");
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
                    system("cls");
                }
            } while (performChoice == 'y' || performChoice == 'Y');
        }
        break;
        case FINDNAME:
        {
            char performChoice;
            do
            {
                system("cls");
                string name;
                cout << "Enter name: ";
                cin >> name;
                auto it = find_if(patients.begin(), patients.end(),
                                  [name](const Patient *sick)
                                  { return sick->getName() == name; });
                system("cls");
                if (it != patients.end())
                {
                    // Display the information before edition
                    cout << "Patient information to be updated:\n";
                    (*it)->display(); // Use (*it) instead of sick

                    // Confirm modification
                    cout << "Do you want to modify this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                    {
                        system("cls");
                        int choice;
                        cout << "==========EDIT MENU==========" << endl;
                        cout << "1. Patient ID(Start from 1 digit)" << endl;
                        cout << "2.	Name" << endl;
                        cout << "3.	Condition/Reason" << endl;
                        cout << "4. Back" << endl;
                        cout << "Enter choice(1-4)-> ";
                        cin >> choice;
                        switch (choice)
                        {
                        case 1:
                        {
                            system("cls");
                            int new_id;
                            cout << "Enter new ID(Start from 1 digit): ";
                            cin >> new_id;

                            (*it)->setId(new_id);
                            cout << "Patient ID changed successfully" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                            cin.get();
                            system("cls");
                        }
                        break;
                        case 2:
                        {
                            system("cls");
                            string new_name;
                            cout << "Enter new name: ";
                            cin >> new_name;

                            (*it)->setName(new_name);
                            cout << "Name changed successfully" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                            cin.get();
                            system("cls");
                        }
                        break;
                        case 3:
                            system("cls");
                            if (typeid(**it) == typeid(OutPatient))
                            {
                                string newReason;
                                cout << "Enter new reason: ";
                                cin >> newReason;
                                dynamic_cast<OutPatient *>(*it)->setReason(newReason);
                                cout << "Reason updated successfully.\n";
                                cout << "Press any key to continue...";
                                cin.ignore();
                                cin.get();
                                system("cls");
                            }
                            else if (typeid(**it) == typeid(InPatient))
                            {
                                string newCondition;
                                cout << "Enter new Condition ";
                                cin >> newCondition;
                                dynamic_cast<InPatient *>(*it)->setCondition(newCondition);
                                cout << "Condition updated successfully.\n";
                                cout << "Press any key to continue...";
                                cin.ignore();
                                cin.get();
                                system("cls");
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
                    system("cls");
                }
            } while (performChoice == 'y' || performChoice == 'Y');
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
    }

    void deletePatient(Patient *sick)
    {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID(Start from 1 digit)" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case FINDID:
        {
            system("cls");
            char performChoice;
            int patientID;
            cout << "Enter ID(Start from 1 digit): ";
            cin >> patientID;
            auto it = find_if(patients.begin(), patients.end(),
                              [patientID](const Patient *sick)
                              { return sick->getId() == patientID; });
            do
            {
                system("cls");
                if (it != patients.end())
                {
                    // Display the information before deletion
                    cout << "Patient information to be deleted:\n";
                    (*it)->display(); // Use (*it) instead of sick

                    // Confirm deletion
                    cout << "Do you want to delete this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                    {
                        system("cls");
                        patients.erase(it);
                        cout << "Patient deleted successfully." << endl;
                        cout << "Press any key to continue...";
                        cin.ignore();
                        cin.get();
                        system("cls");
                    }
                }
                else
                {
                    cout << "Patient is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                    system("cls");
                }
            } while (performChoice == 'y' || performChoice == 'Y');
            break;
        }
        case FINDNAME:
        {
            char performChoice;
            do
            {
                system("cls");
                string name;
                cout << "Enter name: ";
                cin >> name;
                auto it = find_if(patients.begin(), patients.end(),
                                  [name](const Patient *sick)
                                  { return sick->getName() == name; });
                if (it != patients.end())
                {
                    system("cls");
                    // Display the information before deletion
                    cout << "Patient information to be deleted:\n";
                    (*it)->display(); // Use (*it) instead of sick

                    // Confirm deletion
                    cout << "Do you want to delete this Patient? (y/n): ";
                    char choices;
                    cin >> choices;

                    if (choices == 'y' || choices == 'Y')
                    {
                        system("cls");
                        patients.erase(it);
                        cout << "Patient deleted successfully." << endl;
                        cout << "Press any key to continue...";
                        cin.ignore();
                        cin.get();
                        system("cls");
                    }
                }
                else
                {
                    cout << "Patient is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                    system("cls");
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
        system("cls");
        switch (choice)
        {
        case SORTID:
            sort(patients.begin(), patients.end(),
                 [](const Patient *a, const Patient *b)
                 { return a->getId() < b->getId(); });
            cout << "Sorted by ID successfully" << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        case SORTNAME:
            sort(patients.begin(), patients.end(),
                 [](const Patient *a, const Patient *b)
                 { return a->getName() < b->getName(); });
            cout << "Sorted by name successfully" << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
    }

    void searchPatient(Patient *sick)
    {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to the main menu" << endl;
        cout << "Enter choice (1-3): ";
        cin >> choice;
        system("cls");
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
            system("cls");

            if (it != patients.end())
            {
                (*it)->display();
                cout << "Is this the correct patient? (y/n): ";
                char response;
                cin >> response;

                if (response == 'y' || response == 'Y')
                {
                    cout << "Continuing..." << endl;
                    system("cls");
                }
                else
                {
                    cout << "Patient not confirmed. Returning to the main menu." << endl;
                }
            }
            else
            {
                cout << "Patient not found" << endl;
            }
            break;
        }
        case FINDNAME:
        {
            string patientName;
            cout << "Enter name: ";
            cin.ignore(); // Ignore any previous newline characters
            getline(cin, patientName);
            system("cls");
            auto it = find_if(patients.begin(), patients.end(),
                              [patientName](const Patient *sick)
                              { return sick->getName() == patientName; });

            if (it != patients.end())
            {
                system("cls");
                (*it)->display();
                cout << "Is this the correct patient? (y/n): ";
                char response;
                cin >> response;

                if (response == 'y' || response == 'Y')
                {
                    cout << "Continuing..." << endl;
                    system("cls");
                }
                else
                {
                    cout << "Patient not confirmed. Returning to the main menu." << endl;
                }
            }
            else
            {
                cout << "Patient not found" << endl;
            }
            break;
        }

        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            system("cls");
            break;
        }
    }

    void savePatient()
    {
        ofstream outputFile("Patient.dat", ios::out);

        if (!outputFile.is_open())
        {
            cout << "Error in creating file...\n";
            exit(1);
        }
        else
        {
            for (const auto &patient : patients)
            {
                if (typeid(*patient) == typeid(InPatient))
                {
                    // Save InPatient information
                    outputFile << "In Patient:" << endl;
                    outputFile << "-------------------------------------------------------------------\n";
                    outputFile << "ID      Name        Sex           Condition \n";
                    outputFile << "-------------------------------------------------------------------\n";
                    outputFile << patient->getId()
                               << setw(12) << patient->getName()
                               << setw(15) << patient->getSex()
                               << setw(20) << dynamic_cast<InPatient *>(patient)->getCondition() << endl;
                    outputFile << "-------------------------------------------------------------------\n";
                }
                else if (typeid(*patient) == typeid(OutPatient))
                {
                    // Save OutPatient information (you can add a similar block as needed)
                    outputFile << "Out Patient:" << endl;
                    outputFile << "-------------------------------------------------------------------\n";
                    outputFile << "ID      Name        Sex           Reason \n";
                    outputFile << "-------------------------------------------------------------------\n";
                    outputFile <<  patient->getId()
                               << setw(12) << patient->getName()
                               << setw(15) << patient->getSex()
                               << setw(20) << dynamic_cast<OutPatient *>(patient)->getReason() << endl;
                    outputFile << "-------------------------------------------------------------------\n";
                }
            }

            cout << "File saved successfully" << endl;
        }

        outputFile.close();
    }

    void loadPatient()
    {
        ifstream inputFile("Patient.dat", ios::in);
        if (!inputFile.is_open())
        {
            cout << "Error in opening file...\n";
            exit(1);
        }

        try
        {
            int id;
            string name;
            string additionalInfo;

            while (inputFile >> id >> name)
            {
                // Depending on your Patient class, add deserialization for other members
                Patient *patient;
                if (additionalInfo == "Condition:")
                {
                    patient = new InPatient();
                    dynamic_cast<InPatient *>(patient)->setCondition(additionalInfo);
                }
                else if (additionalInfo == "Reason:")
                {
                    patient = new OutPatient();
                    dynamic_cast<OutPatient *>(patient)->setReason(additionalInfo);
                }
                else
                {
                    // Default to a regular Patient
                    patient = new Patient();
                }

                patient->setId(id);
                patient->setName(name);
                addPatient(patient);
            }

            cout << "File loaded successfully" << endl;
        }
        catch (const std::exception &e)
        {
            cerr << "Exception: " << e.what() << endl;
        }

        inputFile.close();
    }
};