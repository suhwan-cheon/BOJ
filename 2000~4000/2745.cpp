#include <iostream>
using namespace std;

int main()
{
	string s; cin >> s;
	int b; cin >> b;
	int ten_sum = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			ten_sum = ten_sum * b + s[i] - '0';
		}
		else {
			ten_sum = ten_sum * b + (s[i] + 10 - 'A');
		}
		}
	cout << ten_sum;
}
