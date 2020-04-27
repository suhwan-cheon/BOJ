#define mod 1000000007
#include <iostream>
using namespace std;

long long c[1024][1024];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	//pascal 삼각형 공식
	for (int i = 0; i <= n; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			c[i][j] %= mod;
		}
	}
	printf("%lld\n", c[n][k]);
	return 0;
}

