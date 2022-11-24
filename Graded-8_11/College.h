#pragma once

//1.
class College {
private:
	//a.
	//i.
	char Name;
	//ii.
	int Students;
	//iii.
	float Success_prc;

public:
	//b.
	//i. Non default constructor
	College(char name, int students, float successPrc);

	//ii. getters and setters
	char GetName();
	void SetName(char name);

	int GetStudents();
	void SetStudents(int students);

	float GetSuccess_prc();
	void SetSuccess_prc(float successPrc);

	//iii.
	void ReadData();

	//iv.
	void PrintInfo();

	//v.
	~College();
};