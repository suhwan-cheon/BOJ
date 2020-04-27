#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s; cin >> s;
	vector<int> v1; //수를 담을 벡터
	vector<int> v2; //부호를 담을 벡터 1/-1
	int temp = 0; int ans = 0;
	v2.push_back(1);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+') v2.push_back(1);
			else if (s[i] == '-') v2.push_back(-1);
			v1.push_back(temp);
			temp = 0;
		}
			else {
				temp = temp * 10 + (s[i] - '0');
			}
	}
	v1.push_back(temp);
	int cur_sign = 1; //현재 부호
	for (int i = 0; i < v1.size(); i++) {
		if (v2[i] == 1) { //마주친 부호가 양수
			if (cur_sign == -1) { //그 전에 음수였을 때
				ans -= v1[i];
				cur_sign = -1;
			}
			else ans += v1[i];
		}
		else {  // '-' 부호일 때
			if (cur_sign == -1) ans -= v1[i];
			else {
				cur_sign = -1;
				ans -= v1[i];
			}
		}
	}
	printf("%d", ans);
	return 0;
}