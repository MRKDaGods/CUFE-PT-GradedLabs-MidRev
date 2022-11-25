#pragma once

#include "Team.h"

//2.
class Startup
{
private:
	//a.
	//i.
	char Name;
	//ii.
	Team** Teams;
	//iii.
	int TeamsNum;
	//iv.
	int Budget;

public:
	//b.
	//i.
	Startup();

	//ii.
	char GetName();
	void SetName(char name);

	Team** GetTeams();
	void SetTeams(Team** teams);

	int GetTeamsNum();
	void SetTeamsNum(int teamsNum);

	int GetBudget();
	void SetBudget(int budget);

	//iii.
	void AddSingleTeam();

	//iv.
	void RemoveSingleTeam();

	//v.
	int GetProfit();

	//vi.
	void PrintInfo();

	//vii.
	~Startup();
};

