#include <iostream>

int d[100001];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		d[temp]++;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < i/2; j++) {
			if (j == i - j) d[i] += d[j];
			else d[i] += d[j] + d[i - j];
		}
	}
	printf("%d\n", d[k]);
	return 0;
}
