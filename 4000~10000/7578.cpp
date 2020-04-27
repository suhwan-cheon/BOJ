#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int l;
void update(vector<int>& tree, int i, int diff) {
	while (i <= l) {
		tree[i] += diff;
		i += (i & -i);
	}
}
int sum(vector<int>& tree, int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}
int sum(vector<int>& tree, int l, int r) {
	if (l > r) return 0;
	return sum(tree, r) - sum(tree, l - 1);
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	map<int, int> position;
	for (int i = 0; i < n; i++) { //다음 열 기계 위치
		int num;
		scanf("%d", &num);
		position[num] = i + 1;
	}
	long long ans = 0;
	vector<int> tree(n + 1); //segment tree
	l = n;
	for (int i = 0; i < n; i++) {
		ans += (long long)sum(tree, position[a[i]] + 1, n);
		update(tree, position[a[i]], 1);
	}
	printf("%lld\n", ans);
	return 0;
}