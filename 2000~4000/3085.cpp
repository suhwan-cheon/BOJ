#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
char board[50][50];
int ans = 1;
void go() {
	int cnt = 1;
	for (int i = 0; i < n; i++) { //가로줄
		char temp = board[i][0];
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (board[i][j] == temp) cnt++;
			else {
				temp = board[i][j];
				ans = max(ans, cnt);
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
	}
	for (int i = 0; i < n; i++) { //세로줄
		char temp = board[0][i];
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (board[j][i] == temp) cnt++;
			else {
				temp = board[j][i];
				ans = max(ans, cnt);
				cnt = 1;
			}
			ans = max(ans, cnt);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				swap(board[i][j], board[i][j + 1]);
				go();
				swap(board[i][j], board[i][j + 1]);
			}
			if (i + 1 < n) {
				swap(board[i][j], board[i + 1][j]);
				go();
				swap(board[i][j], board[i + 1][j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
