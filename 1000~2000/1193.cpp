#include <iostream>
using namespace std;

int main()
{
	int x; cin >> x; int cnt = 0;
	if (x == 1) cout << 1 << '/' << 1;
	else {
		for (int i = 1; i < 10000; i++) {
			if ((i * (i + 1) / 2) < x && x <= ((i + 1) * (i + 2) / 2)) {
				cnt = i + 1;
				break;
			}
		}
		
		int k = x - (cnt * (cnt - 1) / 2);
		if (cnt % 2 == 0) {
			int a = 1, b = cnt;
			for (int i = 1; i < k; i++) {
				a += 1; b -= 1;
			}
			cout << a << '/' << b;
		}
		else if (cnt % 2 == 1) {
			int a = cnt, b = 1;
			for (int i = 1; i < k; i++) {
				a -= 1; b += 1;
			}
			cout << a << '/' << b;
		}
		
	}
}
