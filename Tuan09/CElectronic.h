#pragma once
#include "CProduct.h"
class CElectronic : public CProduct
{
protected:
	string m_Warranty;
	int m_ElectricPower = 0;
public:
	CElectronic();
	CElectronic(string, string, string, int, int, string, int);
	string getWarranty();
	int getElectricPower();
	void Input(string&, vector<string>&) override;
	void Output(ofstream&) override;
	CProduct* Replicate() const {
		return new CElectronic(*this);
	}
};

