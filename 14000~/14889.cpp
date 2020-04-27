#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main()
{
	int n; scanf("%d", &n);
	int s[20][20];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &s[i][j]);
		}
	}
	vector<int> permute;
	for (int i = 0; i < n / 2; i++) {
		permute.push_back(1);
		permute.push_back(0);
	}
	
	sort(permute.begin(), permute.end());
	int ans = 99999999;
	do {
		vector<int> start;
		vector<int> link;
		for (int i = 0; i < n; i++) { //팀 나누기
			if (permute[i] == 0) start.push_back(i);
			else link.push_back(i);
		}
		int start_sum = 0; int link_sum = 0;
		for (int i = 0; i < (n / 2); i++) {
			for (int j = 0; j < (n / 2); j++) {
				if (i != j) {
					start_sum += s[start[i]][start[j]];
					link_sum += s[link[i]][link[j]];
				}
			}
		}
		ans = min(ans, abs(start_sum - link_sum));
	} while (next_permutation(permute.begin(), permute.end()));
	printf("%d\n", ans);
	return 0;
}

