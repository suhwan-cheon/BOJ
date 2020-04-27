#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
//노드 번호, 자식들을 저장할 공간
vector<pair<int, int> >v(10001);
//루트를 가려낼 공간
bool check[10001];
//idx(루트번호) - 열 번호
int row[10001];
vector<int>temp_row;
//레벨 번호
int level[10001];

void preorder(int x) {
	if (x == -1) return;
	preorder(v[x].first);
	temp_row.push_back(x);
	preorder(v[x].second);
}
void level_bfs(int x) {
	int lv = 1;
	level[x] = lv;
	queue<pair<int, int> >q;
	q.push(make_pair(x, lv));
	while (!q.empty()) {
		int dx = q.front().first;
		int dv = q.front().second;
		level[dx] = dv;
		q.pop();
		if (v[dx].first != -1) q.push(make_pair(v[dx].first, dv + 1));
		if (v[dx].second != -1) q.push(make_pair(v[dx].second, dv + 1));
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int node, left, right;
		scanf("%d %d %d", &node, &left, &right);
		v[node].first = left;
		v[node].second = right;
		check[left] = true; check[right] = true;
	}
	//루트 찾기
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			root = i;
			break;
		}
	}
	//전위순회를 통하여 열 번호 추출
	preorder(root);
	for (int i = 0; i < temp_row.size(); i++) {
		row[temp_row[i]] = i + 1;
	}
	//bfs를 통해 레벨 번호 추출
	level_bfs(root);

	//같은 레벨 끼리 묶어서 레벨 너비 추출
	int ans_range = 1;
	int ans_level = 1;
	for (int i = 2; i < 5000; i++) {
		vector<int>v2;
		for (int j = 1; j <= n; j++) {
			if (level[j] == i) v2.push_back(row[j]);
		}
		if (v2.size() == 1) continue;
		else if (v2.size() != 0) {
			sort(v2.begin(), v2.end());
			if (ans_range < v2[v2.size() - 1] - v2[0] + 1) {
				ans_range = v2[v2.size() - 1] - v2[0] + 1;
				ans_level = i;
			}
		}
	}
	printf("%d %d", ans_level, ans_range);
	return 0;
}
