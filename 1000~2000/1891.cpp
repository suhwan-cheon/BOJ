#include<iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum {
		CLERK, SENIOR, ASSIST, MANAGER // 사원,주임,대리,과장
	};

	void ShowRank(int t_rank) {
		switch (t_rank) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
			break;
		}
	}
}


class NameCard {

private:
	const char* name;
	const char* company;
	const char* ph_num;
	int rank;
public:
	NameCard(const char* t_name, const char* t_company, const char* t_ph, int t_rank) :rank(t_rank) {
		name = new char[strlen(t_name) + 1];
		company = new char[strlen(t_company) + 1];
		ph_num = new char[strlen(t_ph) + 1];
		strcpy(name, t_name);
		strcpy(company, t_company);
		strcpy(name, t_ph);

	}
	void ShowNameCardInfo() const {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << ph_num << endl;
		cout << "직급: "; COMP_POS::ShowRank(rank); cout << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]company;
		delete[]ph_num;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-2222", COMP_POS::SENIOR);
	NameCard manAssist("e", "SogoodComp", "010-4444-2222", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

}