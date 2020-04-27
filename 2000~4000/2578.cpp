#include <iostream>
using namespace std;

int a[5][5];
bool bingo[5][5];
int cnt;
int check(int x) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (x == a[i][j]) bingo[i][j] = true;
		}
	}
	bool check_bingo;
	for (int i = 0; i < 5; i++) {
		check_bingo = false;
		for (int j = 0; j < 5; j++) {
			if (bingo[i][j] == false) {
				check_bingo = true;
				break;
			}
		}
		if (check_bingo == false) cnt++;
		check_bingo = false;
		for (int j = 0; j < 5; j++) {
			if (bingo[j][i] == false) {
				check_bingo = true;
				break;
			}
		}
		if (check_bingo == false) cnt++;
	}
	if (bingo[0][0] && bingo[1][1] && bingo[2][2] && bingo[3][3] && bingo[4][4]) cnt++;
	if (bingo[0][4] && bingo[1][3] && bingo[2][2] && bingo[3][1] && bingo[4][0]) cnt++;
	if (cnt >= 3) return true;
	else {
		cnt = 0;
		return false;
	}
}
int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 25; i++) {
		int temp; scanf("%d", &temp);
		if (check(temp)) {
			printf("%d\n", i+1);
			break;
		}
	}
	return 0;
}
