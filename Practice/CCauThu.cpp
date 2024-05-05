#include "CCauThu.h"
void CDate::Input(const string& date) {
	stringstream ss(date);
	char delimiter;
	ss >> m_Day >> delimiter >> m_Month >> delimiter >> m_Year;
}
void CDate::Output(ofstream& outFile) const {
	outFile << setfill('0') << setw(2) << m_Day << "/"
		<< setw(2) << m_Month << "/" << m_Year;
}
CDate::CDate(int year, int month, int day) : m_Year(year), m_Month(month), m_Day(day) {}
CDate CDate::getFullDate() const {
	return CDate(m_Day, m_Month, m_Year);
}
bool CDate::operator<(const CDate& other) const {
	if (m_Year != other.m_Year) {
		return m_Year < other.m_Year;
	}
	if (m_Month != other.m_Month) {
		return m_Month < other.m_Month;
	}
	return m_Day < other.m_Day;
}
CDate CCauThu::getFullDate() const {
	return m_DOB.getFullDate();
}

void CCauThu::Input(ifstream& inFile) {
	string input; getline(inFile, input);
	std::stringstream ss(input);
	std::string token;
	std::vector<std::string> tokens;

	while (std::getline(ss, token, '-')) {
		token.erase(0, token.find_first_not_of(" "));
		token.erase(token.find_last_not_of(" ") + 1);
		tokens.push_back(token);
	}
	m_Name = tokens[0];
	m_Position = tokens[1];
	m_DOB.Input(tokens[2]);
	m_SquadNumber = stoi(tokens[3]);
}
void CCauThu::Output(ofstream& outFile) {
	outFile << m_Name << " - " << m_Position << " - "; m_DOB.Output(outFile);
	outFile << " - " << m_SquadNumber;
}