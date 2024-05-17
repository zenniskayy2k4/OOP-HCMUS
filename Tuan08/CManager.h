#pragma once
#include "CEmployee.h"
class CManager: public CEmployee
{
public:
	CManager();
	CManager(string, string, string, CMyDate, string, float, float);
	float getSalary() override;
	void Input(string&) override;
	void Output(ofstream&) override;
	CEmployee* Replicate() const {
		return new CManager(*this);
	}
};