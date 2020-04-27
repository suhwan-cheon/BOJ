#include <iostream>
using namespace std;

int board[100][100];
int bam[100][100];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int dir = 0;
int head_y, head_x, tail_y, tail_x;
int main()
{
	int n; scanf("%d", &n);
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) { //사과
		int temp_x, temp_y;
		scanf("%d %d", &temp_x, &temp_y);
		board[temp_x][temp_y] = 1;
	}
	int L; scanf("%d", &L);
	int cnt = 0; int ans = 0; bool check = false;
	bam[0][0] = 1; //뱀 위치 초기값
	while (L--) {
		int x; char c; cin >> x >> c;
		int time = x - cnt;
		for (int i = 0; i < time; i++) {
			if (0 <= head_y + dy[dir] && head_y + dy[dir] < n && 0 <= head_x + dx[dir]
				&& head_x + dx[dir] < n && bam[head_y + dy[dir]][head_x + dx[dir]] != 1) { //게임이 끝나지 않을 조건
				if (board[head_y + dy[dir]][head_x + dx[dir]] == 1) { //사과인 경우
					board[head_y + dy[dir]][head_x + dx[dir]] = 0; //사과를 없앰
					head_y += dy[dir]; head_x += dx[dir]; //머리를 늘임
					bam[head_y + dy[dir]][head_x + dx[dir]] = 1;
					cnt++;
					
				}
				else { //사과가 아닌 경우
					bam[head_y + dy[dir]][head_x + dx[dir]] = 1;
					head_y += dy[dir]; head_x += dx[dir]; //머리를 늘임
					cnt++;
					bam[tail_y][tail_x] = 0; //꼬리를 자름
					tail_y += dy[dir]; tail_x = dx[dir];
				}
			}
			else {
				ans = cnt + 1;
				check = true;
				break;
			}
		}
		if (check) break; //뱀이 죽을 경우
		//방향 전환
		if (c == 'D') { //왼쪽 회전
			if (dir > 0) dir--;
			else dir = 3;
		}
		else if (c == 'L'){ //오른쪽 회전
			if (dir < 3) dir++;
			else dir = 0;
		}
	}
	if (!check) { //뱀이 아직도 살아있다?!
		ans = 100;
	}
	printf("%d\n", ans);
	return 0;
}

