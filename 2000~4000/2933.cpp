#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
char a[101][101];
int c[101][101];
int n, m;
vector<pair<int, int> >group;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y) {
	if (a[x][y] == '.') return;
	if (c[x][y]) return;
	c[x][y] = true;
	group.push_back(make_pair(x, y));
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			dfs(nx, ny);
		}
	}
}
void simulate() {
	memset(c, false, sizeof(c));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') continue;
			if (c[i][j]) continue;
			group.clear();
			dfs(i, j);
			vector<int> low(m, -1);
			for (auto& p : group) {
				low[p.second] = max(low[p.second], p.first);
				a[p.first][p.second] = '.';
			}
			int lowest = n;
			for (int i, j = 0; j < m; j++) {
				if (low[j] == -1) continue;
				for (i = low[j]; j < n && a[i][j] == '.'; i++);
				lowest = min(lowest, i - low[j] - 1);
			}
			for (auto& p : group) {
				p.first += lowest;
			}
		}
	}
}
