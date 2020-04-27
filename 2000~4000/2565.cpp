#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1000];
//d[i][j][k] : i개의 수 중 j개를 골랐고, 합을 n으로 나눈 나머지가 k
bool d[1000][500][500]; 

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2*n-1; i++) {
		scanf("%d", &a[i]);
	}
	d[0][0][0] = true;
	//dp
	for (int i = 1; i <= 2 * n - 1; i++) {
		for (int j = i; j >= 0; j--) {
			for (int k = 0; k < n; k++) {
				//case 1 : i 번째 수를 고르지 않은 경우
				if (d[i - 1][j][k]) d[i][j][k] = true;
				
				//case 2 : i 번째 수를 고른 경우
				if (d[i-1][j][k]) {
					d[i][j + 1][(k + a[i]) % n] = true;
				}
			}
		}
	}
}