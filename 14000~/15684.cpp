#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, h;
int start(vector<vector<int> >&a, int c) { //사다리 게임 시작!
	int k = 1;
	while (k <= h) {
		if (a[k][c] == 1) {
			c++;
		}
		else if (a[k][c] == 2) {
			c--;
		}
		k++;
	}
	return c;
}
bool go(vector<vector<int> >& a) { //사다리 세로줄 이동
	for (int i = 1; i <= n; i++) {
		int temp = start(a, i);
		if (temp != i) return false;
	}
	return true; //모든 줄이 만족할 때
}
int main()
{
	scanf("%d %d %d", &n, &m, &h);
	vector<vector<int> >a(h+1, vector<int>(n+1)); // h * n 배열

	for (int i = 1; i <= h; i++) { //배열 초기화
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
		}
	}
	
	for (int i = 0; i < m; i++) {
		int s, t;
		scanf("%d%d", &s, &t);
		a[s][t] = 1; a[s][t + 1] = 2; //여기 사다리있음
	}
	vector<pair<int, int> >ladder;
	for (int i = 1; i <= h; i++) { //사다리 놓을 공간 좌표 pair
		for (int j = 1; j < n; j++) {
			if (a[i][j] != 0) continue;
			if (a[i][j + 1] != 0) continue;
			ladder.push_back(make_pair(i, j));
		}
	}
	int ans = -1;
	if (go(a)) { //초기 상황
		printf("0\n");
		return 0;
	}
	int len = ladder.size();
	for (int i = 0; i < len; i++) {
		int x1 = ladder[i].first;
		int y1 = ladder[i].second;
		if (a[x1][y1] != 0 || a[x1][y1 + 1] != 0) continue;
		a[x1][y1] = 1;
		a[x1][y1 + 1] = 2;
		if (go(a)) {
			if (ans == -1 || ans > 1) {
				ans = 1;
			}
		}
		for (int j = i + 1; j < len; j++) {
			int x2 = ladder[j].first;
			int y2 = ladder[j].second;
			if (a[x2][y2] != 0 || a[x2][y2 + 1] != 0) continue;
			a[x2][y2] = 1;
			a[x2][y2 + 1] = 2;
			if (go(a)) {
				if (ans == -1 || ans > 2) {
					ans = 2;
				}
			}
			for (int k = j + 1; k < len; k++) {
				int x3 = ladder[k].first;
				int y3 = ladder[k].second;
				if (a[x3][y3] != 0 || a[x3][y3 + 1] != 0) continue;
				a[x3][y3] = 1;
				a[x3][y3 + 1] = 2;
				if (go(a)) {
					if (ans == -1 || ans > 3) {
						ans = 3;
					}
				}
				a[x3][y3] = 0;
				a[x3][y3 + 1] = 0;
			}
			a[x2][y2] = 0;
			a[x2][y2 + 1] = 0;
		}
		a[x1][y1] = 0;
		a[x1][y1 + 1] = 0;
	}
	printf("%d\n", ans);
	return 0;
}

