#include <iostream>
#include <cstdio>
using namespace std;

int arr[1000][1000];
int n = 0, column = 0, row = 0, check = 0, column_check = 0, row_check = 0;
int cnt;
int down() {
	for (int i = 0; i < n; i++) {
		arr[row][column] = cnt - check;
		check++;
		row++;
	}
	row--;
	column++;
	column_check++;
	return 0;
}

int right() {
	for (int i = 0; i < n; i++) {
		int j = 1;
		arr[row][column] = cnt - check;
		check++;
		column++;
	}
	column--;
	row--;
	row_check++;
	return 0;
}

int up() {
	for (int i = 0; i < n; i++) {
		arr[row][column] = cnt - check;
		check++;
		row--;
	}
	row++;
	column--;
	column_check++;
	return 0;
}

int left() {
	for (int i = 0; i < n; i++) {
		arr[row][column] = cnt - check;
		check++;
		column--;
	}
	column++;
	row++;
	row_check++;
	return 0;
}

int main() {

	cin >> n;
	int new_n = n;
	cnt = n * n;
	while (cnt - check != 0) {
		if (check == 0) {
			down();
			n--;
			right();
			up();
			n--;
			left();
		}
		else {
			down();
			n--;
			if (n == 0) break;
			right();
			up();
			n--;
			left();
		}

	}
	int i = 0, j = 0;

	for (i = 0; i < new_n; i++) {
		for (j = 0; j < new_n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}