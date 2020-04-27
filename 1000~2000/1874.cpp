#include <iostream>
#include <stack>
#include <string>
using namespace std;

int target[100000];
int main()
{
	int n; scanf("%d", &n);
	stack<int> st;
	string ans;

	int checker = 0; //현 위치 체커

	for (int i = 0; i < n; i++) {
		scanf("%d", &target[i]);
	}
		
	for (int i = 0; i < n; i++) {
		if (checker < target[i]) {
			for (int j = checker + 1; j <= target[i]; j++) { //큰 경우
				st.push(j);
				ans += '+';
			}
			st.pop();
			ans += '-';
			checker = target[i];
		}
		else { //작은 경우
			if (target[i] == st.top()) {
				st.pop();
				ans += '-';
			}
			else {
				printf("NO");
				return 0;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		printf("%c\n", ans[i]);
	}
	return 0;
}

