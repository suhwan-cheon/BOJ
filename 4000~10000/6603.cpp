#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int first_check = 1;
	while (1) {
		int t; scanf("%d", &t);
		if (t == 0) break;
		vector<int> s;
		if (first_check == 0) printf("\n");
		first_check = 0;
		for (int i = 0; i < t; i++) {
			int temp; scanf("%d", &temp);
			s.push_back(temp);
		}
		vector<int> ind;
		int k = 6; //6개 뽑기
		
		for (int i = 0; i < k; i++) { //k개의 1 추가
			ind.push_back(1);
		}
		for (int i = 0; i < s.size() - k; i++) { //전체크기 - k개의 0 추가
			ind.push_back(2);
		}
		sort(ind.begin(), ind.end());
		do {
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					printf("%d ", s[i]);
				}
			}
			printf("\n");
		} while (next_permutation(ind.begin(), ind.end()));
		
	}
	return 0;
}

