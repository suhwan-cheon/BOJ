#include <iostream>
#include <algorithm>
using namespace std;

int d[1500001];
int t[1500000];
int p[1500000];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}
	//n이 1이고 t[0]이 1일경우도 생각할것
	//d[i] : i일 까지의 최대 수익
	for (int i = 0; i < n; i++) {
		if (i != 0 && d[i] < d[i-1]) d[i] = d[i - 1];
		if (i + t[i] <= n) {
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	printf("%d\n", ans);
	return 0;
}