#include <iostream>
#include <algorithm>
using namespace std;

bool prime[10001];
int main()
{
	//에라토스테네스의 체
	for (int i = 2; i * i <= 10000; i++) {
		int k = i + i;
		while (k <= 10000) {
			prime[k] = true;
			k += i;
		}
	}
	prime[1] = true;

	int m, n; scanf("%d%d", &m, &n);
	long long sum = 0; int mini = 0;
	for (int i = m; i <= n; i++) {
		if (prime[i] == false) {
			if (sum == 0) mini = i;
			sum += i;
		}
	}
	if (sum == 0) printf("-1\n");
	else {
		printf("%lld\n%d\n", sum, mini);
	}
	return 0;
}
