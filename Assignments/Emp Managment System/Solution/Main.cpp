#include"Declaration.h"
#include<iostream>

void addEmployeeMenu(EmployeeList &list);    //Functions Declatations
void searchEmployeeMenu(EmployeeList &list);
void deleteEmployeeMenu(EmployeeList &list);

int main()
{

	
	EmployeeList list = EmployeeList();
	char choice;
	do{
		cout << "\n\n******************** 1) Add Employee ********************"
			<< "\n******************** 2) Update Employee Record ***********"
			<< "\n******************** 3) Search Employee ******************"
			<< "\n******************** 4) Delete Employee ******************"
			<< "\n******************** 5) Exit *****************************\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			addEmployeeMenu(list);
			break;
		case '2':
			list.updateEmployeeRecord();
			break;
		case '3':
			searchEmployeeMenu(list);
			break;
		case '4':
			deleteEmployeeMenu(list);
			break;
		case '5':
			exit(-1);
			break;
		default:
			break;
		}
	} while (1);
	system("pause");

}


void addEmployeeMenu(EmployeeList &list)
{
	char choice;
	cout <<"\n\n****************** AddEmployeeMenu *************"
		<< "\n******************** 1) Add Doctor **************"
		<< "\n******************** 2) Add Teacher *************"
		<< "\n******************** 3) Go Back *****************\n";
	cin >> choice;
	switch (choice)
	{
	case '1':
		list.AddNewDoctor();
		break;
	case '2':
		list.AddNewTeacher();
		break;
	case '3':
		break;
	default:
		break;
	}
}
void searchEmployeeMenu(EmployeeList &list)
{
	char choice;
	cout << "\n\n****************** Search Employee Menu ******************"
		<< "\n******************** 1) SearchEmployeeByID *****************"
		<< "\n******************** 2) SearchEmployeeByName ***************"
		<< "\n******************** 3) SearchYoungestEmployee *************"
		<< "\n******************** 4) SearchEldestEmployee ***************"
		<< "\n******************** 5) SearchDoctorBySpecialization *******"
		<< "\n******************** 6) SearchTeacherByTeachingLevel *******"
		<< "\n******************** 7) Go Back ****************************"

		;
	cin >> choice;
	switch (choice)
	{
	case '1':
		list.SearchEmployeeByID();
		break;
	case '2':
		list.SearchEmployeeByName();
		break;
	case '3':
		list.SearchYoungestEmployee();
		break;
	case '4':
		list.SearchEldestEmployee();
		break;
	case '5':
		list.SearchDoctorBySpecialization();
		break;
	case '6':
		list.SearchTeacherByTeachingLevel();
		break;
	case '7':
		break;
	default:
		break;
	}
}
void deleteEmployeeMenu(EmployeeList &list)
{
	char choice;
	cout << "\n\n****************** Delete Employee Menu ******************"
		<< "\n******************** 1) DeleteEmployeeByID *****************"
		<< "\n******************** 2) DeleteEmployeeByName ***************"
		<< "\n******************** 3) Go Back ****************************";
	cin >> choice;
	switch (choice)
	{
	case '1':
		list.DeleteEmployeeByID();
		break;
	case '2':
		list.DeleteEmployeeByName();
		break;
	case '3':
		break;
	default:
		cout << "\nInvalid Choice\n";

	}
}