#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int ans;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int r, c;
bool check[50][50];
void bfs(vector<string>& s, int y, int x) {
	memset(check, false, sizeof(check));
	queue<tuple<int, int, int> >q; //(y, x, cnt)
	q.emplace(y, x, 0);
	check[y][x] = true;
	int temp_ans = 0;
	while (!q.empty()) {
		int ay, ax, cnt;
		tie(ay, ax, cnt) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = ay + dy[k];
			int nx = ax + dx[k];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (s[ny][nx] == 'W' || check[ny][nx] == true) continue;
			q.emplace(ny, nx, cnt + 1);
			check[ny][nx] = true;
			temp_ans = max(temp_ans, cnt + 1);
		}
	}
	ans = max(ans, temp_ans);
}
int main()
{
	scanf("%d%d", &r, &c);
	vector<string> s(r);
	for (int i = 0; i < r; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (s[i][j] == 'L') {
				bfs(s,i,j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
