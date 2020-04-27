#include <iostream>
#include <cstring>
using namespace std;

string s;
int s_size, a_cnt, b_cnt, c_cnt;
bool d[51][51][51][3][3];
char ans[51];
bool go(int a, int b, int c,int fin1, int fin2) {
	if (a+b+c == s_size) {
		return true;
	}
	if (d[a][b][c][fin1][fin2] == true) return false;
	d[a][b][c][fin1][fin2] = true;
	//a 사람
	if (a < a_cnt) {
		ans[a + b + c] = 'A';
		if (go(a + 1, b, c, 0, fin1)) return true;
	}
	//b 사람
	if (b < b_cnt && fin1 != 1) {
		ans[a+b+c] = 'B';
		if (go(a, b + 1, c, 1, fin1)) return true;
	}
	//c 사람
	if (c < c_cnt && fin1 != 2 && fin2 != 2) {
		ans[a + b + c] = 'C';
		if (go(a, b, c + 1, 2, fin1)) return true;
	}
	return false;
}
int main()
{
	cin >> s;
	s_size = s.size();
	for (auto i : s) {
		if (i == 'A') a_cnt++;
		else if (i == 'B') b_cnt++;
		else c_cnt++;
	}
	if (go(0, 0, 0,0,0)) {
		printf("%s\n", ans);
	}
	else printf("-1\n");
	return 0;
}