#include <iostream>
using namespace std;

long long d[100];

long long ans_dp(int n) {
	d[1] = 1;
	d[2] = 1;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]);
	}
	return d[n];
}
int main()
{
	int n;
	cin >> n;
	cout << ans_dp(n);
}

