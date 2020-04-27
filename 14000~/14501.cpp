#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t[15];
int p[15];
int d[10001];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &t[i], &p[i]);
	}
	d[t[0]] = p[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			d[i + t[i]] = max(d[i + t[i]], d[j] + p[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n+1; i++) {
		ans = max(ans, d[i]);
	}
	printf("%d\n", ans);
	return 0;
}

