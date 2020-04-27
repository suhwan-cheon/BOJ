#include <iostream>
using namespace std;

int p[101];
int find(int x) {
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
	int n; scanf("%d", &n); //컴퓨터의 수
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	int m; scanf("%d", &m); //컴퓨터 쌍의 수
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		uni(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (find(1) == find(i)) ans++;
	}
	printf("%d", ans - 1);
	return 0;
}

