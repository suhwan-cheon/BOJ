#include <iostream>
using namespace std;

int pascal[31][31];
int main()
{
    // 각 행의 첫 수와 마지막 수 1로 초기화
	for (int i = 1; i <= 30; i++) {
		pascal[i][1] = 1;
		pascal[i][i] = 1;
	}
	//pascal 삼각형 만들기
	for (int i = 3; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
		}
	}
	int n, k;
	cin >> n >> k;
	cout << pascal[n][k] << "\n";
}
