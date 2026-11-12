#pragma once
#include <array>
#include "Skill.h"
// 포켓몬 한 마리의 전투 상태와 동작 선언
class PokemonData
{
public:
    static constexpr int MaxSkillCount = 4;

    PokemonData() = default;
    PokemonData(char const* const name, EType type, int level,
        int hp, int attack, int spAttack, int defence, int spDefence, int speed);

    const char* GetName() const { return PokemonName; }
    EType GetType() const { return Type; }
    int GetLevel() const { return Level; }
    int GetMaxHp() const { return MaxHp; }
    int GetCurrentHp() const { return CurrentHp; }
    int GetAttack() const { return Attack; }
    int GetSPAttack() const { return SPAttack; }
    int GetDefence() const { return Defence; }
    int GetSPDefence() const { return SPDefence; }
    int GetSpeed() const { return Speed; }
    bool IsFainted() const { return CurrentHp <= 0; }

    // ----- 기술 ------
    // 빈 슬롯에 기술 추가, 슬롯이 가득 차면 false
    bool LearnSkill(const Skill& skill);
    Skill* GetSkill(int index);



    // ----- 전투 -----
    // 데미지 계산 (실제로 깍지는 않음)
    int CalculateDamage(const Skill& skill, const PokemonData& target) const;

    // 피해를 받음
    void TakeDamage(int damage);

    // skillIndex 기술로 target을 공격, 성공 여부를 반환한다.
    bool UseSkill(int skillIndex, PokemonData& target);

    // ----- 경험치 -----
    void GainExp(int amount);

private:
    void LevelUp();
    int RequiredExp() const { return Level * Level * Level; }
private:
    // 이름
    const char* PokemonName = "";
    EType Type = EType::Normal;

    // 기본 스테이터스
    int MaxHp = 1;
    int CurrentHp = 1;
    int Attack = 1;
    int SPAttack = 1;
    int Defence = 1;
    int SPDefence = 1;
    int Speed = 1;

    // 상태
    int Level = 1;
    int CurrentExp = 0;

    // 기술 (최대 4개)
    std::array<Skill, MaxSkillCount> Skills{};
    int SkillCount = 0;
};
