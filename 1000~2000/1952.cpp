#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m, n; scanf("%d %d", &m, &n);
	int ans = 0;
	while (m > 2 && n > 2) {
		m -= 2;
		n -= 2;
		ans += 4;
	}
	int k = min(m, n);
	if (k == 2) ans += 2;
	else ans++;

}
