#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	queue<int> q;
	while (n--) {
		string s;
		cin >> s;
		if (s == "push") {
			int temp; cin >> temp;
			q.push(temp);
		}
		else if (s == "pop") {
			if (q.empty()) cout << -1 << "\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (s == "size") cout << q.size() << "\n";
		else if (s == "empty") cout << (q.empty() ? 1 : 0) << "\n";
		else if (s == "front") cout << (q.empty() ? -1 : q.front()) << "\n";
		else if (s == "back") cout << (q.empty() ? -1 : q.back()) << "\n";
	}
	return 0;
}