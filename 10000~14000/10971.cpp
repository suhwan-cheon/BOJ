#define MAX 100000000
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int w[10][10];
vector<int> city;
int ans = MAX;

int pay_check() {
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		if (w[city[i]][city[i + 1]] == 0) return MAX;
		else temp += w[city[i]][city[i + 1]];
	}
	if (w[city[n - 1]][city[0]] == 0) return MAX;
	else temp += w[city[n - 1]][city[0]];
	return temp;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { //도시들을 배열에 넣음
		city.push_back(i);
	}
	sort(city.begin(), city.end());
	for (int i = 0; i < n; i++) { //비용 행렬
		for (int j = 0; j < n; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	do {
		ans = min(ans, pay_check());
	} while (next_permutation(city.begin(), city.end()));
	printf("%d", ans);
	return 0;
}