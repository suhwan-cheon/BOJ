#include <iostream>
using namespace std;
int main() {

	int arr[8][8] = { 0, };
	int times = 0; //빙거 즐 개수
	int tmp = 0; //정답 숫자
	int cnt = 100; //100이상부터 순서대로
	int bin = 0; //빙고 5개 채우기용
	int a = 0, b = 0; //하나 넣을 때마다 앞뒤양옆 대각선 확인용
	//입력받기

	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			cin >> arr[i][j];
		}
	}

	for (int h = 0; h < 25; h++) {
		cin >> tmp; //정답 입력
		for (int i = 1; i < 6; i++) {
			for (int j = 1; j < 6; j++) {
				if (arr[i][j] == tmp) {
					bin = 0;
					//일단 나온 숫자 표시하기
					arr[i][j] = cnt; //100부터 순서대로 집어넣음
					cnt++;
					//앞뒤양옆대각선 확인하기
	//기준왼쪽
					a = i; b = j - 1;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							b--;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					//기준오른쪽
					a = i; b = j + 1;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							b++;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					//가로다했으니 bin 초기화
					bin = 0;
					//기준 위쪽
					a = i - 1; b = j;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							a--;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					//기준 아래쪽
					a = i + 1; b = j;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							a++;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					//세로다했으니 bin 초기화
					bin = 0;
					//대각선1
					a = i + 1; b = j + 1;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							a++;
							b++;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					a = i - 1; b = j - 1;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							a--;
							b--;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					//대각선2
					bin = 0;
					a = i - 1; b = j + 1;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							a--;
							b++;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
					a = i + 1; b = j - 1;
					while (1) {
						if (arr[a][b] >= 100) {
							bin++;
							a++;
							b--;
							if (bin >= 4) {
								times++;
							}
							if (times >= 3) {
								cout << cnt - 100;
								return 0;
							}
						}
						else {
							break;
						}
					}
				}
				else continue;
			}
		}
	}
	return 0;
}