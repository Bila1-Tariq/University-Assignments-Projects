#include"Declaration.h"
#include<iostream>



EmployeeList::EmployeeList()
{
	Teacher_head = NULL;
	Doctor_head = NULL;
}

void EmployeeList::AddNewTeacher()
{
	TeacherNode *cur = Teacher_head;
	TeacherNode *temp = new TeacherNode;
	temp->setObj(new Teacher());
	if (Teacher_head == NULL)
	{
		Teacher_head = temp;
		temp->setNext(NULL);
	}
	else
	{
		cur = Teacher_head;
		while (cur->getNext() != NULL)
		{
			cur = cur->getNext();
		}
		cur->setNext(temp);
		temp->setNext(NULL);
	}
	temp->getObj()->setRecord();
}

void EmployeeList::AddNewDoctor()
{
	DoctorNode *cur = Doctor_head;
	DoctorNode *temp = new DoctorNode;
	temp->setObj(new Doctor());
	if (Doctor_head == NULL)
	{
		Doctor_head = temp;
		temp->setNext(NULL);
	}
	else
	{
		cur = Doctor_head;
		while (cur->getNext() != NULL)
		{
			cur = cur->getNext();
		}
		cur->setNext(temp);
		temp->setNext(NULL);
	}
	temp->getObj()->setRecord();
}

void EmployeeList::updateEmployeeRecord()
{
	TeacherNode *T_Prev = Teacher_head;
	DoctorNode *D_Prev = Doctor_head;
	int value;
	cout << "\n Enter Employee ID:\n";
	cin >> value;
	TeacherNode *tempT;
	tempT = SearchTeacherById(value,T_Prev);
	if (tempT != NULL)
		tempT->getObj()->upDateRecord();
	else
	{
		DoctorNode *tempD;
		tempD = SearchDoctorById(value,D_Prev);
		if (tempD != NULL)
			tempD->getObj()->upDateRecord();
		else
			cout << "NO Record Found against Employee ID:"<<value<<endl;
	}
}

TeacherNode* EmployeeList::SearchTeacherById(int value, TeacherNode *&prev)
{
	bool flag = false;
	prev = Teacher_head;
	TeacherNode *curT = Teacher_head;
	while (curT != NULL)
	{
		if (curT->getObj()->getEmpId() == value)
		{
			flag = true;
			break;
		}
		prev = curT;
		curT = curT->getNext();
	}
	if (flag == false)
		return NULL;
	else
		return curT;
}

DoctorNode* EmployeeList::SearchDoctorById(int value, DoctorNode *&prev)
{
	bool flag = false;
	prev = Doctor_head;
	DoctorNode *curD = Doctor_head;
	while (curD != NULL)
	{
		if (curD->getObj()->getEmpId() == value)
		{
			flag = true;
			break;
		}
		prev = curD;
		curD = curD->getNext();
	}
	if (flag == false)
		return NULL;
	else
		return curD;
}

void EmployeeList::SearchEmployeeByID()
{
	if (Teacher_head != NULL||Doctor_head != NULL)
	{
		TeacherNode *T_Prev = Teacher_head;
		DoctorNode *D_Prev = Doctor_head;

		int value;
		cout << "\n Enter Employee ID:\n";
		cin >> value;
		TeacherNode *tempT;
		tempT = SearchTeacherById(value, T_Prev);
		if (tempT != NULL)
			tempT->getObj()->showRecord();
		else
		{
			DoctorNode *tempD;
			tempD = SearchDoctorById(value, D_Prev);
			if (tempD != NULL)
				tempD->getObj()->showRecord();
			else
				cout << "NO Record Found against Employee ID:" << value << endl;
		}
	}
	else
	{
		cout << "\nBoth List's Are Empty\n";
	}
}

void EmployeeList::SearchEmployeeByName()
{
	bool flag = false;
	string value;
	cout << "\nENTER Employee Name to Search::";
	cin.ignore(1, '\n');
	getline(cin, value);
	if (Teacher_head != NULL)
	{
		TeacherNode *curT = Teacher_head;
		while (curT != NULL)
		{
			if (curT->getObj()->getEmpName() == value)
			{
				cout << "\n\t Teacher list Data\n";
				curT->getObj()->showRecord();
				flag = true;
			}
			curT = curT->getNext();
		}
	}
	else
		cout << "\n\t Teacher list is Empty\n";

	if (Doctor_head != NULL)
	{
		DoctorNode *curD = Doctor_head;
		while (curD != NULL)
		{
			if (curD->getObj()->getEmpName() == value)
			{
				cout << "\n\t Doctor list Data\n";
				curD->getObj()->showRecord();
				flag = true;
			}
			curD = curD->getNext();
		}
	}
	else
		cout << "\n\t Doctor list is Empty";
	if (flag == false)
		cout << "\n	No Record Found for Employee Name:" << value;
}


void EmployeeList::SearchYoungestEmployee()
{
	int minage = 0;
	if (Teacher_head != NULL)
	{
		cout << "\n\n***************** From Teacher List **************************\n";
		TeacherNode *curT = Teacher_head;
		minage = Teacher_head->getObj()->cal_age();
		TeacherNode *refT = Teacher_head;
		while (curT != NULL)
		{
			if (curT->getObj()->cal_age() < minage)
			{
				minage = curT->getObj()->cal_age();
				refT = curT;
			}
			curT = curT->getNext();
		}

		cout << "\n		Emp Age: " << minage;
		cout << "\n		DATA		";
		refT->getObj()->showRecord();
	}
	else
		cout << "\n\t Teacher list is Empty";
	if (Doctor_head != NULL)
	{
		cout << "\n\n***************** From Doctor List **************************\n";

		minage = 0;
		DoctorNode *curD = Doctor_head;
		minage = Doctor_head->getObj()->cal_age();
		DoctorNode *refD = Doctor_head;
		while (curD != NULL)
		{
			if (curD->getObj()->cal_age() < minage)
			{
				minage = curD->getObj()->cal_age();
				refD = curD;
			}
			curD = curD->getNext();
		}

		cout << "\n		Youngest Employee Age: " << minage;
		cout << "\n		DATA ";
		refD->getObj()->showRecord();
	}
	else
		cout << "\n\t Doctor list is Empty";
}


void EmployeeList::SearchEldestEmployee()
{
	int maxage = 0;
	if (Teacher_head != NULL)
	{
		cout << "\n\n***************** From Teacher List **************************\n";
		TeacherNode *curT = Teacher_head;
		maxage = Teacher_head->getObj()->cal_age();
		TeacherNode *refT = Teacher_head;
		while (curT != NULL)
		{
			if (curT->getObj()->cal_age() > maxage)
			{
				maxage = curT->getObj()->cal_age();
				refT = curT;
			}
			curT = curT->getNext();
		}

		cout << "\n		Emp Age: " << maxage;
		cout << "\n		DATA		";
		refT->getObj()->showRecord();
	}
	else
		cout << "\n\t Teacher list is Empty";
	if (Doctor_head != NULL)
	{
		cout << "\n\n***************** From Doctor List **************************\n";

		maxage = 0;
		DoctorNode *curD = Doctor_head;
		maxage = Doctor_head->getObj()->cal_age();
		DoctorNode *refD = Doctor_head;
		while (curD != NULL)
		{
			if (curD->getObj()->cal_age() > maxage)
			{
				maxage = curD->getObj()->cal_age();
				refD = curD;
			}
			curD = curD->getNext();
		}

		cout << "\n		Eldest Employee Age: " << maxage;
		cout << "\n		DATA ";
		refD->getObj()->showRecord();
	}
	else
		cout << "\n\t Doctor list is Empty";
}

void EmployeeList::SearchDoctorBySpecialization()
{
	if (Doctor_head != NULL)
	{
		bool flag = false;
		char choice;
		string value;
		DoctorNode *cur = Doctor_head;
		cout << "Select Doctor Specialization: \n"
			<< "       1.Ent,\n"
			<< "       2.Heart,\n"
			<< "       3.Stomach\n"
			<< "       4.Gyne\n";

		cin >> choice;
		switch (choice)
		{
		case '1':
			value = "Ent";
			break;
		case '2':
			value = "Heart";
			break;
		case '3':
			value = "Stomach";
			break;
		case '4':
			value = "Gyne";
			break;
		default:
			value = "";
			break;
		}
		while (cur != NULL)
		{
			if (cur->getObj()->getSpecialization() == value)
			{
				cur->getObj()->showRecord();
				flag = true;
			}
			cur = cur->getNext();
		}
		if (flag == false)
			cout << "\n	No Record Found for Specialization " << value<<endl;
	}
	else
	{
		cout << "\nDoctot List is Empty\n";
	}
}

void EmployeeList::SearchTeacherByTeachingLevel()
{
	if (Teacher_head != NULL)
	{
		bool flag = false;
		char choice;
		string value;
		TeacherNode *cur = Teacher_head;
		cout << "Select Teaching Level: \n"
			<< "       1.School\n"
			<< "       2.College\n"
			<< "       3.University\n";

		cin >> choice;
		switch (choice)
		{
		case '1':
			value = "School";
			break;
		case '2':
			value = "College";
			break;
		case '3':
			value = "University";
			break;
		default:
			value = "";
			break;
		}
		while (cur != NULL)
		{
			if (cur->getObj()->getTeachingLevel() == value)
			{
				cur->getObj()->showRecord();
				flag = true;
			}
			cur = cur->getNext();
		}
		if (flag == false)
			cout << "\n	No Record Found for Teaching Level " << value<<endl;
	}
	else
	{
		cout << "\Teacher List is Empty\n";
	}
}

void EmployeeList::DeleteEmployeeByID()
{
	if (Teacher_head != NULL||Doctor_head != NULL)
	{
		int value;
		TeacherNode *T_Prev = Teacher_head;
		DoctorNode *D_Prev = Doctor_head;

		cout << "\n Enter Employee ID:\n";
		cin >> value;
		TeacherNode* curT = SearchTeacherById(value, T_Prev);
		if (curT != NULL)
		{
			deleteFun(curT, T_Prev);
		}
		else
		{
			DoctorNode* curD = SearchDoctorById(value, D_Prev);
			if (curD != NULL)
			{
				deleteFun(curD, D_Prev);
			}
			else
			{
				cout << "\nNo Record Found in any Lis\n";
			}
		}
	}
	else
	{
		cout << "\n Both list's Are Empty\n";
	}
}

void EmployeeList::deleteFun(TeacherNode *curT,TeacherNode *T_Prev)
{
	if ((curT == Teacher_head)){
		Teacher_head = Teacher_head->getNext();
		delete curT;
	}
	else if (curT->getNext() == NULL){
		delete curT;
		T_Prev->setNext(NULL);
	}
	else
	{
		T_Prev->setNext(curT->getNext());
		delete curT;
	}
	cout << "\n:Deletion Completed:\n";
}

void EmployeeList::deleteFun(DoctorNode *curD, DoctorNode *D_Prev)
{
	if ((curD == Doctor_head)){
		Doctor_head = Doctor_head->getNext();
		delete curD;
	}
	else if (curD->getNext() == NULL){
		delete curD;
		D_Prev->setNext(NULL);
	}
	else
	{
		D_Prev->setNext(curD->getNext());
		delete curD;
	}
	cout << "\n:Deletion Completed:\n";
}

void EmployeeList::DeleteEmployeeByName()
{
	bool isagain;
	bool flag = false;
	if (Teacher_head != NULL || Doctor_head != NULL)
	{
		string value;
		TeacherNode *T_Prev;
		DoctorNode *D_Prev;
		TeacherNode *curT;
		DoctorNode *curD;

		cout << "\n Enter Employee Name:\n";
		cin.ignore(1, '\n');
		getline(cin,value);
		if (Teacher_head != NULL)
		{
			do{
				isagain = false;
				curT = Teacher_head;
				T_Prev = Teacher_head;
				while (curT != NULL)
				{
					if (curT->getObj()->getEmpName() == value)
					{
						deleteFun(curT, T_Prev);
						isagain = true;
						flag = true;
						break;
					}
					T_Prev = curT;
					curT = curT->getNext();
				}
			} while (isagain == true);
		}
		if (Doctor_head != NULL)
		{
			do{
				isagain = false;
				curD = Doctor_head;
				D_Prev = Doctor_head;
				while (curD != NULL)
				{
					if (curD->getObj()->getEmpName() == value)
					{
						deleteFun(curD, D_Prev);
						isagain = true;
						flag = true;
						break;
					}
					D_Prev = curD;
					curD = curD->getNext();
				}
			} while (isagain == true);
		}
		if (flag == false)
			cout << "No Record Found in Any List";
	}
	else
	{
		cout << "\n Both list's Are Empty\n";
	}

}