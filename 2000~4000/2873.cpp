#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int happy[1001][1001];
int r, c;
string ans;

void append(string& ans, char c, int cnt) {
	for (int i = 0; i < cnt; i++) {
		ans += c;
	}
}

void side() {
	int mul = r * c - 1;
	int x = 0, y = 0;
	int dir = 0; // 0: 동 1: 북 2: 서 3: 남
	while (mul--) {
		if (dir == 0 && x + 1 < c) { // -->
			x++;
			ans.push_back('R');
		}
		else if (dir == 0 && x + 1 == c) { // 우측 끝
			y++;
			ans.push_back('D');
			dir = 3;
		}
		else if (dir == 2 && x - 1 >= 0) { // <--
			x--;
			ans.push_back('L');
		}
		else if (dir == 2 && x - 1 == -1) { // 좌측 끝
			y++;
			ans.push_back('D');
			dir = 3;
		}
		else if (dir == 3 && x + 1 == c) { //우측 경계
			x--;
			ans.push_back('L');
			dir = 2;
		}
		else if (dir == 3 && x - 1 == -1) { //좌측 경계
			x++;
			ans.push_back('R');
			dir = 0;
		}
	}
}
void up_down() {
	int mul = r * c - 1;
	int x = 0, y = 0;
	int dir = 3; // 0: 동 1: 북 2: 서 3: 남
	while (mul--) {
		if (dir == 3 && y + 1 < r) { // up
			y++;
			ans.push_back('D');
		}
		else if (dir == 3 && y + 1 == r) { // 아래 끝
			x++;
			ans.push_back('R');
			dir = 0;
		}
		else if (dir == 1 && y - 1 >= 0) { // down
			y--;
			ans.push_back('U');
		}
		else if (dir == 1 && y - 1 == -1) { // 윗쪽 끝
			x++;
			ans.push_back('R');
			dir = 0;
		}
		else if (dir == 0 && y + 1 == r) { //아래측 경계
			y--;
			ans.push_back('U');
			dir = 1;
		}
		else if (dir == 0 && y - 1 == -1) { //위측 경계
			y++;
			ans.push_back('D');
			dir = 3;
		}
	}
}

void couple() {
	int x, y;
	x = 0;
	y = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if ((i + j) % 2 == 1) {
				if (happy[x][y] > happy[i][j]) {
					x = i;
					y = j;
				}
			}
		}
	}
	int x1 = 0;
	int y1 = 0;
	int x2 = r - 1;
	int y2 = c - 1;
	string ans2 = "";
	while (x2 - x1 > 1) {
		if (x1 / 2 < x / 2) {
			append(ans, 'R', c - 1);
			append(ans, 'D', 1);
			append(ans, 'L', c - 1);
			append(ans, 'D', 1);
			x1 += 2;
		}
		if (x / 2 < x2 / 2) {
			append(ans2, 'R', c - 1);
			append(ans2, 'D', 1);
			append(ans2, 'L', c - 1);
			append(ans2, 'D', 1);
			x2 -= 2;
		}
	}
	while (y2 - y1 > 1) {
		if (y1 / 2 < y / 2) {
			append(ans, 'D', 1);
			append(ans, 'R', 1);
			append(ans, 'U', 1);
			append(ans, 'R', 1);
			y1 += 2;
		}
		if (y / 2 < y2 / 2) {
			append(ans2, 'D', 1);
			append(ans2, 'R', 1);
			append(ans2, 'U', 1);
			append(ans2, 'R', 1);
			y2 -= 2;
		}
	}
	if (y == y1) {
		append(ans, 'R', 1);
		append(ans, 'D', 1);
	}
	else {
		append(ans, 'D', 1);
		append(ans, 'R', 1);
	}
	reverse(ans2.begin(), ans2.end());
	ans += ans2;
}
int main()
{
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &happy[i][j]);
		}
	}
	if (r % 2 == 1) {
		side();
		cout << ans;
	}
	else if (c % 2 == 1) {
		up_down();
		cout << ans;
	}
	else {
		couple();
		cout << ans;
	}
	return 0;
}
