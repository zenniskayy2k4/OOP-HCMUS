#include "CProgrammer.h"
CProgrammer::CProgrammer() : CEmployee() {}

CProgrammer::CProgrammer(string id, string department, string name, CMyDate dob, string address, float wageCoef)
	: CEmployee(id, department, name, dob, address, wageCoef) {}

void CProgrammer::Input(string& inFile) {
	CEmployee::Input(inFile);
}
void CProgrammer::Output(ofstream& outFile) {
	CEmployee::Output(outFile);
}
float CProgrammer::getSalary() {
	return CEmployee::getSalary() + m_Overtime;
}
void CProgrammer::SetOvertime(float overtime) {
	m_Overtime = overtime;
}
float CProgrammer::GetOvertime() const {
	return m_Overtime;
}