#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int c[1001];
vector<pair<int, int> >v[1001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >,
	greater<tuple<int, int, int> > >pq;
int dist[1001][1001];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == 0) continue;
			else {
				v[i].push_back(make_pair(j, temp));
			}
		}
	}
	int ans1 = 0;
	int ans2 = 0;
	memset(dist, 127, sizeof(dist));
	int INF = dist[0][0];
	dist[0][0] = 0;
	//(trans, hour, idx)
	pq.emplace(0, 0, 0);
	while (!pq.empty()) {
		int trans, hour, idx;
		tie(trans, hour, idx) = pq.top();
		pq.pop();

		if (dist[idx][trans] != hour) continue;
		bool check1 = false;
		for (int i = 0; i < v[idx].size(); i++) {
			int next = v[idx][i].first;
			int time = v[idx][i].second;
			int add = 0;
			if (c[idx] != c[next]) add = 1;

			if (dist[next][trans + add] > hour + time) {
				dist[next][trans + add] = hour + time;
				pq.emplace(trans + add, hour + time, next);
			}
		}
		if (check1) break;
	}

	printf("%d %d\n", ans1, ans2);
	return 0;
}
