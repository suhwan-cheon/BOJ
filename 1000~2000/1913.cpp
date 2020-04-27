#include <iostream>
using namespace std;

int a[1001][1001];
int n;
int main()
{
	scanf("%d", &n);
	int k; scanf("%d", &k);
	int cnt = n * n;
	int dir = 0; // 0: 아래 1: 오른쪽 2: 위쪽 3:왼쪽
	int i = 0; int j = 0;
	int dir_cnt = 1;
	int t = n;
	while (cnt) {
		a[i][j] = cnt;
		if (dir == 0) {
			i++;
			dir_cnt++;
			if (dir_cnt == t) {
				dir = 1;
				dir_cnt = 0;
				t--;
			}
		}
		else if (dir == 1) {
			j++;
			dir_cnt++;
			if (dir_cnt == t) {
				dir = 2;
				dir_cnt = 0;
				
			}
		}
		else if (dir == 2) {
			i--;
			dir_cnt++;
			if (dir_cnt == t) {
				dir = 3;
				dir_cnt = 0;
				t--;
			}
		}
		else {
			j--;
			dir_cnt++;
			if (dir_cnt == t) {
				dir = 0;
				dir_cnt = 0;
				
			}
		}
		cnt--;
	}
	int ans_y = 0, ans_x = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == k) {
				ans_y = i + 1;
				ans_x = j + 1;
			}
			printf("%d", a[i][j]);
			if (j != n - 1) printf(" ");
		}
		printf("\n");
		
	}
	printf("%d %d", ans_y, ans_x);
	return 0;
}
