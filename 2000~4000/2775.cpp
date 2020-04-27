#include <iostream>
using namespace std;

int apart[15][15];
int main()
{
	int t; scanf("%d", &t);
	for (int i = 1; i < 15; i++) {
		apart[0][i] = i;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 1; k <= j; k++) {
				apart[i][j] += apart[i-1][k];
			}
		}
	}
	while (t--) {
		int k, n; scanf("%d%d", &k, &n);
		printf("%d\n", apart[k][n]);
	}
	return 0;
}
