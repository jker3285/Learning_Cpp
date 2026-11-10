// 참고 struct에서도 기존의 class와 같이 접근 지정자와 함수를 작성하는 것이 가능하다.

#include <iostream>

using namespace std;

struct Data{
public:
	Data(char const* const name, float hp, float mp, float strength): Name(name), Hp(hp), Mp(mp), Strength(strength), jonbeo(0), dodge_used(false), dodge_active(false)
	{}
protected:
	// 이름
	char const* const Name;

	// 기본 정보
	float Hp;
	float Mp;
	float Strength;

	// 상태
	int jonbeo;
	
	// 행동 여부
	bool dodge_used;
	bool dodge_active;
};

struct CombatSystem : Data {
public:
	CombatSystem(char const* const name): Data(Name, 100, 100, 10)
	{ }

	// 나머지는 여러분들이 상상하는 전투 구조를 짜면 됩니다~
	// 실습 과제임

private:
	bool Attack(CombatSystem* target, float damage, float cost)
	{
		if (target->Mp >= cost)
		{
			if (target->dodge_active == true)
			{
				target->Mp > damage * 0.5f;

				cout << target->Name << "의 회피!" << endl;
				target->Mp -= damage * 0.5f;

				if (target->Mp < 0)
					target->Mp = 0;
				target->dodge_active = false;
			}

			else
			{
				target->Hp -= damage;
				cout << target->Name << "는 " << damage << "의 피해를 입었다!" << endl;
			}

			Mp -= cost;
			return true;
		}

		else
		{
			cout << "사용 할 수 없습니다." << endl << endl;
			return false;
		}
	}
};

int main()
{
	return 0;
}