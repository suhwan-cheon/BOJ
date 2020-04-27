#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[8];
int n, k;
int ans;
void go(vector<int> &a, int cnt, int w) {
	if (cnt == n && w >= 500) {
		ans++;
		return;
	}
	if (w < 500) return;
	
	for (int i = 0; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			go(a, cnt + 1, w + a[i] - k);
			check[i] = false;
		}
	}
	
}
int main()
{
	scanf("%d %d", &n, &k);
	vector<int>a(n); //키트의 중량 증가량
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	go(a, 0, 500);
	printf("%d", ans);
	return 0;
}
