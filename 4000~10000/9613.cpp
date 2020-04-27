#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		long long gcd_sum = 0;
		int d[101];
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			d[i] = x;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				gcd_sum += gcd(d[i], d[j]);
			}
		}
		cout << gcd_sum << "\n";
	}
}
