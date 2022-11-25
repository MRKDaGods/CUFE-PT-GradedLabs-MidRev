#include <iostream>

#include "Startup.h"

using namespace std;

//3.
void PrintBestStartup(Startup** startups, int len)
{
	Startup* highestStartup = NULL;
	float maxAvgProfit = -INFINITY; //initialize to negative infinity because some profits might be negative

	for (int i = 0; i < len; i++)
	{
		//store in a variable to prevent computing average profit twice
		float avgProfit = startups[i]->GetProfit() / (float)startups[i]->GetTeamsNum();
		if (avgProfit > maxAvgProfit)
		{
			maxAvgProfit = avgProfit;
			highestStartup = startups[i];
		}
	}

	cout << "Startup with highest Average Profit:" << endl;

	//print info of highest startup
	highestStartup->PrintInfo();
}

//4.
int main()
{
	//a.
	Startup S1;

	//b.
	Startup* PS2 = new Startup;

	//c.
	Startup* PS3 = new Startup;

	//d.
	//enter data for startups
	for (int i = 0; i < 3; i++)
	{
		cout << "Details of Startup (" << i + 1 << ")" << endl;

		char name;
		cout << "Name: ";
		cin >> name;

		int budget;
		cout << "Budget: ";
		cin >> budget;

		// 0 - S1
		// 1 - PS2
		// 2 - PS3

		//set data to respective startup
		switch (i)
		{
		case 0: //when i == 0, set data of S1
			S1.SetName(name);
			S1.SetBudget(budget);
			break;

		case 1: //when i == 1, set data of PS2
			PS2->SetName(name);
			PS2->SetBudget(budget);
			break;

		case 2: //when i == 2, set data of PS3
			PS3->SetName(name);
			PS3->SetBudget(budget);
			break;
		}
	}

	//e.
	//add 2 teams to S1
	for (int i = 0; i < 2; i++)
	{
		S1.AddSingleTeam();
	}

	//add 2 teams to PS2
	for (int i = 0; i < 2; i++)
	{
		PS2->AddSingleTeam();
	}

	//add 2 teams to PS3
	for (int i = 0; i < 2; i++)
	{
		PS3->AddSingleTeam();
	}

	//f.
	cout << "Add a team to PS2 with a high budget so that totalBudget > PS2's budget: " << endl;
	//add team that violates the budget
	PS2->AddSingleTeam();
	//AddSingleTeam prints the descriptive message saying that the budget is too high

	//set new budget for PS2 so that the teams gets added without violating the budget
	int newBudget;
	cout << "Enter PS2's new budget: ";
	cin >> newBudget;

	//set budget of PS2
	PS2->SetBudget(newBudget);

	//add team again after setting the budget
	PS2->AddSingleTeam();

	//print PS2's info after adding the new team (descriptive message)
	PS2->PrintInfo();

	//g.
	//remove 2 teams from PS2
	for (int i = 0; i < 2; i++)
	{
		PS2->RemoveSingleTeam();
	}

	//h.
	//print profit of S1 and PS2
	cout << "Profit of S1: " << S1.GetProfit() << endl;
	cout << "Profit of PS2: " << PS2->GetProfit() << endl;

	//i.
	//automatic array of length 3 of type Startup*
	//add S1, PS2 and PS3 to array
	Startup* startups[3] = {
		&S1, PS2, PS3
	};

	//j.
	//call PrintBestStartup using 'startups'
	PrintBestStartup(startups, 3);

	//delete dynamically allocated startups
	delete PS2;
	delete PS3;

	system("pause");
	return 0;
}