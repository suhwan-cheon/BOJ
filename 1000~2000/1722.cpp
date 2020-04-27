#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdbool>
using namespace std;


long long f[21] = { 1, };
bool check[21];
int main()
{
	for (int i = 1; i <= 20; i++) {
		f[i] = f[i - 1] * i;
	}
	int n; scanf("%d", &n);
	int quest; scanf("%d", &quest);
	if (quest == 1) {
		long long k; scanf("%lld", &k);
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (check[j] == true) continue;
				if (f[n - i - 1] < k) {
					k -= f[n - i - 1];
				}
				else {
					v[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d ", v[i]);
		}
		printf("\n");
	}
	else if (quest == 2) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < v[i]; j++) {
				if (check[j] == false) {
					ans += f[n - i - 1];
				}
			}
			check[v[i]] = true;
		}
		printf("%lld", ans + 1);
	}
	return 0;
}