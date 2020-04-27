#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

//idx까지의 psum return
ll query(vector<ll>& tree, int idx) {
	ll ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

void update(vector<ll>& tree, int idx, int value) {
	while (idx < tree.size()) {
		tree[idx] += value;
		idx += (idx & -idx);
	}
}
int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		vector<ll> arr(n + m + 2);
		vector<ll> tree(n + m + 2);
		int Maxrange = n + m + 1;
		int next = n + 1;
		//init fenwick tree
		//arr[i] : 층간 개념. i = 1이 가장 위에 있으니 n-1 층이 된다.
		//ex) arr[1] = n-1, arr[n] = 0
		for (int i = 1; i <= n; i++) {
			arr[i] = n - i + 1;
			//한 층에 하나씩이므로 모두 1로 update
			update(tree, i, 1);
		}
		for (int i = 0; i < m; i++) {
			int value;
			scanf("%d", &value);
			//value 위에 있는 dvd의 수 = 전체 dvd - 밑에 있는 dvd
			ll ans = query(tree, Maxrange) - query(tree, arr[value]);
			printf("%lld ", ans);
			//이제 value 층을 없애고, 그 위에 있던 dvd의 수를 바꿔주어야 한다.
			update(tree, arr[value], -1);
			arr[value] = next;
			next++;
			//올려놓았으니 update
			update(tree, arr[value], 1);
		}
		printf("\n");
	}
	return 0;
}
