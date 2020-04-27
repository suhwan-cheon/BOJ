#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> a(n+1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		a[i].first = x;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < a[i].second - i) {
			ans = a[i].second - i;
		}
	}
	cout << ans + 1;
	return 0;
}