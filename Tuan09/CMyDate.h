#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <ctime>

using namespace std;
class CMyDate {
public:
	int m_Year;
	int m_Month;
	int m_Day;

	CMyDate() : m_Year(0), m_Month(0), m_Day(0) {}
	CMyDate(int, int, int);
	void Input(const string&);
	void Output(ofstream&) const;
	bool operator<(const CMyDate&) const;
	CMyDate getFullDate() const;
	int GetCurrentYear();
};
