#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long d[300001];
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	vector<int> v(n+1);
	v[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + v[i];
	}
	//n이 30만이므로 o(n)에 풀어야함..
	for (int i = 0; i < q; i++) {
		int L, R;
		scanf("%d %d", &L, &R);
		printf("%lld\n", d[R] - d[L-1]);
	}
	return 0;
}
