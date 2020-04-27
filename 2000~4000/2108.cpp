#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[8001];
int main()
{
	int n; scanf("%d", &n);
	vector<int>v(n);
	float sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
		visited[v[i]+4000]++;
	}
	//1번
	float ave = sum / n;
	if (ave >= 0) printf("%d\n", (int)(ave + 0.5));
	else printf("%d\n", (int)(ave - 0.5));

	//2번
	sort(v.begin(), v.end());
	printf("%d\n", v[n / 2]);

	//3번
	int cnt = 1;
	int ans_cnt = 1;
	int temp = v[0];
	int ans;
	if (v.size() == 1) ans = v[0];
	else ans = v[1];
	for (int i = 1; i < n; i++) { //최빈값 개수 파악
		if (temp == v[i]) {
			cnt++;
			if (cnt >= ans_cnt) {
				ans_cnt = cnt;
				ans = v[i];
			}
		}
		else {
			cnt = 1;
			temp = v[i];
		}
	}
	
	if (ans_cnt == 1) printf("%d\n", ans);
	else {
		bool check = false;
		for (int i = 0; i < n; i++) {
			if (visited[v[i]] == ans_cnt && check == false) {
				check = true;
				i += ans_cnt-1;
			}
			else if (visited[v[i]] == ans_cnt && check == true) {
				printf("%d\n", v[i]);
				break;
			}
		}
	}
	//4번
	printf("%d\n", v[n - 1] - v[0]);
	return 0;
}

