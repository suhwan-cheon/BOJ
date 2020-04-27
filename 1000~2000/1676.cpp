#include <iostream>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) ans++;
		if (i % 25 == 0) ans++;
		if (i % 125 == 0) ans++;
	}
	printf("%d", ans);
	return 0;
}
