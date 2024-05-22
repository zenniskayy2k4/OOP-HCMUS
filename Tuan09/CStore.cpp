#include "CStore.h"
CStore::CStore() : m_listProduct(0) {}
CStore::CStore(const CStore& other) {
	for (const auto& item : other.m_listProduct) {
		m_listProduct.push_back(item->Replicate());
	}
	m_Amount = other.m_Amount;
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
	int countOutOfDateFood = 0;
	bool isExpired = true;
	for (int i = 0; i < m_listProduct.size(); i++) {
		if (m_listProduct[i]->getCode()[0] == 'F' &&
			dynamic_cast<CFood*>(m_listProduct[i])->getExpDate() < CStore::getCurrentDate()) {
			countOutOfDateFood++; isExpired = true;
			if (i < m_listProduct.size() && countOutOfDateFood > 1) outFile << '\n';
			outFile << m_listProduct[i]->getCode() << ", " << m_listProduct[i]->getName() << ", " << m_listProduct[i]->getAmount() << ", ";
			(dynamic_cast<CFood*>(m_listProduct[i])->getExpDate()).Output(outFile);
			outFile << ".";
		}
		else isExpired = false;
	}
	outFile.close();
	//In ra màn hình ko có mặt hàng nào hết hạn
	if (countOutOfDateFood == 0) cout << u8"The food does not exist in the warehouse or has been deleted!\n";
	else
	if (countOutOfDateFood == 0 && !isExpired) cout << "There are no expired foods in the warehouse!\n";
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
		delete* it;
		m_listProduct.erase(it);
	}
	else {
		cout << "Product with ID " << deleteID << " not found or has been deleted!\n";
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

	inFile.ignore();

	ofstream outFile("INVOICE.TXT", ios::binary);
	if (!outFile.is_open()) {
		cout << "Unable to open file INVOICE.TXT";
		return;
	}
	outFile << CustomerID << '\n';
	auto now = chrono::system_clock::now();
	time_t now_time_t = chrono::system_clock::to_time_t(now);
	tm local_tm;
	localtime_s(&local_tm, &now_time_t);
	const char* days_of_week[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	const char* day_of_week = days_of_week[local_tm.tm_wday];
	outFile << put_time(&local_tm, "%H:%M:%S") << " " << day_of_week << " "; CStore::getCurrentDate().Output(outFile);
	outFile << '\n';

	int totalPayment = 0, discount = 0, count = 0;
	string line;
	while (getline(inFile, line)) {
		if (line.empty()) continue;
		stringstream ss(line);
		string code, name;
		int quantity;

		getline(ss, code, ',');
		getline(ss, name, ',');
		ss >> quantity;

		code.erase(0, code.find_first_not_of(" "));
		name.erase(0, name.find_first_not_of(" "));
		name.erase(name.find_last_not_of(" ") + 1);
		
		bool foundProduct = false;
		for (auto& product : m_listProduct) {
			if (product->getCode() == code && product->getAmount() >= quantity) {
				foundProduct = true;
				if (product->getCode()[0] == 'F' && dynamic_cast<CFood*>(product)->getExpDate() < CStore::getCurrentDate()) {
					count++;
					outFile << count << ". " << "Thực phẩm " << product->getName() <<" (" << product->getCode() <<
						") khách hàng lựa chọn đã hết hạn sử dụng nên không bán được!\n";
				}
				else {
					count++;
					int cost = product->getPrice() * quantity;
					if (day_of_week == "Friday" && dynamic_cast<CFood*>(product)) {
						discount += cost * 0.2;
					}
					else if ((day_of_week == "Tuesday" || day_of_week == "Wednesday") && dynamic_cast<CElectronic*>(product)) {
						discount += cost * 0.15;
					}
					else if ((day_of_week == "Saturday" || day_of_week == "Sunday") && dynamic_cast<CTerracotta*>(product)) {
						discount += cost * 0.3;
					}

					totalPayment += cost;
					product->setAmount(product->getAmount() - quantity);
					outFile << count << ". " << code << ", " << name << ": " << quantity << " x " << product->getPrice() << " = " << cost << " VNĐ\n";
				}

			}
			else if (product->getCode() == code && product->getAmount() == 0) {
				foundProduct = true;
				count++;
				outFile << count << ". " << "Mặt hàng " << product->getName() << " (" << product->getCode() << ") hiện tại đã hết hàng!\n";
			}
			else if (product->getCode() == code && product->getAmount() < quantity) {
				foundProduct = true;
				count++;
				outFile << count << ". " << "Mặt hàng " << product->getName() << " (" << product->getCode() << ") không đủ số lượng hàng mà khách hàng yêu cầu!\n";
			}
		}
		if (!foundProduct) {
			count++;
			outFile << count << ". " << "Mặt hàng " << name << " (" << code << ") không có trong kho hàng!\n";
		}
	}
	inFile.close();

	//Kiểm tra xem số lượng hàng còn lại có đủ để bán không, nếu không thì in ra thông báo
	//Kiểm tra hàng hết date nên không bán

	if (totalPayment > 5000000) {
		discount += totalPayment * 0.1;
	}
	outFile << "Giảm giá: " << discount << " VNĐ\n";
	outFile << "Số tiền thanh toán: " << totalPayment - discount << " VNĐ";
	outFile.close();
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
	outFile.close();
}