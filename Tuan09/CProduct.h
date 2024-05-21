#pragma once
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
#include "CMyDate.h"
class CProduct
{
protected:
	string m_Code;
	string m_Name;
	string m_Producer;
	int m_Price;
	int m_Amount;
public:
	CProduct();
	CProduct(string, string, string, int, int);
	string getCode();
	string getName();
	string getProducer();
	int getPrice();
	int getAmount();
	void setAmount(int);
	virtual void Input(string&, vector<string>&);
	virtual void Output(ofstream&);
	virtual CProduct* Replicate() const;
};

