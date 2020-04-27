#include <iostream>
#include <algorithm>
using namespace std;
int d[5001][5001];
int a[5001];
int b[5001];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		b[n +1 - i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			}
		}
	}
	int ans = 0;
	ans = n - d[n][n];
	printf("%d\n", ans);
	return 0;
}
