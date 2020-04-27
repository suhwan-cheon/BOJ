#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;
int main()
{
	stack<pair<int, int> > st;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp; scanf("%d", &temp);
		if (st.empty()) { //처음부터 비어있는 경우
			printf("0 ");
			st.emplace(temp, i);
		}
		else if (temp == st.top().first) { //같은 경우 push 할 필요 x
			printf("%d ", i);
			st.emplace(temp, i);
		}
		else if (temp > st.top().first) { //더 큰 경우, 더 높은 탑을 찾아야
			bool check = false;
			while (temp > st.top().first) {
				st.pop();
				if (st.empty()) { //높은 탑이 없는 경우
					printf("0 ");
					st.emplace(temp, i);
					check = true;
					break;
				}
			}
			if (check) continue;
			else { //앞에 큰게 있는 경우
				printf("%d ", st.top().second);
				st.emplace(temp, i);
			}
		}
		else { //더 작은 경우
			printf("%d ", st.top().second);
			st.emplace(temp, i);
		}
	}
	return 0;
}
