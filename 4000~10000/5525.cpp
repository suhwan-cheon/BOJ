#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getPartialMatch(const string& s) {
	int temp = 0;
	int m = s.size();
	vector<int>pi(m, 0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (s[begin + matched] == s[matched]) {
			matched++;
			temp = max(temp, matched);
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return temp;
}
/*
vector<int> kmpSearch(const string& a, const string& b) {
	int n = a.size();
	int m = b.size();
	vector<int> pi = getPartialMatch(b);
	vector<int> ret;

	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && a[matched + begin] == b[matched]) {
			matched++;
			if (matched == m) {
				ret.push_back(begin);
			}
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}
*/
int main()
{
	string L; cin >> L;
	int ans = 0;
	int len = L.size();
	while (len--) {
		int k = getPartialMatch(L);
		ans = max(ans, k);
		L.erase(0, 1);
	}
	cout << ans << "\n";
	return 0;
}
