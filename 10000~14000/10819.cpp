#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n;
int check() {
	int ans = 0;
	for (int i = 0; i < n -1 ; i++) {
		ans += abs(v[i] - v[i + 1]);
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int ans = 0;

	while (next_permutation(v.begin(), v.end())) {
		int k = check();
		ans = max(ans, k);
	}
	printf("%d", ans);
	return 0;
}
