#pragma once
#include <iostream>
#include "InPatient.cpp"
#include "OutPatient.cpp"
#include "PatientCollector.cpp"
#include "Patient.cpp"
#include "RegisterLogin.cpp"
#include "AdminAccount.cpp"

using namespace std;

enum
{
    LOGOUT = 0,
    ADDPATIENT,
    DISPLAYPATIENT,
    UPDATEPATIENT,
    DELETEPATIENT,
    SORTPATIENT,
    SEARCHPATIENT,
    SAVEPATIENT,

};

class Application
{
private:
    PatientCollector p;
    Patient *sick{};

public:
    void patientMenu()
    {
        cout << "==========Hospital Management Menu==========" << endl;
        cout << "1. Create patient profile" << endl;
        cout << "2. View all patient information" << endl;
        cout << "3. Update a specific patient information" << endl;
        cout << "4. Delete a specific patient information" << endl;
        cout << "5. Sort patient information" << endl;
        cout << "6. Search for a specific patient information" << endl;
        cout << "7. Save patient data" << endl;
        cout << "0. Log out" << endl;
    }
    void authenticationMenu()
    {
        cout << "==========Patient Management System==========" << endl;
        cout << "1. Login" << endl;
        cout << "0. Exit" << endl;
    }
    void menu()
    {
        cout << "==========Account Management System==========" << endl;
        cout << "1. Admin" << endl;
        cout << "2. User" << endl;
        cout << "0. Exit" << endl;
    }
    void adminMenu()
    {
        cout << "You have successful enter the admin interface." << endl;
        cout << "==========Welcom to Account Management System==========" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Register New Admin" << endl;
        cout << "0. Exit" << endl;
    }

    int getChoice()
    {
        int choice;
        cout << "Enter your choice(0-7)-> ";
        cin >> choice;
        return choice;
    }

    void patientManagement()
    {
        cout << "Entering patientManagement()" << endl;
        int choice = 0;
        int option = 0;

        do
        {

            patientMenu();
            choice = getChoice();

            switch (choice)
            {
            case ADDPATIENT:
            {
                system("cls");
                char addMore;
                do
                {
                    cout << "1. InPatient" << endl;
                    cout << "2. OutPatient" << endl;
                    cout << "Choose the current status of the patient(1-2)-> ";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                    {
                        system("cls");
                        auto inPatient = make_unique<InPatient>();
                        inPatient->input();
                        p.addPatient(inPatient.release());
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        auto outPatient = make_unique<OutPatient>();
                        outPatient->input();
                        p.addPatient(outPatient.release());
                        break;
                    }
                    default:
                        cout << "Invalid Patient" << endl;
                        cout << "Press any key to continue..." << endl;
                        cin.ignore();
                        cin.get();
                        break;
                    }

                    cout << "Patient Profile created successfully." << endl;

                    cout << "Do you want to add more patients? (y/n): ";
                    cin >> addMore;
                    system("cls");

                } while (addMore == 'y' || addMore == 'Y');
                break;
            }
            case DISPLAYPATIENT:
                system("cls");
                p.viewPatient();
                break;
            case UPDATEPATIENT:
                system("cls");
                p.updatePatient(sick);
                break;
            case DELETEPATIENT:
                system("cls");
                p.deletePatient(sick);
                break;
            case SORTPATIENT:
                system("cls");
                p.sortPatient();
                break;
            case SEARCHPATIENT:
                system("cls");
                p.searchPatient(sick);
                break;
            case SAVEPATIENT:
                system("cls");
                p.savePatient();
                break;
            case LOGOUT:
                cout << "Logging out..." << endl;
                exit;
                system("cls");
                break;
            default:
                cout << "Invalid Choice, Try again" << endl;
                break;
            }

        } while (choice != LOGOUT);
        cout << "Exiting patientManagement()" << endl;
    }
    void run()
    {
        int choice = 0;
        RegisterLogin log;
        AdminAccount admin;

        do
        {
            menu();
            cout << "Please clarify your current role(0-2): ";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                system("cls");
                if (admin.adminLogin() == true)
                {
                    system("cls");
                    adminMenu();
                    int option;
                    cout << "Choose your option(0-2)-> ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        system("cls");
                        log.userRegister();
                        break;
                    case 2:
                        system("cls");
                        admin.adminRegister();
                        break;
                    case 0:
                        exit;
                        system("cls");
                        break;
                    }
                }
                else
                {
                    cout << "Login failed. Please try again." << endl;
                }
                break;
            }
            case 2:
            {
                system("cls");
                int choices;
                authenticationMenu();
                cout << "Enter your choice(0-1)-> ";
                cin >> choices;
                switch (choices)
                {
                case 1:
                    if (log.userLogin() == true)
                    {
                        system("cls");
                        p.loadPatient();
                        patientManagement();
                    }
                    else
                    {
                        cout << "Login failed. Please try again." << endl;
                    }
                    break;
                case 0:
                    exit;
                    system("cls");

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            }

        } while (choice != 0);
    }
};