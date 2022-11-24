#include <iostream>

#include "Company.h"

using namespace std;

//3.
void PrintHighest(Company** comps, int len)
{
	Company* highestComp = NULL;
	float maxAvgIncome = -1.0f;

	for (int i = 0; i < len; i++)
	{
		//store in a variable to prevent computing AverageIncome twice
		float currentAvgIncome = comps[i]->CalcAverageIncome();
		if (currentAvgIncome > maxAvgIncome)
		{
			maxAvgIncome = currentAvgIncome;
			highestComp = comps[i];
		}
	}

	cout << "Company with highest AverageIncome:" << endl;

	//print info of highest company
	highestComp->PrintInfo();
}

//4.
int main()
{
	//a.
	Company C1;

	//b.
	Company* PC2 = new Company;

	//c.
	Company* PC3 = new Company;

	//d.
	//add 2 departments to C1
	for (int i = 0; i < 2; i++)
	{
		C1.AddOneDepartment();
	}

	//add 3 departments to PC2
	for (int i = 0; i < 3; i++)
	{
		PC2->AddOneDepartment();
	}

	//add 2 departments to PC3
	for (int i = 0; i < 2; i++)
	{
		PC3->AddOneDepartment();
	}

	//e.
	//remove 2 departments from PC2
	for (int i = 0; i < 2; i++)
	{
		//depRemoved is TRUE if department has been found and removed
		bool depRemoved = PC2->RemoveOneDepartment();

		//print descriptive message
		if (depRemoved)
		{
			cout << "Department was found and has been removed" << endl;
		}
		else
		{
			cout << "Department was not found" << endl;
		}
	}

	//f.
	//print best department of C1
	cout << "Best Department of C1: " << endl;
	C1.PrintBestDepartment();

	//print best department of PC2
	cout << "Best Department of PC2: " << endl;
	PC2->PrintBestDepartment();

	//g.
	//automatic array of length 3 of type Company*
	//add C1, PC2 and PC3 to array
	Company* comps[3] = {
		&C1,
		PC2,
		PC3
	};

	//h.
	//call PrintHighest
	PrintHighest(comps, 3);

	//delete dynamically allocated companies
	delete PC2;
	delete PC3;

	system("pause");
	return 0;
}