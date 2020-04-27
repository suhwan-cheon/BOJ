#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

long long a[100001];
int main()
{
	
		int n; scanf("%d", &n);
		stack<int> s;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			int left = i;
			while (!s.empty() && a[s.top()] > a[i]) {
				long long height = a[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) width = (i - s.top() - 1);
				if (ans < width * height) ans = width * height;
			}
			s.push(i);
	}
		while (!s.empty()) {
			long long height = a[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) width = n - s.top() - 1;
			if (ans < width * height) ans = width * height;
		}
		printf("%lld\n", ans);
	return 0;
}

