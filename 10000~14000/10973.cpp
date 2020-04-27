#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		v.push_back(temp);
	}
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			printf("%d ", v[i]);
		}
	}
	else printf("-1");
	return 0;
}