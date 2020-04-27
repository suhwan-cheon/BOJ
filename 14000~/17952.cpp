#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int ans = 0;
	stack<pair<int, int> >st;
	while (n--) {
		int cmd, a, t;
		scanf("%d", &cmd);
		if (cmd == 1) { //새로운 과제가 등장
			scanf("%d %d", &a, &t);
			if (t == 1) {
				ans += a;
			}
			else st.push(make_pair(a, t-1));
		}
		else { //과제가 주어지지 않은 경우
			if (!st.empty()) { //밀려있는 과제가 있을 경우
				int temp_a, temp_t;
				temp_a = st.top().first;
				temp_t = st.top().second;
				if (temp_t == 1) {
					ans += temp_a;
					st.pop();
				}
				else {
					st.pop();
					st.push(make_pair(temp_a, temp_t - 1));
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

