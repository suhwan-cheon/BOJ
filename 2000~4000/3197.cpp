#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string a[1500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool wcheck[1500][1500];
bool scheck[1500][1500];
int r, c;
int swan1_y, swan1_x, swan2_y, swan2_x;
queue<pair<int, int> >swan, nswan, water, nwater;
void go() { //simulate
	while (!water.empty()) {
		int y = water.front().first;
		int x = water.front().second;
		water.pop();
		a[y][x] = '.';
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (wcheck[ny][nx]) continue;
			if (a[ny][nx] == '.') {
				water.emplace(ny, nx);
				wcheck[ny][nx] = true;
			}
			else {
				nwater.emplace(ny, nx);
				wcheck[ny][nx] = true;
			}
			
		}
	}
}
bool check() {
	
	while (!swan.empty()) {
		int y = swan.front().first;
		int x = swan.front().second;
		swan.pop();
		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
			if (scheck[ny][nx]) continue;
			if (a[ny][nx] == '.') {
				swan.emplace(ny, nx);
				scheck[ny][nx] = true;
			}
			else {
				nswan.emplace(ny, nx);
				scheck[ny][nx] = true;
			}
		}
	}
	if (scheck[swan2_y][swan2_x]) return true;
	else return false;
}
int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		cin >> a[i];
	}
	bool check1 = false;
	for (int i = 0; i < r; i++) { //백조 좌표 기록
		for (int j = 0; j < c; j++) {
			if (a[i][j] == 'L' && check1 == false) {
				swan1_y = i; swan1_x = j;
				check1 = true;
				a[i][j] = '.';
			}
			else if (a[i][j] == 'L' && check1 == true) {
				swan2_y = i; swan2_x = j;
				a[i][j] = '.';
			}
			if (a[i][j] == '.') {
				water.emplace(i, j);
				wcheck[i][j] = true;
			}
		}
	}
	swan.emplace(swan1_y, swan1_x);
	for (int i = 0;; i++) {
		go();
		if (check()) {
			printf("%d\n", i);
			break;
		}
		water = nwater;
		swan = nswan;
		nwater = queue<pair<int, int>>();
		nswan = queue<pair<int, int>>();
	}
	return 0;
}
