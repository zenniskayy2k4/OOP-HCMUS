#include "CStudent.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>
void CClassStudent::Input() {
    cout << "Enter number of students: ";
    cin >> m_Amount;
    m_Student.resize(m_Amount);
    for (int i = 0; i < m_Amount; ++i) {
        cout << "Enter information for student " << i + 1 << ":" << endl;
        cin >> m_Student[i];
    }
}
void CClassStudent::Output() {
    for (const auto& student : m_Student) {
        cout << student << endl;
    }
}
CStudent CClassStudent::Max() {
    if (m_Student.empty()) return CStudent();
    CStudent maxStudent = m_Student[0];
    for (size_t i = 1; i < m_Amount; ++i) {
        if (m_Student[i] > maxStudent) {
            maxStudent = m_Student[i];
        }
    }
    return maxStudent;
}
CStudent CClassStudent::Min() {
    if (m_Student.empty()) return CStudent();
    CStudent minStudent = m_Student[0];
    for (size_t i = 1; i < m_Amount; ++i) {
        if (m_Student[i] < minStudent) {
            minStudent = m_Student[i];
        }
    }
    return minStudent;
}
void CClassStudent::Ascending() {
    for (int gap = m_Amount / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < m_Amount; i += 1)
        {
            CStudent temp = m_Student[i];

            int j = 0;
            for (j = i; j >= gap && m_Student[j - gap] > temp; j -= gap)
                m_Student[j] = m_Student[j - gap];

            m_Student[j] = temp;
        }
    }
}
void CClassStudent::Descending() {
    for (int gap = m_Amount / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < m_Amount; i += 1)
        {
            CStudent temp = m_Student[i];

            int j = 0;
            for (j = i; j >= gap && m_Student[j - gap] < temp; j -= gap)
                m_Student[j] = m_Student[j - gap];

            m_Student[j] = temp;
        }
    }
}
void CClassStudent::Delete(string code) {
    for (auto it = m_Student.begin(); it != m_Student.end();) {
        if ((*it).getCode() == code) {
            it = m_Student.erase(it);
        }
        else {
            ++it;
        }
    }
}
CStudent CClassStudent::Find(string code) {
    for (const auto& student : m_Student) {
        if (student.getCode() == code) {
            return student;
        }
    }
    cout << "Student not found!" << endl;
    return CStudent();
}
void CClassStudent::Rank() {
    SetConsoleOutputCP(65001);
    for (const auto& student : m_Student) {
        float avg = student.AverageGrade();
        cout << "Student: " <<student.getName() << 
            ", Code: " << student.getCode() << ", Average Grade: " << avg;
        if (avg < 3.0)
            cout << " - Poor" << endl;
        else if (avg < 5.0)
            cout << " - Fair" << endl;
        else if (avg < 6.5)
            cout << " - Average" << endl;
        else if (avg < 8.0)
            cout << " - Good" << endl;
        else if (avg < 9.0)
            cout << " - Excellent" << endl;
        else
            cout << " - Outstanding" << endl;
    }
}
