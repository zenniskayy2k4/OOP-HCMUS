#include <iostream>
using namespace std;

#include "CDate.h"

void input(CDate& date) {
    cout << "Please enter new date!\n";
    date.InputDate();
    while (!date.CheckDate()) {
        if (date.CheckDate()) {
            cout << "Your date is valid!\n";
        }
        else {
            cout << "Your date is not valid! Please enter again.\n";
            date.InputDate();
        }
    }

}
void output(CDate& date) {
    date.OutputDate();
}
void solve(CDate& date) {
    input(date); cout << "The valid date: "; output(date);
    if (date.InspectLeapYear()) cout << date.Y() << " is leap year.\n";
    else cout << date.Y() << " is not leap year.\n\n";
}
void solve1(CDate date) { // Increase 1 year, month, day
    cout << "The date after increasing 1 year: ";
    date = date.IncreaseYear(); date.OutputDate();

    cout << "The date after increasing 1 month: ";
    date = date.IncreaseMonth(); date.OutputDate();

    cout << "The date after increasing 1 day: ";
    date = date.IncreaseDay(); date.OutputDate();

    cout << "\n";
}
void solve2(CDate& date1) { // Decrease 1 year, month, day
    input(date1); cout << "The valid date: "; output(date1);
    if (date1.InspectLeapYear()) cout << date1.Y() << " is leap year.\n";
    else cout << date1.Y() << " is not leap year.\n\n";
    cout << "The date after decreasing 1 year: ";
    date1 = date1.DecreaseYear(); date1.OutputDate();

    cout << "The date after decreasing 1 month: ";
    date1 = date1.DecreaseMonth(); date1.OutputDate();

    cout << "The date after decreasing 1 day: ";
    date1 = date1.DecreaseDay(); date1.OutputDate();

    cout << '\n';
}
void solve3(CDate& newDate, int& n) { // Increase n year(s), month(s), day(s)
    input(newDate);
    cout << "The valid date: "; output(newDate);
    if (newDate.InspectLeapYear()) cout << newDate.Y() << " is leap year.\n";
    else cout << newDate.Y() << " is not leap year.\n\n";
    cout << "\n";
    cout << "Enter the number of year(s) to increase: "; cin >> n;
    cout << "The date after increasing " << n << " year(s): ";
    newDate = newDate.IncreaseYear(n); newDate.OutputDate();

    cout << "Enter the number of month(s) to increase: "; cin >> n;
    cout << "The date after increasing " << n << " month(s): ";
    newDate = newDate.IncreaseMonth(n); newDate.OutputDate();

    cout << "Enter the number of day(s) to increase: "; cin >> n;
    cout << "The date after increasing " << n << " day(s): ";
    newDate = newDate.IncreaseDay(n); newDate.OutputDate();

    cout << "\n";
}
void solve4(CDate& date2, int& n) { // Decrease n year(s), month(s), day(s)

    input(date2); cout << "The valid date: "; output(date2);
    if (date2.InspectLeapYear()) cout << date2.Y() << " is leap year.\n";
    else cout << date2.Y() << " is not leap year.\n\n";

    cout << "Enter the number of year(s) to decrease: "; cin >> n;
    cout << "The date after decreasing " << n << " year(s): ";
    date2 = date2.DecreaseYear(n); date2.OutputDate();

    cout << "Enter the number of month(s) to decrease: "; cin >> n;
    cout << "The date after decreasing " << n << " month(s): ";
    date2 = date2.DecreaseMonth(n); date2.OutputDate();

    cout << "Enter the number of day(s) to decrease: "; cin >> n;
    cout << "The date after decreasing " << n << " day(s): ";
    date2 = date2.DecreaseDay(n); date2.OutputDate();

    cout << "\n";
}
void solve5(CDate& date3) {
    input(date3); cout << "The valid date: "; output(date3);
    cout << "Day order in year: " << date3.DayOrderInYear() << '\n';
    cout << "Week order in year: " << date3.WeekOrderInYear() << '\n';
    cout << "The date after converting to the format 'Month DD, YYYY': ";
    date3.ConvertDate(); cout << endl;
    cout << "Difference between Date 1 and Date 2: "
        << date3.DeductDateToDate() << " day(s)";
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    CDate date(1, 1, 1900);
    CDate date1(1, 1, 1900);
    CDate newDate(1, 1, 1900);
    CDate date2(1, 1, 1900);
    CDate date3(1, 1, 1900);

    int n = 0;

    solve(date);

    solve1(date);

    solve2(date1);

    solve3(newDate, n);

    solve4(date2, n);

    solve5(date3);

    return 0;
}