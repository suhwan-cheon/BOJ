#include <iostream>
using namespace std;
long long c;

long long calc(long long a, long long b) {
	if (b == 0) return 1;
	else if (b == 1) return a;
	else if (b % 2 == 0) { //제곱수가 짝수일 때
		long long temp = calc(a, b / 2) % c;
		return (temp * temp) % c;
	}
	else { //홀수일 때
		return (a * calc(a, b - 1) % c);
	}
}
int main()
{
	long long a, b; scanf("%lld %lld %lld", &a, &b, &c);
	long long ans = calc(a, b) % c;
	printf("%lld\n", ans);
	return 0;
}

