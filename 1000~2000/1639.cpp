#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s; cin >> s;
	int len = s.size();
	int ans = 0;
	
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			int a = 0, b = 0;
			int mid = (i+j) / 2;
			for (int k = i; k <= j; k++) {
				if (k <= mid) a += s[k] - '0';
				else b += s[k] - '0';
			}
			if (a == b) ans = max(ans, (j - i) + 1);
			j++;
		}
	}
	
	printf("%d\n", ans);
	return 0;
}

