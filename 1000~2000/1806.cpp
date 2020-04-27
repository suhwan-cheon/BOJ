#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;
int main()
{
	scanf("%d %d", &n, &s);
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int left = 0;
	int right = 0;
	int sum = v[0];
	int ans = 100001;
	while (left <= right && right < n) {
		if (sum < s) { //합이 s보다 작은 경우
			right++;
			sum += v[right];
		}
		else if (sum >= s) {
			ans = min(ans, right - left);
			sum -= v[left];
			left++;
			if (left >= right && left < n) {
				right = left;
				sum = v[left];
			}
		}
	}
	if (ans == 100001) printf("0\n");
	else printf("%d\n", ans+1);
	return 0;
}
