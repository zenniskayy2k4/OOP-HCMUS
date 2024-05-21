#include "CStore.h"
CStore::CStore() : m_listProduct(0) {}
CStore::CStore(const CStore& other) {
	for (const auto& item : other.m_listProduct) {
		m_listProduct.push_back(item->Replicate());
	}
	//m_Amount = other.m_Amount;
}
CStore::~CStore() {
	m_listProduct.clear();
}
void CStore::Input() {
	ifstream inFile("INPUT.TXT", ios::binary);
	if (!inFile.is_open()) {
		cout << "Unable to open file INPUT.TXT\n";
		return;
	}

	vector <string> tokens;
	string line;
	while (getline(inFile, line)) {
		// Lưu vị trí bắt đầu của dòng
		streampos lineStart = inFile.tellg();

		// Xử lý thông tin dòng dữ liệu
		char type = line[0];
		switch (type) {
		case 'E': {
			CProduct* e = new CElectronic;
			e->Input(line, tokens);
			m_listProduct.push_back(e);
			break;
		}
		case 'T': {
			CProduct* t = new CTerracotta;
			t->Input(line, tokens);
			m_listProduct.push_back(t);
			break;
		}
		case 'F': {
			CProduct* f = new CFood;
			f->Input(line, tokens);
			m_listProduct.push_back(f);
			break;
		}
		default:
			cout << "Invalid item type!\n";
			return;
		}

		// Đặt con trỏ đọc về vị trí bắt đầu của dòng tiếp theo
		inFile.seekg(lineStart);
		tokens.clear();
	}

	inFile.close();
}


void CStore::Output() {
	string fileName = "OUTPUT.TXT";
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
	outFile << m_listProduct.size() << " Mặt hàng:\n";
	for (int i = 0; i < m_listProduct.size(); i++) {
		outFile << i + 1 << ". "; m_listProduct[i]->Output(outFile);
		outFile << "."; if (i < m_listProduct.size() - 1) outFile << endl;
	}
	outFile.close();
}
CMyDate CStore::getCurrentDate() {
	time_t now = time(0);
	tm localtm;
	localtime_s(&localtm, &now);
	int year = 1900 + localtm.tm_year;
	int day = localtm.tm_mday;
	int month = localtm.tm_mon + 1;
	return CMyDate(day, month, year);
}
void CStore::ViewExpDate() {
	string fileName = "EXPDATE.TXT";
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
	for (int i = 0; i < m_listProduct.size(); i++) {
		if (m_listProduct[i]->getCode()[0] == 'F' &&
			dynamic_cast<CFood*>(m_listProduct[i])->getExpDate() < CStore::getCurrentDate()) {
			outFile << m_Code << ", " << m_Name << ", " << m_Amount << ", "; (dynamic_cast<CFood*>(m_listProduct[i])->getExpDate()).Output(outFile);
			outFile << "."; if (i < m_listProduct.size() - 1) outFile << endl;
		}
	}
}

void CStore::Delete() {
	set<string> productCodes;
	for (const auto& product : m_listProduct) {
		productCodes.insert(product->getCode());
	}

	cout << "List of unique product codes: ";
	int count = 0;
	for (auto it = productCodes.begin(); it != productCodes.end(); ++it) {
		if (it != productCodes.begin()) {
			cout << ", ";
		}
		cout << *it;
	} cout << '\n';

	string deleteID;
	cout << "Please enter the ID of the product you want to delete: ";
	cin >> deleteID;
	auto it = find_if(m_listProduct.begin(), m_listProduct.end(), [&deleteID](CProduct* product) {
		return product->getCode() == deleteID; });
	if (it != m_listProduct.end()) {
		m_listProduct.erase(it);
		delete* it;
	}
	else {
		cout << "Prodcut with ID " << deleteID << " not found!\n";
	}
}
void CStore::Buy() {
	ifstream inFile("BUY.TXT", ios::binary);
	if (!inFile.is_open()) {
		cout << "Unable to open file INPUT.TXT\n";
		return;
	}
	string CustomerID;
	inFile >> CustomerID;

	ofstream outFile("INVOICE.TXT", ios::trunc);
	if (!outFile.is_open()) {
		cout << "Unable to open file INVOICE.TXT";
		return;
	}

}

void CStore::ViewQuantity() {
	ofstream outFile("QUANTITY.TXT", ios::trunc);
	if (!outFile.is_open()) {
		cout << "Unable to open file QUANTITY.TXT";
		return;
	}

	streampos lineStart = outFile.tellp();
	outFile << '\n';

	int countOutOfStockProducts = 0;
	for (int i = 0; i < m_listProduct.size(); i++) {
		if (m_listProduct[i]->getAmount() == 0) {
			countOutOfStockProducts++;
			if (i < m_listProduct.size() && countOutOfStockProducts > 1) outFile << '\n';
			outFile << m_listProduct[i]->getCode() << ", " << m_listProduct[i]->getName();
		}
	}
	outFile.seekp(lineStart);
	outFile << countOutOfStockProducts;
}