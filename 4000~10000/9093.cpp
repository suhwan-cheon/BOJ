#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int t; cin >> t;
	cin.ignore();
	while (t--) {
		string s = "";
		getline(cin, s);
		s += '\n';
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ' || s[i] == '\n') {
				while (!st.empty()) {
					printf("%c", st.top());
					st.pop();
				}
				printf(" ");
			}
			else st.push(s[i]);
		}
		
	}
	return 0;
}