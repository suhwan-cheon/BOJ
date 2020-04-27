#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool c[10];

int main()
{
	int zero_y = 0; int zero_x = 0;
	vector<vector<int> >puzzle(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &puzzle[i][j]);
			if (puzzle[i][j] == 0) {
				zero_y = i; zero_x = j;
			}
		}
	}
	queue<pair<vector<int>, int> >q;
	
}

