#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int maxi = -1000000000;
int mini = 1000000000;


int go(vector<int>& a, int idx, int cur, int plus, int minus, int mul, int div) {
	if (idx == n) return cur;
	vector<int> res;
	if (plus > 0) {
		res.push_back(go(a, idx + 1, cur + a[idx], plus - 1, minus, mul, div));
	}
	if (minus > 0) {
		res.push_back(go(a, idx + 1, cur - a[idx], plus, minus - 1, mul, div));
	}
	if (mul > 0) {
		res.push_back(go(a, idx + 1, cur * a[idx], plus, minus, mul - 1, div));
	}
	if (div > 0) {
		res.push_back(go(a, idx + 1, cur / a[idx], plus, minus, mul, div - 1));
	}

	for (auto i : res) {
		if (maxi < i) {
			maxi = i;
		}
		if (mini > i) {
			mini = i;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int plus, minus, mul, div;
	scanf("%d %d %d %d", &plus, &minus, &mul, &div);
	int ans = go(a, 1, a[0], plus, minus, mul, div);
	cout << maxi << "\n";
	cout << mini;
	return 0;
}