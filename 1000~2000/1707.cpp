#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int check[20001];
vector <int> a[20001];

void dfs(int node, int c) {
	check[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}
int main()
{
	int k; cin >> k;
	while (k--) {
		int v, e; cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			a[i].clear();
			check[i] = 0;
		}
		for (int i = 0; i < e; i++) {
			int x, y; cin >> x >> y;
			a[x].push_back(y); a[y].push_back(x);
		}
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		bool ok = true;
		for (int i = 1; i <= v; i++) {
			for (int k = 0; k < a[i].size(); k++) {
				int j = a[i][k];
				if (check[i] == check[j]) {
					ok = false;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
	return 0;
}
