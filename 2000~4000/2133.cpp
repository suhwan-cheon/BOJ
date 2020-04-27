#include <iostream>
using namespace std;
long long dp[31];

int ans_dp(int n) {
	if (n % 2 == 1) return 0;
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;
	for (int i = 6; i <= n; i+=2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2) {
			dp[i] += dp[j] * 2;
		}
	}
	return dp[n];
}
int main()
{
	int n;
	cin >> n;
	cout << ans_dp(n);
}

