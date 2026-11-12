#pragma once
#include <memory>
#include <random>
#include "Pokemon.h"

// 현재는 인터페이스 선언입니다. 각 함수 본문은 별도로 구현해야 합니다.
// ------------------------------------------------------------
// 행동 / 상태 정의
// ------------------------------------------------------------

enum class EActionType
{
    UseSkill,
    Switch,
    Run,
};

struct BattleAction {
    EActionType Type = EActionType::UseSkill;
    int skillIndex = 0; // 0 ~ 3
};

enum class EBattleState {
    Ready,
    SelectAction,
    ExecuteTurn,
    ExcuteTurn = ExecuteTurn, // 이전 철자와 호환
    CheckResult,
    Finished,
};

// ------------------------------------------------------------
// 조종자 (플레이어 / AI 공통 인터페이스)
// ------------------------------------------------------------

class IBattleController
{
public:
    virtual ~IBattleController() = default;

    // self: 내 포켓몬, opponent: 상대 포켓몬
    virtual BattleAction DecideAction(PokemonData& self, const PokemonData& opponent) = 0;
};

class PlayerController : public IBattleController {
public:
    BattleAction DecideAction(PokemonData& self, const PokemonData& opponent) override;

private:
    void PrintSkillList(PokemonData& self) const;
};

// 랜덤 AI: PP가 남은 기술 중 하나를 무작위로 선택
class RandomAIController : public IBattleController {
public:
    RandomAIController();
    BattleAction DecideAction(PokemonData& self, const PokemonData& opponent) override;

private:
    std::mt19937 Rng;
};


// ------------------------------------------------------------
// 전투 시스템
// ------------------------------------------------------------
class BattleSystem
{
public:
    // 포켓몬은 외부에서 소유하며 전투가 끝날 때까지 유효해야 합니다.
    // 생성자 구현에서 nullptr와 동일 포켓몬 포인터를 거부해야 합니다.
    BattleSystem(PokemonData* playerPokemon, PokemonData* enemyPokemon);

    // 전투 시작 ~ 종료까지 한 번에 진행
    void Run();

    // 한 턴만 진행 (이미 종료되었다면 아무 동작도 하지 않도록 구현)
    void ProcessTurn();

    bool IsFinished() const { return State == EBattleState::Finished; }
    // 승자 반환 (전투 중, 도주 또는 무승부이면 nullptr)
    const PokemonData* GetWinner() const;

private:
    // 턴 진행 단계
    void SelectActions();
    void ExecuteActions();
    void CheckResult();

    // 속도 비교로 선공 결정, 같으면 랜덤
    bool PlayerGoesFirst(); // 난수 생성기의 상태가 바뀌므로 const가 아님

    // 한 쪽의 행동 실행
    void ExecuteAction(PokemonData& attacker, PokemonData& defender, const BattleAction& action);

    // 출력
    void PrintBattleStatus() const;
    void PrintHpBar(const PokemonData& pokemon) const;
    void PrintResult() const;

private:
    PokemonData* Player = nullptr;
    PokemonData* Enemy = nullptr;

    std::unique_ptr<IBattleController> PlayerController_;
    std::unique_ptr<IBattleController> EnemyController_;

    BattleAction PlayerAction;
    BattleAction EnemyAction;

    EBattleState State = EBattleState::Ready;
    int TurnCount = 0;

    std::mt19937 Rng;
};