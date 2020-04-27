#include <iostream>
using namespace std;

int check(int x) {
	int temp = 0;
	while (x) {
		x /= 10;
		temp++;
	}
	return temp;
}
int main()
{
	int n; scanf("%d", &n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += check(i);
	}
	printf("%lld", ans);
	return 0;
}
