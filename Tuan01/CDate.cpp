#include "CDate.h"
#include <iostream>
using namespace std;
CDate::~CDate() {

}
CDate::CDate(int _day, int _month, int _year) {
	this->Day = _day;
	this->Year = _year;
	this->Month = _month;
}
bool CDate::InspectLeapYear() {
	if (this->Year % 400 == 0) return true;
	if (this->Year % 4 == 0 && this->Year % 100 != 0) return true;
	return false;
}
int CDate::MaxDayInMonth(int month, int year) {
	switch (month) {
	case 4: case 6: case 9: case 11: return 30;
	case 2: return (InspectLeapYear() == true ? 29 : 28);
	default: return 31;
	}
}
int CDate::DaysFromStartOfYear() {
	int days = 0;
	for (int m = 1; m < Month; ++m) {
		days += MaxDayInMonth(m, Year);
	}
	days += Day;
	return days;
}
int CDate::DaysToEndOfYear() {
	int totalDays = InspectLeapYear() ? 366 : 365;
	return totalDays - DaysFromStartOfYear();
}
void CDate::InputDate() {
	cout << "Input Day: "; cin >> Day;
	cout << "Input Month: "; cin >> Month;
	cout << "Input Year: "; cin >> Year;
}
void CDate::OutputDate() {
	cout << this->Day << "/" << this->Month << "/" << this->Year << "\n";
}
bool CDate::CheckDate() {
	int months[13] = { 0,
	31,28,31,30,31,30,31,31,30,31,30,31 };
	if (InspectLeapYear()) months[2] = 29;
	if (Year < 0) {
		return false;
	}
	if (Month > 12 || Month < 1) return false;
	if (Day < 1 || Day > months[Month]) return false;
	return true;
}
/* Increase 1 year, month, day
-------------------------------------------------------------------------------------------------------------------*/
CDate CDate::IncreaseYear() {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	Year++;
	int newMonth = Month;
	int newDay = Day;

	int maxDay = MaxDayInMonth(Month, Year);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, Year);
}
CDate CDate::IncreaseMonth() {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year + Month / 12;
	int newMonth = Month % 12 + 1;
	int newDay = Day;

	int maxDay = MaxDayInMonth(newMonth, newYear);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, newYear);
}

CDate CDate::IncreaseDay() {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year;
	int newMonth = Month;
	int newDay = Day + 1;

	while (true) {
		int daysInCurrentMonth = MaxDayInMonth(newMonth, newYear);
		if (newDay <= daysInCurrentMonth) break;

		newDay -= daysInCurrentMonth;
		newMonth++;
		if (newMonth > 12) {
			newMonth = 1;
			newYear++;
		}
	}
	return CDate(newDay, newMonth, newYear);
}
/* Decrease 1 year, month, day
-------------------------------------------------------------------------------------------------------------------*/
CDate CDate::DecreaseYear() {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	Year--;
	int newMonth = Month;
	int newDay = Day;

	int maxDay = MaxDayInMonth(Month, Year);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, Year);
}
CDate CDate::DecreaseMonth() {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year;
	int newMonth = Month - 1;
	int newDay = Day;

	while (newMonth <= 0) {
		newMonth += 12;
		newYear--;
	}

	int maxDay = MaxDayInMonth(newMonth, newYear);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, newYear);
}

CDate CDate::DecreaseDay() {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year;
	int newMonth = Month;
	int newDay = Day - 1;

	while (newDay < 1) {
		newMonth--;
		if (newMonth < 1) {
			newMonth += 12;
			newYear--;
		}
		int maxDayInPrevMonth = MaxDayInMonth(newMonth, newYear);
		newDay += maxDayInPrevMonth;
	}
	return CDate(newDay, newMonth, newYear);
}
//-------------------------------------------------------------------------------------------------------------------

/* Increase n year(s), month(s), day(s)
---------------------------------------------------------------------------------------------------------------------*/
CDate CDate::IncreaseYear(int n) {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year + n;
	int newMonth = Month;
	int newDay = Day;

	int maxDay = MaxDayInMonth(newMonth, newYear);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, newYear);
}
CDate CDate::IncreaseMonth(int n) {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year + (n + Month - 1) / 12;
	int newMonth = (n + Month - 1) % 12 + 1;
	int newDay = Day;

	int maxDay = MaxDayInMonth(newMonth, newYear);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, newYear);
}

CDate CDate::IncreaseDay(int n) {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year;
	int newMonth = Month;
	int newDay = Day + n;

	while (true) {
		int daysInCurrentMonth = MaxDayInMonth(newMonth, newYear);
		if (newDay <= daysInCurrentMonth) break;

		newDay -= daysInCurrentMonth;
		newMonth++;
		if (newMonth > 12) {
			newMonth = 1;
			newYear++;
		}
	}
	return CDate(newDay, newMonth, newYear);
}
/* Decrease n year(s), month(s), day(s)
---------------------------------------------------------------------------------------------------------------------*/
CDate CDate::DecreaseYear(int n) {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year - n;
	int newMonth = Month;
	int newDay = Day;

	int maxDay = MaxDayInMonth(newMonth, newYear);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, newYear);
}
CDate CDate::DecreaseMonth(int n) {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year;
	int newMonth = Month - n;
	int newDay = Day;

	while (newMonth <= 0) {
		newMonth += 12;
		newYear--;
	}

	int maxDay = MaxDayInMonth(newMonth, newYear);
	if (newDay > maxDay) {
		newDay = maxDay;
	}
	return CDate(newDay, newMonth, newYear);
}

CDate CDate::DecreaseDay(int n) {
	if (!this->CheckDate()) {
		return CDate(1, 1, 1900);
	}
	int newYear = Year;
	int newMonth = Month;
	int newDay = Day - n;

	while (newDay < 1) {
		newMonth--;
		if (newMonth < 1) {
			newMonth += 12;
			newYear--;
		}
		int maxDayInPrevMonth = MaxDayInMonth(newMonth, newYear);
		newDay += maxDayInPrevMonth;
	}
	return CDate(newDay, newMonth, newYear);
}
//-------------------------------------------------------------------------------------------------------------------

int CDate::DayOrderInYear() {
	int dayOrder = this->Day;
	for (int m = 1; m < this->Month; ++m) {
		dayOrder += MaxDayInMonth(m, this->Year);
	}
	return dayOrder;
}
int CDate::WeekOrderInYear() {
	return DayOrderInYear() / 7;
}
void CDate::ConvertDate() {
	string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	if (this->CheckDate()) {
		if (this->Month >= 1 && this->Month <= 12) {
			cout << months[this->Month - 1] << " ";
			if (this->Day < 10) {
				cout << 0 << this->Day;
			}
			else cout << this->Day;
			cout << ", " << this->Year << endl;
		}
	}
	else {
		cout << "Invalid Date" << endl;
	}
}
int CDate::DeductDateToDate() {
	CDate date1(1, 1, 1900), date2(1, 1, 1900);

	cout << "Please input 2 dates to deduct date to date.\n";
	cout << "1st Date\n"; date1.InputDate();
	cout << "2nd Date\n"; date2.InputDate();
	cout << "The 1st valid date: "; date1.OutputDate();
	cout << "The 2nd valid date: "; date2.OutputDate();
	int res = 0;
	int dayOrder1 = date1.DayOrderInYear();
	int dayOrder2 = date2.DayOrderInYear();
	if (date1.Year == date2.Year) {
		int res = abs(dayOrder1 - dayOrder2);
	}
	else {
		int days = date1.DaysToEndOfYear() + date2.DaysFromStartOfYear();
		for (int i = date1.Year + 1; i < date2.Year; ++i) {
			days += InspectLeapYear() ? 366 : 365;
		}
		res = days;
	}
	return res;
}