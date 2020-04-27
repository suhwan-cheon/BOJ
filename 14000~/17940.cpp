#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int n, m;
int c[1001];
//(next, hours)
vector<pair<int, int> >v[1001];
int d[1011]; 
const int TP = 1000000;
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp; scanf("%d", &temp);
			if (temp == 0) continue;
			else {
				if (c[i] == c[j]) {
					v[i].push_back(make_pair(j, temp));
				}
				else v[i].push_back(make_pair(j, temp + TP));
			}
		}
	}

	//init (hour, node)
	priority_queue<pair<int, int>, vector<pair<int, int> >,
	greater<pair<int, int> > >pq;
	pq.push(make_pair(0, 0));
	//(node, trans) -> hours
	memset(d, 127, sizeof(d));
	int INF = d[0];
	d[0] = 0;
	while (!pq.empty()) {
		int hour = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (d[node] != hour) continue;
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i].first;
			int hours = v[node][i].second;
			
			if (d[next] > hour + hours) {
				d[next] = hour + hours;
				pq.push(make_pair(hour + hours, next));
			}
		}
	}
	printf("%d %d\n", d[m] / TP, d[m] % TP);
	return 0;
}
