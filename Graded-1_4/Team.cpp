#include "Team.h"

#include <iostream>

using namespace std;

Team::Team(int code, int income, int budget) : Code(code), Income(income), Budget(budget)
{
	cout << "Team Constructor is called" << endl;
}

int Team::GetCode()
{
	return Code;
}

int Team::GetIncome()
{
	return Income;
}

int Team::GetBudget()
{
	return Budget;
}

int Team::GetProfit()
{
	return Income - Budget;
}

void Team::PrintInfo()
{
	cout << "Code: " << Code
		<< "\nIncome: " << Income
		<< "\nBudget: " << Budget
		<< endl;
}

Team::~Team()
{
	cout << "Team Destructor is called" << endl;
}
