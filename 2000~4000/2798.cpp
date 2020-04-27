#include <iostream>
#include <cstring>
using namespace std;

int card[101];
int main()
{
	int card_num, dealer_num; // card 개수, 딜러가 외치는 값
	cin >> card_num >> dealer_num;
	memset(card, 0, sizeof(card));  //card 배열 초기화
	//각 카드에 쓰여 있는 수 입력받는다.
	for (int i = 0; i < card_num; i++) {
		int k = 0;
		cin >> k;
		card[i] = k;
	}

	int max_ans = 0;  // dealer_num을 넘지 않는 최대값 ( 정답 )

	//브루트 포스를 이용하여 시간복잡도를 계산하지 않고 중첩 for문 사용
	for (int i = 0; i < card_num; i++) {
		for (int j = i + 1; j < card_num; j++) {
			for (int k = j + 1; k < card_num; k++) {
				int max_num = card[i] + card[j] + card[k];
				if (max_num > max_ans && max_num <= dealer_num) max_ans = max_num;
			}
		}
	}
	cout << max_ans;
	return 0;
}
