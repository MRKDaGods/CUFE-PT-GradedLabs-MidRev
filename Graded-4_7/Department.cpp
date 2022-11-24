#include "Department.h"

#include <iostream>

using namespace std;

Department::Department() : Name('_'), Code(-1), Income(0.0f)
{
	cout << "Department Constructor is called" << endl;
}

char Department::GetName()
{
	return Name;
}

void Department::SetName(char name)
{
	Name = name;
}

int Department::GetCode()
{
	return Code;
}

void Department::SetCode(int code)
{
	Code = code;
}

float Department::GetIncome()
{
	return Income;
}

void Department::SetIncome(float income)
{
	Income = income;
}

void Department::ReadData()
{
	cout << "Name: ";
	cin >> Name;

	cout << "Code: ";
	cin >> Code;

	cout << "Income: ";
	cin >> Income;
}

void Department::PrintInfo()
{
	cout << "Name: " << Name
		<< "\nCode: " << Code
		<< "\nIncome: " << Income
		<< endl;
}

Department::~Department()
{
	cout << "Department Destructor is called" << endl;
}
