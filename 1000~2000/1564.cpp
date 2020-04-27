#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	long long ans = 1;

	for (int i = 1; i <= n; i++) {
		ans *= i;

		while (ans % 10 == 0) {
			ans = ans / 10;
		}
		ans %= 1000000000000;
	}

	while (ans % 10 == 0) {
		ans = ans / 10;
	}
	// 5자리 미만
	if (ans / 10000 == 0) {
		cout << ans << '\n';
	}
	else {
		string tmp;
		for (int i = 0; i < 5; i++) {
			int d = ans % 10;
			tmp = to_string(d) + tmp;
			ans /= 10;
		}
		cout << tmp << '\n';
	}
	return 0;
}