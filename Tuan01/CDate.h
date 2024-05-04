#pragma once
class CDate
{
private:
	int Year;
	int Month;
	int Day;
public:
	int Y() { return Year; }
	int M() { return Month; }
	int D() { return Day; }
	void InputDate();
	void OutputDate();
	bool CheckDate();
	bool InspectLeapYear();
	CDate IncreaseYear();
	CDate IncreaseMonth();
	CDate IncreaseDay();
	CDate DecreaseYear();
	CDate DecreaseMonth();
	CDate DecreaseDay();
	CDate IncreaseYear(int);
	CDate IncreaseMonth(int);
	CDate IncreaseDay(int);
	CDate DecreaseYear(int);
	CDate DecreaseMonth(int);
	CDate DecreaseDay(int);
	int DayOrderInYear();
	int WeekOrderInYear();
	void ConvertDate();
	int DeductDateToDate();

public:
	CDate(int, int, int);
	//CDate();
	~CDate();
	int MaxDayInMonth(int, int);
	int DaysFromStartOfYear();
	int DaysToEndOfYear();
};