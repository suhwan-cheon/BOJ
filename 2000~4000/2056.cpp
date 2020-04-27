#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int ch[100001][35]; //idx 저장용

int main()
{
	int n; scanf("%d", &n);
	vector<int> v;
	int first = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		for (int j = 30; j > 0; j--) { //비트 변환
			if (temp & (1 << j)) {
				ch[i][j] = 1;
				sum++;
			}
		}
		v.push_back(temp);
	}
	int ans = 0;
	for (int i = 30; i > 0; i--) {
		int cnt = 0;
		for (int j = 0; j < v.size(); j++) {
			if (ch[j][i] == 1) cnt++;
		}
		if (cnt == 1) { //유일한 원소이면
			for (int j = 0; j < v.size(); j++) {
				if (ch[j][i] == 1) {
					ans = v[j];
					break;
				}
			}
			break;
		}
	}
	if (ans != 0 || sum == 0) {
		printf("%d ", ans);
	}
	bool check = false;
	for (int i = 0; i < n; i++) {
		if (!check && v[i] == ans) {
			check = true;
			continue;
		}
		if (i == n - 1) printf("%d\n", v[i]);
		else printf("%d ", v[i]);
	}
	return 0;
}