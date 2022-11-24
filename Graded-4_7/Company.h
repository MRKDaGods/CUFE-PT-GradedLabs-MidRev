#pragma once

#include "Department.h"

//2.
class Company
{
private:
	//a.
	//i.
	Department** Deps;
	//ii.
	int Num;

public:
	//b.
	//i.
	Company();

	//ii.
	void AddOneDepartment();

	//iii.
	bool RemoveOneDepartment();

	//iv.
	float CalcAverageIncome();

	//v.
	void PrintBestDepartment();

	//vi.
	void PrintInfo();

	//vii.
	~Company();
};

