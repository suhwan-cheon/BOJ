#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int k = n;
	while (k--) {
		for (int i = 0; i < n; i+= 2) {
			printf("* ");
		}
		printf("\n");
		for (int i = 1; i < n; i += 2) {
			printf(" *");
		}
		printf("\n");
	}
	return 0;
}