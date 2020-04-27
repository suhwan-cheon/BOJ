#include <iostream>
using namespace std;

int main()
{
	int month, day, sum_day;
	int day_month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	const char* day_week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	cin >> month >> day;
	if (month == 1) {
		sum_day = day-1;
	}
	else {
		for (int k = 0; k < month; k++) {
			sum_day += day_month[k];
		}
		sum_day += day - 1;
	}
	int answer = sum_day % 7;
	cout << day_week[answer];
}

