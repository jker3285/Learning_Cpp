// 클래스를 이용한 간단한 턴제 전투 게임을 구현
// 여러분들도 한 번 시도 해 볼 것!

#include <iostream>

using namespace std;

class CombatSystem {
public:
	CombatSystem(char const* const name) : name(name), Hp(100), stamina(100), strength(10), jonbeo(0), dodge_used(false), dodge_activated(false){}

	void Report()
	{
		cout << "이름 : " << name << endl;
		cout << "체력 : " << Hp << endl;
		cout << "기력: " << stamina << endl;
		cout << endl;
	}

	bool Cry()
	{
		cout << name << endl;

		return true;
	}

	bool Rest()
	{
		stamina += Hp * 0.25f;

		if (stamina > 100)
			stamina = 100;

		return true;
	}

	bool Scratch(CombatSystem& target)
	{
		return Attack(target, strength, 10.f);
	}

	bool Bite(CombatSystem& target)
	{
		return Attack(target, strength * 1.5f, 20.f);
	}

	bool Charge()
	{
		jonbeo++;
		return true;
	}

	bool Bust(CombatSystem& target)
	{
		float damage = strength;
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
			dodge_used = dodge_activated = true;

			return true;
		}

		else
		{
			cout << "사용할 수 없습니다." << endl << endl;

			return true;
		}
	}
private:
	bool Attack(CombatSystem& target, float damage, float cost)
	{
		if (stamina >= cost) 
		{
			if (target.dodge_activated == true)
			{
				target.stamina > damage * 0.5;

				cout << target.name << "의 회피!" << endl;

				target.stamina -= damage * 0.5;

				if (target.stamina < 0)
					target.stamina = 0;
				target.dodge_activated = false;
			}

			else
			{
				target.Hp -= damage;
				cout << target.name << "는 " << damage << "의 피해를 입었다!" << endl;
			}

			stamina -= cost;
			return true;
		}

		else
		{
			cout << "사용 할 수 없습니다." << endl << endl;
			return false;
		}
	}

	char const* const name;
	float Hp;
	float stamina;
	float  strength;

	unsigned jonbeo;

	bool dodge_used;
	bool dodge_activated;
};

int main()
{
	CombatSystem Gengar("팬텀");
	CombatSystem Nidorino("니드리노");

	CombatSystem* turn = &Gengar;
	CombatSystem* non = &Nidorino;
	int action = 0;

	while(true)
	{
		bool result = false;
		while (result == true)
		{
			turn->Report();
			non->Report();

			cout << "0. 짖기" << endl;
			cout << "1. 쉬기" << endl;
			cout << "2. 할퀴기" << endl;
			cout << "3. 물기" << endl;
			cout << "4. 견디기" << endl;
			cout << "5. 처형" << endl;
			cout << endl;
			cout << "행동을 선택해 주세요 : ";
			cin >> action;
			cout << endl;
			switch (action)
			{
			case 0: result = turn->Cry(); break;
			case 1: result = turn->Rest(); break;
			case 2: result = turn->Scratch(*non); break;
			case 3: result = turn->Bite(*non); break;
			case 4: result = turn->Charge(); break;
			case 5: result = turn->Dodge(); break;
			case 6: result = turn->Bust(*non); break;
			}

			if (result == true)
			{
				CombatSystem* temp = turn;
				turn = non;
				non = temp;
			}
		}
	}

	return 0;
}