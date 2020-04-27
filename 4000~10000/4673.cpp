#include <iostream>
using namespace std;

bool check[10001];

int self_num(int x) {
	int sum = x;

	while (1) {
		if (x == 0) break;
		sum += x % 10;
		x = x / 10;
	}
	return sum;
}

int main() {
	for (int i = 1; i < 10001; i++) {
		int idx = self_num(i);

		if (idx <= 10001) {
			check[idx] = true;
		}
	}
	for (int i = 1; i < 10001; i++) {
		if (check[i] == false) cout << i << "\n";
	}
	return 0;
}
