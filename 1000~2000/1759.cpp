#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int l, c;
//a: 모음 수, b: 자음 수, i : 사용할지 말지 결정해야하는 알파벳 인덱스
void pas(vector<char>& alpha, string password, int a, int b, int i) {
	if (password.length() == l) {
		if (a >= 1 && b>= 2) {
			cout << password << "\n";
		}
		return;
	}
	if (i == alpha.size()) return;
	if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u') {
		pas(alpha, password + alpha[i],a+1,b, i + 1);
	}
	else pas(alpha, password + alpha[i],a,b+1, i + 1);
	//패스하고 다음으로 넘어가는 경우
	pas(alpha, password,a,b, i + 1);
}
int main() {
	scanf("%d%d", &l, &c);
	vector<char> alpha(c);
	for (int i = 0; i < c; i++) {
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());
	pas(alpha, "", 0, 0,0);
	return 0;
}