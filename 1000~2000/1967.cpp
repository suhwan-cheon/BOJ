#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

bool check[100001];
vector<pair<int, int> >w[100001];
int far = 0;
int d = 0;
void dfs(int node, int cost) {
	if (check[node]) return;
	check[node] = true;
	if (d < cost) {
		d = cost;
		far = node;
	}
	for (int i = 0; i < w[node].size(); i++) {
		dfs(w[node][i].first, cost + w[node][i].second);
	}
}
int main()
{
	int v; scanf("%d", &v);
	for (int i = 0; i < v-1; i++) {
		int node; scanf("%d", &node);
		while (1) { //-1이 입력될 때까지
			int next, weight;
			scanf("%d", &next);
			if (next == -1) break;
			scanf("%d", &weight);
			w[node].push_back(make_pair(next, weight));
			w[next].push_back(make_pair(node, weight));
		}
	}
	
	//루트 ~ 가장 먼점 찾기
	dfs(1, 0);
	//가장 먼점에서 가장 먼 점 찾기
	memset(check, false, sizeof(check));
	d = 0;
	dfs(far, 0);
	printf("%d\n", d);
	return 0;
}
