#include <iostream>
#include <vector>
using namespace std;

int board[20][20];
int x, y;
int k;
int n, m;
int dice[6]; // up, down, 동, 서, 북, 남 순서대로
void turn_east() {
	int temp_dice[6] = { 0, };
	temp_dice[2] = dice[0];
	temp_dice[3] = dice[1];
	temp_dice[1] = dice[2];
	temp_dice[0] = dice[3];
	for (int i = 0; i < 4; i++) {
		dice[i] = temp_dice[i];
	}
}
void turn_west() {
	int temp_dice[6] = { 0, };
	temp_dice[3] = dice[0];
	temp_dice[2] = dice[1];
	temp_dice[1] = dice[3];
	temp_dice[0] = dice[2];
	for (int i = 0; i < 4; i++) {
		dice[i] = temp_dice[i];
	}
}
void turn_north() {
	int temp_dice[6] = { 0, };
	temp_dice[4] = dice[0];
	temp_dice[5] = dice[1];
	temp_dice[1] = dice[4];
	temp_dice[0] = dice[5];
	temp_dice[2] = dice[2]; temp_dice[3] = dice[3];
	for (int i = 0; i < 6; i++) {
		dice[i] = temp_dice[i];
	}
}
void turn_south() {
	int temp_dice[6] = { 0, };
	temp_dice[4] = dice[1];
	temp_dice[5] = dice[0];
	temp_dice[1] = dice[5];
	temp_dice[0] = dice[4];
	temp_dice[2] = dice[2]; temp_dice[3] = dice[3];
	for (int i = 0; i < 6; i++) {
		dice[i] = temp_dice[i];
	}
}
int main()
{
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 1) { //동쪽
			if (y + 1 == m) continue;
			else {
				//주사위 회전
				turn_east();
				y++;
				if (board[x][y] == 0) {
					board[x][y] = dice[1];
				}
				else {
					dice[1] = board[x][y];
					board[x][y] = 0;
				}
			}
		}
		else if (cmd == 2) { //서쪽
			if (y == 0) continue;
			else {
				//주사위 회전
				turn_west();
				y--;
				if (board[x][y] == 0) {
					board[x][y] = dice[1];
				}
				else {
					dice[1] = board[x][y];
					board[x][y] = 0;
				}
			}
		}
		else if (cmd == 3) { //북쪽
			if (x == 0) continue;
			else {
				//주사위 회전
				turn_north();
				x--;
				if (board[x][y] == 0) {
					board[x][y] = dice[1];
				}
				else {
					dice[1] = board[x][y];
					board[x][y] = 0;
				}
			}
		}else if (cmd == 4) { //남쪽
			if (x+1 == n) continue;
			else {
				//주사위 회전
				turn_south();
				x++;
				if (board[x][y] == 0) {
					board[x][y] = dice[1];
				}
				else {
					dice[1] = board[x][y];
					board[x][y] = 0;
				}
			}
		}
		printf("%d\n", dice[0]);
	}
	return 0;
}

