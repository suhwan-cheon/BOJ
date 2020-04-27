#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int n, a, b;
int l, p;
int it;
int ans;
//(연료의 양, 거리)
priority_queue<int>pq;
pair<int, int>arr[10002];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	scanf("%d %d", &l, &p);
	sort(arr, arr + n);
	//p : 시작점은 고정한 채 연료의 양
	//거리 l보다 커지면 멈춘다.
	while (p < l) {
		//현재 갈 수 있는 거리(p) 내에서의 주유소 가스 최대량을 찾기위해
		//pq에 가능한 주유소를 모두 push한다.
		while (arr[it].first <= p) {
			if (it == n) break;
			pq.push(arr[it].second);
			it++;
		}
		//더 이상 주유소를 못찾을 경우 멈춤
		if (!pq.size()) break;
		ans++;
		//석유 드링킹, 요즘 석유값이 마이너스라 돈 받고 산다고 한다.
		p += pq.top(); pq.pop();
	}
	if (p < l) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
