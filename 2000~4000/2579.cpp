#include <iostream>
#include <algorithm>
using namespace std;

int dp[301][2];
int a[301];
int ans_dp(int n) {
	dp[1][1] = dp[1][0] = a[1];
	dp[2][0] = a[2];
	dp[2][1] = a[1] + a[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
		dp[i][1] = dp[i - 1][0] + a[i];
	}
	int ans = max(dp[n][0], dp[n][1]);
	return ans;
}
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int ai;
		cin >> ai;
		a[i] = ai;
	}
	cout << ans_dp(n);
}
