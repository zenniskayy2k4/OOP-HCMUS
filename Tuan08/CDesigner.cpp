#include "CDesigner.h"
CDesigner::CDesigner() : CEmployee() {}

CDesigner::CDesigner(string id, string department, string name, CMyDate dob, string address, float wageCoef)
	: CEmployee(id, department, name, dob, address, wageCoef) {}

void CDesigner::Input(string& inFile) {
	CEmployee::Input(inFile);
}
void CDesigner::Output(ofstream& outFile) {
	CEmployee::Output(outFile);
}
float CDesigner::getSalary() {
	return CEmployee::getSalary() + m_Bonus;
}
void CDesigner::SetBonus(float bonus) {
	m_Bonus = bonus;
}
float CDesigner::GetBonus() const {
	return m_Bonus;
}