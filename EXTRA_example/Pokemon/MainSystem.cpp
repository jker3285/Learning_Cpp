#include "PokemonData.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

static const char* LearnMethodName(pokemon::LearnMethod method)
{
	switch (method) {
    case pokemon::LearnMethod::LevelUp: return "레벨업";
    case pokemon::LearnMethod::Egg:     return "교배";
    case pokemon::LearnMethod::Tutor:   return "가르침";
    case pokemon::LearnMethod::Machine: return "기술머신 / 비전머신";
    default:                          return "특수 습득";
	}
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    using namespace pokemon;

    bool Game_Switch = false;
    int action = 0;

    while (true) 
    {
        while (Game_Switch == true)
        {
            cout << "0. 탐험" << endl;
            cout << "1. 도감" << endl;
            cout << "2. 가방" << endl;
            cout << "3. 종료" << endl;
            cout << endl << "행동 입력 : ";
            cin >> action;
            cout << endl;
            switch (action)
            {

            }
        }
    }
}
