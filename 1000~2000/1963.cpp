#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool decimal[10001];
bool check[10001];
int change(int num, int index, int digit) {
	if (index == 0 && digit == 0) return -1;
	string s = to_string(num);
	s[index] = digit + '0';
	return stoi(s);
}
int main()
{
    //소수 배열 만들기
	for (int i = 2; i*i <= 10000; i++) {
		if (decimal[i] == false) { //소수일 때
			int k = i + i;
			while (k < 10000) {
				decimal[k] = true;
				k += i;
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		decimal[i] = !decimal[i];
	}

	int t; scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d%d", &a, &b); //소수 쌍 입력받기
		memset(check,false, sizeof(check));

		check[a] = true;
		queue<pair<int, int> >q; //소수, 카운트
		q.push(make_pair(a, 0));
		int num = 0; int cnt = 0;
		
		while (!q.empty()) {
			num = q.front().first;
			cnt = q.front().second;		
			decimal[num] = true;
			q.pop();
			if (num == b) {
				break;
			}
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(num, i, j);
					if (next != -1) {
						if (decimal[next] && check[next] == false) {
							q.push(make_pair(next, cnt+1));
							check[next] = true;
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}

