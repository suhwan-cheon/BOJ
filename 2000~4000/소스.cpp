#include <iostream>

using namespace std;

int d[5001];
int mod = 1000000;
int ans_dp(string s) {
	d[0] = 1;
	int n = s.size();
	s = " " + s;
	for(int i=1;i<=n;i++){
		int x = s[i] - '0';
		if (1 <= x && x <= 9) {
			d[i] = (d[i] + d[i - 1]) % mod;
		}
		if (i == 1) continue;
		if (s[i - 1] == '0') continue;
		x = (s[i - 1] - '0') * 10 + (s[i] - '0');
		if (10 <= x && x <= 26) {
			d[i] = (d[i] + d[i - 2]) % mod;
		}
	}
	return d[n];
}

int main() {
	string s;
	cin >> s;
	cout << ans_dp(s);
}