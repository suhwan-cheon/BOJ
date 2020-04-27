#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<string> board;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int go(int cnt, int c1_y, int c1_x, int c2_y, int c2_x) {
	if (cnt > 10) return -1; //횟수 초과
	if (c1_y == c2_y && c1_x == c2_x) return -1; //코인이 겹친 경우
	bool coin1 = false, coin2 = false;
	if (c1_y < 0 || c1_y >= n || c1_x < 0 || c1_x >= m) coin1 = true;
	if (c2_y < 0 || c2_y >= n || c2_x < 0 || c2_x >= m) coin2 = true;
	if (coin1 && coin2) return -1;
	if (coin1 || coin2) return cnt;
	int ans = -1;
	for (int k = 0; k < 4; k++) {
		int ny1 = c1_y + dy[k];
		int nx1 = c1_x + dx[k];
		int ny2 = c2_y + dy[k];
		int nx2 = c2_x + dx[k];
		if (0 <= ny1 && ny1 < n && 0 <= nx1 && nx1 < m && board[ny1][nx1] == '#') { //벽이 있는 경우
			ny1 = c1_y;
			nx1 = c1_x;
		}
		if (0 <= ny2 && ny2 < n && 0 <= nx2 && nx2 < m && board[ny2][nx2] == '#') { //벽이 있는 경우
			ny2 = c2_y;
			nx2 = c2_x;
		}
		int temp = go(cnt + 1, ny1, nx1, ny2, nx2);
		if (temp == -1) continue;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) { //입력 받기
		string s; cin >> s;
		board.push_back(s);
	}
	int coin1_x, coin1_y;
	int coin2_x, coin2_y;
	//코인의 위치 입력 받기
	bool check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'o' && check == false) {
				coin1_y = i; coin1_x = j;
				check = true;
			}
			else if (board[i][j] == 'o' && check) {
				coin2_y = i; coin2_x = j;
			}
		}
	}
	//재귀 함수 호출 인자 : 버튼 클릭 횟수, 동전의 상태
	int ans = go(0, coin1_y, coin1_x, coin2_y, coin2_x);
	printf("%d\n", ans);
	return 0;
}

