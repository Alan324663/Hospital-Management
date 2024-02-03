Project Technical Proposal
Hospital management system
I.	Project Description:
	Hospital management system is design to help nurse or doctor in the register desk can be more efficient at managing their patient. The project is created in a way to differentiate the difference between a walk-in patient and emergency patient. In another sense, the approach of the project is aim to help the hospital to keep all the patient under a better system.
	It also contain Login option to maintain the usage, as well.
	Having taking in different type of patient in a single, workers that work in the register would require a proper system of keeping simple data of the patient. It would lessen up the burden on nurses or doctors in organizing data into file, and it would also help in keeping patient staying in a better control environment if there were unexpected variable to occur.

Project Modules and Features:
•	Patient Information Management (ID, Name, Sex, Phone Number…)
o	Add new patient (Walk-in or Emergency differentiation)
o	View all patients
o	Update patient by ID
o	Delete patient by ID
o	Search patient by ID
o	Sort patient by ID
•	Patient diagnose Management (diagnose, medication…)
o	Add new diagnose for new patient
o	Update patient diagnose by ID
o	Delete patient diagnose by ID
o	View all patient diagnose by ID
o	Search for patient










 
	
II.	Project technology and tools
About the Project	Project Details
Project Name: 	Hospital Management System
Project Platform:	C++
Project Language Used:	C++ Programming Language
Developer Name:	Eung Hann
IDE tool:	Visual Studio Code
Project type:	CLI Desktop Application Software
Data Storage:	Store data in .dat file
Created date:	18/12/2023
Modified date:	29/01/2024


III.	Design UML Class Diagram

 



IV.	Design UI




------------------------- WELCOME ---------------------------

1. Register Patient
2. Register Diagnose
3. Exit
Enter choice (1-3): 1

Module 1: 


==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 1


1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 1

Enter ID: 000 000 000
Enter Name (First name, Last name): Bunbee Lee
Enter Sex: M
Enter Contact info: 000 000 0000
Enter Reason for visitation: Coughing non-stop

Do you want to continue? y/n
Enter choice: n



==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 1



1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 2

Enter ID: 000 000 000
Enter Name (First name, Last name): Bunbee Lee
Enter Sex: M
Enter Condition: Severely hit on the stomach, need urgent surgery


==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 2

Walk-in Patient:
------------------------------------------------------------------------------
 ID           Name                Sex         Contact info          Reason
____________________________________________________
 1               BunBee Lee         M              000 000 0000           Coughing
---------------------------------------------------------------------------------------

Emergency Patient:
------------------------------------------------------------------------------
 ID           Name                Sex         Reason
____________________________________________________
 1               BunBee Lee         M              Severely need surgery

Press any key to continue…..

==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 3

Enter Patient ID: 1

Is this the correct patient (Bunbee Lee)? y/n
Enter choice: y

1. Update ID:
2. Update Contact info:
3. Update Reason for visitation: 
Enter choice (1-3): 1
1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 1

Enter updated ID: 2

Update successfully!!


==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 4

1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 1

Enter Patient ID: 2

Is this the correct patient (Bunbee Lee)? y/n
Enter choice: y

Delete successfully!!


==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 5

1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 1

Enter ID: 2
Walk-in Patient:
------------------------------------------------------------------------------
 ID           Name                Sex         Contact info          Reason
____________________________________________________
 2               BunBee Lee         M              000 000 0000           Coughing
---------------------------------------------------------------------------------------


==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 6


1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 2

Successfully sort patient by ID!!


==========Register Patient Menu==========
1. Add Patient 
2. View all Patient 
3. Update a specific Patient detail 
4. Delete a specific Patient 
5. Find a specific Patient
6. Sort Patient
7. Exit
Enter choice (1-7): 7
You have exited form the program!!

------------------------- WELCOME ---------------------------

1. Register Patient
2. Register Diagnose
3. Exit
Enter choice (1-3): 2

Module 2: 

------------------------- WELCOME ---------------------------

1. Walk-in Patient
2. Emergency care Patient
Enter choice (1-2): 2

Enter patient ID: 2

==========Register Patient Menu==========
------------------------------------------------------------------------------
 ID           Name                Sex         Contact info          Reason
____________________________________________________
 2               BunBee Lee         M              000 000 0000           Coughing
---------------------------------------------------------------------------------------


1. Add Diagnose
2. View all Diagnose
3. Update a specific Diagnose
4. Delete a Diagnose
5. Find a Diagnose
6. Sort Diagnose
7. Exit
Enter choice (1-7): 1


