/**
 * @file waterType.cpp
 * @author Jacob Porath
 * @brief Definition file for WaterType class
 * @date 2021-04-29
 */
#include "waterType.h"

/**
 * @brief Construct a new Water Type:: Water Type object
 * 
 * @param ssidHash hashed ssid value for determining stats
 */
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