#include"Declaration.h"
#include<iostream>

Teacher::Teacher()
{
	Education = "Not Set";
	Teaching_level = "Not Set";
	Subject = "Not Set";
}
Teacher::Teacher(int id, string name, string f_name, DateType DOB, int pay_scale, string job, string edu, string teaching_level, string subject) :Employee(id,name,f_name,DOB,pay_scale,job)
{
	Education = edu;
	Teaching_level = teaching_level;
	Subject = subject;
}


void Teacher::setRecord()
{
	Employee::setRecord();
	char choice;
	bool isokay = true;
	/////////////// Education ///////////////
	setEducation();
	/////////////// Teaching level ///////////////
	setTeachingLevel();
	/////////////// Subject ///////////////
	setSubject();
}


void Teacher::showRecord()
{
	Employee::showRecord();
	cout << "\n\n             Teaching Details\n"
		<< "\n        Teacher Education      " << Education
		<< "\n        Teaching Level         " << Teaching_level
		<< "\n        Subject                " << Subject<<endl;
}


void Teacher::upDateRecord()
{
	char choice;
	cout << "      Update Menu\n"
		<< "\n       1.Job Type"
		<< "\n       2.Pay Scale"
		<< "\n       3.Education"
		<< "\n       4.Teaching Level";
	cout << "\nEnter Your Choice:";
	cin >> choice;
	switch (choice)
	{
	case '1':
		Employee::setJobType();
		break;
	case '2':
		Employee::setPayScale();
	case '3':
		setEducation();
		break;
	case '4':
		setTeachingLevel();
		break;
	default:
		cout << "Invalid Choice";
		break;
	}

}



void Teacher::setEducation()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Teacher Education: \n"
			<< "       1.Bachelor\n"
			<< "       2.Masters\n"
			<< "       3.PHD\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Education = "Bachelor";
			break;
		case '2':
			Education = "Masters";
			break;
		case '3' :
			Education = "PHD";
			break;
		default:
			cout << "\nINVALID INPUT try again";
			isokay = false;
			break;
		}
	} while (!isokay);
}
void Teacher::setTeachingLevel()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Teaching Level: \n"
			<< "       1.School\n"
			<< "       2.College\n"
			<< "       3.University\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Teaching_level = "School";
			break;
		case '2':
			Teaching_level = "College";
			break;
		case '3':
			Teaching_level = "University";
			break;
		default:
			cout << "INVALID INPUT try again";
			isokay = false;
			break;
		}
	} while (!isokay);
}
void Teacher::setSubject()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Teacher Subject: \n"
			<< "       1.Physics\n"
			<< "       2.Chemistry\n"
			<< "       3.Maths\n"
			<< "       4.Computer Science\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Subject = "Physics";
			break;
		case '2':
			Subject = "Chemistry";
			break;
		case '3':
			Subject = "Maths";
			break;
		case '4':
			Subject = "Computer Science";
			break;
		default:
			cout << "INVALID INPUT try agin";
			isokay = false;
			break;
		}
	} while (!isokay);
}

string Teacher::getTeachingLevel()
{
	return Teaching_level;
}