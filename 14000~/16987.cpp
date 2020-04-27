#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[10];
int w[10];
int ans = 0;
int go(int idx) {
	if (idx == n) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] <= 0) temp++;
		}
		return temp;
	}

	if (s[idx] <= 0) return go(idx + 1);

	bool ok = false;
	for (int i = 0; i < n; i++) {
		if (i == idx) continue;
		if (s[i] > 0) {
			ok = true;
			s[i] -= w[idx];
			s[idx] -= w[i];
			ans = max(ans, go(idx + 1));
			s[i] += w[idx];
			s[idx] += w[i];
		}
	}
	if (!ok) return go(idx + 1);
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &s[i], &w[i]);
	}

	printf("%d\n", go(0));
	return 0;
}