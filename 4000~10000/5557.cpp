#include <iostream>
#include <cstring>
using namespace std;

long long d[101][21]; // d[i][j] : i번까지 더한 결과 j
int a[101];
int sum = 0;
int main()
{
	int n; scanf("%d", &n);
	memset(d, 0, sizeof(d));
	for (int i = 0; i < n-1; i++) { //1 ~ n-1
		scanf("%d", &a[i]);
	}
	scanf("%d", &sum);
	d[0][a[0]] = 1; //initial
	for (int i = 1; i < n - 1; i++) { // 1 ~ n-1
		for (int j = 0; j <= 20; j++) { // 0 ~ 20
			if (0<= j + a[i] && j + a[i] <= 20) {
				d[i][j] += d[i - 1][j + a[i]];
			}
			if (j - a[i] >= 0 && j - a[i] <= 20) {
				d[i][j] += d[i - 1][j - a[i]];
			}
		}
	}
	printf("%lld\n", d[n - 2][sum]);
	return 0;
}

