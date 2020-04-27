#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int a[101][101];
int b[101][101];
bool check1[101][101];
bool check2[101][101];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int main()
{
	int n; scanf("%d", &n);
	vector<string>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char temp = v[i][j];
			if (temp == 'R') {
				a[i][j] = b[i][j] = 1;
			}
			else if (temp == 'G') {
				a[i][j] = 2;
				b[i][j] = 1;
			}
			else {
				a[i][j] = 3;
				b[i][j] = 3;
			}
		}
	}
	//bfs
	//적록색약이 아닌 사람
	int ans1 = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check1[i][j]) continue;
			ans1++;
			queue<pair<int, int> >q;
			q.emplace(i, j);
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (0 <= ny && ny < n && 0 <= nx && nx < n
						&& a[i][j] == a[ny][nx] && check1[ny][nx] == false) {
						q.emplace(ny, nx);
						check1[ny][nx] = true;
					}
				}
			}
		}
	}

	//적록색약인 사람
	int ans2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check2[i][j]) continue;
			ans2++;
			queue<pair<int, int> >q;
			q.emplace(i, j);
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (0 <= ny && ny < n && 0 <= nx && nx < n
						&& b[i][j] == b[ny][nx] && check2[ny][nx] == false) {
						q.emplace(ny, nx);
						check2[ny][nx] = true;
					}
				}
			}
		}
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}

