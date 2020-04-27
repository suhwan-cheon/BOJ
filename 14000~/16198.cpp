#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int go(vector<int>& a, int weight) {
	if (a.size() == 2) return weight;
	int ans = -1;
	for (int i = 1; i < a.size()-1; i++) {
		vector<int> temp;
		for (int j = 0; j < a.size(); j++) {
			if (j != i) temp.push_back(a[j]);
		}
		ans = max(ans,go(temp, weight + a[i - 1] * a[i + 1]));
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
	}
	int ans = go(w, 0);
	printf("%d", ans);
	return 0;
}

