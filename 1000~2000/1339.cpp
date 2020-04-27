#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check[26]; //알파벳 개수 파악
vector<char> alpha;
char a[256];
int main()
{
	int n; scanf("%d", &n);
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		v.push_back(temp);
	}
	int alpha_cnt = 0;
	for (int i = 0; i < n; i++) {
		string temp1 = v[i];
		for (int i = 0; i < temp1.size(); i++) {
			if (check[temp1[i] - 'A'] == false) {
				alpha_cnt++;
				check[temp1[i] - 'A'] = true;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		if (check[i] == true) alpha.push_back(i + 'A');
	}
	//수열 만들기
	vector<int>permute;
	for (int i = 9; i >= 10 - alpha_cnt; i--) {
		permute.push_back(i);
	}
	sort(permute.begin(), permute.end());
	long long ans = 0;
	do {
		long long temp_ans = 0;
		for (int i = 0; i < alpha_cnt; i++) {
			a[alpha[i]] = permute[i];
		}
		for (string s : v) {
			int now = 0;
			for (char x : s) {
				now = now * 10 + a[x];
			}
			temp_ans += now;
		}
		ans = max(ans, temp_ans);
	} while (next_permutation(permute.begin(), permute.end()));
	printf("%lld", ans);
	return 0;
}
