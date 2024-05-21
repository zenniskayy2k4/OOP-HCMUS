#pragma once
#include "CProduct.h"
class CFood : public CProduct
{
protected:
	CMyDate m_MfgDate;
	CMyDate m_ExpDate;
public:
	CFood();
	CFood(string, string, string, int, int, CMyDate, CMyDate);
	CMyDate getMfgDate();
	CMyDate getExpDate();
	void Input(string&, vector<string>&) override;
	void Output(ofstream&) override;
	CProduct* Replicate() const {
		return new CFood(*this);
	}
};

