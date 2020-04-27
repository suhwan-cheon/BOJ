#include <iostream>
using namespace std;

int cnt[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		cnt[x] += 1;
	}
	for (int i = 1; i <=10000; i++) {
		if (cnt[i] != 0) {
			for (int j = 0; j < cnt[i]; j++) {
				cout << i<<"\n";
			}
		}
	}
	return 0;
}

