#include <iostream>
using namespace std;

bool check[201][201];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		check[a][b] = true;
		check[b][a] = true;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			for (int k = j+1; k <= n; k++) {
				if (check[i][j] != true && check[j][k] != true
					&& check[i][k] != true) ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

