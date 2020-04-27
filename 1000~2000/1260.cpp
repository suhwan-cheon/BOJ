#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool check1[1001];
bool check2[1001];
vector<int> a[10001];

void dfs(int x) {
	check1[x] = true;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check1[y] == false) dfs(y);
	}
}
void bfs(int x) {
	queue<int> q;
	check2[x] = true; q.push(x);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x << ' ';
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (check2[y] == false) {
				check2[y] = true; q.push(y);
			}
		}
	}
}
int main()
{
	int n, m, v; cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		a[x].push_back(y); a[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	dfs(v);
	cout << "\n";
	bfs(v);
	return 0;
}
