﻿#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s; cin >> s;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		ans += 1;
		if (s[i] == 'c' && i != s.length() - 1) {
			if (s[i + 1] == '=' || s[i + 1] == '-') {
				i += 1;
			}
		}
		else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=' && i != s.length() - 2) {
			i += 2;
		}
		else if (s[i] == 'd' && s[i + 1] == '-' && i != s.length() - 1) {
			i += 1;
		}
		
		else if (s[i] == 'l' && s[i + 1] == 'j' && i != s.length() - 1) {
			i += 1;
		}
		else if (s[i] == 'n' && s[i + 1] == 'j' && i != s.length() - 1) {
			i += 1;
		}
		else if (s[i] == 's' && s[i + 1] == '=' && i != s.length() - 1) {
			i += 1;
		}
		else if (s[i] == 'z' && s[i + 1] == '=' && i != s.length() - 1) {
			i += 1;
		}
	}
	cout << ans<<"\n";
	return 0;
}
