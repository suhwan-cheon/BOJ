#include <iostream>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int t[3];
	//물통의 크기
	for (int i = 0; i < 3; i++) {
		scanf("%d", &t[i]);
	}
	//현재 물통에 들어있는 물의 양
	int water[3];
	water[0] = 0; water[1] = 0; water[2] = t[2];
	set<int> s; s.insert(t[2]);

}
