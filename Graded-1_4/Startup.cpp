#include "Startup.h"
#include <iostream>

using namespace std;

Startup::Startup() : Name('_'), TeamsNum(0), Budget(0)
{
	//initialize Teams array, dynamic array of type Team* of size 200
	Teams = new Team*[200];

	//zero out all pointers in Teams
	for (int i = 0; i < 200; i++)
	{
		Teams[i] = NULL;
	}

	cout << "Startup Constructor is called" << endl;
}

char Startup::GetName()
{
	return Name;
}

void Startup::SetName(char name)
{
	Name = name;
}

Team** Startup::GetTeams()
{
	return Teams;
}

void Startup::SetTeams(Team** teams)
{
	Teams = teams;
}

int Startup::GetTeamsNum()
{
	return TeamsNum;
}

void Startup::SetTeamsNum(int teamsNum)
{
	TeamsNum = teamsNum;
}

int Startup::GetBudget()
{
	return Budget;
}

void Startup::SetBudget(int budget)
{
	Budget = budget;
}

void Startup::AddSingleTeam()
{
	//read team info from user
	cout << "Enter Team information to be added" << endl;
	
	int code;
	cout << "Code: ";
	cin >> code;

	int income;
	cout << "Income: ";
	cin >> income;

	int budget;
	cout << "Budget: ";
	cin >> budget;

	//calculate total budget including the new team
	int totalBudget = budget;

	//200 is a large number to loop about
	//so add a counter to terminate the loop
	//when (numberOfNonNullElements == TeamsNum)

	//number of non null elements
	int c = 0;

	for (int i = 0; i < 200; i++)
	{
		if (Teams[i] != NULL)
		{
			totalBudget += Teams[i]->GetBudget();
			
			//increment number of non null elements
			c++;
		}

		//check if (numberOfNonNullElements == TeamsNum)
		if (c == TeamsNum)
		{
			//exit the loop, we have counted all departments
			break;
		}
	}

	//check if totalBudget is less than or equal to the startup budget
	if (totalBudget <= Budget)
	{
		//add to Teams
		//we add the element in the array of pointers
		//by looping about ALL the elements
		//and placing the element at the first NULL/empty index
		for (int i = 0; i < 200; i++)
		{
			if (Teams[i] == NULL)
			{
				//empty index found
				//place new team at this index
				Teams[i] = new Team(code, income, budget);

				//increment number of teams
				TeamsNum++;

				//exit the loop after adding the Team
				break;
			}
		}
	}
	else
	{
		//totalBudget is greater than the startup budget
		//display error message to user
		cout << "Budget is too high" << endl;
	}
}

void Startup::RemoveSingleTeam()
{
	//read team code from user
	int code;
	cout << "Enter code of team to remove: ";
	cin >> code;

	//search for team by code
	for (int i = 0; i < 200; i++)
	{
		//check if current element is not null and then compare its code with the one the user has input
		if (Teams[i] != NULL && Teams[i]->GetCode() == code)
		{
			//Team with matching code has been found
			//delete team pointer then zero out the location
			delete Teams[i];
			Teams[i] = NULL;

			//decrement Num (team count)
			TeamsNum--;

			//print a descriptive message saying that the team has been removed
			cout << "Team has been found and removed" << endl;

			//exit the function, the team has been removed
			return;
		}
	}

	//this part will only be reached if the team has not been found
	//print a descriptive message saying that the team hasnt been found
	cout << "Team was not found" << endl;
}

int Startup::GetProfit()
{
	//calculate profit of all teams
	int totalProfit = 0;

	//200 is a large number to loop about
	//so add a counter to terminate the loop
	//when (numberOfNonNullElements == TeamsNum)

	//number of non null elements
	int c = 0;

	for (int i = 0; i < 200; i++)
	{
		if (Teams[i] != NULL)
		{
			totalProfit += Teams[i]->GetProfit();

			//increment nonNullElements
			c++;

			//check if (numberOfNonNullElements == TeamsNum)
			if (c == TeamsNum)
			{
				//exit the loop, we have counted all departments
				break;
			}
		}
	}

	return totalProfit;
}

void Startup::PrintInfo()
{
	cout << "Name: " << Name
		<< "\nTeamsNum: " << TeamsNum
		<< "\nBudget: " << Budget
		<< "\nTeams:"
		<< endl;

	//print information of teams
	//we can still add the counter to terminate the loop when (numberOfNonNullElements == TeamsNum)
	//to be more efficient
	for (int i = 0; i < 200; i++)
	{
		if (Teams[i] != NULL)
		{
			Teams[i]->PrintInfo();
		}
	}
}

Startup::~Startup()
{
	//delete all Team pointers
	for (int i = 0; i < 200; i++)
	{
		if (Teams[i] != NULL)
		{
			delete Teams[i];
		}
	}

	//delete array of pointers itself
	delete[] Teams;

	cout << "Startup Destructor is called" << endl;
}
