#include <iostream>
#include <algorithm>
using namespace std;

int v[101];
bool d[101][1001];
int main()
{
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	d[0][s] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (d[i][j] == false) continue;
			if (j - v[i + 1] >= 0) {
				d[i + 1][j - v[i + 1]] = true;
			}
			if (j + v[i + 1] <= m) {
				d[i + 1][j + v[i + 1]] = true;
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; i++) {
		if (d[n][i]) ans = i;
	}	
	printf("%d\n", ans);
	return 0;
}
