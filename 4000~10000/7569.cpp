#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int a[100][100][100];
bool check[100][100][100];
int m, n, h;
int dh[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dx[] = { 0,0,0,0,1,-1 };
int ans;
bool simulate() {
	bool check1 = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (a[i][j][k] == 0) check1 = true;
			}
		}
	}
	if (check1) return false;
	else return true;
}
int main()
{
	queue<tuple<int, int, int, int> >q;
	scanf("%d%d%d", &m, &n, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &a[i][j][k]);
				if (a[i][j][k] == 1) {
					q.emplace(i, j, k, 0);
					check[i][j][k] = true;
				}
			}
		}
	}
	if (simulate()) { //이미 모든 토마토가 익어있는 상태
		printf("0");
		return 0;
	}
	while (!q.empty()) {
		int ah, ay, ax, cnt;
		tie(ah, ay, ax, cnt) = q.front();
		q.pop();
		for (int k = 0; k < 6; k++) {
			int nh = ah + dh[k];
			int ny = ay + dy[k];
			int nx = ax + dx[k];
			if (nh < 0 || nh >= h || ny < 0 || ny >= n
				|| nx < 0 || nx >= m) continue;
			if (check[nh][ny][nx] == true) continue;
			if (a[nh][ny][nx] == 0) {
				q.emplace(nh, ny, nx, cnt + 1);
				check[nh][ny][nx] = true;
				a[nh][ny][nx] = 1;
				ans = max(ans, cnt + 1);
			}
		}
	}
	if (simulate()) { //이미 모든 토마토가 익어있는 상태
		printf("%d\n", ans);
	}
	else printf("-1\n");
	return 0;
}
