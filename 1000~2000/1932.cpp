#include <iostream>
#include <algorithm>
using namespace std;

int d[501][501];
int tri_size[501][501];

int ans_dp(int n) {
	d[1][1] = tri_size[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1) d[i][j] = d[i - 1][j] + tri_size[i][j];
			else if (j == i) d[i][j] = d[i - 1][j - 1] + tri_size[i][j];
			else d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + tri_size[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (d[n][i] > ans) ans = d[n][i];
	}
	return ans;
}
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int x; cin >> x;
			tri_size[i][j] = x;
		}
	}
	int ans = ans_dp(n);
	cout << ans << "\n";
	return 0;
}

