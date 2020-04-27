#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<string>v(50);
bool alpha[26];
int ans = 0;

int simulate() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool check = true;
		for (int j = 0; j < v[i].size(); j++) {
			if (alpha[v[i][j] - 'a'] == false) {
				check = false;
				break;
			}
		}
		if (check) cnt++;
	}
	return cnt;
}
void go(int first, int cnt) {
	if (cnt == k) { //기저 사례 : 요건 충족
		int temp = simulate();
		ans = max(ans, temp);
		return;
	}
	
	for (int i = first; i < 26; i++) {
		if (alpha[i] == false) {
			alpha[i] = true;
			go(i, cnt + 1);
			alpha[i] = false;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	//필수 문자 입력
	alpha[0] = true; alpha['i' - 'a'] = true;
	alpha['n' - 'a'] = true; alpha['t' - 'a'] = true;
	alpha['c' - 'a'] = true;
	//필수 문자 없는 경우
	if (k < 5) {
		cout << 0 << "\n";
		return 0;
	}
	else {
		go(0, 5);
	}
	cout << ans << "\n";
	return 0;
}
