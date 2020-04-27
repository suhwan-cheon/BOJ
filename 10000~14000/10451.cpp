#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[1001];
vector <int> a[1001];
int dfs(int x) {
	check[x] = true;
	int y = a[x][0];
	if (check[y] == true) return 1;
	else dfs(y);
}
int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			a[i].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] != true) cnt +=dfs(i);
		}
		cout << cnt << "\n";
		for (int i = 1; i <= n; i++) {
			check[i] = false;
			a[i].clear();
		}
	}
	return 0;
}
