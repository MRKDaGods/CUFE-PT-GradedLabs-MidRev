#include "Company.h"

#include <iostream>

using namespace std;

Company::Company()
{
	//initialize Deps with an array of 300 pointers
	Deps = new Department*[300];
	
	//zero out all pointers
	for (int i = 0; i < 300; i++)
	{
		Deps[i] = NULL;
	}

	//set num to 0 by default
	Num = 0;

	cout << "Company Constructor is called" << endl;
}

void Company::AddOneDepartment()
{
	//create new department
	Department* d = new Department();

	//read data from user
	d->ReadData();

	//there are no restrictions to addition of departments
	//add department right away

	//add to Deps
	//we add the element in the array of pointers
	//by looping about ALL the elements
	//and placing the element at the first NULL/empty index
	for (int i = 0; i < 300; i++)
	{
		//check if place is null
		if (Deps[i] == NULL)
		{
			//empty place found
			//place object at this index
			Deps[i] = d;

			//increment Num
			Num++;

			//exit the loop after adding the department
			break;
		}
	}
}

bool Company::RemoveOneDepartment()
{
	cout << "Code of department to remove: ";

	//read code from user
	int code;
	cin >> code;

	//search for department by code
	for (int i = 0; i < 300; i++)
	{
		//check if current element is not null and then compare its code with the one the user has input
		if (Deps[i] != NULL && Deps[i]->GetCode() == code)
		{
			//department with matching code has been found
			//delete department pointer then zero out the location
			delete Deps[i];
			Deps[i] = NULL;

			//decrement Num (department count)
			Num--;

			//department has been removed, return true
			return true;
		}
	}

	return false;
}

float Company::CalcAverageIncome()
{
	//average = income sum / department count
	float incomeSum = 0.0f;

	//300 is a large number to loop about
	//so add a counter to terminate the loop
	//when (numberOfNonNullElements == Num)

	//number of non null elements
	int c = 0;

	for (int i = 0; i < 300; i++)
	{
		if (Deps[i] != NULL)
		{
			incomeSum += Deps[i]->GetIncome();

			//increment number of non null elements
			c++;

			//check if (numberOfNonNullElements == Num)
			if (c == Num)
			{
				//exit the loop, we have counted all departments
				break;
			}
		}
	}

	return incomeSum / Num;
}

void Company::PrintBestDepartment()
{
	//find department with maximum income
	Department* highestDepartment = NULL;
	float maxIncome = -1.0f;

	//get max Income

	//300 is a large number to loop about
	//so add a counter to terminate the loop
	//when (numberOfNonNullElements == Num)

	//number of non null elements
	int c = 0;

	for (int i = 0; i < 300; i++)
	{
		if (Deps[i] != NULL)
		{
			//break down the if checks as to count the number of elements
			if (Deps[i]->GetIncome() > maxIncome)
			{
				maxIncome = Deps[i]->GetIncome();
				highestDepartment = Deps[i];
			}

			//increment number of non null elements
			c++;

			//check if (numberOfNonNullElements == Num)
			if (c == Num)
			{
				//exit the loop, we have counted all departments
				break;
			}
		}
	}

	//print info of highest department
	highestDepartment->PrintInfo();
}

void Company::PrintInfo()
{
	//print info of Company
	cout << "Department Count: " << Num << endl;

	//print info of each department
	//we can still add the counter to terminate the loop when (numberOfNonNullElements == Num)
	//to be more efficient "bs ana mksl" ~seif tamer
	for (int i = 0; i < 300; i++)
	{
		if (Deps[i] != NULL)
		{
			Deps[i]->PrintInfo();
		}
	}
}

Company::~Company()
{
	//delete all Department pointers
	for (int i = 0; i < 300; i++)
	{
		if (Deps[i] != NULL)
		{
			delete Deps[i];
		}
	}

	//delete array of pointers itself
	delete[] Deps;

	cout << "Company Destructor is called" << endl;
}
