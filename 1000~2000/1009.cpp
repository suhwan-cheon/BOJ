#include <iostream>
using namespace std;

int deviation(int a, int b) {
	if (a == 1) return 1;
	else if (a == 2) {
		int two[4] = { 6,2,4,8 };
		int k = b % 4;
		return two[k];
	}
	else if (a == 3) {
		int three[4] = { 1,3,9,7 };
		int k = b % 4;
		return three[k];
	}
	else if (a == 4) {
		int four[2] = { 6,4 };
		int k = b % 2;
		return four[k];
	}
	else if (a == 5) return 5;
	else if (a == 6) return 6;
	else if (a == 7) {
		int seven[4] = { 1,7,9,3 };
		int k = b % 4;
		return seven[k];
	}
	else if (a == 8) {
		int eight[4] = { 6,8,4,2 };
		int k = b % 4;
		return eight[k];
	}
	else if (a == 9) {
		int nine[2] = { 1,9 };
		int k = b % 2;
		return nine[k];
	}
	else return 0;
}
int main()
{
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		int ans = 0;
		if (a < 10) ans = deviation(a, b);
		else if (a >= 10) ans = deviation(a % 10, b);
		cout << ans << "\n";;
	}
}
