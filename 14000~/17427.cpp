#define MAX 1000000
#include <iostream>
#include <vector>
using namespace std;


vector<long long> d(MAX + 1);
int main()
{
	int t; scanf("%d", &t);
	vector<long long> f(MAX + 1, 1);
	for (int i = 2; i <= MAX; i++) {
		for (int j = 1; i * j <= MAX; j++) {
			f[i * j] += i;
		}
	}
	for (int i = 1; i <= MAX; i++) {
		d[i] = d[i - 1] + f[i];
	}
	while (t--) {
		int n; scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
	return 0;
}