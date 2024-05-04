#pragma once
#include <iostream>
#include <vector>
using namespace std;
class CStudent
{
private:
	string m_Name;
	string m_Code;
	float m_Math;
	float m_Literature;
public:
	CStudent();
	~CStudent();
	CStudent(string, string, float, float);
	CStudent(const CStudent&);
public:
	friend istream& operator>>(istream&, CStudent& );
	friend ostream& operator<<(ostream&, const CStudent&);
	float AverageGrade() const;
	bool operator>(const CStudent&);
	bool operator>=(const CStudent&);
	bool operator==(const CStudent&);
	bool operator<(const CStudent&);
	bool operator<=(const CStudent&); 
	string getCode() const { return m_Code; }
	string getName() const { return m_Name; }
};
class CClassStudent : public CStudent
{
private:
	int m_Amount = 0;
	vector <CStudent> m_Student;
public:
	void Input();
	void Output();
	CStudent Max();
	CStudent Min();
	void Ascending();
	void Descending();
	void Delete(string);
	CStudent Find(string);
	void Rank();
};
