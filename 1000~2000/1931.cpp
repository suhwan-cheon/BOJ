#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int ans = 0;
	vector<pair<int, int> >p;
	for (int i = 0; i < n; i++) { //pair(끝나는 시간, 시작 시간)
		int a, b; scanf("%d%d", &a, &b);
		p.push_back(pair<int, int>(b, a));
	}
	sort(p.begin(), p.end());
	int end = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].second >= end) {
			ans++;
			end = p[i].first;
		}
	}
	printf("%d", ans);
	return 0;
}

