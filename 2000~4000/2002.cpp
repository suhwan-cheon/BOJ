#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n; cin >> n;
	queue<string>q1, q2;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		q1.push(temp);
	}
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		q2.push(temp);
	}
	int ans = 0;
	while (n--) {
		string str1, str2;
		str1 = q1.front(); str2 = q2.front();
		if (str1 == str2) {
			q1.pop(); q2.pop();
		}
		else {
			ans++;
			q1.push(str1); q1.pop();
			q2.pop();
			while (1) {
				string temp2 = q1.front();
				if (temp2 == str1) break;
				else if (temp2 != str2) {
					q1.push(temp2);
				}
				q1.pop();
			}
		}
	}
	cout << ans << "\n";
	return 0;
}

