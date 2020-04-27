#include <iostream>
#include <vector>
using namespace std;

long long gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int n; scanf("%d", &n);
	long long s; scanf("%lld", &s);
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++) { //위치의 차이 구하기
		if (s > a[i]) a[i] = s - a[i];
		else a[i] = a[i] - s;
	}
	long long ans = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] >= ans) ans = gcd(a[i], ans);
		else ans = gcd(ans, a[i]);
	}
	printf("%lld", ans);
}
