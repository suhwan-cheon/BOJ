#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int k = 666;
	int cnt = 0;
	while (1) {
		string s = to_string(k);
		int temp_cnt = 0;
		bool check = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - '0' == 6) temp_cnt++;
			else temp_cnt = 0;
			if (temp_cnt == 3) check = true;
		}
		if (check) cnt++;
		if (cnt == n) {
			printf("%d", k);
			break;
		}
		k++;
	}
	return 0;
}

