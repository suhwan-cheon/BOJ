#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int start[100001];
int start2[100001];

int main()
{
	int end[100001];
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char temp; scanf(" %c", &temp);
		if (temp == '0') {
			start[i] = -1;
			start2[i] = -1;
		}
		else {
			start[i] = 1;
			start2[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		char temp; scanf(" %c", &temp);
		if (temp == '0') end[i] = -1;
		else end[i] = 1;
	}
	start2[0] *= -1; start2[1] *= -1;
	int ans = 0; int ans2 = 1;
	for (int i = 1; i < n-1; i++) {
		if (start[i] != end[i]) {
			if (i == n - 2) {
				start[i] *= -1;
				start[i + 1] *= -1;
			}
			else {
				start[i] *= -1; start[i + 1] *= -1;
				start[i + 2] *= -1;
				
			}
			ans++;
		}
	}
	if (start[n - 1] != end[n - 1]) {
		ans++;
		start[n - 1] *= -1; start[n - 2] *= -1;
	}
	for (int i = 1; i < n-1; i++) {
		if (start2[i] != end[i]) {
			if (i == n - 2) {
				start2[i] *= -1;
				start2[i + 1] *= -1;
			}
			else {
				start2[i] *= -1; start2[i + 1] *= -1;
				start2[i + 2] *= -1;

			}
			ans2++;
		}
	}
	if (start2[n - 1] != end[n - 1]) {
		ans2++;
		start2[n - 1] *= -1; start2[n - 2] *= -1;
	}
	bool check1 = false; bool check2 = false;
	for (int i = 0; i < n; i++) {
		if (start[i] != end[i]) check1 = true;
		if (start2[i] != end[i]) check2 = true;
	}
	if (check1 && check2) printf("-1");
	else if (check1 && !check2) printf("%d", ans2);
	else if (!check1 && check2) printf("%d", ans);
	else if (!check1 && !check2) printf("%d", min(ans,ans2));
	return 0;
}
