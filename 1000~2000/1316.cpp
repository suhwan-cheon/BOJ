#include <iostream>
#include <string>
using namespace std;

bool ans_h(string s) {
	bool a[26] = { false };

	for (int i = 0; i < s.size(); i++) {
		if (a[s[i] - 'a']) {
			return false;
		}
		else {
			char tmp = s[i];
			a[s[i] - 'a'] = true;

			while (1) {
				if (tmp != s[++i]) {
					i--;
					break;
				}
			}
		}
	}
	return true;
}

int main() {
	int n; cin >> n;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if(ans_h(s)) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}