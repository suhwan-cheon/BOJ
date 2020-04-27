#include <iostream>
#include <algorithm>
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int n, m;
void dfs(int x, int y, int cnt) {
	d[x][y] = cnt;
	for (int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && ny >= 0 && ny < m) {
			if (a[nx][ny] == 1 && d[nx][ny] == 0) {
				dfs(nx, ny, cnt);
			}
		}
	}
}
int main() {
	while (true) {
		cin >> m >> n;
		if (m == 0 && n ==0) break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%1d", &a[i][j]);
				d[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					dfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << "\n";
		
	}
	return 0;
}


