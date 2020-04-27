#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001][4];
int r_array[1001], g_array[1001], b_array[1001];

int ans_dp(int n) {
	dp[1][1] = r_array[1];
	dp[1][2] = g_array[1];
	dp[1][3] = b_array[1];
	for (int i = 2; i <= n; i++) {
		dp[i][1] = min(dp[i - 1][2] + r_array[i], dp[i - 1][3] + r_array[i]);
		dp[i][2] = min(dp[i - 1][1] + g_array[i], dp[i - 1][3] + g_array[i]);
		dp[i][3] = min(dp[i - 1][1] + b_array[i], dp[i - 1][2] + b_array[i]);
	}
	return min(dp[n][1], min(dp[n][2], dp[n][3]));
}
int main()
{
	int r_color, g_color, b_color;
	int n; cin >> n;
	for(int i=1; i<=n;i++) {
		cin >> r_color >> g_color >> b_color;
		r_array[i] = r_color;
		g_array[i] = g_color;
		b_array[i] = b_color;
	}
	int ans = ans_dp(n);
	cout << ans;
	return 0;
}

