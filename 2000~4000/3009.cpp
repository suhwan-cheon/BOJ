#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double r;
	cin >> r;

	// 소수점 여섯째자리까지 출력 
	cout << fixed;
	cout.precision(6);
	// 유클리드  
	cout << r * r * M_PI << '\n';
	// 택시
	cout << r * r * 2 << '\n';

	return 0;
}
