#include "CFood.h"
CFood::CFood() : CProduct(), m_MfgDate(1,1,1900), m_ExpDate(1,1,1900) {}

CFood::CFood(string id, string name, string producer, int price, int amount, CMyDate mfg, CMyDate exp)
	: CProduct(id, name, producer, price, amount), m_MfgDate(mfg), m_ExpDate(exp) {}

void CFood::Input(string& inFile, vector<string>& tokens) {
	CProduct::Input(inFile, tokens);
	m_MfgDate.Input(tokens[4]);
	m_ExpDate.Input(tokens[5]);
	CProduct::setAmount(stoi(tokens[6]));
}
void CFood::Output(ofstream& outFile) {
	CProduct::Output(outFile);
}
CMyDate CFood::getMfgDate() {
	return m_MfgDate.getFullDate();
}
CMyDate CFood::getExpDate() {
	return m_ExpDate.getFullDate();
}