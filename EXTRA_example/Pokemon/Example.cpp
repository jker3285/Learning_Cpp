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
    {
#ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
#endif
        using namespace pokemon;
        std::cout << "포켓몬 도감" << std::endl << "=======================================" << std::endl;
        std::cout << "확인하실 포켓몬의 번호를 입력하시오. >> ";
        int index;
        std::cin >> index;
        const auto* pokemon = FindPokemon(index);
        std::cout << "포켓몬: " << pokemon->name
            << " | 타입: " << GetTypeName(pokemon->primaryType)
            << " | HP 종족값: " << pokemon->baseStats.hp << "\n\n"
            << "[에메랄드에서 배우는 기술]\n";
        for (const auto& entry : GetLearnset(index, VersionGroup::Emerald)) {
            const auto* move = FindMove(entry.moveId);
            std::cout << move->name << " | 습득 방식: " << LearnMethodName(entry.method);
            if (entry.method == LearnMethod::LevelUp)
                std::cout << " | 습득 레벨: " << entry.level;
            std::cout << '\n';
        }
    }

    {

    }
}
