#include <iostream>
#include <cstdbool>
using namespace std;

long long length[10001];
int k, n;

bool check(long long x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += length[i] / x;
	}
	return cnt >= n;
}
int main() {
	scanf("%d%d", &k, &n);
	int max = 0;
	for (int i = 0; i < k; i++) {
		scanf("%lld", &length[i]);
		if (max < length[i]) max = length[i];
	}
	long long ans = 0;
	long long left = 1;
	long long right = max;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%lld", ans);
	return 0;
}