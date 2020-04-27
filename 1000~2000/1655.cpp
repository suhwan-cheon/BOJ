#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	int n; scanf("%d", &n);

	priority_queue<int> left; //최대 힙
	priority_queue<int, vector<int>, greater<int> > right;

	while (n--) {
		int k; scanf("%d", &k);

		if (left.empty() || right.empty()) left.push(k);
		else {
			if (k <= left.top()) {
				left.push(k);
			}
			else if (k >= right.top()) {
				right.push(k);
			}
			else {
				left.push(k);
			}
		}
		if (left.size() != right.size() && left.size() != right.size() + 1) {
			if (left.size() > right.size()) {
				right.push(left.top());
				left.pop();
			}
			else {
				left.push(right.top());
				right.pop();
			}
		}
		printf("%d\n", left.top());
	}
	return 0;
}

