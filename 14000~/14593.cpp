#include <iostream>
#include <vector> 
using namespace std;
int s[10001];
int c[10001];
int l[10001];
int main()
{
	int n; scanf("%d", &n);
	int max_s = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &s[i], &c[i], &l[i]);
		if (s[i] > max_s) max_s = s[i];
	}
	vector<int>pro;
	for (int i = 1; i <= n; i++) {
		if (s[i] == max_s) pro.push_back(i);
	}
	int min_c = 100;
	for (int i = 0; i < pro.size(); i++) {
		if (min_c > c[pro[i]]) min_c = c[pro[i]];
	}
	vector<int>countc;
	for (int i = 0; i < pro.size(); i++) {
		if (min_c == c[pro[i]]) countc.push_back(pro[i]);
	}
	int min_l = 180;
	for (int i = 0; i < countc.size(); i++) {
		if (min_l > l[countc[i]]) min_l = l[countc[i]];
	}
	vector<int>ans;
	for (int i = 0; i < countc.size(); i++) {
		if (min_l == l[countc[i]]) ans.push_back(countc[i]);
	}
	printf("%d\n", ans[0]);
	return 0;
}

