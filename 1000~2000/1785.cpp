#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	vector<int>tip(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tip[i]);
	}
	sort(tip.begin(), tip.end(), greater<int>());
	long long ans = 0;
	
	for (int i = 0; i < n; i++) {
		int money = tip[i] - i;
		if (money <= 0) continue;
		ans += money;
	}
	printf("%lld\n", ans);
	return 0;
}
