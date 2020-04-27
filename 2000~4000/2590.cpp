#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int number, length;
	int num = 0, count = 0;
	char first[10], other[10];

	cin >> number;
	scanf("%s", first);
	number--;

	while (number--) {
		scanf("%s", other);
		length = strlen(first) - strlen(other);
		printf("length :  %d\n", length);
		if (length == 0) {  //문자열 길이가 같을때
			num = 0;
			for (int i = 0; i < strlen(first); i++) {
				for (int j = 0; j < strlen(other); j++) {
					if (first[i] == other[j]) {
						other[j] = '.';
						break;
					}
					else if (j == strlen(other) - 1) {
						num++;
					}
				}
			}
			if (num < 2) count++;
			printf("num :    %d\n", num);
		}

		else if (length == 1) { //처음 문자열 길이가 더 길때
			num = -1;
			for (int i = 0; i < strlen(first); i++) {
				for (int j = 0; j < strlen(other); j++) {
					if (first[i] == other[j]) {
						other[j] = '.';
						break;
					}
					else if (j == strlen(other) - 1) {
						num++;
					}
				}
			}
			if (num == 0) count++;
		}

		else if (length == -1) { //나중 문자열 길이가 더 길때
			num = 0;
			for (int i = 0; i < strlen(first); i++) {
				for (int j = 0; j < strlen(other); j++) {
					if (first[i] == other[j]) {
						other[j] = '.';
						break;
					}
					else if (j == strlen(other) - 1) {
						num++;
					}
				}
			}
			if (num == 0) {
				for (int i = 0, cont = 0; i < strlen(other); i++) {
					if ('A' <= other[i] && other[i] < 'Z') {
						for (int j = 0; j < strlen(first); j++) {
							if (cont < 1 && other[i] == first[j]) {
								other[i] = '.';
								cont++;
								break;
							}
							else if (j == strlen(first) - 1) {
								num++;
							}
						}
					}
				}
				if (num == 0) count++;
			}
		}
	}
	cout << count;
}
