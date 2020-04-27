#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int factor[50];
int main()
{
	int num = 0; cin >> num;
	for (int i = 0; i < num; i++) {
		int a; cin >> a;
		factor[i] = a;
	}
	sort(factor, factor+num);
	cout << factor[0] * factor[num-1];
	return 0;
}
