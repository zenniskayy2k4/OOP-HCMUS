#include <iostream>
#include "CStudent.h"
using namespace std;
int main()
{
    CClassStudent classStudent;
    classStudent.Input();
    cout << "Students information:" << endl;
    classStudent.Output();

    cout << "Student with the highest average grade:" << endl;
    cout << classStudent.Max() << endl;

    cout << "Student with the lowest average grade:" << endl;
    cout << classStudent.Min() << endl;

    cout << "Students sorted in ascending order of average grade:" << endl;
    classStudent.Ascending();
    classStudent.Output();

    cout << "Students sorted in descending order of average grade:" << endl;
    classStudent.Descending();
    classStudent.Output();

    string codeToDelete; 
    cout << "Enter the student's code want to delete: "; cin >> codeToDelete;
    cout << "Deleting student with code " << codeToDelete << endl;
    classStudent.Delete(codeToDelete);
    classStudent.Output(); 

    string codeToFind;
    cout << "Enter the student's code want to find: "; cin >> codeToFind;
    cout << "Finding student with code " << codeToFind << endl;
    CStudent foundStudent = classStudent.Find(codeToFind);
    if (foundStudent.getCode() != "") {
        cout << "Found student: " << foundStudent << endl;
    }

    cout << "Ranking students:" << endl;
    classStudent.Rank();
    return 0;
}
