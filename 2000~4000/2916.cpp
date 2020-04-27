#include <iostream>
#include <vector>
using namespace std;

int d[361]; //d[i] : i각을 만들 수 있는가?
int a[10];
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	d[0] = 1;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 360; j++) {
			for (int t = 0; t < 360; t++) {
				if (d[t] == 0) continue;
				d[(t - a[i] + 360) % 360] = 1;
				d[(t + a[i]) % 360] = 1;
			}
		}
	}
	while (k--) {
		int q;
		scanf("%d", &q);
		cout << (d[q] ? "YES" : "NO") << "\n";
	}
	return 0;
}
