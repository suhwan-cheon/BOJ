#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

stack<pair<int, int> >st;
string input;
string bomb;
string ans;
int main()
{
	cin >> input >> bomb;
	int input_size = input.size();
	int bomb_size = bomb.size();
	int cnt = 0;
	for (int i = 0; i < input_size; i++) {
		if (input[i] == bomb[0]) cnt = 1;
		else if (input[i] == bomb[cnt]) cnt++;
		else cnt = 0;
		st.push(make_pair(i, cnt));
		if (cnt == bomb_size) {
			for (int j = 0; j < bomb_size; j++) {
				st.pop();
			}
			if (!st.empty()) cnt = st.top().second;
			else cnt = 0;
		}
	}
	if (st.empty()) printf("FRULA");
	else {
		int k = st.size();
		for (int i = 0; i < k; i++) {
			ans.push_back(input[st.top().first]);
			st.pop();
		}
		reverse(ans.begin(), ans.end());
	}
	cout << ans << "\n";
	return 0;
}

