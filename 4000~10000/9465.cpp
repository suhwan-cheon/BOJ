#include <iostream>
#include <algorithm>
using namespace std;

long long A[100001][3];
long long dp[100001][3];
int ans_dp(int n) {
	dp[0][0] = dp[0][1] = dp[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + A[i][1];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + A[i][2];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(max(ans, dp[i][0]), max(dp[i][1], dp[i][2]));
	}
	return ans;
}
int main()
{
	int t = 0;
	cin >> t;
	ios_base::sync_with_stdio(false);
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x = 0;
			cin >> x;
			A[i][1] = x;
		}
		for (int i = 1; i <= n; i++) {
			int x = 0;
			cin >> x;
			A[i][2] = x;
		}
		cout << ans_dp(n)<<"\n";
	}	
	return 0;
}
