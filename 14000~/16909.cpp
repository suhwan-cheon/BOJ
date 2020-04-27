#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	stack<pair<int, int> >st;

	int ans = 0;
	int min = 1000001;
	for (int i = 0; i < n; i++) {
		if (i == 0) st.push(make_pair(a[i], a[i]));
		else {
			if (a[i] < st.top().second) {
				st.push(make_pair(a[i], a[i]));
			}
			else {
				st.push(make_pair(a[i], st.top().second));
			}

		}
	}
}

