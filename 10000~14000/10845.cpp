#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n; cin >> n;
	queue <int> q;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int k;
			cin >> k;
			q.push(k);
		}
		else if (s == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";;
				q.pop();
			}
			else cout << -1 << "\n";
		}
		else if (s == "size") cout << q.size() << "\n";
		else if (s == "empty") cout << (!q.empty() ? 0 : 1) << "\n";
		else if (s == "front") cout << q.front() << "\n";
		else if (s == "back") cout << q.back() << "\n";
	}
	return 0;
}
