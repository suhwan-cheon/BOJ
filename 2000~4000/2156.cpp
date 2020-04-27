#include <iostream>

using namespace std;

int dp[10001];
int a[10001];

int ans_dp(int n) {
	dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + a[i]) {
			dp[i] = dp[i - 2] + a[i];
		}
		if (dp[i] < dp[i - 3] + a[i] + a[i - 1]) {
			dp[i] = dp[i - 3] + a[i] + a[i - 1];
		}
	}
	return dp[n];
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	cout << ans_dp(n);
    
}
