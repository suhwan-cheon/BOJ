#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int ind[32001];
vector <int> prob[32001];

int main()
{
	priority_queue<int, vector<int>, greater<int> >q;
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		ind[b] += 1;
		prob[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int temp = q.top();
		q.pop();
		printf("%d ",temp);
		for (int i = 0; i < prob[temp].size(); i++) {
			int y = prob[temp][i];
			ind[y] -= 1;
			if (ind[y] == 0) {
				q.push(y);
			}
		}
	}
	printf("\n");
	return 0;
}
