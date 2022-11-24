#include "University.h"

#include <iostream>

using namespace std;

University::University()
{
	//initialize Clgs with an array of 15 pointers
	Clgs = new College*[15];

	//zero out all pointers
	for (int i = 0; i < 15; i++)
	{
		Clgs[i] = NULL;
	}

	//set num to 0 by default
	Num = 0;

	cout << "University Contructor is called" << endl;
}

void University::AddOneCollege()
{
	//0.0f, f indicates float
	College* c = new College('_', 0, 0.0f); //initialize college with dummy arguments
	
	//read data from user
	c->ReadData();

	//check if it exists
	bool found = false;
	for (int i = 0; i < 15; i++)
	{
		//check if current element is not null
		//then access it and compare its name to the name that the user entered
		if (Clgs[i] != NULL && Clgs[i]->GetName() == c->GetName())
		{
			//mark the college found before
			found = true;

			//break as there is no point in continuing the loop
			break;
		}
	}

	//check if the college has been found or not
	if (found)
	{
		//college has been found
		//do not add new college to Clgs
		//delete "c" as there is no use of it
		delete c;
	}
	else
	{
		//college has not been found
		//add to Clgs

		//we add the element in the array of pointers
		//by looping about ALL the elements
		//and placing the element at the first NULL/empty index
		for (int i = 0; i < 15; i++)
		{
			//check if place is null
			if (Clgs[i] == NULL)
			{
				//empty place found
				//place object at this index
				Clgs[i] = c;

				//increment Num
				Num++;

				//exit the loop after adding the college
				break;
			}
		}
	}
}

bool University::RemoveCollege()
{
	cout << "Name of college to remove: ";

	//read name from user
	char name;
	cin >> name;

	//search for college by name
	for (int i = 0; i < 15; i++)
	{
		//check if current element is not null and then compare its name with the one the user has input
		if (Clgs[i] != NULL && Clgs[i]->GetName() == name)
		{
			//college with matching name has been found
			//delete college pointer then zero out the location
			delete Clgs[i];
			Clgs[i] = NULL;

			//decrement Num (college count)
			Num--;

			//college has been removed, return true
			return true;
		}
	}

	return false;
}

float University::CalcAverageSuccess()
{
	//average = success rate sum / college count
	float successRate = 0.0f;
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL)
		{
			successRate += Clgs[i]->GetSuccess_prc();
		}
	}

	return successRate / Num;
}

void University::PrintBestCollege()
{
	//find college with maximum Success_prc
	College* highestCollege = NULL;
	float maxSuccessPrc = -1.0f;

	//get max Success_prc
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL && Clgs[i]->GetSuccess_prc() > maxSuccessPrc)
		{
			maxSuccessPrc = Clgs[i]->GetSuccess_prc();
			highestCollege = Clgs[i];
		}
	}

	//print info of highest college
	highestCollege->PrintInfo();
}

void University::PrintInfo()
{
	//print info of University
	cout << "College Count: " << Num << endl;

	//print info of each college
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL)
		{
			Clgs[i]->PrintInfo();
		}
	}
}

University::~University()
{
	//delete all College pointers
	for (int i = 0; i < 15; i++)
	{
		if (Clgs[i] != NULL)
		{
			delete Clgs[i];
		}
	}

	//delete array of pointers itself
	delete[] Clgs;

	cout << "University Destructor is called" << endl;
}
