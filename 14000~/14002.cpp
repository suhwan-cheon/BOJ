#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;
vector<int> a;
int d[1001];
int v[1001];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		a.push_back(temp);
		d[i] = 1; //모두 길이 1로 초기화
	} //d[i] = i로 끝났을 경우 부분 수열의 길이
	v[0] = -1;
	for (int i = 1; i < n; i++) {
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j]+1) {
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	int k = -1; //LIS 길이
	int ans_idx = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > k) {
			k = d[i];
			ans_idx = i; //마지막 부분 idx
		}
	}
	ans.push_back(a[ans_idx]);
	while (v[ans_idx] != -1) {
		ans_idx = v[ans_idx];
		ans.push_back(a[ans_idx]);
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}

