#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int ans = 999999;
vector<pair<int, int> >chicken;
vector<pair<int, int> >home;
bool check[13];
int simulate(vector<pair<int, int> >& chick) {
	int temp_ans = 0; //임시 치킨 거리

	//각 집에 대한 최소 치킨 거리 구하기
	for (int i = 0; i < home.size(); i++) {
		int temp = 99999;
		for (int j = 0; j < chick.size(); j++) {
			int dist = 0;
			int dist1 = home[i].first - chick[j].first;
			int dist2 = home[i].second - chick[j].second;
			if (dist1 < 0) dist += (-dist1);
			else dist += dist1;
			if (dist2 < 0) dist += (-dist2);
			else dist += dist2;
			temp = min(temp, dist);
		}
		temp_ans += temp;
	}
	return temp_ans;
}
void go(vector<pair<int, int> >& chick, int cnt) {
	if (cnt == m) {
		ans = min(ans, simulate(chick));
		return;
	}
	else if (cnt > m) return;
	for (int i = 0; i < chicken.size(); i++) {
		if (check[i] == false) {
			chick.push_back(chicken[i]);
			check[i] = true;
			go(chick, cnt + 1);
			chick.pop_back();
			
		}
		else continue;
	}
	return;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp; scanf("%d", &temp);
			if (temp == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (temp == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	vector<pair<int, int> >chick;
	go(chick, 0);
	printf("%d\n", ans);
	return 0;
}
