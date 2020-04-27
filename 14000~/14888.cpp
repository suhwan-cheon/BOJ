#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int oper[4];
	for (int i = 0; i < 4; i++) {
		scanf("%d", &oper[i]);
	}
	vector<int> permute;
	// 0: 덧셈, 1: 뺄셈, 2: 곱셈, 3: 나눗셈
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < oper[i]; j++) {
			permute.push_back(i);
		}
	}
	sort(permute.begin(), permute.end());
	int mini = 1000000000, maxi = -1000000000; //최대, 최소값 초기화
	do {
		int temp_ans = a[0];
		for (int i = 0; i < n - 1; i++) {
			if (permute[i] == 0) temp_ans += a[i + 1];
			else if (permute[i] == 1) temp_ans -= a[i + 1];
			else if (permute[i] == 2) temp_ans *= a[i + 1];
			else if (permute[i] == 3) temp_ans /= a[i + 1];
		}
		mini = min(mini, temp_ans);
		maxi = max(maxi, temp_ans);
	} while (next_permutation(permute.begin(), permute.end()));
	printf("%d\n%d", maxi, mini);
	return 0;
}

