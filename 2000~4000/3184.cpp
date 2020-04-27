#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int r, c;
bool check[250][250];
int d[250 * 250][2];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
void bfs(vector<string>& a, int y, int x, int cnt) {
	check[y][x] = true;
	queue<pair<int, int> >q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (a[y][x] == 'v') d[cnt][0] += 1;
		else if (a[y][x] == 'o') d[cnt][1] += 1;
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (0 <= ny && ny < r && 0 <= nx && nx < c) {
				if (a[ny][nx] == '#') continue;
				if (check[ny][nx]) continue;
				q.push(make_pair(ny, nx));
				check[ny][nx] = true;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &r, &c);
	vector<string> a(r+1);
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	//bfs
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (check[i][j] == false && a[i][j] != '#') {
				bfs(a, i, j, cnt);
				cnt++;
			}
		}
	}
	int sheep = 0;
	int wolf = 0;
	for (int i = 0; i < cnt; i++) {
		if (d[i][0] >= d[i][1]) wolf += d[i][0];
		else sheep += d[i][1];
	}
	printf("%d %d\n", sheep, wolf);
	return 0;
}
