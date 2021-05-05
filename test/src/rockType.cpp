/**
 * @file rockType.cpp
 * @author Jacob Porath
 * @brief Definition file for RockType class
 * @date 2021-04-29
 */
#include "rockType.h"

/**
 * @brief Construct a new Rock Type:: Rock Type object
 * 
 * @param ssidHash hashed ssid value for determining stats
 */
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