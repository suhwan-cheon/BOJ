#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	set<string> st;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string name, cmd;
		cin >> name >> cmd;
		if (cmd == "enter") st.insert(name);
		else st.erase(st.find(name));
	}
	for (auto it = st.rbegin(); it != st.rend(); it++) {
		cout << *it << "\n";
	}
	return 0;
}
