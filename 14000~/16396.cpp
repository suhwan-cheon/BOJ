#include <iostream>
#include <cstdbool>
#include <cstring>
#include <algorithm>
using namespace std;

bool line_check[10001];
int main()
{
	memset(line_check, false, sizeof(line_check));
	int n; cin >> n;
	int cnt = 0;
	while (n--) {
		int x = 0; int y = 0;
		cin >> x >> y;
		for (int i = x; i < y; i++) {
			if (line_check[i] == false) {
				cnt++;
				line_check[i] = true;
			}
			else continue;
		}
	}
	int ans_cnt = 0;
	for (int i = 1; i < 10001; i++) {
		if (line_check[i] == true) ans_cnt++;
	}
	cout << ans_cnt << "\n";
	return 0;
}

