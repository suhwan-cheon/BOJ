#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
#include <algorithm>
using namespace std;

int a[50][50];
int n, m;
int ans = 10000;
bool check[250];
bool check2[50][50];
int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

//2. bfs
int simulate(vector<pair<int, int> >& v) {
	int temp_ans = 0;
	memset(check2, false, sizeof(check2));
	queue<tuple<int, int, int> >q;
	for (int i = 0; i < m; i++) {
		q.emplace(v[i].first, v[i].second, 0);
		check2[v[i].first][v[i].second] = true;
	}
	while (!q.empty()) {
		int y, x, cnt;
		tie(y, x, cnt) = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (check2[ny][nx] == true) continue;
			if (a[ny][nx] == 1) continue;
			q.emplace(ny, nx, cnt + 1);
			check2[ny][nx] = true;
			temp_ans = max(temp_ans, cnt + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 || a[i][j] == 2) { //빈 공간인데 false 인경우
				if (check2[i][j] == false) {
					return 99999;
				}
			}
		}
	}
	return temp_ans;
}
void go(vector<pair<int, int> >&v, int cnt, vector<pair<int, int> >&virus) {
	if (cnt == m) {
		int temp = simulate(v);
		ans = min(ans, temp);
		return;
	}
	int virus_len = virus.size();
	for (int i = 0; i < virus_len; i++) {
		if (check[i] == true) continue;
		else {
			v.push_back(virus[i]);
			check[i] = true;
			go(v, cnt + 1, virus);
			v.pop_back();
			check[i] = false;
		}
	}
}
int main()
{
	vector<pair<int, int> >virus;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	//1. brute force
	vector<pair<int, int> >v;
	go(v, 0, virus);
	if (ans == 10000) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
