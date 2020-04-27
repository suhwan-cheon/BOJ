#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool check[9];
int a[9];
vector<int> t;
vector<vector<int> >d;
void go(int idx) {
	if (idx == m) {
		vector<int> temp;
		for (int i = 0; i < m; i++) {
			temp.push_back(t[a[i]]);
		}
		d.push_back(temp);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (idx > 0 && i < a[idx - 1]) continue;
		a[idx] = i;
		go(idx + 1);
		
	}
}
int main()
{
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		int temp; scanf("%d", &temp);
		t.push_back(temp);
	}
	sort(t.begin(), t.end());
	go(0);
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	for (auto& v : d) {
		for (int i = 0; i < m; i++) {
			cout << v[i];
			if (i != m - 1) {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}

