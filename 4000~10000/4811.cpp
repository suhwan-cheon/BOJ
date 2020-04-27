#include <iostream>
using namespace std;

long long d[61][61]; // (one, half)
int one, half;
int main()
{
	//미리 dp 만들어두기
	//d[i][j] = d[i-1][j+1] + d[i][j-1] + 1
	for (int i = 0; i <= 60; i++) {
		for (int j = 0; j <= 60; j++) {
			if (i == 0) d[i][j] = 1;
			else {
				if (j == 60) continue;
				if (j - 1 >= 0) {
					d[i][j] = d[i - 1][j + 1] + d[i][j - 1];
				}
				else if (j == 0) {
					d[i][j] = d[i - 1][1];
				}
			}
		}
	}
	while (1) {
		int n; scanf("%d", &n);
		if (n == 0) break;
		printf("%lld\n", d[n][0]);
	}
	return 0;
}
