#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	
	//만들 수 있는 최대 팀 수 구하기
	int team_cnt = 0;
	if (n >= 2 * m) team_cnt = m;
	else if (n < 2 * m) team_cnt = n / 2;
	while (k > 0) {
		if (n > 2 * m) {
			n--;
			k--;
			team_cnt = m;
		}
		else if (n < 2 * m) {
			m--;
			k--;
			team_cnt = n/2;
		}
		else {
			k -= 3;
			m--;
			n -= 2;
			team_cnt = m;
		}
	}
	printf("%d", team_cnt);
	return 0;
}
