#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	set<string> s;
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string k; cin >> k;
		s.insert(k);
	}
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		v.push_back(*iter);
	}

	for (int i = 1; i <= 50; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j].size() == i) {
				cout << v[j] << "\n";
			}
		}
	}
	return 0;
}

