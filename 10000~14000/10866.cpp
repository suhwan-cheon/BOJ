#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	deque<int> d;
	while (n--) {
		string s; cin >> s;
		if (s == "push_front") {
			int temp; scanf("%d", &temp);
			d.push_front(temp);
		}
		else if (s == "push_back") {
			int temp; scanf("%d", &temp);
			d.push_back(temp);
		}
		else if (s == "pop_front") {
			if (d.empty()) printf("-1\n");
			else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty()) printf("-1\n");
			else {
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if (s == "size") printf("%d\n", d.size());
		else if (s == "empty") cout << (d.empty() ? 1 : 0) << "\n";
		else if (s == "front") cout << (d.empty() ? -1 : d.front()) << "\n";
		else if (s == "back") cout << (d.empty() ? -1 : d.back()) << "\n";
	}
	return 0;
}

