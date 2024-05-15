#pragma once
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
#include <locale>
#include <codecvt>
#include "CMyDate.h"
class CEmployee : public CMyDate
{
protected:
	string m_ID;
	string m_Department;
	string m_Name;
	CMyDate m_Birthday;
	string m_Address;
	float m_WageCoefficient;
	float m_basicWage = 0.0;

public:
	CEmployee();
	CEmployee(string, string, string, CMyDate, string, float);
	virtual float getSalary();
	CMyDate getDOB();
	string getID();
	string getName();
	string getAddress();
	string getDepartment();
	void setBasicWage(float);
	virtual void Input(string&);
	virtual void Output(ofstream&);
	virtual CEmployee* Replicate() const;
	void OutputSortYearOld(ofstream&);
	int CalculateAge();
	int getYearofDOB();
};

