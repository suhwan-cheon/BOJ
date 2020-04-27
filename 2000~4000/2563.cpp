#include <iostream>
#include <string>
using namespace std;
int main() {
	int now = 100;
	int want = 0; int fix = 0; char arr[11];
	int simple = 0;
	int max = 999999, min = 0;
	int lmax = 0, lmin = 0;
	int flag = 0, flag2 = 0;
	int click = 0;
	int tmp = 0;
	//string str1;
//입력
	cin >> want >> fix;
	for (int i = 0; i < fix; i++) {
		tmp = 0;
		cin >> tmp;
		//cout << "tmp : " << tmp << "\n";
		arr[tmp] = 'a';
		//cout << "!!금지!! \n" << arr[tmp] << "\n";
	}
	//단순++--
	if (want > now) {
		simple = want - now;
	}
	else if (want < now) {
		simple = now - want;
	}
	else {
		simple = 0;
	}
	//숫자버튼+위아래
	for (int i = 0; i <= 999999; i++) {
		flag = 0;
		string str1 = to_string(i);
		//cout << "check to_string : " << str1 << "\n";
		for (int j = 0; j < 10; j++) {
			//고장난 버튼이면서 그 버튼이 현재 바깥 for문에 포함되어 있다면
			if (arr[j] == 'a' && str1.find((j + 48)) != string::npos) {
				//cout << "현재 i: " << i << " : " << j << "\n";
				//cout << "!!!!!!" << str1.find(arr[j]) << "\n";
				flag = -1;
				//cout << "$$$버튼 고장 포함$$$. : " << j << "\n";
				break;
			}
		}
		if (flag == -1) {//버튼 고장난 숫자 포함한거니까 다시 for문 진행
			continue;
		}
		else if (flag == 0) {
			if (want >= i) {
				//cout << "min 건들러!" << "\n";
				min = i; //이렇게 해주면 원하는 숫자에 근접한 버튼눌러서 구할 수 있음
			}
			else if (i > want) {
				//cout << "max 건들러!" << "\n";
				max = i;
				break;
			}
		}
	}
	if (max >= 100000) {
		click = 6;
	}
	else if (max >= 10000) {
		click = 5;
	}
	else if (max >= 1000) {
		click = 4;
	}
	else if (max >= 100) {
		click = 3;
	}
	else if (max >= 10) {
		click = 2;
	}
	else {
		click = 1;
	}
	if (min >= 100000) {
		click = 6;
	}
	else if (min >= 10000) {
		click = 5;
	}
	else if (min >= 1000) {
		click = 4;
	}
	else if (min >= 100) {
		click = 3;
	}
	else if (min >= 10) {
		click = 2;
	}
	else {
		click = 1;
	}
	//cout << "**max** : " << max << "\n";
	//cout << "**min** : " << min << "\n";
	lmax = max - want + click;
	lmin = want - min + click;
	//최종비교(그냥 위아래 눌러서, 버튼 누르고 위아래)
	if (simple <= lmin) {
		if (simple <= lmax) {
			cout << simple;
		}
		else {
			cout << lmax;
		}
	}
	else if (lmin <= lmax) {
		if (lmin <= simple) {
			cout << lmin;
		}
		else {
			cout << simple;
		}
	}
	else if (lmax <= simple) {
		if (lmax <= lmin) {
			cout << lmax;
		}
		else {
			cout << lmin;
		}
	}
	cout << "\n";
	return 0;
}