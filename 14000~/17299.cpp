#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int f[1000001];
int main()
{
    
	int n; scanf("%d", &n);
	vector<int> a(n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		f[a[i]]++; //개수 카운트
	}

	vector<int> ans(n);
	stack<int> s;
	s.push(0); //처음 idx 저장

	for (int i = 1; i < n; i++) {
		if (s.empty()) s.push(i);
		while (!s.empty() && f[a[s.top()]] < f[a[i]]) { //오등큰수 발견 시
			ans[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}
