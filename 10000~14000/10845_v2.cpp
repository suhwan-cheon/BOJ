#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	queue<int> q;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int temp; scanf("%d", &temp);
			q.push(temp);
		}
		else if (s == "pop") {
			if (q.empty()) printf("-1\n");
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") printf("%d\n", q.size());
		else if (s == "empty") cout << (q.empty() ? 1 : 0) << "\n";
		else if (s == "front") cout << (q.empty() ? -1 : q.front()) << "\n";
		else if (s == "back") cout << (q.empty() ? -1 : q.back()) << "\n";
	}
	return 0;
}

