#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int ans_dp(int n) {
	dp[1] = 0;
	int a = 0, b = 0, c = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = a = dp[i-1] + 1;
		if (i % 2 == 0) {
			b = dp[i / 2] + 1;
			dp[i] = min(a, b);
		}
		if (i % 3 == 0) {
			c = dp[i / 3] + 1;
			dp[i] = min(dp[i], c);
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << ans_dp(n);
}