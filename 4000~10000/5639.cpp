#include <iostream>
using namespace std;

int node[10000];

void postorder(int start, int end) {

}
int main()
{
	int cnt = 0;
	//데이터의 개수를 알 수 없을 때
	for (int i = 0; scanf("%d", node[i]) > 0; i++) cnt++;

	postorder(0, cnt);
	return 0;
}