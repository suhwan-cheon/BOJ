#include <iostream>
using namespace std;

int d[100001];

int a[100001];
int ans_dp(int n) {
	d[1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i] = a[i];
		if (d[i] < d[i - 1] + a[i]) {
			d[i] = d[i - 1] + a[i];
		}
	}
	int ans = d[1];
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int ai;
		cin >> ai;
		a[i] = ai;
	}
	cout << ans_dp(n);
}