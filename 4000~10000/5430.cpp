#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; //test case
	cin >> t;
	while (t--) {
		int dir = 0; // 0:front, 1: back
		string p; //command
		cin >> p;

		int n;
		cin >> n;
		string s;
		cin >> s;
		deque<int>dq;
		string temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '[') continue;
			else if (s[i] >= '0' && s[i] <= '9') {
				temp += s[i];
			}
			else if (s[i] == ',' || s[i] == ']') {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}
		
		
		bool check = true;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'D') {
				if (dq.empty()) {
					check = false;
					cout << "error\n";
					break;
				}
				if (dir == 0) dq.pop_front();
				else dq.pop_back();
			}
			else { //p[i] == 'R' pop 방향 바꿔야함
				if (dir == 1) dir = 0;
				else dir = 1;
			}
		}
		if (!check) continue;
		//output
		cout << "[";
		int len = dq.size();
		for (int i = 0; i < len; i++) {
			if (dir == 0) {
				if (i == len - 1) {
					cout << dq.front();
					dq.pop_front();
				}
				else {
					cout << dq.front() << ",";
					dq.pop_front();
				}
			}
			else {
				if (i == len - 1) {
					cout << dq.back();
					dq.pop_back();
				}
				else {
					cout << dq.back() << ",";
					dq.pop_back();
				}
			}
		}
		cout << "]\n";
	}
	return 0;
}
