#include <iostream>
#include <cstdbool>
#include <vector>
using namespace std;


bool check(vector<long long>&a, long long x, long long m) {
	int n = a.size();
	long long total = 0;
	for (int i = 0; i < n; i++) {
		if (x <= a[i]) total += a[i] - x;
	}
	return (total >= m);
}
int main()
{
	long long n, m;
	scanf("%lld%lld", &n, &m);
	vector<long long> a(n);
	long long max = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
		if (max < a[i]) max = a[i];
	}
	long long left = 0;
	long long right = max;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(a,mid,m)) {
			if (ans <=mid) ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%lld", ans);
	return 0;
}
