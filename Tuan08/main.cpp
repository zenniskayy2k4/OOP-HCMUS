#include "CCompany.h"
int main()
{
	CCompany company;
	company.Input();
	company.Output("OUTPUT.TXT");
	cout << "Total company salary: " << fixed << setprecision(3) << company.Salary() << "\n\n";
	company.Search();
	company.SortYearOld();
}

