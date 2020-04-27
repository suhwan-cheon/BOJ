#include <iostream>
using namespace std;

long long d[40][40][4]; //(y,x) 좌표와 파이프의 상태
int main()
{
	int a[40][40];
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i < n; i++) {
		if (a[0][i] == 1) break;
		d[0][i][1] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (a[i][j] == 1) continue;
			d[i][j][1] = d[i][j-1][2] + d[i][j - 1][1];
			d[i][j][3] = d[i - 1][j][2] + d[i - 1][j][3];
			if (a[i - 1][j] == 1 || a[i][j - 1] == 1) continue;
			d[i][j][2] = d[i - 1][j - 1][1] + d[i - 1][j - 1][2] + d[i - 1][j - 1][3];
			
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 3; i++) {
		ans += d[n - 1][n - 1][i];
	}
	printf("%lld\n", ans);
	return 0;
}

