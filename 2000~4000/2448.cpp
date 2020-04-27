#include <iostream>
using namespace std;

char star[10001][10001];
int n;
void put_star(int y, int x, int squard, int check) {

}
int main()
{
	scanf("%d", &n);
	int k = n / 3; //2^k 수 분리하기
	int squard = 0;
	while (k != 1) {
		k /= 2;
		squard++;
	}
	put_star(n - 3, 2, squard, 0);
}
