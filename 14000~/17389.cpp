#include <iostream>
using namespace std;
int main()
{
	int ans = 0; int seq = 0;
	int n; cin >> n;
	string k; cin >> k;
	for (int i = 0; i < n; i++) {
		if (k[i] == 'O') {
			ans += (i+1) + seq;
			seq += 1;
		}
		else if (k[i] == 'X') {
			seq = 0;
		}
	}
	cout << ans;
	return 0;
}
