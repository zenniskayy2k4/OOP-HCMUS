#include "CProduct.h"
CProduct::CProduct() :m_Code(""), m_Name(""), m_Producer(""), m_Price(10), m_Amount(1) {}

CProduct::CProduct(string id, string name, string producer, int price, int n)
	: m_Code(id), m_Name(name), m_Producer(producer), m_Price(price), m_Amount(n) {}

CProduct* CProduct::Replicate() const {
	return new CProduct(*this);
}
string CProduct::getCode() {
	return m_Code;
}
string CProduct::getName() {
	return m_Name;
}
string CProduct::getProducer() {
	return m_Producer;
}
int CProduct::getPrice() {
	return m_Price;
}
int CProduct::getAmount() {
	return m_Amount;
}
void CProduct::setAmount(int amount) {
	m_Amount = amount;
}
void CProduct::Input(string& line, vector<string>& tokens) {
	for (int i = 0; i < line.size(); ++i) {
		if (line[i] == '(') {
			line[i] = ',';
			break;
		}
	}
	line.erase(remove(line.begin(), line.end(), ')'), line.end());
	stringstream ss(line);
	string token;

	while (getline(ss, token, ',')) {
		token.erase(0, token.find_first_not_of(" "));
		token.erase(token.find_last_not_of(" ") + 1);
		tokens.push_back(token);
	}
	m_Code = tokens[0];
	m_Name = tokens[1];
	m_Producer = tokens[2];
	m_Price = stoi(tokens[3]);
}
void CProduct::Output(ofstream& outFile) {
	outFile << m_Name << ", " << m_Producer << ", " << m_Price << ", " << m_Amount;
}