#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	vector<int> plus;
	vector<int> minus;
	int zero = 0;
	int one = 0;
	for (int i = 0; i < n; i++) {
		int k; scanf("%d", &k);
		if (k == 1) {
			one++;
		}
		else if (k > 0) {
			plus.push_back(k);
		}
		else if (k < 0) {
			minus.push_back(k);
		}
		else zero++;
	}
	sort(plus.begin(), plus.end(), greater<int>());
	sort(minus.begin(), minus.end());
	if (plus.size() % 2 == 1) plus.push_back(1);
	if (minus.size() % 2 == 1) minus.push_back(zero > 0 ? 0 : 1);

	int ans = 0;
	for (int i = 0; i < plus.size(); i += 2) {
		ans += plus[i] * plus[i + 1];
	}
	for (int i = 0; i < minus.size(); i += 2) {
		ans += minus[i] * minus[i + 1];
	}
	ans = ans + one;
	printf("%d", ans);
	return 0;
}
