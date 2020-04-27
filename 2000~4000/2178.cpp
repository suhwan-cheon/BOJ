#include <iostream>
#include <queue>
using namespace std;
int a[101][101];
bool check[101][101];
int dist[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = true;
	dist[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny < m && ny >= 0) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = true;
				}
			}
		}
		
		
	}
	printf("%d\n", dist[n - 1][m - 1]);
	return 0;
}
