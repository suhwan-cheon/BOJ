#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n; cin >> n;
	stack <int> st;
	if (n == 0) st.push(0);
	else {
		while (n) {
			if (n % 2 == 0) {
				st.push(0);
				n = -(n / 2);
			}
			else {
				if (n > 0) n = -(n / 2);
				else n = ((-n + 1) / 2);
				st.push(1);
			}
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
