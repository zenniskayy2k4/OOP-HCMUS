#include "CManager.h"
CManager::CManager() : CEmployee() {}

CManager::CManager(string id, string department, string name, CMyDate dob, string address, float wageCoef, float basicWage)
	: CEmployee(id, department, name, dob, address, wageCoef, basicWage) {}

void CManager::Input(string& inFile) {
	CEmployee::Input(inFile);
}
void CManager::Output(ofstream& outFile) {
	CEmployee::Output(outFile);
}
float CManager::getSalary() {
	return CEmployee::getSalary();
}