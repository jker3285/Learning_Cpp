// 참고 struct에서도 기존의 class와 같이 접근 지정자와 함수를 작성하는 것이 가능하다.

#include <iostream>

using namespace std;

struct Data {
public:
	Data(char const* const name, float hp, float mp, float strength) : Name(name), Hp(hp), Mp(mp), Strength(strength), jonbeo(0), dodge_used(false), dodge_active(false)
	{
	}
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
	CombatSystem(char const* const name) : Data(Name, 100, 100, 10)
	{
	}

	void Report() {
		cout << "이름: " << Name << endl;
		cout << "체력: " << Hp << endl;
		cout << "마나: " << Mp << endl;
		cout <<  endl;
	}

	bool Scratch(CombatSystem *target)
	{
		return Attack(target, Strength, 10);
	}

	bool Bite(CombatSystem* target)
	{
		return Attack(target, Strength * 2.0f, 20);
	}

	bool Charge()
	{
		jonbeo++;
		return true;
	}

	bool Burst(CombatSystem* target)
	{
		float damage = Strength;
		damage *= 1.5f;

		if (Attack(target, damage, damage) == true)
		{
			jonbeo = 0;
			return true;
		}

		else
		{
			return false;
		}
	}

	bool Dodge()
	{
		if (dodge_used == false)
		{
			dodge_used = dodge_active = true;

			return true;
		}

		else
		{
			cout << "사용할 수 없습니다." << endl;
			cout << endl;

			return true;
		}
	}

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