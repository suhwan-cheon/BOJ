#include <iostream>
using namespace std;
int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int min_dist = x;
	if (w - x < min_dist) min_dist = w - x;
	if (y < min_dist) min_dist = y;
	if (h - y < min_dist) min_dist = h - y;
	cout << min_dist;
	return 0;
}
