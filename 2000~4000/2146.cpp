#include <iostream>
#include <queue>
using namespace std;
int a[101][101];
int d[101][101];
int g[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
int n;

int main()
{
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && d[i][j] == 0) {
				d[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
							if (a[nx][ny] == 1 && d[nx][ny] == 0) {
								d[nx][ny] = cnt;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
	}
	int ans = -1;
	for (int l = 1; l <= cnt; l++) {
		queue<pair<int, int>>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = -1;
				if (d[i][j] == l) {
					q.push(make_pair(i, j));
					g[i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < n) {
					if (g[nx][ny] == -1) {
						g[nx][ny] = g[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == 1 && d[i][j] != l) {
					if (ans == -1 || g[i][j] - 1 < ans) {
						ans = g[i][j] - 1;
					}
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

