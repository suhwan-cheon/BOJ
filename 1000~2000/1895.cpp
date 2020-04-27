#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[40][40];
int b[40][40];
int main()
{
	int r, c;
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int t; scanf("%d", &t);
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			vector<int> temp;
			for (int k = 0; k < 3; k++) {
				for (int t = 0; t < 3; t++) {
					temp.push_back(a[i + k][j + t]);
				}
			}
			sort(temp.begin(), temp.end());
			b[i][j] = temp[4];
		}
	}

	int ans = 0;
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			if (b[i][j] >= t) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}

