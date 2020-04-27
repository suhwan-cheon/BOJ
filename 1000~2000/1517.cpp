#include <iostream>
#include <algorithm>
using namespace std;

int a[500000];
int b[500000];
long long ans;
//단순한 버블 소트 = 시간초과
void merge_sort(int start, int end) {
	if (start == end) return; //기저 사례
	int mid = (start + end) / 2;
	//끝까지 분해
	merge_sort(start, mid);
	merge_sort(mid + 1, end);

	int i = start;
	int j = mid + 1;
	int k = 0;
	while (i <= mid || j <= end) {
		if (i <= mid && (j > end || a[i] <= a[j])) {
			b[k++] = a[i++];
		}
		else {
			ans += (long long)(mid - i + 1);
			b[k++] = a[j++];
		}
	}
	for (int i = start; i <= end; i++) {
		a[i] = b[i - start];
	}
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	merge_sort(0, n - 1);
	printf("%lld", ans);
	return 0;
}

