#include <iostream>
using namespace std;
int main()
{
	int hour, min;
	scanf("%d%d", &hour, &min);
	int c; scanf("%d", &c);
	hour += c / 60;
	min += c % 60;
	if (min >= 60) {
		hour++;
		min -= 60;
	}
	if (hour >= 24) {
		hour -= 24;
	}
	printf("%d %d", hour, min);
	return 0;
}

