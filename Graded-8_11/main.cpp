#include <iostream>

#include "University.h"

using namespace std;

//3.
void PrintHighest(University** unis, int len)
{
	University* highestUni = NULL;
	float maxAvgSuccess = -1.0f;

	for (int i = 0; i < len; i++)
	{
		//store in a variable to prevent computing AverageSuccess twice
		float currentAvgSuccess = unis[i]->CalcAverageSuccess();
		if (currentAvgSuccess > maxAvgSuccess)
		{
			maxAvgSuccess = currentAvgSuccess;
			highestUni = unis[i];
		}
	}

	cout << "College with highest AverageSuccessRate:" << endl;

	//print info of highest Uni
	highestUni->PrintInfo();
}

//4.
int main()
{
	//a.
	University U1;

	//b.
	University* PU2 = new University;

	//c.
	University* PU3 = new University;

	//d.
	//add 2 unis to U1
	for (int i = 0; i < 2; i++)
	{
		U1.AddOneCollege();
	}

	//add 3 unis to PU2
	for (int i = 0; i < 3; i++)
	{
		PU2->AddOneCollege();
	}

	//add 2 unis to PU3
	for (int i = 0; i < 3; i++)
	{
		PU3->AddOneCollege();
	}

	//e.
	//remove 2 colleges from PU2
	for (int i = 0; i < 2; i++)
	{
		//collegeRemoved is TRUE if college has been found and removed
		bool collegeRemoved = PU2->RemoveCollege();

		//print descriptive message
		if (collegeRemoved)
		{
			cout << "College was found and has been removed" << endl;
		}
		else
		{
			cout << "College was not found" << endl;
		}
	}

	//f.
	//print best college of U1
	cout << "Best College of U1: " << endl;
	U1.PrintBestCollege();

	//print best college of PU2
	cout << "Best College of PU2: " << endl;
	PU2->PrintBestCollege();

	//g.
	//automatic array of length 3 of type University*
	//add U1, PU2 and PU3 to array
	University* unis[3] = {
		&U1,
		PU2,
		PU3
	};

	//h.
	//call PrintHighest
	PrintHighest(unis, 3);

	//delete dynamically allocated universities
	delete PU2;
	delete PU3;

	system("pause");
	return 0;
}