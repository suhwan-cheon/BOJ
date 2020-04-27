#include <iostream>
#include <cmath>

using namespace std;
int main()

{
	int t; scanf("%d", &t);

	for (int i = 0; i < t; i++)

	{
		int x, y; scanf("%d%d", &x, &y);
		long long k = 1; //제곱 수

		while (k * k <= (y - x))
			k++;
		k--;

		long long remain = (y - x) - (k * k);
		remain = (long long)ceil((double)remain / (double)k);

		cout << k * 2 - 1 + remain << "\n";
	}

	return 0;

}