#include <iostream>
using namespace std;

int n, r, c;
int ans = 0;

void solve(int y, int x,int n, int squard) {
	if (n == 1) { //기저 사례
		if (y == r) {
			if (x == c) return;
			else {
				ans += 1;
				return;
			}
		}
		else if (x==c){
			ans+= 2;
			return;
		}
		else {
			ans += 3;
			return;
		}
	}

	if ((y <= r && r < y+squard / 2) && (x <= c && c < x+squard / 2)) { //왼쪽 위
		solve(y, x, n - 1, squard / 2);
	}
	else if ((y <= r && r < y+squard / 2) && (x+squard / 2 <= c && c < x+squard)) { //오른쪽위
		ans += (squard / 2) * (squard / 2);
		solve(y, x + (squard / 2), n - 1, squard / 2);
		
	}
	else if ((y+squard / 2 <= r && r < y+squard) && (x <= c && c < x+squard / 2)) { // 왼쪽 아래
		ans += 2 * (squard / 2) * (squard / 2);
		solve(y + (squard / 2), x, n - 1, squard / 2);
		
	}
	else {//오른쪽 아래
		ans += 3 * (squard / 2) * (squard / 2);
		solve(y + (squard / 2), x + (squard / 2), n - 1, squard / 2);
		
	}
}
int main()
{
	scanf("%d%d%d", &n, &r, &c);
	int squard = 1;
	for (int i = 0; i < n; i++) {
		squard *= 2;
	}
	solve(0, 0, n,squard);
	printf("%d", ans);
}

