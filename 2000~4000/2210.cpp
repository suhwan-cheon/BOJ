#include <iostream>
#include <set>
#include<string>
using namespace std;

int a[5][5];
set<int>st;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void go(int cnt, int num, int x, int y) {
	if (cnt == 6) {
		st.insert(num);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
			go(cnt + 1, num*10 + a[nx][ny], nx, ny);
		}
	}
	return;
}
int main()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	string s = "";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(1, a[i][j], i, j);
		}
	}
	int ans = st.size();
	printf("%d\n", ans);
	return 0;
}
