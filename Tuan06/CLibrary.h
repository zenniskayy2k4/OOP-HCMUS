#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cctype>
#include <sstream>
using namespace std;

class CDate {
public:
	int m_Year;
	int m_Month;
	int m_Day;

	CDate();
	CDate(int, int, int);
	void Input(const string&);
	void Output(ofstream&) const;
	bool operator<(const CDate&) const;
	CDate getFullDate() const;
};
class CCatalogue {
protected:
	string m_ID;
	string m_Title;
	string m_Author;
	int m_Count;
public:
	CCatalogue();
	CCatalogue(string, string, string, int);
	virtual string getID();
	virtual CDate getFullDate() const = 0;
	int getCount() const;
	virtual void Input(ifstream&) = 0;
	virtual void Output(ofstream&) = 0;
	virtual CCatalogue* Replicate() const = 0;
};
class CPaper : public CCatalogue
{
private:
	string m_Journal;
	CDate m_Year;
public:
	CPaper();
	CPaper(string, string, string, int, string, CDate);
	string getID() override;
	CDate getFullDate() const override;
	void Input(ifstream&) override;
	void Output(ofstream&) override;
	CCatalogue* Replicate() const {
		return new CPaper(*this);
	}
};
class CBook : public CCatalogue
{
private:
	string m_Publisher;
	string m_Version;
	CDate m_Year;
public:
	CBook();
	CBook(string, string, string, int, string, string, CDate);
	string getID() override;
	CDate getFullDate() const override;
	void Input(ifstream&) override;
	void Output(ofstream&) override;
	CCatalogue* Replicate() const {
		return new CBook(*this);
	}
};
class CThesis : public CCatalogue
{
private:
	string m_School;
	string m_Faculty;
	CDate m_Year;
public:
	CThesis();
	CThesis(string, string, string, int, string, string, CDate);
	string getID() override;
	CDate getFullDate() const override;
	void Input(ifstream&) override;
	void Output(ofstream&) override;
	CCatalogue* Replicate() const {
		return new CThesis(*this);
	}
};
class CLibrary {
private:
	vector <CCatalogue*> m_Item;
	int m_Amount = 0;
public:
	CLibrary();
	CLibrary(const CLibrary&);
	~CLibrary();
	void Input();
	void Output(const string&);
	void Delete();
	void SortYear();
	void SortCount();
};