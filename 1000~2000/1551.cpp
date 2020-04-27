#include <iostream>
using namespace std;
char a[20];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	string s; cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') continue;
		else {
			a[cnt] = s[i] - '0';
			cnt++;
		}
	}
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n - 1; j++) {
			a[j] = a[j + 1] - a[j];
		}
		n--;
	}
	for (int i = 0; i < n; i++) {
		if (i == n - 1) printf("%d", a[n-1]);
		else printf("%d,", a[i]);
	}
	return 0;
}
