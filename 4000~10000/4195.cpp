#define mod 1000000007
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

bool visited[100010];
stack<int> st;
vector<int>v[100010];
void dfs(int cur) {
	visited[cur] = true;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (visited[next] == false) {
			dfs(next);
		}
	}
	st.push(cur);
}
void dfs2(int cur) {
	visited[cur] = true;
	for (int i = 0; i < v[cur].size(); i++) {
		int next = v[cur][i];
		if (visited[next] == false) {
			dfs2(next);
		}
	}
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 100010; i++) v[i].clear();
		memset(visited, false, sizeof(visited));
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			if (visited[i] == false) {
				dfs(i);
			}
		}
		memset(visited, false, sizeof(visited));
		int ans = 0;
		while (!st.empty()) {
			int temp = st.top();
			st.pop();
			if (visited[temp] == false) {
				dfs2(temp);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
