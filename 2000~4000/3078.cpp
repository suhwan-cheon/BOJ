#include <iostream>
#include <deque>
#include <string>
using namespace std;

int nameSize[21]; // 2~ 20 글자 사이
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	deque<string>dq;
	long long ans = 0;

	//init_setting
	for (int i = 0; i < k; i++) {
		string temp; cin >> temp;
		nameSize[temp.size()]++;
		dq.push_back(temp);
	}
	//init_ans
	for (int i = 2; i <= 20; i++) {
		if (nameSize[i] >= 2) {
			ans += (nameSize[i] * (nameSize[i] - 1)) / 2;
		}
	}

	for (int i = 0; i < n - k; i++) {
		string temp; cin >> temp;
		//추가된 문자열에 따라 좋은 친구수가 늘어날 경우
		int len = temp.size();
		if (nameSize[len] >= 1) ans += nameSize[len];
		nameSize[len]++;
		dq.push_back(temp);
		nameSize[dq.front().size()]--;
		dq.pop_front();
	}
	cout << ans << "\n";
	return 0;
}
