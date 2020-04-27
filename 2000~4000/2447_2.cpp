#include <iostream>
using namespace std;

char star[2500][2500];
int n;
void put_star(int y, int x, int squard, int check) {
	if (squard == 0) {
		if (check == 1) star[y][x] = ' ';
		else star[y][x] = '*';
		return;
	}
	else {
		int t = 1;
		for (int i = 0; i < squard - 1; i++) {
			t *= 3;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1) put_star(y + (i * t), x + (j * t), squard - 1, 1);
				else {
					if (check == 1) put_star(y + (i * t), x + (j * t), squard - 1, 1);
					else put_star(y + (i * t), x + (j * t), squard - 1, 0);
				}
			}
		}
	}
}

void print_star() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d", &n);
	int squard = 0;
	int temp_n = n;
	while (temp_n != 1) { //3의 제곱 수 구하기
		temp_n /= 3;
		squard++;
	}
	put_star(0, 0, squard, 0);
	print_star();
	return 0;
}
