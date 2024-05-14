#include "CEmployee.h"
CEmployee::CEmployee() :m_ID(""), m_Department(""), m_Name(""), m_Birthday(CMyDate(01,01,1900)), m_Address(""), m_WageCoefficient(1.0) {}
CEmployee::CEmployee(string id, string department, string name, CMyDate dob, string address, float wageCoef)
	: m_ID(id), m_Department(department), m_Name(name), m_Birthday(dob), m_Address(address), m_WageCoefficient(wageCoef){}
CEmployee* CEmployee::Replicate() const {
	return new CEmployee(*this);
}
string CEmployee::getID() {
	return m_ID;
}
CMyDate CEmployee::getDOB() {
	return m_Birthday.getFullDate();
}
string CEmployee::getDepartment() {
	return m_Department;
}
string CEmployee::getName() {
	return m_Name;
}
string CEmployee::getAddress() {
	return m_Address;
}
void CEmployee::Input(string &line) {
	stringstream ss(line);
	string token;
	vector<string> tokens;

	while (getline(ss, token, ',')) {
		token.erase(0, token.find_first_not_of(" "));
		token.erase(token.find_last_not_of(" ") + 1);
		tokens.push_back(token);
	}
	m_ID = tokens[0];
	m_Department = tokens[1];
	m_Name = tokens[2];
	m_Birthday.Input(tokens[3]);
	m_Address = tokens[4];
	m_WageCoefficient = stof(tokens[5]);

	tokens.clear();
}

void CEmployee::Output(ofstream& outFile) {
	outFile << getID() << ", " << m_Name << ", "; m_Birthday.Output(outFile);
}
float CEmployee::getSalary() {
	return m_basicWage * m_WageCoefficient;
}
void CEmployee::setBasicWage(float basicWage) {
	m_basicWage = basicWage;
}
int CEmployee::getYearofDOB() {
	return m_Birthday.m_Year;
}
int CEmployee::CalculateAge() {
	int currentYear = CMyDate::GetCurrentYear();
	int age = currentYear - getYearofDOB();
	return age;
}
void CEmployee::OutputSortYearOld(ofstream& outFile) {
	outFile << getID() << " " << m_Name << " " << CalculateAge();
}