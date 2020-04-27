#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string color[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
	int cnt = 0;
	long long num = 0; long long multiple = 1;
	char name_color[10];
	scanf("%s", name_color);
	for (int i = 0; i < 10; i++) {
		if (name_color == color[i]) break;
		else cnt++;
	}
	num += (10 * cnt);
	cnt = 0;
	scanf("%s", name_color);
	for (int i = 0; i < 10; i++) {
		if (name_color == color[i]) break;
		else cnt++;
	}
	num += cnt;
	cnt = 0;
	scanf("%s", name_color);
	for (int i = 0; i < 10; i++) {
		if (name_color == color[i]) break;
		else cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		multiple *= 10;
	}
	num *= multiple;
	cout << num;
	return 0;
}
