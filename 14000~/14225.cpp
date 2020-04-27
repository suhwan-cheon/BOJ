#include <iostream>
using namespace std;

bool d[2000001];
int a[20];
int n;
void go(int i, int sum) {
	if (i == n) {
		d[sum] = true;
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	//o(2^n)
	go(0, 0);
	int i = 1;
	while (i < 2000001) {
		if (d[i] == false) {
			printf("%d\n", i);
			break;
		}
		i++;
	}
	return 0;
}
