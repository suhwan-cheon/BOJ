#include <iostream>
using namespace std;
int n, max_num, min_num;

void Input() { cin >> n; }

void Solution() {
	max_num = -1000000;
	min_num = 10000000;
	ios_base::sync_with_stdio(false);
	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		max_num = (tmp > max_num) ? tmp : max_num;
		min_num = (tmp < min_num) ? tmp : min_num;
	}
}
void Output() {
	cout << min_num << " " << max_num << endl;

}
int main(void)
{
	Input();
	Solution();
	Output();
	return 0;
}

