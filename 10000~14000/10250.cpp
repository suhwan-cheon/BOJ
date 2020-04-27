#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--) {
		int h, w, n,x,y;
		scanf(" %d %d %d", &h, &w, &n);
		if (h >= n) {
			x = 1;
			y = n;
		}
		else if (h == 1) {
			x = n;
			y = 1;

		}
		else if (n % h == 0) {
			x = n / h;
			y = h;
		}
		else {
			x = (n / h) + 1;
			y = n % h;

		}
		if (x / 10 == 0) {
			printf("%d0%d\n", y, x);
			
		}
		else {
			printf("%d%d\n", y, x);
			
		}
	}
	return 0;
}
