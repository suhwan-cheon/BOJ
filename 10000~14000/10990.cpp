#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j <= (n - i); j++) {
				cout << " ";
			}
			cout << "*" << endl;

		}
		else {
			for (int j = 1; j <= (n - i); j++) {
				cout << " ";
			}
			cout << "*";

			for (int t = 1; t <= (2*i-3); t++) {
				cout << " ";
			}
			cout << "*" << endl;
		}
	}
}
