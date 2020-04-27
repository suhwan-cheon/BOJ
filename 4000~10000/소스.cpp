#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		stack <char> st;
		stack <char> st2;

		cin >> s;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(s[i]);
			else if (s[i] == ')') {
				st2.push(s[i]);
				if (st.empty()) break;
				st.pop();
				st2.pop();
			}
		}
		if (st.empty() && st2.empty()) cout << "YES" << endl;
		else if (!st.empty() || !st2.empty()) cout << "NO" << endl;
	}
}