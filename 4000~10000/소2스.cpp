#include <iostream>

using namespace std;

int dp[12];
int ans_dp(int n) {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
	}
	return dp[n];
}

int main() {
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << ans_dp(n) << "\n";
	}
}