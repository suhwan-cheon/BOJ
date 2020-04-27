#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string a, t;
	cin >> a >> t;
	int t_size = t.size();
	int a_size = a.size();
	int start = 0;
	int end = t_size - 1;
	bool check = true;
	while (true) {
		for (int i = start; i < t_size; i++) {
			if (t.substr(i, a_size) == a) {
				t.erase(i, a_size);
				t_size = t.size();
				
				if ((i - 2 * a_size) <= 0) {
					start = 0;
				}
				else {
					start = i - 2 * a_size;
				}
				check = false;
				break;
			}
		}
		if (check) break; //못 찾은 경우

		if (end >= t_size) end = t_size - 1; //앞 당겨진 경우
		
		for (int i = end; i >= 0; i--) {
			if (t.substr(i, a_size) == a) {
				t.erase(i, a_size);
				t_size = t.size();
				end = i;
				check = true;
				break;
			}
		}
		if (!check) break; // 못 찾은 경우
	}
	cout << t << "\n";
	return 0;
}