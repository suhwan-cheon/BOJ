#include <iostream>
#include <algorithm>
using namespace std;

int d[101][10];
int mod = 1000000000;
int ans_dp(int n) {
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	d[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j - 1 >= 0) d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9) d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += d[n][i];
		ans %= mod;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	cout << ans_dp(n);
}