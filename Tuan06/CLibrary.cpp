#include "CLibrary.h"
//Function of class CCatalouge:
CCatalogue::CCatalogue() : m_ID(""), m_Title(""), m_Author(""), m_Count(0) {}
CCatalogue::CCatalogue(string id, string title, string author, int count)
	: m_ID(id), m_Title(title), m_Author(author), m_Count(count) {}
string CCatalogue::getID() {
	return m_ID;
}
int CCatalogue::getCount() const {
	return m_Count;
}

CDate::CDate() : m_Day(0), m_Month(0), m_Year(0) {}
CDate::CDate(int _day, int _month, int _year) {
	m_Day = _day;
	m_Year = _year;
	m_Month = _month;
}
void CDate::Input(const string& date) {
	stringstream ss(date);
	char delimiter;
	ss >> m_Day >> delimiter >> m_Month >> delimiter >> m_Year;
}
void CDate::Output(ofstream& outFile) const {
	outFile << setfill('0') << setw(2) << m_Day << "/"
		<< setw(2) << m_Month << "/" << m_Year;
}
bool CDate::operator<(const CDate& other) const {
	if (m_Year != other.m_Year) {
		return m_Year < other.m_Year;
	}
	if (m_Month != other.m_Month) {
		return m_Month < other.m_Month;
	}
	return m_Day < other.m_Day;
}

CDate CDate::getFullDate() const {
	return CDate(m_Day, m_Month, m_Year);
}

//Function of class CPaper:
CPaper::CPaper() : CCatalogue(), m_Journal(""), m_Year(CDate()) {}

CPaper::CPaper(string id, string title, string author, int count, string journal, CDate year)
	: CCatalogue(id, title, author, count), m_Journal(journal), m_Year(year) {}

string CPaper::getID() {
	return "P" + m_ID;
}
CDate CPaper::getFullDate() const {
	return m_Year.getFullDate();
}

void CPaper::Input(ifstream& inFile) {
	string line;
	getline(inFile, line); m_ID = line;
	getline(inFile, line); m_Title = line;
	getline(inFile, line); m_Author = line;
	getline(inFile, line); stringstream(line) >> m_Count;
	getline(inFile, line); m_Journal = line;
	getline(inFile, line); m_Year.Input(line);
}
void CPaper::Output(ofstream& outFile) {
	outFile << getID() << ", " << m_Title << ", " << m_Author << ", " << m_Count << ", "
		<< m_Journal << ", "; m_Year.Output(outFile);
}

//Function of class CBook:

CBook::CBook() : CCatalogue(), m_Publisher(""), m_Version(""), m_Year(CDate()) {}

CBook::CBook(string id, string title, string author, int count, string publisher, string version, CDate year)
	: CCatalogue(id, title, author, count), m_Publisher(publisher), m_Version(version), m_Year(year) {}

string CBook::getID() {
	return "B" + m_ID;
}

CDate CBook::getFullDate() const {
	return m_Year.getFullDate();
}
void CBook::Input(ifstream& inFile) {
	string line;
	getline(inFile, line); m_ID = line;
	getline(inFile, line); m_Title = line;
	getline(inFile, line); m_Author = line;
	getline(inFile, line); stringstream(line) >> m_Count;
	getline(inFile, line); m_Publisher = line;
	getline(inFile, line); m_Version = line;
	getline(inFile, line); m_Year.Input(line);
}
void CBook::Output(ofstream& outFile) {
	outFile << getID() << ", " << m_Title << ", " << m_Author << ", " << m_Count
		<< ", " << m_Publisher << ", " << m_Version << ", "; m_Year.Output(outFile);
}
//Function of class CThesis:

CThesis::CThesis() : CCatalogue(), m_School(""), m_Faculty(""), m_Year(CDate()) {}

CThesis::CThesis(string id, string title, string author, int count, string school, string faculty, CDate year)
	: CCatalogue(id, title, author, count), m_School(school), m_Faculty(faculty), m_Year(year) {}

string CThesis::getID() {
	return "T" + m_ID;
}

CDate CThesis::getFullDate() const {
	return m_Year.getFullDate();
}
void CThesis::Input(ifstream& inFile) {
	string line;
	getline(inFile, line); m_ID = line;
	getline(inFile, line); m_Title = line;
	getline(inFile, line); m_Author = line;
	getline(inFile, line); stringstream(line) >> m_Count;
	getline(inFile, line); m_School = line;
	getline(inFile, line); m_Faculty = line;
	getline(inFile, line); m_Year.Input(line);
}
void CThesis::Output(ofstream& outFile) {
	outFile << getID() << ", " << m_Title << ", " << m_Author << ", " << m_Count
		<< ", " << m_School << ", " << m_Faculty << ", ";
	m_Year.Output(outFile);
}

//Function of class Library:
CLibrary::CLibrary() : m_Item(m_Amount), m_Amount(0) {}

CLibrary::~CLibrary() {
	m_Item.clear();
}
CLibrary::CLibrary(const CLibrary& other) {
	for (const auto& item : other.m_Item) {
		m_Item.push_back(item->Replicate());
	}
}
void CLibrary::Input() {
	ifstream inFile("input.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file INPUT.TXT\n";
		return;
	}
	inFile >> m_Amount;
	inFile.ignore();
	m_Item.resize(m_Amount);
	for (int i = 0; i < m_Amount; i++) {
		char type;
		inFile >> type;

		if (type == 'B')
			m_Item[i] = new CBook;
		else if (type == 'P')
			m_Item[i] = new CPaper;
		else if (type == 'T')
			m_Item[i] = new CThesis;
		else {
			cout << "Invalid item type" << endl;
			return;
		}

		m_Item[i]->Input(inFile);
	}
	inFile.close();
}

void CLibrary::Output(const string& fileName) {
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

	for (int i = 0; i < m_Item.size(); i++) {
		outFile << i + 1 << ". "; m_Item[i]->Output(outFile);
		outFile << "."; if (i < m_Item.size() - 1) outFile << endl;
	}
	outFile.close();
}
void CLibrary::Delete() {
	ifstream deleteFile("delete.txt");
	if (!deleteFile.is_open()) {
		cout << "Unable to open file DELETE.TXT\n";
		return;
	}
	vector<string> deletedIDs;
	string id;
	while (deleteFile >> id) {
		deletedIDs.push_back(id);
	}
	deleteFile.close();

	CLibrary tempLibrary(*this);
	auto iter = tempLibrary.m_Item.begin();
	while (iter != tempLibrary.m_Item.end()) {
		if (find(deletedIDs.begin(), deletedIDs.end(), (*iter)->getID()) != deletedIDs.end()) {
			delete* iter;
			iter = tempLibrary.m_Item.erase(iter);
		}
		else {
			++iter;
		}
	}
	tempLibrary.Output("deleteoutput.txt");
}
void CLibrary::SortYear() {
	CLibrary tempLibrary(*this);
	sort(tempLibrary.m_Item.begin(), tempLibrary.m_Item.end(), [](const auto& a, const auto& b) {
		return a->getFullDate() < b->getFullDate();
		});
	tempLibrary.Output("sortyear.txt");
}
void CLibrary::SortCount() {
	sort(m_Item.begin(), m_Item.end(), [](const auto& a, const auto& b) {
		return a->getCount() < b->getCount();
	});
	Output("sortcount.txt");
}