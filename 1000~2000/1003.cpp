#include <iostream>
#include <vector>
using namespace std;


int dp(int x) {
	vector <int> a[41];
	a[0].push_back(1); a[0].push_back(0);
	a[1].push_back(0); a[1].push_back(1);
	for (int i = 2; i <= x; i++) {
		a[i].push_back(a[i - 1][0]+a[i-2][0]);
		a[i].push_back(a[i - 1][1]+ a[i - 2][1]);
	}
	cout << a[x][0] << ' ' << a[x][1] << "\n";
	return 0;
}

int main()
{
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		dp(n);
		
	}
}

