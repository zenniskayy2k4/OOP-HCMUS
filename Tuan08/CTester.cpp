#include "CTester.h"
CTester::CTester() : CEmployee() {}

CTester::CTester(string id, string department, string name, CMyDate dob, string address, float wageCoef, float basicWage)
	: CEmployee(id, department, name, dob, address, wageCoef, basicWage) {}

void CTester::Input(string& inFile) {
	CEmployee::Input(inFile);
}
void CTester::Output(ofstream& outFile) {
	CEmployee::Output(outFile);
}
float CTester::getSalary() {
	return CEmployee::getSalary() + m_Errors * 100000;
}
void CTester::SetErrors(int errors) {
	m_Errors = errors;
}

int CTester::GetErrors() const {
	return m_Errors;
}