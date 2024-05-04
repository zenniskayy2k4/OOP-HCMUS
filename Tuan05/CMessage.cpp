#include "CMessage.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

CMyTime::CMyTime() :m_Hour(0), m_Minute(0), m_Second(0) {}
CMyDate::CMyDate() :m_Day(0), m_Month(0), m_Year(0) {}
bool CMyDate::operator<(const CMyDate& other) const {
	if (m_Year != other.m_Year)
		return m_Year < other.m_Year;
	if (m_Month != other.m_Month)
		return m_Month < other.m_Month;
	return m_Day < other.m_Day;
}
bool CMyTime::operator<(const CMyTime& other) const {
	if (m_Hour != other.m_Hour)
		return m_Hour < other.m_Hour;
	if (m_Minute != other.m_Minute)
		return m_Minute < other.m_Minute;
	return m_Second < other.m_Second;
}

CListMessage::~CListMessage() {
	m_Messages.clear();
}
void CMyDate::Input(ifstream& inFile) {
	char delim = '/';
	inFile >> m_Day >> delim >> m_Month >> delim >> m_Year;
}
void CMyDate::Output(ofstream& outFile) const {
	outFile << setfill('0') << setw(2) << m_Day << "/"
		<< setw(2) << m_Month << "/" << m_Year;
}
void CMyTime::Input(ifstream& inFile) {
	char delim = ':';
	inFile >> m_Hour >> delim >> m_Minute >> delim >> m_Second;
}
void CMyTime::Output(ofstream& outFile) const {
	outFile << setfill('0') << setw(2) << m_Hour << ":"
		<< setw(2) << m_Minute << ":" << setw(2) << m_Second;
}
void CMessage::Input(ifstream& inFile) {
	inFile >> m_Number >> m_Vote;
	m_Date.Input(inFile);
	m_Time.Input(inFile);
	
}

void CMessage::Output() {
	ofstream outFile("output.txt", ios::out);
	outFile << "Phone number: " << m_Number << endl;
	outFile << "Vote: " << m_Vote << endl;
	outFile << "Date: ";
	m_Date.Output(outFile);
	outFile << "Time: ";
	m_Time.Output(outFile);
}

void CListMessage::Input() {
	ifstream inFile("input.txt");
	if (!inFile.is_open()) {
		cout << "Unable to open file INPUT.TXT" << endl;
		return;
	}

	inFile >> m_Amount;
	m_Messages.resize(m_Amount);

	for (int i = 0; i < m_Amount; ++i) {
		m_Messages[i].Input(inFile);
	}
	inFile.close();
}

void CListMessage::Output() {
	ofstream outFile("output.txt");
	if (!outFile.is_open()) {
		cout << "Unable to open file OUTPUT.TXT" << endl;
		return;
	}

	vector<int> maxCodes = FindCode();
	outFile << "Max codes: ";
	for (int code : maxCodes) {
		outFile << code << "  ";
	}
	outFile << endl;

	vector<string> mostFrequentPhones = FindPhone();
	outFile << "Most frequent phone numbers: ";
	for (const string& phone : mostFrequentPhones) {
		outFile << phone << "  ";
	}
	outFile << endl;

	vector<CMyDate> mostFrequentDays = FindDay();
	outFile << "Most frequent days: ";
	for (const CMyDate& date : mostFrequentDays) {
		date.Output(outFile);
		outFile << "  ";
	}
	outFile << endl;

	vector<CMyTime> mostFrequentTimes = FindTime();
	outFile << "Most frequent times: ";
	for (const CMyTime& time : mostFrequentTimes) {
		time.Output(outFile);
		outFile << "  ";
	}
	outFile << endl;

	Top10();

	outFile.close();
}


vector <int> CListMessage::FindCode() {
	vector <int> voteCounts(10, 0);

	for (const auto& msg : m_Messages) {
		voteCounts[msg.m_Vote]++;
	}

	int maxVotes = *max_element(voteCounts.begin(), voteCounts.end());

	vector<int> mostFrequentCodes;
	for (int i = 0; i < voteCounts.size(); ++i) {
		if (voteCounts[i] == maxVotes) {
			mostFrequentCodes.push_back(i);
		}
	}

	return mostFrequentCodes;
}

vector<string> CListMessage::FindPhone() {
	map<string, int> phoneCounts;

	for (const auto& msg : m_Messages) {
		phoneCounts[msg.m_Number]++;
	}

	int maxCount = 0;
	for (const auto& pair : phoneCounts) {
		if (pair.second > maxCount) {
			maxCount = pair.second;
		}
	}

	vector<string> mostFrequentPhones;
	for (const auto& pair : phoneCounts) {
		if (pair.second == maxCount) {
			mostFrequentPhones.push_back(pair.first);
		}
	}

	return mostFrequentPhones;
}


vector<CMyDate> CListMessage::FindDay() {
	map <CMyDate, int> dateCounts;

	for (const auto& msg : m_Messages) {
		dateCounts[msg.m_Date]++;
	}

	int maxCount = 0;
	for (const auto& pair : dateCounts) {
		if (pair.second > maxCount) {
			maxCount = pair.second;
		}
	}

	vector <CMyDate> mostFrequentDate;
	for (const auto& pair : dateCounts) {
		if (pair.second == maxCount) {
			mostFrequentDate.push_back(pair.first);
		}
	}
	return mostFrequentDate;
}

vector <CMyTime> CListMessage::FindTime() {
	map <CMyTime, int> timeCounts;

	for (const auto& msg : m_Messages) {
		timeCounts[msg.m_Time]++;
	}

	auto maxTime = max_element(timeCounts.begin(), timeCounts.end(), [](const auto& a, const auto& b) {
		return a.second < b.second;
	});
	int maxCount = 0;
	for (const auto& pair : timeCounts) {
		if (pair.second > maxCount) {
			maxCount = pair.second;
		}
	}

	vector <CMyTime> mostFrequentTime;
	for (const auto& pair : timeCounts) {
		if (pair.second == maxCount) {
			mostFrequentTime.push_back(pair.first);
		}
	}
	return mostFrequentTime;
}

void CListMessage::Top10() {
	map<int, int> voteCounts;

	for (const auto& msg : m_Messages) {
		voteCounts[msg.m_Vote]++;
	}

	ofstream outFile("output.txt", ios::app);
	outFile << "Top 10 most voted codes:" << endl;

	for (int i = 0; i < 10; ++i) {
		int maxVote = 0;
		int maxCode = 0;
		for (const auto& pair : voteCounts) {
			if (pair.second > maxVote) {
				maxVote = pair.second;
				maxCode = pair.first;
			}
		}
		if (maxVote == 0) break; // No more votes to count
		outFile << "Code: " << maxCode << ", Votes: " << maxVote << endl;
		voteCounts.erase(maxCode); // Remove this code from the map
	}
}
