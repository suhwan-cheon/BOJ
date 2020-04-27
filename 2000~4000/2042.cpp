#include <iostream>
using namespace std;

long long a[1000001];
long long tree[3000001];
long long init(int node, int start, int end) {
	if (start == end) {
		return tree[node] = a[start];
	}
	else {
		return tree[node] = init(node * 2, start, (start + end) / 2) +
			init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(int node, int start, int end, int i, long long diff) {
	if (i < start || i > end) return;
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, i, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, i, diff);
	}
}
long long sum(int node, int start, int end, int i, int j) {
	if (i > end || j < start) return 0;
	if (i <= start && end <= j) {
		return tree[node];
	}
	return sum(node * 2, start, (start + end) / 2, i, j) +
		sum(node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	//수 입력
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	init(1, 1, n);
	for (int i = 0; i < m + k; i++) {
		int cmd, b;
		long long c;
		scanf("%d %d %lld", &cmd, &b, &c);
		
		if (cmd == 1) { //update
			long long diff = c - a[b];
			a[b] = c;
			update(1, 1, n, b, diff);
		}
		else if (cmd == 2) {
			printf("%lld\n", sum(1, 1, n, b, c));
		}
	}
	return 0;
}
