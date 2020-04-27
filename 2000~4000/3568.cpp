#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string basic; //기본 변수형
	cin >> basic;
	while (1) { // ';' 나올 때 까지..
		string a;
		cin >> a;
		string name = ""; //기본 변수명
		string val = ""; //추가 변수형
		bool check = true;
		for (auto &i : a) {
			if (i == '*' || i == '[' || i == ']' || i =='&') {
				val += i;
			}
			else if (i == ',') {
				break;
			}
			else if (i == ';') {
				check = false;
			}
			else {
				name += i;
			}
		}
		reverse(val.begin(), val.end());
		for (int i = 0; i < val.size(); i++) {
			if (val[i] == '[') val[i] = ']';
			else if (val[i] == ']') val[i] = '[';
		}
		cout << basic << val << " " << name << ";" << "\n";
		if (!check) break;
	}
	return 0;
}

