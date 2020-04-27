#include <iostream>
using namespace std;

int dp[100001];
int ans_dp(int n) {
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			if (dp[i] > dp[i - j * j] + 1) {
				dp[i] = dp[i - j * j] + 1;
			}
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

