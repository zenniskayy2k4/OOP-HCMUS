#pragma once
#include "CEmployee.h"
class CTester : public CEmployee
{
protected:
	int m_Errors = 0;
public:
	CTester();
	CTester(string, string, string, CMyDate, string, float);
	float getSalary() override;
	void Input(string&) override;
	void Output(ofstream&) override;
	CEmployee* Replicate() const {
		return new CTester(*this);
	}
	void SetErrors(int);
	int GetErrors() const;
};