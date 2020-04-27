#define MAX 2000000000LL * 1000000LL
#include <iostream>
using namespace std;
int a[10000];
int p, n;
int main()
{
	scanf("%d%d", &p, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	if (p <= n) {
		printf("%d\n", p);
		return 0;
	}
	long long left = 0;
	long long right = MAX;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long begin, end; 
		//begin,end : begin시간이 시작하기전과 끝날때까지 몇명탔는가?
		begin = end = 0;
		end = n; //처음에 바로 n명이 타니까
		for (int i = 0; i < n; i++) {
			end += mid / a[i];
		}
		begin = end;
		for (int i = 0; i < n; i++) { //mid시간에 탄 친구들은 빼준다
			if (mid % a[i] == 0) begin -= 1;
		}
		begin += 1;
		if (p < begin) { //덜 탄경우
			right = mid - 1;
		}
		else if (p > end) { //너무 많이 탄 경우
			left = mid + 1;
		}
		else { //p가 begin과 end 사이 범위에 들어갈 때(정답 범위 내)
			for (int i = 0; i < n; i++) {
				if (mid % a[i] == 0) { //mid시간에 a[i]가 쉬는경우
					if (p == begin) { //p가 바로 begin인경우
						printf("%d\n", i + 1);
						return 0;
					}
					begin++; //begin이 end까지 갈때까지 ㄱㄱ
				}
			}
		}
	}
	return 0;
}

