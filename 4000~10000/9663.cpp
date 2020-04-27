#include <iostream>
#include <cstdbool>
#include <cstring>
using namespace std;

int ans;
int n;
bool a[15][15];
bool check(int row, int col) {
	for (int i = 0; i < n; i++) { //열을 위로 올리면서
		if (i == row) continue;
		if (a[i][col]) return false; //해당 열에 갈 수 없는 경우 false 리턴
	}
	// 왼쪽 위 대각선
	int x = row - 1;
	int y = col - 1;
	while (x >= 0 && y >= 0) {
		if (a[x][y] == true) {
			return false;
		}
		x -= 1;
		y -= 1;
	}
	// 오른쪽 위 대각선
	x = row - 1;
	y = col + 1;
	while (x >= 0 && y < n) {
		if (a[x][y] == true) {
			return false;
		}
		x -= 1;
		y += 1;
	}
	return true;
}
void queen(int row) {
	if (row == n) ans++;
	for (int col = 0; col < n; col++) { //해당 열 확인
		a[row][col] = true;
		if (check(row, col)) { //열이 비어있으면 다음 행으로 전진
			queen(row + 1);
		}
		a[row][col] = false; //백트래킹
	}
}
int main()
{
	scanf("%d", &n);
	queen(0);
	cout << ans;
	return 0;
}

