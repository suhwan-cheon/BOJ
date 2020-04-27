#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	priority_queue<int, vector<int>, greater<int> >q;
	while (n--) {
		int x; scanf("%d", &x);
		if (x == 0) {
			cout << (q.empty() ? 0 : q.top()) << "\n";
			if (!q.empty()) q.pop();
		}
		else q.push(x);
	}
	return 0;
}

