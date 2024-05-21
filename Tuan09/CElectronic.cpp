#include "CElectronic.h"
CElectronic::CElectronic() : CProduct(), m_Warranty(""), m_ElectricPower(0) {}

CElectronic::CElectronic(string id, string name, string producer, int price, int amount, string warranty, int ep)
	: CProduct(id, name, producer, price, amount), m_Warranty(warranty), m_ElectricPower(ep) {}

void CElectronic::Input(string& inFile, vector<string>& tokens) {
	CProduct::Input(inFile, tokens);
	m_Warranty = tokens[4];
	if (tokens[5] != "Null")
		m_ElectricPower = stoi(tokens[5]);
	else m_ElectricPower = 0;
	CProduct::setAmount(stoi(tokens[6]));
}
void CElectronic::Output(ofstream& outFile) {
	CProduct::Output(outFile);
}
string CElectronic::getWarranty() {
	return m_Warranty;
}
int CElectronic::getElectricPower() {
	return m_ElectricPower;
}