#include <iostream>
#include <string>
using namespace std;
int digit[10][10] = { //디지털 숫자로 생각 0 ~ 9
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
int main()
{
	int s; string n;
	cin >> s >> n;
	int t = n.size();
	for (int i = 0; i < 5; i++) { //4단계 구성
		if (i == 0 || i == 2 || i == 4) { //가로 칸
			for (int j = 0; j < t; j++) {
				int temp = n[j] - '0'; //숫자 번호
				if (j != 0) { //처음 값 처리(숫자 간 공백 처리)
					cout << ' '; 
				}
				cout << ' ';
				if ((i == 0 && digit[temp][0]) || (i == 2 && digit[temp][3])
					|| (i == 4 && digit[temp][6])) {
					for (int k = 0; k < s; k++) {
						cout << '-';
					}
				}
				else {
					for (int k = 0; k < s; k++) {
						cout << ' ';
					}
				}
				cout << ' ';
			}
			cout << "\n";
		}
		else { //세로 칸
			for (int v = 0; v < s; v++) { //세로 줄 크기(vertical)
				for (int j = 0; j < t; j++) {
					int temp = n[j] - '0';
					if (j != 0) {
						cout << ' ';
					}
					if ((i == 1 && digit[temp][1]) || (i == 3 && digit[temp][4])) {
						cout << '|';
					}
					else {
						cout << ' ';
					}
					for (int k = 0; k < s; k++) {
						cout << ' ';
					}
					if ((i == 1 && digit[temp][2]) || (i == 3 && digit[temp][5])) {
						cout << '|';
					}
					else cout << ' ';
				
				}
				cout << "\n";
			}
			
		}
	}
	return 0;
}

