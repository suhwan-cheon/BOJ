#include <iostream>
using namespace std;

bool check[1000];
int a[3];
int c[3];
int main()
{
	int n; scanf("%d", &n);
	while (n--) {
		int temp; scanf("%d", &temp);
		a[2] = temp % 10;
		a[1] = (temp % 100) / 10;
		a[0] = temp / 100;
		int s, b; scanf("%d %d", &s, &b);
		for (int i = 100; i < 1000; i++) {
			if (check[i] == true) continue;
			c[2] = i % 10;
			c[1] = (i % 100) / 10;
			c[0] = i / 100;
			if (c[0] == c[1] || c[1] == c[2] || c[0] == c[2]) {
				check[i] = true;
				continue;
			}
			if (c[0] == 0 || c[1] == 0 || c[2] == 0) {
				check[i] = true;
				continue;
			}
			int temp_s = 0;
			int temp_b = 0;

			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					if (j == k && a[j] == c[k]) temp_s++;
					else if (a[j] == c[k]) temp_b++;
				}
			}
			if (s != temp_s || b != temp_b) check[i] = true;
		}
	}
	int ans = 0;
	for (int i = 100; i < 1000; i++) {
		if (check[i] == false) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
