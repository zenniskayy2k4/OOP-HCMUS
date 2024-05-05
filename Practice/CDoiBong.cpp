#include "CDoiBong.h"
void CDoiBong::Input() {
	ifstream inFile("input.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file INPUT.TXT\n";
		return;
	}
	inFile >> m_Amount;
	inFile.ignore();
	m_DoiBong.resize(m_Amount);
	for (int i = 0; i < m_Amount; i++) {
		m_DoiBong[i].Input(inFile);
	}
	inFile.close();
}
void CDoiBong::Output(const string& fileName) {
	ofstream outFile(fileName, ios::trunc);
	if (!outFile.is_open()) {
		cout << "Unable to open file ";
		string fileNameCopy = fileName;
		for (char& c : fileNameCopy) {
			c = toupper(c);
		}
		cout << fileName << endl;
		return;
	}

	for (int i = 0; i < m_DoiBong.size(); i++) {
		outFile << i + 1 << ". "; m_DoiBong[i].Output(outFile);
		outFile << "."; if (i < m_DoiBong.size() - 1) outFile << endl;
	}
	outFile.close();
}
void CDoiBong::IncreasingSquadNumber(const string& fileName) {
	sort(m_DoiBong.begin(), m_DoiBong.end(), [](const auto& a, const auto& b) {
		return a.GetSquadNumber() < b.GetSquadNumber();
		});
	Output("output.txt");
}

CCauThu CDoiBong::oldestFootballer() {
	if (m_DoiBong.empty()) return CCauThu();
	CCauThu oldestPlayer = m_DoiBong[0];
	for (size_t i = 1; i < m_DoiBong.size(); ++i) {
		if (m_DoiBong[i].getFullDate() < oldestPlayer.getFullDate()) {
			oldestPlayer = m_DoiBong[i];
		}
	}
	return oldestPlayer;
}