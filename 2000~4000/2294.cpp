#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int d[10001];
int n, k;
int a[101];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= k; i++) {
		d[i] = 10001;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = a[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - a[i]] + 1);
		}
	}
	if (d[k] == 10001) printf("-1\n");
	else printf("%d\n", d[k]);
	return 0;
}

