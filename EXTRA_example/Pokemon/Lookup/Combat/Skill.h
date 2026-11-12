#pragma once
#include "Enums.h"

// 기술 한 개의 전투 상태: 위력, 명중률, 남은 PP
class Skill {

public:

    Skill() = default;

    Skill(char const* const name, EType type, ESkillCategory category,

        int power, int accuracy, int maxPP)

        : Name(name), Type(type), Category(category),

        Power(power), Accuracy(accuracy), MaxPP(maxPP), CurrentPP(maxPP) {

    }



private:

    const char* Name = "";

    EType Type = EType::Normal;

    ESkillCategory Category = ESkillCategory::Physical;

    int Power = 0;

    int Accuracy = 100;

    int MaxPP = 0;

    int CurrentPP = 0;

};
