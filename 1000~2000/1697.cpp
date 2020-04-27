#define MAX 200001
#include <iostream>
#include <queue>
using namespace std;

bool check[MAX];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	int pos = 0; int cnt = 0;
	queue<pair<int, int> >q;
	q.push(make_pair(n, 0));
	while (!q.empty()) {
		pos = q.front().first;
		cnt = q.front().second;
		check[pos] = true;
		q.pop();

		if (check[k] == true) break;

		if (pos + 1 < MAX && check[pos + 1] == false) {
			q.push(make_pair(pos + 1, cnt + 1));
		}
		if (pos - 1 >= 0 && check[pos - 1] == false) {
			q.push(make_pair(pos - 1, cnt + 1));
		}
		if (pos * 2 < MAX && check[pos * 2] == false) {
			q.push(make_pair(pos * 2, cnt + 1));
		}
	}
	printf("%d", cnt);
	return 0;
}

