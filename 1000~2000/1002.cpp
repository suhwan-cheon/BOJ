#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t; cin >> t;
	while (t--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//두 점 사이의 거리
		double distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		if (r1== r2 && distance == 0) cout << -1 << "\n";  //# case1 두 원 일치
		else if (distance == (r1 + r2) * (r1 + r2)) cout << 1 << "\n"; // #case 2 두 원이 외접
		else if (abs(r1 - r2) * abs(r1 - r2) == distance) cout << 1 << "\n"; //#case 3 두 원이 내접
		else if (distance > (r1 + r2) * (r1 + r2)) cout << 0 << "\n";  // #case 4 원과 원사이가 매우 멀 떄
		else if (distance < abs(r1 - r2) * abs(r1 - r2)) cout << 0 << "\n"; //#case 5 한 원이 다른 원 안에 있을 때
		else cout << 2 << "\n";
	}
	return 0;
}
