#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getPartialMatch(const string& s) {
	
	int m = s.size();
	vector<int>pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (s[begin + matched] == s[matched]) {
			matched++;
			pi[begin+matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}
int main()
{
	string s; cin >> s;
	int ans = 0;
	while (s.size() != 0) {
		vector<int>pi = getPartialMatch(s);
		int temp = 0;
		int len = 0;
		for (int i = 0; i < pi.size(); i++) {
			if (pi[i] > temp) {
				if (pi[i] == 1 && i != pi[i]) continue;
				temp = pi[i];
				len = i + 1;
			}
		}
		if (temp == 0) len = 1;
		cout << len << "\n";
		s.erase(0, len);
		cout << s << "\n";
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
