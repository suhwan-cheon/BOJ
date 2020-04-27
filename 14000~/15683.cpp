#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n, m;
void check(vector<vector<int> >& a, vector<vector<int> >& b, int x,
	int y, int dir) {
	int i = x;
	int j = y;
	while (0 <= i && i < n && 0 <= j && j < m) {
		if (a[i][j] == 6) break;
		b[i][j] = a[x][y];
		i += dx[dir];
		j += dy[dir];
	}
}
int go(vector<vector<int> >& a, vector<tuple<int, int, int> >& cctv,
	int idx, vector<int> dirs) {
	if (cctv.size() == idx) { //cctv를 다 배정한 경우
		vector<vector<int> >b(a); //copy
		for (int i = 0; i < cctv.size(); i++) {
			int what, x, y; // what : cctv 고유 번호
			tie(what, x, y) = cctv[i];
			if (what == 1) {
				check(a, b, x, y, dirs[i]);
			}
			else if (what == 2) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 3) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
			}
			else if (what == 4) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (what == 5) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
				check(a, b, x, y, (dirs[i] + 3) % 4);
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (b[i][j] == 0) {
					cnt++;
				}
			}
		}
		return cnt;
	}
	int ans = 100;
	for (int i = 0; i < 4; i++) { //brute force
		dirs[idx] = i;
		ans = min(ans, go(a, cctv, idx + 1, dirs));
	}
	return ans;
}
int main()
{
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	vector<tuple<int, int, int> > cctv;
	vector<int> dirs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] >= 1 && a[i][j] <= 5) { //cctv
				cctv.emplace_back(a[i][j], i, j);
				dirs.push_back(0);
			}
		}
	}
	cout << go(a, cctv, 0, dirs) << '\n';
	return 0;
}

