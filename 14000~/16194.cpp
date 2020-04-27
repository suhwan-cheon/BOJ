#include <iostream>
#include <algorithm>
using namespace std;

int p[1001];
int d[1001];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		d[i] = p[i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			d[i] = min(d[i], d[i - j] + p[j]);
		}
	}
	printf("%d", d[n]);
	return 0;
}

