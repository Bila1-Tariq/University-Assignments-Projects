#include"Declaration.h"
#include<iostream>
#include <ctime>

Employee::Employee()
{
	Emp_id = 0;
	Name = "Not set";
	Father_Name = "Not set";
	dob = DateType();
	bps = 1;
	Job_Type = "Not Selected yet";
}


Employee::Employee(int id, string name, string f_name, DateType DOB, int pay_scale, string job) :Emp_id(id), Name(name), Father_Name(f_name), dob(DOB), bps(pay_scale), Job_Type(job)
{}

void Employee::setRecord()
{
	cout << "Enter Employee ID: \n";
	cin >> Emp_id;
	cout << "Enter Employee Name: \n";
	cin.ignore(1, '\n');
	getline(cin, Name);
	cout << "Enter Employee Father Name: \n";
	cin.ignore(1, '\n');
	getline(cin,Father_Name);
	cout << "Enter Employee Date of Birth: \n";
	dob.set();
	setPayScale();
	setJobType();

}

void Employee::showRecord()
{
	cout << "             Employee Data\n"
		<< "\n        Employee ID            " << Emp_id
		<< "\n        Name                   " << Name
		<< "\n        Father Name            " << Father_Name
		<< "\n        Date of Birth          " << dob.disp()
		<< "\n        Basic Pay Scale        " << bps
		<< "\n        Job Type               " << Job_Type;
}




void Employee::setPayScale()
{ 
	bool valid_scale = false;
	do{
		cout << "Enter Employee Pay Scale: \n";
		cin >> bps;
		if (bps > 0 && bps < 23)
			valid_scale = true;
	} while (!valid_scale);
}
void Employee::setJobType()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Employee Job Type: \n"
			<< "       1.Private\n"
			<< "       2.Public\n"
			<< "       3.Autonomous\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Job_Type = "Private";
			break;
		case '2':
			Job_Type = "Public";
			break;
		case '3':
			Job_Type = "Autonomous";
			break;
		default:
			cout << "INVALID INPUT try again";
			isokay = false;
			break;
		}
	} while (!isokay);
}
int Employee::getEmpId()
{
	return Emp_id;
}
string Employee::getEmpName()
{
	return Name;
}

int Employee::cal_age()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	int now = timePtr->tm_year + 1900;
	int age = now - dob.getYear();
	return age;
}