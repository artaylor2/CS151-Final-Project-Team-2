/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Rock type monster definition file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "rockType.h"

/**
 * @brief Initialize this rock type monster
 * 
 * @param ssidHash Integer from hash to generate from
 */

void RockType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    
    // Set type and default name
    this->type = Rock;
    this->name = "Sledge";

    return;
}

/**
 * @brief Update all of the monster's vitals
 * 
 */

void RockType::doTick()
{
    MonsterBase::doTick();
}

/**
 * @brief Call MonsterBase's eat method
 * 
 * @param food 
 */

void RockType::eat(int food)
{
    MonsterBase::eat(food);
}

/**
 * @brief Set Godot command bindings
 * 
 */
void RockType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &RockType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &MonsterBase::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &MonsterBase::eat);
}