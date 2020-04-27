#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int a[8][8];
int temp[8][8];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };
int ans;

int simulate() {
	queue<pair<int, int> >q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = a[i][j];
			if (temp[i][j] == 2) {
				q.push(make_pair(i, j));
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
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (temp[nx][ny] == 0) {
					temp[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}
	return cnt;
}
void go(int cnt) {
	if (cnt == 3) {
		int temp_ans = simulate();
		if (ans < temp_ans) ans = temp_ans;
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				a[i][j] = 1;
				go(cnt + 1);
				a[i][j] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) { //지도의 모양
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	go(0);
	printf("%d\n", ans);
	return 0;
}

