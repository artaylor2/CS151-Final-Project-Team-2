#include "waterType.h"

WaterType::WaterType(int ssidHash) : MonsterBase(ssidHash)
{
    // Set type
    this->type = Water;

    // Set name
    setName();

    // Passive ability: 20% more max Happiness
    this->maxHappiness = maxHappiness * 1.2;
    this->happiness = maxHappiness;
}