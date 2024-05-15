#pragma once
#include "CEmployee.h"
#include "CProgrammer.h"
#include "CTester.h"
#include "CDesigner.h"
#include "CManager.h"
class CCompany : public CEmployee
{
private:
	vector <CEmployee*> m_ListEmployees;
public:
	CCompany();
	CCompany(const CCompany&);
	~CCompany();
	void Input();
	void Output();
	double Salary();
	void Search();
	void SortYearOld();
};

