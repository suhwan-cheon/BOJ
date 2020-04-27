#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	set<string> st1;
	set<string> st2;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		st1.insert(s);
	}
	for (int i = 0; i < m; i++) {
		string s1; cin >> s1;
		auto iter= st1.find(s1);
		if (iter != st1.end()) st2.insert(s1);
	}
	cout << st2.size() << "\n";
	for (auto it = st2.begin(); it != st2.end(); it++) {
		cout << *it << "\n";
	}
	return 0;
}

