#define MAX 1000000
#include <iostream>
#include <vector>
using namespace std;

vector<long long> f(MAX + 1);
vector<long long> d(MAX + 1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; scanf("%d", &t);
	for (int i = 1; i <= MAX; i++) {
		for (int j = 1; j * j <= i; j++) {
			if (i % j == 0) {
				if ((i / j) != j) {
					f[i] += j;
					f[i] += (i / j);
				}
				else f[i] += j;
			}
		}
	}
	for (int i = 1; i <= MAX; i++) {
		d[i] = d[i - 1] + f[i];
	}
	while (t--) {
		int n; scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
}