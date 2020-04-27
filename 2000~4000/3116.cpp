#define MAX 2000001
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int DX[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int DY[] = { 1, 1, 1, 0, -1, -1, -1, 0 };

struct bac {
	int x, y, dx, dy;
};

int compute(bac& b1, bac& b2) {
	int d1 = max(abs(b1.x - b2.x), abs(b1.y - b2.y));
	int d2 = max(abs(b1.x + b1.dx - b2.x - b2.dx),
		abs(b1.y + b1.dy - b2.y - b2.dy));

	if (d2 >= d1 || d1 % (d1 - d2) != 0) return -1;

	int t = d1 / (d1 - d2);
	if (b1.x + t * b1.dx == b2.x + t * b2.dx &&
		b1.y + t * b1.dy == b2.y + t * b2.dy) {
		return t;
	}
	return -1;
}

int cnt[MAX], now = 0;
int rang[MAX];
int main()
{
	int n; scanf("%d", &n);
	vector<bac> bact(n);
	for (int i = 0; i < n; i++) {
		int dir;
		scanf("%d %d %d", &bact[i].x, &bact[i].y, &dir);
		bact[i].dx = DX[dir - 1];
		bact[i].dy = DY[dir - 1];
	}

	int max_rank = 0, min_time = 0;
	for (int i = 0; i < n; i++) {
		now++;
		for (int j = i + 1; j < n; j++) {
			int t = compute(bact[i], bact[j]);
			if (t == -1) continue;

			if (cnt[t] != now) {
				cnt[t] = now;
				rang[t] = 2;
			}
			else rang[t]++;

			if (rang[t] > max_rank ||
				rang[t] == max_rank && t < min_time) {
				max_rank = rang[t];
				min_time = t;
			}
		}
	}
	cout << max_rank << "\n";
	cout << min_time << "\n";
	return 0;
}

