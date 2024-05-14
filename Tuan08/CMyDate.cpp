#include "CMyDate.h"
#define _CRT_SECURE_NO_WARNINGS
CMyDate::CMyDate(int _day, int _month, int _year) {
	m_Day = _day;
	m_Year = _year;
	m_Month = _month;
}
void CMyDate::Input(const string& date) {
	stringstream ss(date);
	char delimiter;
	ss >> m_Day >> delimiter >> m_Month >> delimiter >> m_Year;
}
void CMyDate::Output(ofstream& outFile) const {
	outFile << setfill('0') << setw(2) << m_Day << "/"
		<< setw(2) << m_Month << "/" << m_Year;
}
bool CMyDate::operator<(const CMyDate& other) const {
	if (m_Year != other.m_Year) {
		return m_Year < other.m_Year;
	}
	if (m_Month != other.m_Month) {
		return m_Month < other.m_Month;
	}
	return m_Day < other.m_Day;
}

CMyDate CMyDate::getFullDate() const {
	return CMyDate(m_Day, m_Month, m_Year);
}
int CMyDate::GetCurrentYear() {
	time_t now = time(0);
	tm localtm;
	localtime_s(&localtm, &now); // Note: localtime_s is safer than localtime
	int year = 1900 + localtm.tm_year;
	return year;
}
