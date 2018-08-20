#include"Declaration.h"
#include<iostream>

Doctor::Doctor()
{
	Doctor_type = "Not Set";
	Specialization = "Not Set";
	Job_level = "Not Set";
}
Doctor::Doctor(int id, string name, string f_name, DateType DOB, int pay_scale, string job, string doctor_type, string specialization, string job_level) :Employee(id, name, f_name, DOB, pay_scale, job)
{
	Doctor_type = doctor_type;
	Specialization = specialization;
	Job_level = job_level;
}
void Doctor::setRecord()        //Overrided Function:
{
	Employee::setRecord();     //Baseclass Function Call
	setDoctorType();
	setSpecialization();
	setJobLevel();

}

void Doctor::showRecord()     //Overrided Function
{
	Employee::showRecord();
	cout << "\n\n             Doctor Details\n"
		<< "\n        Doctor Type            " << Doctor_type
		<< "\n        Specialization         " << Specialization
		<< "\n        Job Level              " << Job_level<<endl;

}


void Doctor::upDateRecord()
{
	char choice;
	cout << "      Update Menu\n"
		<< "\n       1.Job Type"
		<< "\n       2.Pay Scale"
		<< "\n       3.Job Level";

	cout << "\nEnter Your Choice:";
	cin >> choice;
	switch (choice)
	{
	case '1':
		Employee::setJobType();
		break;
	case '2':
		Employee::setPayScale();
		break;
	case '3':
		setJobLevel();
		break;
	default:
		cout << "Invalid Choice";
		break;
	}

}

void Doctor::setDoctorType()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Doctor Type: \n"
			<< "       1.MBBS\n"
			<< "       2.BDS\n"
			<< "       3.Vetnery\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Doctor_type = "MBBS";
			break;
		case '2':
			Doctor_type = "BDS";
			break;
		case '3':
			Doctor_type = "Vetnery";
			break;
		default:
			cout << "\nINVALID INPUT try again";
			isokay = false;
			break;
		}
	} while (!isokay);
}
void Doctor::setSpecialization()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Doctor Specialization: \n"
			<< "       1.Ent,\n"
			<< "       2.Heart,\n"
			<< "       3.Stomach\n"
			<< "       4.Gyne\n";

		cin >> choice;
		switch (choice)
		{
		case '1':
			Specialization = "Ent";
			break;
		case '2':
			Specialization = "Heart";
			break;
		case '3':
			Specialization = "Stomach";
			break;
		case '4':
			Specialization = "Gyne";
			break;
		default:
			cout << "INVALID INPUT try again";
			isokay = false;
			break;
		}
	} while (!isokay);
}
void Doctor::setJobLevel()
{
	bool isokay;
	char choice;
	do{
		isokay = true;
		cout << "Select Doctor Job Level: \n"
			<< "       1.House Job\n"
			<< "       2.Medical Officer\n"
			<< "       3.Senior Medical Officer\n";
		cin >> choice;
		switch (choice)
		{
		case '1':
			Job_level = "House Job";
			break;
		case '2':
			Job_level = "Medical Officer";
			break;
		case '3':
			Job_level = "Senior Medical Officer";
			break;
		default:
			cout << "INVALID INPUT try agin";
			isokay = false;
			break;
		}
	} while (!isokay);
}

string Doctor::getSpecialization()
{
	return Specialization;
}