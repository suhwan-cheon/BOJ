#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int d[201][201][31];
int a[201][201];
int ans = -1;
//원숭이
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
//말
int hx[] = { -2,-2,-1,-1,1,1,2,2 };
int hy[] = { -1,1,-2,2,-2,2,-1,1 };

int main()
{
	int t, w, h;
	scanf("%d %d %d", &t, &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	// (0,0) ~ (h-1, w-1)
	queue<tuple<int, int, int> >q;
	q.emplace(0, 0, 0);
	while (!q.empty()) {
		int x, y, z;
		tie(y, x, z) = q.front();
		q.pop();

		//원숭이
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
			if (a[ny][nx] == 1 || d[ny][nx][z] != 0) continue;
			q.emplace(ny, nx, z);
			d[ny][nx][z] = d[y][x][z] + 1;
		}

		//말
		if (z + 1 <= t) {
			for (int k = 0; k < 8; k++) {
				int nx = x + hx[k];
				int ny = y + hy[k];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
				if (a[ny][nx] == 1 || d[ny][nx][z+1] != 0) continue;
				q.emplace(ny, nx, z + 1);
				d[ny][nx][z + 1] = d[y][x][z] + 1;
			}
		}
	}
	for (int i = 0; i <= t; i++) {
		if (d[h - 1][w - 1][i] == 0) continue;
		if (ans == -1 || ans > d[h - 1][w - 1][i]) {
			ans = d[h - 1][w - 1][i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
