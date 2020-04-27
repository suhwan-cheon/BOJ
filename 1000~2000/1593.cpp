#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

//읽을 수 있는 문자
int alpha[52]; //A ~ z count
int compare[52];

int main()
{
	string w, s;
	int w_len, s_len;
	cin >> w_len >> s_len;
	cin >> w >> s;
	
	for (int i = 0; i < w_len; i++) {
		if ('a' <= w[i] && w[i] <= 'z') { //소문자
			alpha[w[i] - 'a' + 26]++;
		}
		else {
			alpha[w[i] - 'A']++;
		}
	}
	int ans = 0;
	//초기 설정
	for (int j = 0; j < w_len; j++) {
		if ('a' <= s[j] && s[j] <= 'z') { //소문자
			compare[s[j] - 'a' + 26]++;
		}
		else {
			compare[s[j] - 'A']++;
		}
	}
	for (int i = 0; i < s_len - w_len; i++) {
		bool check = true;
		for (int j = 0; j < 52; j++) {
			if (alpha[j] != compare[j]) {
				check = false;
				break;
			}
		}
		if (check) ans++;
		if ('a' <= s[i] && s[i] <= 'z') { //소문자
			compare[s[i] - 'a' + 26]--;
		}
		else {
			compare[s[i] - 'A']--;
		}
		if ('a' <= s[i+w_len] && s[i+w_len] <= 'z') { //소문자
			compare[s[i+w_len] - 'a' + 26]++;
		}
		else {
			compare[s[i+w_len] - 'A']++;
		}
	}
	bool check = true;
	for (int j = 0; j < 52; j++) {
		if (alpha[j] != compare[j]) {
			check = false;
			break;
		}
	}
	if (check) ans++;
	printf("%d\n", ans);
	return 0;
}
