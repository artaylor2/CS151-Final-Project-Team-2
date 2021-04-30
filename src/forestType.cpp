/**
 * @file forestType.cpp
 * @author Jacob Porath
 * @brief Definition file for ForestType class
 * @date 2021-04-29
 */
#include "forestType.h"

/**
 * @brief Construct a new Forest Type:: Forest Type object
 * 
 * @param ssidHash hashed ssid value for determining stats
 */
ForestType::ForestType(int ssidHash) : MonsterBase(ssidHash)
{
    // Set type
    this->type = Forest;

    // Set name
    setName();
}

/**
 * @brief override MonsterBase function to adjust hunger rates of this monster
 * 
 */
void ForestType::doTick()
{
    if(this->isDead) // Check if monster is still alive
    {
        std::cout << this->name << " is dead\n";
        return;
    }

    // Calculate points to remove
    int curTime = time(nullptr);
    double hungerRemove = curTime - this->lastHungerTick;
    double HappyRemove = curTime - this->LastHappyTick;
    hungerRemove /= 7200.0; // Remove .5 per hour
    HappyRemove /= 3600.0; // Remove 1 per hour

    // Remove points from hunger
    this->hunger -= hungerRemove;
    if(hunger < 0) // If hunger is negative
    {
        this->hp += this->hunger; // remove negative points from health
        this->hunger = 0; // Set hunger to zero
    }
    this->lastHungerTick = time(nullptr); // Update hunger tick time

    // Remove points from happiness
    this->happiness -= HappyRemove;
    if(happiness < 0) // If happiness is negative
    {
        this->hp += this->happiness; // remove negative points from health
        this->happiness = 0; // Set happiness to zero
    }
    this->LastHappyTick = time(nullptr); // Update happy tick time
    if(this->hp <= 0)
    {
        this->isDead = true;
    }
}