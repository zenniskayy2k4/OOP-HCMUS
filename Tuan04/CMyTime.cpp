#include "CMyTime.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;
CMyTime::CMyTime() :m_Hour(0), m_Minute(0), m_Second(0) {}

CMyTime::CMyTime(int hour, int minute, int second) : m_Hour(hour), m_Minute(minute), m_Second(second) {}

CMyTime::CMyTime(const CMyTime& other) {
	m_Hour = other.m_Hour;
	m_Minute = other.m_Minute;
	m_Second = other.m_Second;
}
CMyTime::~CMyTime() { }

string CMyTime::SetValidTime(const CMyTime& time) const {
	stringstream correctFormat;
	correctFormat << setfill('0') << setw(2) << time.m_Hour << ":" << setw(2) << time.m_Minute << ":" << setw(2) << time.m_Second;
	return correctFormat.str();
}
void CMyTime::Input() {
	ifstream inputFile("INPUT.txt", ios::in);
	if (inputFile.is_open()) {
		inputFile >> m_Hour >> m_Minute >> m_Second;
		inputFile.close();
	}
}
void CMyTime::Output() {
	CMyTime time(*this);
	ofstream outputFile("OUTPUT.txt", ios::trunc);
	if (outputFile.is_open()) {
		cout << "The input time has been written to the output file.\n All data will be written to the output file.\n";
		outputFile << "Input time: " << SetValidTime(time) << endl << endl;

		++time;
		outputFile << "After increasing by 1 second: " << SetValidTime(time) << endl << endl;

		time = *this;
		--time;
		outputFile << "After decreasing by 1 minute: " << SetValidTime(time) << endl << endl;

		time = *this;
		int n_hours_increment; cout << "Enter the number of hours you want to increment by: "; cin >> n_hours_increment;
		time += n_hours_increment;
		outputFile << "After increasing by " << n_hours_increment << " hour(s): " << SetValidTime(time) << endl << endl;

		time = *this;
		int n_hours_decrement; cout << "Enter the number of hours you want to decrement by: "; cin >> n_hours_decrement;
		time -= n_hours_decrement;
		outputFile << "After decreasing by " << n_hours_decrement << " hour(s): " << SetValidTime(time) << endl << endl;

		CMyTime anotherTime;
		cout << "Please enter another time.\n";
		cout << "Another hour: "; cin >> anotherTime.m_Hour;
		cout << "Another minute: "; cin >> anotherTime.m_Minute;
		cout << "Another second: "; cin >> anotherTime.m_Second;

		outputFile << "Another time: " << SetValidTime(anotherTime) << endl << endl;
		
		time = *this;
		CMyTime sum = time + anotherTime;
		outputFile << "Sum of both times: " << SetValidTime(sum) << endl << endl;

		CMyTime difference = anotherTime - time;
		outputFile << "Difference of both times: " << SetValidTime(difference) << endl << endl;

		outputFile << "Is current time [" << SetValidTime(time) <<
			"] greater than [" << SetValidTime(anotherTime) << "]? => " << (time > anotherTime ? "Yes\n\n" : "No\n\n");

		outputFile << "Is current time [" << SetValidTime(time) <<
			"] less than [" << SetValidTime(anotherTime) << "]? => " << (time < anotherTime ? "Yes\n\n" : "No\n\n");

		outputFile << "Is current time [" << SetValidTime(time) <<
			"] greater than or equal to [" << SetValidTime(anotherTime) << "]? => "	<< (time >= anotherTime ? "Yes\n\n" : "No\n\n");

		outputFile << "Is current time [" << SetValidTime(time) <<
			"] less than or equal to [" << SetValidTime(anotherTime) << "]? => " << (time <= anotherTime ? "Yes\n\n" : "No\n\n");

		outputFile << "Is current time [" << SetValidTime(time) << "] equal to [" << SetValidTime(anotherTime) << "]? => " 
			<< (time == anotherTime ? "Yes" : "No");
		outputFile.close();
	}
	else {
		cout << "Unable to open file!\n";
	}
	
}

void CMyTime::operator++() {
	m_Second++;
	if (m_Second >= 60) {
		m_Second -= 60;
		m_Minute++;
		if (m_Minute >= 60) {
			m_Minute -= 60;
			m_Hour = (m_Hour + 1) % 24;
		}
	}
}
void CMyTime::operator--() {
	if (m_Minute > 0)
		m_Minute--;
	else {
		m_Minute = 59;
		if (m_Hour > 0) m_Hour--;
		else m_Hour = 23;
	}
}
void CMyTime::operator+=(int hours) {
	m_Hour = (m_Hour + hours) % 24;
}
void CMyTime::operator-=(int hours) {
	m_Hour = (m_Hour - hours + 24) % 24;
}
CMyTime CMyTime::operator+(const CMyTime& other) const {
	CMyTime result(*this);
	result.m_Second += other.m_Second;
	result.m_Minute += other.m_Minute;
	result.m_Hour += other.m_Hour;

	if (result.m_Second >= 60) {
		result.m_Second -= 60;
		result.m_Minute++;
	}
	if (result.m_Minute >= 60) {
		result.m_Minute -= 60;
		result.m_Hour++;
	}
	if (result.m_Hour >= 24) {
		result.m_Hour -= 24;
	}
	return result;
}
CMyTime CMyTime::operator-(const CMyTime& other) const {
	int total_seconds = m_Hour * 3600 + m_Minute * 60 + m_Second;
	int other_total_seconds = other.m_Hour * 3600 + other.m_Minute * 60 + other.m_Second;

	int diff_seconds = total_seconds - other_total_seconds;
	if (diff_seconds < 0)
		diff_seconds += 24 * 3600;

	CMyTime result(*this);
	result.m_Hour = diff_seconds / 3600;
	result.m_Minute = (diff_seconds % 3600) / 60;
	result.m_Second = (diff_seconds % 3600) % 60;

	return result;
}

bool CMyTime::operator>(const CMyTime& other) const {
	if (m_Hour > other.m_Hour) {
		return true;
	}
	else if (m_Hour == other.m_Hour && m_Minute > other.m_Minute) {
		return true;
	}
	else if (m_Hour == other.m_Hour && m_Minute == other.m_Minute && m_Second > other.m_Second) {
		return true;
	}
	return false;
}
bool CMyTime::operator<(const CMyTime& other) const {
	return !(*this > other || *this == other);
}
bool CMyTime::operator>=(const CMyTime& other) const {
	return !(*this < other);
}
bool CMyTime::operator<=(const CMyTime& other) const {
	return !(*this > other);
}
bool CMyTime::operator==(const CMyTime& other) const {
	return m_Hour == other.m_Hour &&
		m_Minute == other.m_Minute &&
		m_Second == other.m_Second;
}