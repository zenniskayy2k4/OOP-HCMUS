#include "CTerracotta.h"
CTerracotta::CTerracotta() : CProduct(), m_Material("") {}

CTerracotta::CTerracotta(string id, string name, string producer, int price, int amount, string material)
	: CProduct(id, name, producer, price, amount), m_Material(material) {}

void CTerracotta::Input(string& line, vector<string>& tokens) {
	CProduct::Input(line, tokens);
	m_Material = tokens[4];
	CProduct::setAmount(stoi(tokens[5]));
}
void CTerracotta::Output(ofstream& outFile) {
	CProduct::Output(outFile);
}
string CTerracotta::getMaterial() {
	return m_Material;
}