#include <iostream>
using namespace std;

int video[65][65];
void solve(int y, int x, int n) { 
	if (n == 1) {
		printf("%d", video[y][x]);
		return;
	}
	int check = 1;
	for (int i = y; i < y+n; i++) {
		for (int j = x; j < x+n; j++) {
			if (video[y][x] != video[i][j]) check = 0;
		}
	}
	if (check == 1) printf("%d", video[y][x]);
	else {
		printf("(");
		solve(y, x, n / 2);
		solve(y, x + (n / 2), n / 2);
		solve(y + (n / 2), x, n / 2);
		solve(y + (n / 2), x + (n / 2), n / 2);
		printf(")");
	}
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char a; scanf(" %c", &a);
			video[i][j] = a - '0';
		}
	}
	solve(0, 0, n);
	return 0;
}

