#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int gcd_num = gcd(a, b);
		long long Lcm = gcd_num * (a / gcd_num) * (b / gcd_num);
		cout << Lcm << "\n";
	}
}

