// 포켓몬 데이터 조회 예제: 이 프로젝트의 실행 진입점입니다.
#include "PokemonData.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

static const char* LearnMethodName(pokemon::LearnMethod method) {
    switch (method) {
    case pokemon::LearnMethod::LevelUp: return "레벨업";
    case pokemon::LearnMethod::Egg:     return "교배";
    case pokemon::LearnMethod::Tutor:   return "가르침";
    case pokemon::LearnMethod::Machine: return "기술머신 / 비전머신";
    default:                          return "특수 습득";
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    using namespace pokemon;
    const auto* pikachu = FindPokemon(25);
    std::cout << "포켓몬: " << pikachu->name
              << " | 타입: " << GetTypeName(pikachu->primaryType)
              << " | HP 종족값: " << pikachu->baseStats.hp << "\n\n"
              << "[에메랄드에서 배우는 기술]\n";
    for (const auto& entry : GetLearnset(25, VersionGroup::Emerald)) {
        const auto* move = FindMove(entry.moveId);
        std::cout << move->name << " | 습득 방식: " << LearnMethodName(entry.method);
        if (entry.method == LearnMethod::LevelUp)
            std::cout << " | 습득 레벨: " << entry.level;
        std::cout << '\n';
    }
}
