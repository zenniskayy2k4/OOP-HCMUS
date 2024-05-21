#pragma once
#include "CProduct.h"
class CTerracotta : public CProduct
{
protected:
	string m_Material;
public:
	CTerracotta();
	CTerracotta(string, string, string, int, int, string);
	string getMaterial();
	void Input(string&, vector<string>&) override;
	void Output(ofstream&) override;
	CProduct* Replicate() const {
		return new CTerracotta(*this);
	}
};

