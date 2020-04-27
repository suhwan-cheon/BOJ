#define MAX 1000001
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[MAX];
int main()
{
	for (int i = 2; i * i < MAX; i++) { //소수 구하기
		if (check[i] == false) {
			int j = i + i;
			while (j < MAX) {
				check[j] = true;
				j += i;
			}
		}
	}
	check[2] = true;

	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		int ans = 0;
		for (int i = 3; i <= (n / 2); i++) {
			if (check[i] == false) {
				if (check[n - i] == false) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
