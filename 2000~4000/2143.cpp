#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
	//input
	int t; scanf("%d", &t);
	int n; scanf("%d", &n);
	vector<int>a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int m; scanf("%d", &m);
	vector<int>b(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	
	vector<long long>psum_a, psum_b;
	//모든 경우의 부분 합
	for (int i = 0; i < n; i++) {
		long long sum = a[i];
		psum_a.push_back(sum);
		for (int j = i + 1; j < n; j++) {
			sum += a[j];
			psum_a.push_back(sum);
		}
	}
	for (int i = 0; i < m; i++) {
		long long sum = b[i];
		psum_b.push_back(sum);
		for (int j = i + 1; j < m; j++) {
			sum += b[j];
			psum_b.push_back(sum);
		}
	}
	sort(psum_a.begin(), psum_a.end());
	sort(psum_b.begin(), psum_b.end());
	long long ans = 0;
	for (int i = 0; i < psum_a.size(); i++) {
		int low = lower_bound(psum_b.begin(), psum_b.end(), t - psum_a[i]) - psum_b.begin();
		int upper = upper_bound(psum_b.begin(), psum_b.end(), t - psum_a[i]) - psum_b.begin();
		ans += upper - low;
	}
	printf("%lld\n", ans);
	return 0;
}
