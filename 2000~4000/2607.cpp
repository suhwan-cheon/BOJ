#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int check_init[26];
int check[26];
int ans;
int main()
{
	int n; scanf("%d", &n);
	string init;
	cin >> init;
	int init_len = init.length();
	for (int i = 0; i < init.length(); i++) {
		check_init[init[i] - 'A']++;
	}
	for (int i = 0; i < n - 1; i++) {
		memset(check, 0, sizeof(check));
		string s;
		cin >> s;
		int s_len = s.length();
		int dif = 0;
		for (int j = 0; j < s.length(); j++) {
			check[s[j] - 'A']++;
		}
		for (int j = 0; j < 26; j++) { //두 단어 비교
			if (check_init[j] - check[j] >= 0) { //양의 차이
				dif += check_init[j] - check[j];
			}
			else { //음의 차이
				dif += check[j] - check_init[j];
			}
		}

		//case 1
		if (init_len == s_len) {
			if (dif == 0 || dif == 2) ans++;
		}
		//case 2,3
		if (init_len == s_len + 1 || init_len == s_len - 1) {
			if (dif == 1) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
