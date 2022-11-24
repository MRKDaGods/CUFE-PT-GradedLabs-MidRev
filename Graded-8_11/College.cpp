#include "College.h"

#include <iostream>

using namespace std;

College::College(char name, int students, float successPrc) : Name(name), Students(students), Success_prc(successPrc)
{
	cout << "College Constructor is called" << endl;
}

char College::GetName()
{
	return Name;
}

void College::SetName(char name)
{
	Name = name;
}

int College::GetStudents()
{
	return Students;
}

void College::SetStudents(int students)
{
	Students = students;
}

float College::GetSuccess_prc()
{
	return Success_prc;
}

void College::SetSuccess_prc(float successPrc)
{
	Success_prc = successPrc;
}

void College::ReadData()
{
	cout << "Name: ";
	cin >> Name;

	cout << "Students: ";
	cin >> Students;

	cout << "Success_prc: ";
	cin >> Success_prc;
}

void College::PrintInfo()
{
	cout << "Name: " << Name
		<< "\nStudents: " << Students
		<< "\nSuccess_prc: " << Success_prc
		<< endl;
}

College::~College()
{
	cout << "College Destructor is called" << endl;
}
