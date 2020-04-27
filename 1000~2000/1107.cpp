#include <iostream>
#include <algorithm>
#include <cstdbool>
#include <vector>
using namespace std;

int n, m;  //이동하려는 채널 n, 고장난 버튼의 개수 m
bool break_btn[10];

int simple_case() { //단순히 +/- 버튼만을 이용
	if (n >= 100) return n - 100;
	else return 100 - n;
}

int press(int t) { //누를 수 있는 채널인지 체크 + 자릿수 반환
	if (t == 0) { // 예외 : 0일때
		if (break_btn[0]) return 0;
		else return 1;
	}
	else {
		int len = 0;
		while (t) {
			int temp_t = t % 10;
			if (break_btn[temp_t]) return 0;
			len++;
			t /= 10;
		}
		return len;
	}
}
int press_chn() {
	int ans = 1000001;
	for (int i = 0; i <= 1000000; i++) {
		int temp_i = i;
		int len = press(temp_i);
		if (len > 0) {
			int press = temp_i - n;
			if (press < 0) press = -press;
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int temp; scanf("%d", &temp);
		break_btn[temp] = true;
	}
	int ans = min(simple_case(), press_chn());
	printf("%d", ans);
	return 0;
}