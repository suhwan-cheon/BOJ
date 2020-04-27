#include <iostream>
#include <algorithm>
using namespace std;
int d[1001][1001];
int main()
{
	string temp1, temp2;
	cin >> temp1 >> temp2;

	string a, b;
	a = " " + temp1;
	b = " " + temp2;

	int na = a.size();
	int nb = b.size();

	for (int i = 1; i < na; i++) { // LCS 문자 길이 찾기
		for (int j = 1; j < nb; j++) {
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			}
		}
	}
	printf("%d\n", d[na-1][nb-1]);
	string ans;
	int i = na - 1;
	int j = nb - 1;

	while (d[i][j] != 0) {
		if (d[i][j] == d[i][j - 1]) { //앞의 값과 같다면
			j--;
		}
		else if (d[i][j] == d[i-1][j]) { //위의 값과 같다면 
			i--;
		}
		else { //대각선이 1차이
			ans += a[i];
			i--;
			j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}

