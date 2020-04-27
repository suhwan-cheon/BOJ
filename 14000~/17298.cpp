#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int a[1000001];

int main()
{
	int n; scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> v(n);
	stack<int> s;
	s.push(0);
	for (int i = 1; i < n; i++) {
		if (s.empty()) { //초기 값
			s.push(i);
		}
		while (!s.empty() && a[s.top()] < a[i]) { //오큰수 발견 시
			v[s.top()] = a[i];
			s.pop(); //짝을 찾았으므로 pop
		}
		s.push(i); //현재 idx를 push
	}
	while (!s.empty()) { //짝을 찾지 못한 아이들
		v[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	return 0;
}
