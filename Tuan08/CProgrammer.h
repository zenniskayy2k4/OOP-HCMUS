#pragma once
#include "CEmployee.h"
class CProgrammer : public CEmployee
{
protected:
	float m_Overtime = 0.0;
public:
	CProgrammer();
	CProgrammer(string, string, string, CMyDate, string, float, float);
	float getSalary() override;
	void Input(string&) override;
	void Output(ofstream&) override;
	CEmployee* Replicate() const {
		return new CProgrammer(*this);
	}
	void SetOvertime(float);
	float GetOvertime() const;
};