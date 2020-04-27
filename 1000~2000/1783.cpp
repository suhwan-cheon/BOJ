#include <iostream>
using namespace std;

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	if (m == 1 || n == 1) printf("%d", 1); //둘 중 하나만 1이어도 이동x
	else if (n == 2) {
		if (m == 2) printf("%d", 1);
		else if (m == 3 || m == 4) printf("%d", 2);
		else if (m == 5 || m == 6) printf("%d", 3);
		else printf("%d", 4);
	}
	else { //n이 3 이상이면 n은 고려하지 않아도 된다.
		if (m == 2) printf("%d", 2);
		else if (m == 3) printf("%d", 3);
		else if (m == 4 || m == 5 || m == 6) printf("%d", 4);
		else { //4가지 다 움직일 수 있을 때
			printf("%d", m - 2);
		}
	}
	return 0;
}
