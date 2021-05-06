/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Ghost type monster definition file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "ghostType.h"

/**
 * @brief Initialize this ghost type monster
 * 
 * @param ssidHash Integer from hash to generate from
 */

void GhostType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    
    // Set type and default name
    this->type = Ghost;
    this->name = "Grimoire";

    return;
}

/**
 * @brief Update all of the monster's vitals
 * 
 */

void GhostType::doTick() // Remove 1 point of hunger and .5 happiness per hour
{
    print_line(vformat("Grimoire Tick"));
    if(this->isDead) // Check if monster is still alive
    {
        return;
    }

    // Calculate points to remove
    int curTime = time(nullptr);
    double hungerRemove = curTime - this->lastHungerTick;
    double HappyRemove = curTime - this->LastHappyTick;
    hungerRemove /= 3600.0; // Remove 1 per hour
    HappyRemove /= 7200.0; // Remove .5 per hour

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

/**
 * @brief Call MonsterBase's eat method
 * 
 * @param food Amount the monster is eating
 */

void GhostType::eat(int food)
{
    MonsterBase::eat(food);

    return;
}


/**
 * @brief Set Godot command bindings
 * 
 */

void GhostType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &GhostType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &GhostType::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &GhostType::eat);
}