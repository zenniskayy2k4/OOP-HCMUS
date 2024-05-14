#pragma once
#include "CEmployee.h"
class CDesigner : public CEmployee
{
protected:
	float m_Bonus = 0.0;
public:
	CDesigner();
	CDesigner(string, string, string, CMyDate, string, float);
	float getSalary() override;
	void Input(string&) override;
	void Output(ofstream&) override;
	CEmployee* Replicate() const {
		return new CDesigner(*this);
	}
	void SetBonus(float);
	float GetBonus() const;
};