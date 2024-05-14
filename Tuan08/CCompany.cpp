#include "CCompany.h"
CCompany::CCompany() : m_ListEmployees(0) {}
CCompany::CCompany(const CCompany& other) {
	for (const auto& item : other.m_ListEmployees) {
		m_ListEmployees.push_back(item->Replicate());
	}
	m_basicWage = other.m_basicWage;
}
CCompany::~CCompany() {
	m_ListEmployees.clear();
}
void CCompany::Input() {
	ifstream inFile("INPUT.TXT", ios::binary);
	if (!inFile.is_open()) {
		cout << "Unable to open file INPUT.TXT\n";
		return;
	}

	string line;
	while (getline(inFile, line)) {
		// Lưu vị trí bắt đầu của dòng
		streampos lineStart = inFile.tellg();

		// Xử lý thông tin dòng dữ liệu
		char type = line[0];
		switch (type) {
		case 'M': {
			CEmployee* m = new CManager();
			m->Input(line);
			m_ListEmployees.push_back(m);
			break;
		}
		case 'P': {
			CEmployee* p = new CProgrammer();
			p->Input(line);
			m_ListEmployees.push_back(p);
			break;
		}
		case 'D': {
			CEmployee* d = new CDesigner();
			d->Input(line);
			m_ListEmployees.push_back(d);
			break;
		}
		case 'T': {
			CEmployee* t = new CTester();
			istringstream iss(line);
			t->Input(line);
			m_ListEmployees.push_back(t);
			break;
		}
		default:
			cout << "Invalid item type!\n";
			return;
		}

		// Đặt con trỏ đọc về vị trí bắt đầu của dòng tiếp theo
		inFile.seekg(lineStart);
	}

	inFile.close();
}


void CCompany::Output(const string& fileName) {
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

	for (int i = 0; i < m_ListEmployees.size(); i++) {
		outFile << i + 1 << ". "; m_ListEmployees[i]->Output(outFile);
		outFile << "."; if (i < m_ListEmployees.size() - 1) outFile << endl;
	}
	outFile.close();
}

double CCompany::Salary() {
	ifstream inFile("SALARY.TXT");
	if (!inFile.is_open()) {
		cout << "Unable to open file SALARY.TXT\n";
		return -1;
	}

	// Đọc lương cơ bản từ dòng đầu tiên của tệp SALARY.TXT
	string basicWageStr;
	getline(inFile, basicWageStr);
	float basicWage = stof(basicWageStr);

	// Đặt lương cơ bản cho mỗi nhân viên
	for (int i = 0; i < m_ListEmployees.size(); ++i) {
		m_ListEmployees[i]->setBasicWage(basicWage);
	}

	// Biến để tính tổng lương toàn bộ công ty
	float totalCompanySalary = 0;

	// Đọc và xử lý thông tin lương từng loại nhân viên
	string line;
	while (getline(inFile, line)) {
		stringstream ss(line);
		string type, id, value;
		ss >> type >> id >> value;

		// Xác định loại nhân viên và cập nhật thông tin lương tương ứng
		if (type == "P") {
			for (int i = 0; i < m_ListEmployees.size(); ++i) {
				if (m_ListEmployees[i]->getID() == id) {
					dynamic_cast<CProgrammer*>(m_ListEmployees[i])->SetOvertime(stof(value));
					break;
				}
			}
		}
		else if (type == "D") {
			for (int i = 0; i < m_ListEmployees.size(); ++i) {
				if (m_ListEmployees[i]->getID() == id) {
					dynamic_cast<CDesigner*>(m_ListEmployees[i])->SetBonus(stof(value));
					break;
				}
			}
		}
		else if (type == "T") {
			for (int i = 0; i < m_ListEmployees.size(); ++i) {
				if (m_ListEmployees[i]->getID() == id) {
					dynamic_cast<CTester*>(m_ListEmployees[i])->SetErrors(stoi(value));
					break;
				}
			}
		}
	}
	inFile.close();

	// Tính tổng lương toàn bộ công ty
	for (int i = 0; i < m_ListEmployees.size(); ++i) {
		totalCompanySalary += m_ListEmployees[i]->getSalary();
	}

	// Xuất lương của từng nhân viên
	for (int i = 0; i < m_ListEmployees.size(); ++i) {
		cout << "Employee ID: " << m_ListEmployees[i]->getID() << ", Salary: " << fixed << setprecision(3) << m_ListEmployees[i]->getSalary() << endl;
	}
	return totalCompanySalary;
}

void CCompany::Search() {
	string fileName = "SEARCH.TXT";
	ofstream outFile(fileName, ios::trunc);
	if (!outFile.is_open()) {
		cout << "Unable to open file " << fileName << "\n";
	}
	string findID;
	cout << "Please enter the ID of the department you want to search for: ";
	cin >> findID; int countDepartmentFindID = 0;
	for (int i = 0; i < m_ListEmployees.size(); i++) {
		if (m_ListEmployees[i]->getDepartment() == findID) {
			countDepartmentFindID++;
			outFile << m_ListEmployees[i]->getID() << ", " << m_ListEmployees[i]->getName() << ", ";
			m_ListEmployees[i]->getDOB().Output(outFile); outFile << ", " << m_ListEmployees[i]->getAddress();
		}
		if (i < m_ListEmployees.size() - 1 && countDepartmentFindID > 1) outFile << endl;
	}
}
void CCompany::SortYearOld() {
	sort(m_ListEmployees.begin(), m_ListEmployees.end(), [](const auto& a, const auto& b) {
		return a->CalculateAge() > b->CalculateAge();
		});
	string fileName = "SORTYEAROLD.TXT";
	ofstream outFile(fileName, ios::trunc);
	if (!outFile.is_open()) {
		cout << "Unable to open file " << fileName << "\n";
	}

	for (int i = 0; i < m_ListEmployees.size(); i++) {
		outFile << i + 1 << ". "; m_ListEmployees[i]->OutputSortYearOld(outFile);
		if (i < m_ListEmployees.size() - 1) outFile << endl;
	}
	outFile.close();
}