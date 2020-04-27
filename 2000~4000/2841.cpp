#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	vector<stack<int> >v(7); // 1~6
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int line, flat;
		scanf("%d %d", &line, &flat);
		if (v[line].empty()) {
			ans++;
			v[line].push(flat);
		}
		else { //비어있지 않은 경우
			if (v[line].top() < flat) {
				ans++;
				v[line].push(flat);
			}
			else if (v[line].top() == flat) continue;
			else { //flat 보다 큰 경우
				bool check = false;
				while (v[line].top() > flat) {
					v[line].pop();
					ans++;
					if (v[line].empty()) {
						ans++;
						check = true;
						v[line].push(flat);
						break;
					}
				}
				if (check) continue;
				if(v[line].top() == flat) continue;
				else {
					v[line].push(flat);
					ans++;
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
