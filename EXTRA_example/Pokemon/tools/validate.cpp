#include "../PokemonData.h"
#include <cassert>
#include <iostream>
#include <cstring>

int main() {
    using namespace pokemon;
    assert(View(kGeneration1Pokemon).size == 151);
    assert(View(kGeneration2Pokemon).size == 100);
    assert(View(kGeneration3Pokemon).size == 135);
    assert(View(kGeneration1Moves).size + View(kGeneration2Moves).size + View(kGeneration3Moves).size == 354);
    assert(View(kAbilities).size == 76);
    assert(std::strcmp(FindPokemon(1)->name, "이상해씨") == 0);
    assert(std::strcmp(FindPokemon(25)->name, "피카츄") == 0);
    assert(std::strcmp(FindMove(85)->name, "10만볼트") == 0);
    for (int id = 1; id <= 386; ++id) {
        const auto* p = FindPokemon(id);
        assert(p && p->dexNumber == id && p->baseStats.hp > 0);
        assert(p->name[0] && FindAbility(p->firstAbilityId));
        assert(!p->secondAbilityId || FindAbility(p->secondAbilityId));
    }
    assert(!FindPokemon(0) && !FindPokemon(387));
    assert(!FindMove(0) && !FindMove(355));
    assert(!FindAbility(0));
    for (int id = 1; id <= 354; ++id) assert(FindMove(id));
    // Regression checks for later-generation changes and the pre-gen4 damage split.
    assert(FindPokemon(25)->baseStats.defense == 30);
    assert(FindPokemon(25)->baseStats.specialDefense == 40);
    assert(FindPokemon(35)->primaryType == Type::Normal);
    assert(FindPokemon(94)->firstAbilityId == 26); // Levitate
    assert(FindPokemon(279)->baseStats.specialAttack == 85);
    assert(FindPokemon(279)->secondAbilityId == 0); // no Drizzle in gen3
    assert(FindMove(33)->power == 35 && FindMove(33)->accuracy == 95);
    assert(FindMove(53)->power == 95); // Flamethrower
    assert(FindMove(247)->damageClass == DamageClass::Physical); // Shadow Ball
    assert(FindMove(242)->damageClass == DamageClass::Special); // Crunch
    assert(FindMove(174)->type == Type::Unknown); // Curse: ???
    const VersionGroup versions[] = {VersionGroup::RedBlue, VersionGroup::Yellow,
        VersionGroup::GoldSilver, VersionGroup::Crystal, VersionGroup::RubySapphire,
        VersionGroup::Emerald, VersionGroup::FireRedLeafGreen, VersionGroup::Colosseum,
        VersionGroup::Xd};
    unsigned total = 0;
    for (auto version : versions) {
        for (int generation = 1; generation <= 3; ++generation) {
            int previous = 0;
            for (const auto& e : GetGenerationLearnset(generation, version)) {
                assert(e.dexNumber >= previous);
                assert(FindPokemon(e.dexNumber) && FindMove(e.moveId));
                assert(FindPokemon(e.dexNumber)->generation == generation);
                assert(FindMove(e.moveId)->generation <= (static_cast<int>(version)<=2 ? 1 : (static_cast<int>(version)<=4 ? 2 : 3)));
                assert(e.level >= 0 && e.level <= 100);
                assert(e.version == version);
                previous = e.dexNumber;
                ++total;
            }
        }
        assert(GetLearnset(0, version).size == 0);
        assert(GetLearnset(387, version).size == 0);
    }
    assert(total == 104243);
    assert(CanLearn(25, 85, VersionGroup::Emerald)); // Thunderbolt
    assert(GetLearnset(252, VersionGroup::RedBlue).size == 0);
    assert(GetLearnset(25, static_cast<VersionGroup>(999)).size == 0);
    std::cout << "Validated 386 species, 354 moves, 76 abilities, " << total << " learnset entries.\n";
}
