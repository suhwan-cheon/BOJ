#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s; cin >> s;
	int sum = 0; //3의 배수인지 체크
	int zero_chk = 0;
	for (char i : s) {
		int k = i - '0';
		if (k == 0) zero_chk = 1;
		sum += k;
		
	}
	sort(s.begin(), s.end());
	if (zero_chk && sum % 3 == 0) {
		reverse(s.begin(), s.end());
		cout << s;
	}
	else printf("%d", -1);
	return 0;
}
