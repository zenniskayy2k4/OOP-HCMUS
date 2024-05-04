#include "CStudent.h"
#include <iostream>
using namespace std;
#define loop(i,x,n) for (int i = x; i < n; ++i)
#define loopReverse(i,x,n) for (int i = (n); i >= (x); i--)
CStudent::CStudent() {
	m_Name = "", m_Code = "", m_Math = 0, m_Literature = 0;
}
CStudent::CStudent(const CStudent& other) {
	m_Name = other.m_Name;
	m_Code = other.m_Code;
	m_Math = other.m_Math;
	m_Literature = other.m_Literature;
}
CStudent::CStudent(string name, string code, float math, float literature)
{
	m_Name = name, m_Code = code, m_Math = math, m_Literature = literature;

}
CStudent::~CStudent() {
}
istream& operator>>(istream& is, CStudent& student) {
	cout << "Enter student's name: ";
	is >> student.m_Name;
	cout << "Enter student's code: ";
	is >> student.m_Code;
	cout << "Enter student's math grade: ";
	is >> student.m_Math;
	cout << "Enter student's literature grade: ";
	is >> student.m_Literature;
	return is;
}
ostream& operator<<(ostream& os, const CStudent& student) {
	os << "Name: " << student.m_Name << ", Code: " << student.m_Code
		<< ", Math: " << student.m_Math << ", Literature: " << student.m_Literature;
	return os;
}
float CStudent::AverageGrade() const {
	return (m_Literature + m_Math) / 2;
}
bool CStudent::operator>(const CStudent& other) { return AverageGrade() > other.AverageGrade(); }
bool CStudent::operator>=(const CStudent& other) { return AverageGrade() >= other.AverageGrade(); }
bool CStudent::operator==(const CStudent& other) { return AverageGrade() == other.AverageGrade(); }
bool CStudent::operator<(const CStudent& other) { return AverageGrade() < other.AverageGrade(); }
bool CStudent::operator<=(const CStudent& other) { return AverageGrade() <= other.AverageGrade(); }