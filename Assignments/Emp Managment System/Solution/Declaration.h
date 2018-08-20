#include<string>
using namespace std;

struct DateType
{
	int day, month, year;

	DateType();
	void set();
	string disp();
	int getMon();
	int getDay();
	int getYear();
	bool operator>(DateType);
	bool operator<(DateType);
	bool operator!=(DateType);
};


class Employee
{
public:
	Employee();
	Employee(int id, string name, string f_name, DateType DOB, int pay_scale, string job);
	void setRecord();
	void showRecord();

	void setPayScale();
	void setJobType();
	int getEmpId();
	string getEmpName();
	int cal_age();
private:
	int Emp_id;
	int bps;
	string Name;
	string Father_Name;
	DateType dob;                    ///DOB MUST HAVE DATE TYPE    (WHICH IS SET YET....)
	string Job_Type;
};

class Teacher:public Employee
{
public:
	Teacher();
	Teacher(int id, string name, string f_name, DateType DOB, int pay_scale, string job, string edu, string teaching_level, string subject);
	void setRecord();
	void showRecord();
	void upDateRecord();

	void setEducation();
	void setTeachingLevel();
	void setSubject();

	string getTeachingLevel();

private:
	string Education;
	string Teaching_level;
	string Subject;
};

class Doctor:public Employee
{
public:
	Doctor();
	Doctor(int, string, string, DateType, int, string, string, string, string);
	void setRecord();
	void showRecord();
	void upDateRecord();

	void setDoctorType();
	void setSpecialization();
	void setJobLevel();
	string getSpecialization();

private:
	string Doctor_type;
	string Specialization;
	string Job_level;
};




class TeacherNode
{
	Teacher *obj;
	TeacherNode *next;
public:
	TeacherNode();
	Teacher* getObj();
	void setObj(Teacher*);
	TeacherNode* getNext();
	void setNext(TeacherNode*);
};

class DoctorNode
{
	Doctor *obj;
	DoctorNode *next;
public:
	DoctorNode();
	Doctor* getObj();
	void setObj(Doctor*);
	DoctorNode* getNext();
	void setNext(DoctorNode*);
};





class EmployeeList
{
public:
	EmployeeList();
	void AddNewDoctor();
	void AddNewTeacher();
	void updateEmployeeRecord();
	void SearchEmployeeByID();
	void SearchEmployeeByName();
	void SearchYoungestEmployee();
	void SearchEldestEmployee();
	void SearchDoctorBySpecialization();
	void SearchTeacherByTeachingLevel();
	void DeleteEmployeeByID();
	void DeleteEmployeeByName();
	
	void deleteFun(TeacherNode*, TeacherNode*);
	void deleteFun(DoctorNode*, DoctorNode*);

	TeacherNode* SearchTeacherById(int,TeacherNode*&);
	DoctorNode* SearchDoctorById(int,DoctorNode*&);
private:
	TeacherNode *Teacher_head;
	DoctorNode *Doctor_head;
};
