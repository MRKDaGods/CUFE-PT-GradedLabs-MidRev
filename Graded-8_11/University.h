#pragma once

#include "College.h"

//2.
class University
{
private:
	//a.
	//i.
	College** Clgs;
	//ii.
	int Num;

public:
	//b.
	//i.
	University();

	//ii.
	void AddOneCollege();

	//iii.
	bool RemoveCollege();

	//iv.
	float CalcAverageSuccess();

	//v.
	void PrintBestCollege();

	//vi.
	void PrintInfo();

	//vii.
	~University();
};