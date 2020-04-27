#include <iostream>
#include <vector>
using namespace std;

int two_ten(string k) {
	int ans_1 = 0;
	for (int i = 0; i < k.length(); i++) {
		int t = k[k.length()-1-i] - '0';
		ans_1 += t * (2 ** i);
	}
	return ans_1;
}

string ten_two(int x) {

}
int main()
{
	int n; int ans = 0; string k;
	cin >> n; cin >> k;
	vector <int> a(n);

}
