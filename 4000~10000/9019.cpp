#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

bool c[10001];

int cmd_d(int n) {
	if (n * 2 > 9999) return (2 * n) % 10000;
	else return (2 * n);
}
int cmd_s(int n) {
	if (n == 0) return 9999;
	else return n - 1;
}
int cmd_L(int n) {
	int first = n / 1000;
	int temp = (n % 1000) * 10;
	return temp + first;
}
int cmd_R(int n) {
	int last = (n % 10);
	int temp = (n / 10);

	return (last * 1000) + temp;
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d%d", &a, &b);
		queue<pair<int, string> >q;
		memset(c, false, sizeof(c));

		q.push(make_pair(a, ""));
		while (!q.empty()) {
			int num = q.front().first;
			string k = q.front().second;
			
			if (num == b) {
				cout << k << "\n";
				break;
			}
			q.pop();
			int x = cmd_d(num);
			if (c[x] == false) {
				c[x] = true;
				q.push(make_pair(x, k + "D"));
			}
			int y = cmd_s(num);
			if (c[y] == false) {
				c[y] = true;
				q.push(make_pair(y, k + "S"));
			}
			x = cmd_L(num);
			if (c[x] == false) {
				c[x] = true;
				q.push(make_pair(x, k + "L"));
			}
			y = cmd_R(num);
			if (c[y] == false) {
				c[y] = true;
				q.push(make_pair(y, k + "R"));
			}
		}
	}
	return 0;
}

