#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
int a[100][100];
int temp[100][100];
int r, c, m;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,1,-1 };
int ans;
vector<tuple<int, int, int, int, int> >v;
void fishing(int x) {
	for (int i = 0; i < r; i++) {
		if (a[i][x] != 0) { //상어가 존재하면?
			ans += a[i][x]; //포획
			
			//같은 무게 상어 찾아서 지워버림
			for (int j = 0; j < v.size(); j++) {
				if (get<4>(v[j]) == a[i][x]) {
					get<4>(v[j]) = 0;
					break;
				}
			}
			a[i][x] = 0;
			break;
		}
	}
}
void move() {
	memset(temp, 0, sizeof(temp)); //임시 배열 초기화
	for (int i = 0; i < v.size(); i++) {
		if (get<4>(v[i])) { //무게가 0이 아니라면
			int temp_s = get<2>(v[i]);
			int ty = get<0>(v[i]);
			int tx = get<1>(v[i]);
			
			while (temp_s--) { //속력만큼
				int dir = get<3>(v[i]);
				if ((dir == 1 && ty == 0) || (dir == 2 && ty == r-1)
					|| (dir == 3 && tx == c-1) || (dir == 4 && tx == 0) ) { //범위를 벗어날 경우
					if (get<3>(v[i]) == 1 || get<3>(v[i]) == 3) {
						get<3>(v[i])++;
					}
					else get<3>(v[i])--;
				}
				//이동
				ty += dy[get<3>(v[i])];
				tx += dx[get<3>(v[i])];
			}
			if (temp[ty][tx] != 0) { //그 자리에 상어가 있다면?
				if (temp[ty][tx] < get<4>(v[i])) {
					//그 무게 상어 찾아서 지워버림
					for (int j = 0; j < v.size(); j++) {
						if (get<4>(v[j]) == temp[ty][tx]) {
							get<4>(v[j]) = 0;
							break;
						}
					}
					temp[ty][tx] = get<4>(v[i]);
				}
				else {
					get<4>(v[i]) = 0;
				}
			}
			else temp[ty][tx] = get<4>(v[i]);
			
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = temp[i][j];
		
		}
		
	}
}
int main()
{
	scanf("%d %d %d", &r, &c, &m);
	for (int i = 0; i < m; i++) {
		int y, x, s, d, z;
		scanf("%d %d %d %d %d", &y, &x, &s, &d, &z);
		v.push_back(make_tuple(y-1, x-1, s, d, z));
		a[y-1][x-1] = z; //상어의 무게를 저장
	}
	int cnt = 0;
	int k = c;
	while (k--) { //열 개수 만큼 이동
		fishing(cnt); //cnt 열 낚시
		cnt++;
		move(); //상어 이동
	}
	printf("%d\n", ans);
	return 0;
}
