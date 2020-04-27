#include <iostream>
using namespace std;
string a[50];
bool check[50][50]; //i와 j가 친구이면 true
int ans[50];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'Y') {
				check[i][j] = true;
				for (int k = 0; k < n; k++) {
					if (a[j][k] == 'Y' && k != i) {
						check[i][k] = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == true) ans[i]++;
		}
	}
	int summ = 0;
	for (int i = 0; i < n; i++) {
		if (summ < ans[i]) summ = ans[i];
	}
	printf("%d\n", summ);
	return 0;
}
