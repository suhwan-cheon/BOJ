#include <iostream>
using namespace std;
long long d[10001];
int main()
{
	//dp
	d[0] = 1;
	for (int i = 1; i <= 10000; i++) {
		d[i] = d[i] + d[i - 1];
	}
	for (int i = 2; i <= 10000; i++) {
		d[i] = d[i] + d[i - 2];
	}
	for (int i = 3; i <= 10000; i++) {
		d[i] = d[i] + d[i - 3];
	}
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
}
