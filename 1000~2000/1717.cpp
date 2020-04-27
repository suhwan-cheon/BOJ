#include <iostream>
using namespace std;

int p[1000001];

int find(int x) { //루트 찾기
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	p[y] = x;
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		p[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int cmd; scanf("%d", &cmd);
		if (cmd == 0) {
			int a, b; scanf("%d%d", &a, &b);
			uni(a, b);
		}
		else if (cmd == 1) {
			int a, b; scanf("%d%d", &a, &b);
			if (find(a) == find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}

