#include <iostream>
using namespace std;

int mat_a[101][101];
int mat_b[101][101];
int mat_c[101][101];
int main()
{
	int n, m; scanf("%d %d", &n, &m); //행렬 a의 크기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mat_a[i][j]);
		}
	}

	int k; scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &mat_b[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			mat_c[i][j] = 0;
			for (int t = 0; t < m; t++) {
				mat_c[i][j] += mat_a[i][t] * mat_b[t][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", mat_c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
