#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int m; scanf("%d", &m);
	while (m--) {
		int temp; scanf("%d", &temp);
		int left = 0; int right = n - 1;
		bool check = false;
		int lower = 0; int upper = 0;
		//lower bound
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] == temp) {
				lower = mid;
				right = mid - 1;
				check = true;
			}
			else if (a[mid] > temp) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		//upper bound
		left = 0; right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] == temp) {
				upper = mid + 1;
				left = mid + 1;
				check = true;
				
			}
			else if (a[mid] > temp) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		if (!check) printf("0 ");
		else printf("%d ", upper - lower);
	}
}

