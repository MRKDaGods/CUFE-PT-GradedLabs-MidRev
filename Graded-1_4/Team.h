#pragma once

//1.
class Team
{
private:
	//a.
	//i.
	int Code;
	//ii.
	int Income;
	//iii.
	int Budget;

public:
	//b.
	//i.
	Team(int code, int income, int budget);

	//ii.
	int GetCode();
	int GetIncome();
	int GetBudget();

	//iii.
	int GetProfit();

	//iv.
	void PrintInfo();

	//v.
	~Team();
};