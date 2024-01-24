 #pragma once
#include <iostream>
#include "InPatient.cpp"
#include "OutPatient.cpp"
#include "PatientCollector.cpp"
#include "Patient.cpp"
#include "RegisterLogin.cpp"

using namespace std;

enum
{
    ADDPATIENT = 1,
    DISPLAYPATIENT,
    UPDATEPATIENT,
    DELETEPATIENT,
    SORTPATIENT,
    SEARCHPATIENT,
    SAVEPATIENT,
    LOADPATIENT,
    LOGOUT
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
        cout << "8. Load patient data" << endl;
        cout << "9. Log out" << endl;
    }
    void authenticationMenu()
    {
        cout << "==========Bank Management System==========" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
    }

    int getChoice()
    {
        int choice;
        cout << "Enter your choice(1-9)-> ";
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
                    cout << "1. InPatient" << endl;
                    cout << "2. OutPatient" << endl;
                    cout << "Choose the current status of the patient(1-2)-> ";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                    {
                        auto inPatient = make_unique<InPatient>();
                        inPatient->Input();
                        p.addPatient(inPatient.release());
                        break;
                    }
                    case 2:
                    {
                        auto outPatient = make_unique<OutPatient>();
                        outPatient->Input();
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
                    break;
                }
                case DISPLAYPATIENT:
                    p.viewPatient();
                    break;
                case UPDATEPATIENT:
                    p.updatePatient(sick);
                    break;
                case DELETEPATIENT:
                    p.deletePatient(sick);
                    break;
                case SORTPATIENT:
                    p.sortPatient();
                    break;
                case SEARCHPATIENT:
                    p.searchPatient(sick);
                    break;
                case SAVEPATIENT:
                    p.savePatient();
                    break;
                case LOADPATIENT:
                    p.loadPatient();
                    break;
                case LOGOUT:
                    cout << "Logging out..." << endl;
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

        do
        {
            authenticationMenu();
            cout << "Enter your choice(1-3)-> ";
            cin >> choice;
            switch (choice)
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
            case 2:
                log.userRegister();
                break;
            case 3:
                exit(1);

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }

        } while (choice != 3);
    }
};