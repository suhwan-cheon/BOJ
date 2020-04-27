#define MAX 500000
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int arr[MAX+1];
vector<int> tree(4 * MAX);
void update(int node, int idx, int left, int right, int val) {
	if (left > idx || idx > right) return;
	tree[node] += val;
	if(left != right) {
		int mid = (left + right) / 2;
		update(node * 2, idx, left, mid, val);
		update(node * 2 + 1, idx, mid + 1, right, val);
	}
}

int query(int node, int Nodeleft, int Noderight, int left, int right) {
	if (right < Nodeleft || left > Noderight) return 0;
	if (Nodeleft <= left && right <= Noderight) return tree[node];
	int mid = (left + right) / 2;
	return query(node * 2, Nodeleft, Noderight, left, mid) +
		query(node * 2 + 1, Nodeleft, Noderight, mid + 1, right);
}
int main()
{
	int n; scanf("%d", &n);
	vector<int>v(500001);
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		arr[temp] = i;
		v[i] = temp;
		update(1, i, 1, MAX, 1);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		ans += query(1, 1, MAX, arr[temp], arr[v[i]]);
	}
	printf("%d\n", ans);
	return 0;
}
