#pragma once

//1.
class Department
{
private:
	//a.
	//i.
	char Name;
	//ii.
	int Code;
	//iii.
	float Income;

public:
	//b.
	//i.
	Department();

	//ii.
	char GetName();
	void SetName(char name);

	int GetCode();
	void SetCode(int code);

	float GetIncome();
	void SetIncome(float income);

	//iii.
	void ReadData();

	//iv.
	void PrintInfo();

	//v.
	~Department();
};