#include <iostream>
using namespace std;

int combination(long long x, long long y) {
	if (y == x) return 1;
	else if (y == 1) return x;
	else return combination(x - 1, y - 1) + combination(x - 1, y);
}
int main()
{
	int t; cin >> t;
	while (t--) {
		int x, y;
		cin >> y >> x;
		long long ans = combination(x, y);
		cout << ans << "\n";
	}
	return 0;
}
