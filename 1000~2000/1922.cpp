#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int>v[1001];
int pay[1001][1001];
bool check[1001];
int main()
{
	priority_queue<pair<int, int> >q; // (pay, to)
	int n, m;
	scanf("%d %d", &n, &m);
	int start = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(b);
		v[b].push_back(a);
		pay[a][b] = c;
		pay[b][a] = c;
		start = a;
	}
	//다익스트라 초기값
	for (int i = 0; i < v[start].size(); i++) {
		q.push(make_pair(-1 * pay[start][v[start][i]], v[start][i]));
	}
	check[start] = true;
	int ans = 0;
	while (!q.empty()) {
		int x = q.top().second;
		int money = q.top().first;
		q.pop();
		if (check[x] == true) continue;
		check[x] = true;
		ans += (-1 * money);
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (check[y] == true) continue; //연결 되지 않은 노드일 때
			q.push(make_pair(-1 * pay[x][y], y));
		}
		
	}
	printf("%d\n", ans);
	return 0;
}

