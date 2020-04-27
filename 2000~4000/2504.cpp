#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pow_2(int x) { //2의 제곱 수
	if (x == 0) return 0;
	int temp = 1;
	for (int i = 0; i < x; i++) {
		temp *= 2;
	}
	return temp;
}

int pow_3(int x) { //3의 제곱 수
	if (x == 0) return 0;
	int temp = 1;
	for (int i = 0; i < x; i++) {
		temp *= 3;
	}
	return temp;
}
int main()
{
	string s; cin >> s;

	stack<char> st; //괄호 stack
	stack<int> value; //괄호값 stack

	int ans = 0; //완성된 괄호값
	int part_ans = 0; //아직 미완성 괄호값
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			st.push(s[i]);
			value.push(0); //여는 괄호는 0을 push
		}
		//닫힌 괄호일 때 조건이 많음
		else {
			if (st.empty()) { //올바르지 못한 괄호열 처리
				printf("0");
				return 0;
			}
			else if (s[i] == ')') {
				if (st.top() != '(') { //올바르지 못한 괄호열
					printf("0");
					return 0;
				}
				else {
					part_ans = value.top();
					value.pop();
					if (part_ans == 0) part_ans = 1;
					part_ans *= 2;
					if (value.empty()) ans += part_ans;
					else {
						part_ans += value.top();
						value.pop();
						value.push(part_ans);
					}
				}
				st.pop();
			}
			else if (s[i] == ']') {
				if (st.top() != '[') { //올바르지 못한 괄호열
					printf("0");
					return 0;
				}
				else {
					part_ans = value.top();
					value.pop();
					if (part_ans == 0) part_ans = 1;
					part_ans *= 3;
					if (value.empty()) ans += part_ans;
					else {
						part_ans += value.top();
						value.pop();
						value.push(part_ans);
					}
				}
				st.pop();
			}
		}
	}
	if (!st.empty()) ans = 0;
	printf("%d", ans);
	return 0;
}
