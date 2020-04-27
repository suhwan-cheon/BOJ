#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	//투 포인터
	int left = 0, right = 0, sum = a[0];
	while (left <= right && right < n) {
		if (sum < m) {
			right++;
			if (right == n) break;
			sum += a[right];
		}
		else if (sum == m) {
			ans++;
			right++;
			if (right == n) break;
			sum += a[right];
		}
		else if (sum > m) {
			sum -= a[left];
			left++;
			if (left > right && left < n) {
				right = left;
				if (right == n) break;
				sum = a[left];
			}
		}
	}
	printf("%d", ans);
	return 0;
}

