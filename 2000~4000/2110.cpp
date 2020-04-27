#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& v, int m, int t) {
	int cnt = 1;
	int last = v[0];
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - last >= t) {
			cnt++;
			last = v[i];
		}
	}
	return cnt >= m;
}
int main()
{
	int n, c; scanf("%d%d", &n, &c);
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x.begin(), x.end());
	//left : 최소 거리, right : 최대 거리
	int left = 1;
	int right = x[n-1] - x[0];
	int ans = left;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(x, c, mid)) { //c 이상으로 공유기 설치 가능
			if (ans < mid) ans = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d", ans);
	return 0;
}

