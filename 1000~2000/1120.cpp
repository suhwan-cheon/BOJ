#include <iostream>
#include <string>
using namespace std;
int b_size = 0;
int check(string& a, string& b) {
	int size_a = a.size();
	int cnt = 0;
	for (int i = 0; i < size_a; i++) {
		if (a[i] == b[i]) cnt++;
	}
	return cnt;
}
int go(string& a, string& b) {
	if (a.size() == b_size) return check(a, b);
	int ans = 0;
	int diff = b_size - a.size();
	for (int i = diff-1; i >= 0; i++) {
		a = b[i] + a;
		go(a, b);
		
	}
}
int main()
{
	string a, b;
	cin >> a >> b;
	b_size = b.size();
	printf("%d\n",go(a, b));
	return 0;
}

