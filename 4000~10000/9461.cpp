#include <iostream>
using namespace std;
long long dp[1001];
long long ans_dp(int n) {
	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i = 6; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	return dp[n];
}
int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << ans_dp(n) << "\n";
	}
}

