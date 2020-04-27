#define MAX 300000
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool prime[MAX+1];

int main()
{
    //소수 구하기
	for (int i = 2; i * i <= MAX; i++) {
		int k = i + i;
		while (k <= MAX) {
			prime[k] = true;
			k += i;
		}
	}
	prime[1] = true; prime[0] = true;
	
	while (1) {
		int n; scanf("%d", &n);
		if (n == 0) break;
		int ans = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			if (prime[i] == false) ans++;
		}
		printf("%d\n", ans);
	}
}
