#include <iostream>
using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
	long long temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - (y1 * x2 + y2 * x3 + y3 * x1);
	if (temp > 0) {
		return 1;
	}
	else if (temp < 0) {
		return -1;
	}
	else {
		return 0;
	}
}
int main()
{
	long long x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
	scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
	int check1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int check2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);
	if (check1 < 0 && check2 < 0) {
		printf("1\n");
	}
	else printf("0\n");
	return 0;
}
