#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[1000001];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		temp %= m;
		a[i] = temp;
	}
	vector<long long>cnt(m, 0);
	cnt[0] = 1;
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		sum %= m;
		cnt[sum] += 1;
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) { //같은 것의 순서쌍
		ans += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2LL;
	}
	printf("%lld\n", ans);
	return 0;
}
