#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;
class CDate {
public:
	int m_Year;
	int m_Month;
	int m_Day;

	CDate() : m_Year(0), m_Month(0), m_Day(0) {}
	CDate(int, int, int);
	void Input(const string&);
	void Output(ofstream&) const;
	bool operator>(const CDate&) const;
	CDate getFullDate() const;
};
class CCauThu
{
private:
	string m_Name;
	CDate m_DOB;
	string m_Position;
	int m_SquadNumber;
public:
	void Input(ifstream&);
	void Output(ofstream&);
	CDate getFullDate() const;
	int GetSquadNumber() const { return m_SquadNumber; }
};