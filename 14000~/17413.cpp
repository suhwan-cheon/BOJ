#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	string s = "";
	getline(cin, s);
	s += '\n';
	stack<char> st;
	bool check = false;
	for (int i = 0; i < s.size(); i++) {
		
		if (s[i] == '<') {
			while (!st.empty()) {
				printf("%c", st.top());
				st.pop();
			}
			printf("<");
			check = true;
		}
		else if (s[i] == '>') {
			string a = "";
			while (!st.empty()) {
				a += st.top();
				st.pop();
			}
			reverse(a.begin(), a.end());
			cout << a;
			printf(">");
			check = false;
		}
		else if (check) printf("%c", s[i]); //그냥 받자마자 출력하자
		else if (s[i] == ' ' || s[i] == '\n') {
			while (!st.empty()) {
				printf("%c", st.top());
				st.pop();
			}
			printf(" ");
		}
		else st.push(s[i]);
	}
	return 0;
}

