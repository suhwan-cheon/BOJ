#include <iostream>
using namespace std;
int n;
int parent[51];
bool check[51]; //리프면 false
bool check2[51]; //한번더 체크해줘야함
int root;
//떨어지는 노드들
void fall(int x) {
	check[x] = true; //절대 카운팅 될 수 없으므로
	parent[x] = 999; //나올 수 없는 부모 값으로 바꿔주기
	for (int i = 0; i < n; i++) {
		if (parent[i] == x) fall(i);
	}
	return;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &parent[i]);
		if (parent[i] == -1) { //루트노드라면
			parent[i] = 999; //나올 수 없는 부모 값
			check[i] = true; //리프 x
			root = i;
		}
	}
	//지울 노드
	int trash; scanf("%d", &trash);
	if (trash == root) { //지울 노드가 루트라면
		printf("0\n");
		return 0;
	}
	fall(trash);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (parent[i] == 999) continue;
		check[parent[i]] = true;
	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) ans++;
	}
	//루트만 달랑~ 남은경우!
	if (ans == 0) ans = 1;
	printf("%d\n", ans);
	return 0;
}
