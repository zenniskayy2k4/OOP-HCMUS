#pragma once
#include "CCauThu.h"
#include <iostream>
class CDoiBong {
private:
	int m_Amount;
	vector <CCauThu> m_DoiBong;
public:
	void Input();
	CCauThu oldestFootballer();
	void Output(const string&);
	void IncreasingSquadNumber(const string&);
};

