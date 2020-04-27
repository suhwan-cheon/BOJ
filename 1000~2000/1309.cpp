#define mod 9901
#include <iostream>
using namespace std;

long long d[100001][3];
int main()
{
	int n; scanf("%d", &n);
	d[1][0] = 1; d[1][1] = 1; d[1][2] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % mod;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % mod;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % mod;
	}
	long long ans = 0;
	for (int i = 0; i < 3; i++) {
		ans = (ans + d[n][i]) % mod;
	}
	printf("%lld", ans);
	return 0;
}
