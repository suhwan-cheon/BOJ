#include <iostream>
using namespace std;

int board[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int main()
{
	int n, m; scanf("%d %d", &n, &m);
	int r, c, d; scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	int ans = 0;

	while (1) {
		if (board[r][c] == 0) {
			ans++;
			board[r][c] = 2;
		}
		//c,d 번 check
		bool check = false;
		for (int i = 0; i < 4; i++) {
			if (0 <= r + dy[i] && r + dy[i] < n && 0 <= c + dx[i] && c + dx[i] < m) {
				if (board[r + dy[i]][c + dx[i]] == 0) check = true;
			}
		}
		int temp_back = 0; //뒤쪽 방향 구하기
		if (d < 2) temp_back = d + 2;
		else temp_back = d - 2;
		if (!check && board[r + dy[temp_back]][c + dx[temp_back]] == 1) { //d번 사례
			break;
		}
		if (!check) { //c번 사례
			r = r + dy[temp_back];
			c = c + dx[temp_back];
			continue;
		}
		int temp_left = 0; // 왼쪽 방향 구하기
		if (d > 0) temp_left = d - 1;
		else temp_left = 3;
		if ((0 <= r + dy[temp_left] && r + dy[temp_left] < n && 0 <= c + dx[temp_left] && c + dx[temp_left] < m) && board[r + dy[temp_left]][c + dx[temp_left]] == 0) { //a번 사례
			r = r + dy[temp_left];
			c = c + dx[temp_left];
			d = temp_left;
			continue;
		}
		else {
			d = temp_left;
			continue;
		}
	}
	printf("%d\n", ans);
	return 0;
}
