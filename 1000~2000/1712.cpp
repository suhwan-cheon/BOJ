#include <iostream>
using namespace std;

int main()
{
	int a, b, c, sell;
	cin >> a >> b >> c;
	if (b >= c) {
		cout << -1; return 0;
	}
	sell = a / (c - b) + 1;
	if (sell <= 0) cout << -1;
	else cout << sell;
}

