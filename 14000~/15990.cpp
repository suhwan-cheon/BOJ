#define MAX 1000000009
#include <iostream>
using namespace std;

long long d[1000001][4];
int main()
{
	int t; scanf("%d", &t);
	d[1][1] = 1; d[1][2] = 0; d[1][3] = 0;
	d[2][1] = 1; d[2][2] = 1; d[2][3] = 0;
	d[3][1] = 2; d[3][2] = 1; d[3][3] = 1;
	for (int i = 4; i <= 1000000; i++) {
		d[i][1] = (d[i-1][1]+ d[i - 1][2] + d[i - 1][3]) % MAX;
		d[i][2] = (d[i - 2][1]+ d[i-2][2] + d[i - 2][3]) % MAX;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]+ d[i-3][3]) % MAX;
	}
	while (t--) {
		int n; scanf("%d", &n);
		long long ans = 0;
		for (int i = 1; i <= 3; i++) {
			ans += d[n][i];
			ans %= MAX;
		}
		printf("%lld\n", ans);
	}
}