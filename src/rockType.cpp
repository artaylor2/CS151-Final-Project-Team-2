#include "rockType.h"

RockType::RockType(int ssidHash) : MonsterBase(ssidHash)
{
    // Set type
    this->type = Rock;

    // Set name
    setName();

    // Passive ability: 20% more hp
    this->maxHp = maxHp * 1.2;
    this->hp = maxHp;
}