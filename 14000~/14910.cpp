#include <iostream>
using namespace std;
int a[1000001];
int main()
{
	int k = 0;
	do {
		scanf("%d", &a[k]);
		k++;
	} while (getc(stdin) == ' ');
	int temp = a[0];
	if (k == 1) {
		printf("Good\n");
		return 0;
	}
	for (int i = 1; i < k; i++) {
		if (temp <= a[i]) temp = a[i];
		else {
			printf("Bad\n");
			break;
		}
		if (i == k - 1) {
			printf("Good");
			break;
		}
	}
	return 0;
}

