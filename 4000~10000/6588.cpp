#define MAX 1000001
#include <iostream>
using namespace std;

bool p[MAX];
int main() {
	//100만 이하의 홀수 소수 구하기
	int ptn = 0; //홀수 소수의 개수
	for (int i = 2; i * i < MAX; i++) {
		if (p[i] == false) {
			ptn++;
			int j = i + i;
			while (j < MAX) {
				p[j] = true;
				j = j + i;
			}
		}
	}
	p[2] = true;
	
	
	while (1) {
		int n; scanf("%d", &n);
		if (n == 0) break;
		for (int i = 3; i < n; i++) {
			if (p[i] == false) { //i가 홀수 소수이고,
				if (p[n - i] == false) { //n-i가 홀수 소수이면
					printf("%d = %d + %d\n", n, i, n - i);
					break;
				}
			}
		}
	}
	return 0;
}