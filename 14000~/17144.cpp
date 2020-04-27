#include <iostream>
#include <cstring>
using namespace std;

int a[50][50];
int temp[50][50]; //임시 저장 배열
int r, c, t;
int top_x, top_y, bottom_x, bottom_y; //공기 청정기 위치
int dy[] = { 0,0,1,-1 }; //4방향
int dx[] = { 1,-1,0,0 };

void diffu() { //미세먼지의 확산
	memset(temp, 0, sizeof(temp)); //임시 배열 초기화
	temp[top_y][top_x] = -1;
	temp[bottom_y][bottom_x] = -1;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != -1 && a[i][j] != 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ty = i + dy[k];
					int tx = j + dx[k];
					if (a[ty][tx] != -1 && 0 <= ty && ty < r
						&& 0 <= tx && tx < c) { //범위를 벗어나지 않는 경우
						temp[ty][tx] += (a[i][j] / 5);
						cnt++;
					}
				}
				temp[i][j] += a[i][j] - (a[i][j] / 5) * cnt;
			}
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = temp[i][j];
			
		}
		
	}
}

void clean() { //공기청정기의 작동
	memset(temp, 0, sizeof(temp)); //임시 배열 초기화
	temp[top_y][top_x] = -1;
	temp[bottom_y][bottom_x] = -1;

	//top
	for (int i = 2; i < c; i++) {
		temp[top_y][i] = a[top_y][i - 1];
	}
	for (int i = top_y-1; i >= 0; i--) {
		temp[i][c - 1] = a[i + 1][c - 1];
	}
	for (int i = c - 2; i >= 0; i--) {
		temp[0][i] = a[0][i + 1];
	}
	for (int i = 1; i < top_y; i++) {
		temp[i][0] = a[i - 1][0];
	}
	//bottom
	for (int i = 2; i < c; i++) {
		temp[bottom_y][i] = a[bottom_y][i - 1];
	}
	for (int i = bottom_y + 1; i < r; i++) {
		temp[i][c - 1] = a[i - 1][c - 1];
	}
	for (int i = c - 2; i >= 0; i--) {
		temp[r-1][i] = a[r-1][i + 1];
	}
	for (int i = r-2; i > bottom_y; i--) {
		temp[i][0] = a[i + 1][0];
	}

	//나머지 범위 값들 대입
	for (int i = 1; i < r-1; i++) {
		for (int j = 1; j < c-1; j++) {
			if (i != top_y && i != bottom_y) {
				temp[i][j] = a[i][j];
			}
		}
	}
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = temp[i][j];
			
		}
		
	}
}
int main()
{
	scanf("%d %d %d", &r, &c, &t);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == -1) {
				if (top_y == 0) {
					top_y = i; top_x = j;
				}
				else {
					bottom_y = i; bottom_x = j;
				}
			}
		}
	}
	while (t--) {
		diffu(); //미세먼지 확산
		clean();
	}
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (a[i][j] != -1) ans += a[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
