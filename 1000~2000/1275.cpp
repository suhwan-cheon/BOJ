#define ll long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, q;
vector<ll> arr;
vector<ll> tree;
ll init(int node, int left, int right) {
	if (left == right) return tree[node] = arr[left];
	else {
		int mid = (left + right) / 2;
		ll m1 = init(node * 2, left, mid);
		ll m2 = init(node * 2 + 1, mid + 1, right);
		return tree[node] = m1 + m2;
	}
}
ll init() {
	return init(1, 0, n - 1);
}
ll query(int node,
	int left, int right, int i, int j) {
	//범위 밖
	if (j < left || right < i) return 0;
	//범위 포함
	if (i <= left && right <= j) return tree[node];
	else {
		int mid = (left + right) / 2;
		ll v1 = query(node * 2, left, mid, i, j);
		ll v2 = query(node * 2 + 1, mid + 1, right, i, j);
		return v1 + v2;
	}
}
ll query(int i, int j) {
	return query(1, 0, n - 1, i, j);
}
ll update(int idx, int newValue, int node, int L, int R){
	//범위 밖
	if (idx < L || R < idx) return tree[node];
	//리프 노드
	if (L == R) return tree[node] = newValue;
	int mid = (L + R) / 2;
	return tree[node] = (update(idx, newValue, node * 2, L, mid)) +
		(update(idx, newValue, node * 2 + 1, mid + 1, R));
}
ll update(int idx, int newValue) {
	return update(idx, newValue, 1, 0, n - 1);
}
int main()
{
	scanf("%d %d", &n, &q);
	arr.resize(n * 4);
	tree.resize(n * 4);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	init();
	for (int i = 0; i < q; i++) {
		int x, y, a, b;
		scanf("%d %d", &x, &y);
		x--; y--;
		if (x <= y) {
			printf("%lld\n", query(x, y));
		}
		else printf("%lld\n", query(y, x));
		scanf("%d %d", &a, &b);
		a--;
		update(a, b);
	}
	return 0;
}
