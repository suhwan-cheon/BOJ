#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	string n; cin >> n;
	vector <char> a(n.size());
	for (int i = 0; i < n.size(); i++) {
		a[i] = n[i];
	}
	sort(a.begin(), a.end(),greater<char>());
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];

	}
}

