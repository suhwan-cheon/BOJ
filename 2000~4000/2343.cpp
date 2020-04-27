#include <iostream>
using namespace std;

int n, m;
int les[100001];

bool check(int x) {
	int temp = 1;
	int bun = 0;
	for (int i = 0; i < n; i++) {
		if (x < les[i]) return false; //하나도 못담을 때
		bun += les[i];
		if (bun > x) {
			temp++;
			bun = les[i];
		}
	}
	if (temp > m) return false;
	else return true;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &les[i]);
	}
	int left = 1;
	int right = n * 10000;
	int ans = 1000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			if (ans > mid) ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}

