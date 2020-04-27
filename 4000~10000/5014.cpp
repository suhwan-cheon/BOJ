#include <iostream>
#include <queue>
using namespace std;

bool check[1000001];
int a[1000001];
int f, s, g, u, d;

void bfs() {
	queue<int>q;
	q.push(s);
	check[s] = true;
	a[s] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int up = x + u;
		int down = x - d;
		if (up <= f) {
			if (check[up] == false) {
				q.push(up);
				check[up] = true;
				a[up] = a[x] + 1;
			}
		}
		if (down >= 1) {
			if (check[down] == false) {
				q.push(down);
				check[down] = true;
				a[down] = a[x] + 1;
			}
		}
	}
}
int main()
{
	cin >> f >> s >> g >> u >> d;
	bfs();
	if (check[g] == true) {
		printf("%d\n", a[g]);
	}
	else printf("use the stairs\n");
}
