#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int a[101][101]; // i or j 값이 짝수면 벽의 위치
bool check[101][101];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp; scanf("%d", &temp);
			if (i == 1) { //서쪽에 벽
				temp -= 1;
			}
			else if (i == n) { //동쪽에 벽
				temp -= 4;
			}
			if (j == 1) { //북쪽에 벽
				temp -= 2;
			}
			else if (j == m) { //남쪽에 벽
				temp -= 8;
			}
			int y = 2 * i - 1;
			int x = 2 * j - 1;

			if (temp >= 8) { //남쪽에 벽이 있는 경우
				a[y + 1][x] = 1;
				temp -= 8;
			}
			if (temp >= 4) { //동쪽에 벽이 있는 경우
				a[y][x + 1] = 1;
				temp -= 4;
			}
			if (temp >= 2) { //북쪽에 벽이 있는 경우
				a[y - 1][x] = 1;
				temp -= 2;
			}
			if (temp >= 1) { //서쪽에 벽이 있는 경우
				a[y][x - 1] = 1;
				temp -= 1;
			}
		}
	}

	//(홀수, 홀수) 일 때만 bfs
	int ans1 = 0;
	int ans2 = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int y = 2 * i - 1;
			int x = 2 * j - 1;
			if (check[y][x] == true) continue; //이미 방문한 경우
			queue<pair<int, int> >q;
			q.emplace(y, x);

			while (!q.empty()) {
				int ay = q.front().first;
				int ax = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int ny = ay + dy[k];
					int nx = ax + dx[k];
					if (check[ny][nx] == true) continue;
					if (ny < 1 || ny > 2 * n || nx < 1 || nx > 2 * m) continue;

				}
			}
		}
	}
}