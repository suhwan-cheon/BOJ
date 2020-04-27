#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int> >p1; //x축 먼저
vector<pair<int, int> >p2; //y축 먼저
int main()
{
	int n; scanf("%d", &n);
	long long ans = 1000000000;
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		p1.push_back(pair<int, int>(x, y));
		p2.push_back(pair<int, int>(y, x));
	}
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	
	for (int i = 0; i < n-1; i++) {
		long long length = (p1[i].first - p1[i + 1].first) * (p1[i].first - p1[i + 1].first);
		length += (p1[i].second - p1[i+1].second) * (p1[i].second - p1[i+1].second);
		if (length < ans) ans = length;

		length = (p2[i].first - p2[i + 1].first) * (p2[i].first - p2[i + 1].first);
		length += (p2[i].second - p2[i+1].second) * (p2[i].second - p2[i+1].second);
		if (length < ans) ans = length;
	}
	printf("%lld", ans);
}

