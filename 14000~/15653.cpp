#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int d[10][10][10][10]; //몇 번 째 이동인지 check 배열
int hx, hy; //구멍의 위치(불변)
//구슬 이동 simulate
pair<bool, bool> simulate(vector<string>& a, int k, int& x, int& y) {
	if (a[x][y] == '.') return make_pair(false, false); //어떤 구슬이 빠져버린 경우
	bool moved = false;
	while (true) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			return make_pair(moved, false);
		}
		if (a[nx][ny] == '#') { //그 다음이 벽인 경우
			return make_pair(moved, false);
		}
		else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') {
			return make_pair(moved, false);
		}
		else if (a[nx][ny] == '.') { //빈칸인 경우 swap
			swap(a[nx][ny], a[x][y]);
			x = nx;
			y = ny;
			moved = true;
		}
		else if (a[nx][ny] == 'O') { //구멍인 경우
			a[x][y] = '.';
			moved = true;
			return make_pair(moved, true);
		}
	}
	return make_pair(false, false);
}
pair<bool, bool> next(vector<string> a, int& rx, int& ry, int& bx, int& by, int dir) {
	a[rx][ry] = 'R';
	a[bx][by] = 'B';
	bool hole1 = false, hole2 = false;
	while (true) {
		auto p1 = simulate(a, dir, rx, ry);
		auto p2 = simulate(a, dir, bx, by);
		if (p1.first == false && p2.first == false) { //더 이상 움직이지 않을 때
			break;
		}
		if (p1.second) hole1 = true; //구슬의 빠짐 여부
		if (p2.second) hole2 = true;
	}
	return make_pair(hole1, hole2);
}
int main() {
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = -1;
	queue<tuple<int, int, int, int>> q;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'O') {
				hx = i; hy = j;
			}
			else if (a[i][j] == 'R') {
				rx = i; ry = j;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'B') {
				bx = i; by = j;
				a[i][j] = '.';
			}
		}
	}
	memset(d, -1, sizeof(d));
	q.emplace(rx, ry, bx, by); //push랑 같음
	d[rx][ry][bx][by] = 0; //처음 위치
	bool found = false;
	while (!q.empty()) { //bfs
		tie(rx, ry, bx, by) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) { //방향
			bool hole1, hole2;
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			tie(hole1, hole2) = next(a, nrx, nry, nbx, nby, k);
			if (hole2) continue;
			if (hole1) {
				found = true;
				ans = d[rx][ry][bx][by] + 1;
				break;
			}
			if (d[nrx][nry][nbx][nby] != -1) continue;
			q.emplace(nrx, nry, nbx, nby);
			d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1;
		}
		if (found) {
			break;
		}
	}
	cout << ans << '\n';
	return 0;
}