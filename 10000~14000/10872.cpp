#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int ans = 1;
	if (n == 0) {
		cout << 1 << "\n";
	}
	else {
		for (int i = 1; i <= n; i++) {
			ans *= i;
		}
		cout << ans << "\n";
	}
}