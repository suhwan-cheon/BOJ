#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	//입력
	int n; scanf("%d", &n);
	int h[500001];
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	//풀이
	long long ans = 0;
	stack<pair<int, int> > s;
	for (int i = 0; i < n; i++) {
		pair<int, int> p = { h[i], 1 };
		while (!s.empty()) {
			if (s.top().first <= h[i]) { //그 전 사람보다 키가 큰 경우
				ans += (long long)s.top().second;
				if (s.top().first == h[i]) {
					p.second += s.top().second;
				}
				s.pop();
			}
			else break;
		}
		if (!s.empty()) ans += 1LL;
		s.push(p);
	}
	printf("%lld", ans);
}
