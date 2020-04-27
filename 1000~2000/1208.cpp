#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) sum += a[j];
		}
		if (sum == s) ans++;
	}
	printf("%d", ans);
	return 0;
}

