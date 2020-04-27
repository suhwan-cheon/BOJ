#define MAX 1000001
#include <iostream>
#include <algorithm>
using namespace std;

bool break_btn[10]; //고장난 버튼 : true
bool btn[MAX];
void check_btn() { //누를 수 있는 버튼 다 탐색해보기~
	if (break_btn[0] == false) btn[0] = true;
	for (int i = 1; i < MAX; i++) {
		int temp = i;
		btn[i] = true;
		while (temp) {
			if (break_btn[temp % 10] == true) { //고장난 버튼이 있는 경우
				btn[i] = false;
				break;
			}
			temp /= 10;
		}
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) { 
		int temp; scanf("%d", &temp);
		break_btn[temp] = true;
	}
	check_btn();
	int ans = MAX;
	if (n == 100) {
		ans = 0;
	}
	else if (n < 100) {
		ans = min(ans, 100 - n); //case 1
		//case 2 : upper bound
		for (int i = n; i < 100; i++) {
			if (btn[i]) { //누를 수 있는 버튼인 경우
				if (i < 10) { //1의 자릿수
					ans = min(ans, 1 + (i - n));
				}
				else {
					ans = min(ans, 2 + (i - n));
				}
			}
		}
		//case 3 : under bound
		for (int i = n - 1; i >= 0; i--) {
			if (btn[i]) {
				if (i < 10) { //1의 자릿수
					ans = min(ans, 1 + (n - i));
				}
				else {
					ans = min(ans, 2 + (n - i));
				}
			}
		}
	}
	else if (n > 100) {
		//case 1
		ans = min(ans, n - 100);
		//case 2 : upper bound
		for (int i = n; i < MAX; i++) {
			if (btn[i]) {
				//자릿수 check
				int cnt = 0;
				int temp_i = i;
				while (temp_i) {
					cnt++;
					temp_i /= 10;
				}

				ans = min(ans, cnt + (i - n));
			}
		}
		//case 3 : under bound
		for (int i = n - 1; i > 100; i--) {
			if (btn[i]) {
				//자릿수 check
				int cnt = 0;
				int temp_i = i;
				while (temp_i) {
					cnt++;
					temp_i /= 10;
				}

				ans = min(ans, cnt + (n - i));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

