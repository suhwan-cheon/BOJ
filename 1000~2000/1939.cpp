#define MAX 1000000000;
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int first, second;
bool check1[100001];
vector<pair<int, int> >v[100001];



bool dfs(int st, int t) { //st : first , t : mid
	if (check1[st]) return false; //이미 방문했다면
	check1[st] = true;
	if (st == second) return true; //도착 시
	for (auto& p : v[st]) {
		int next = p.first; //다음 섬
		int cost = p.second;
		if (cost >= t) {
			if (dfs(next, t)) return true;
		}
		
	}
	return false;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) { //다리 입력받기
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	scanf("%d%d", &first, &second);
	int left = 1;
	int right = MAX;
	int ans = 0;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		memset(check1, false, sizeof(check1));
		if (dfs(first, mid)) { //옮길 수 있을 경우
			ans = mid;
			left = mid + 1; //중량 증가
		}
		else right = mid - 1; //중량 감소
	}
	printf("%d", ans);
	return 0;
}
