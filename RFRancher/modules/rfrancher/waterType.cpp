/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Water type monster definition file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "waterType.h"

/**
 * @brief Initialize this water type monster
 * 
 * @param ssidHash Integer from hash to generate from
 */

void WaterType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    
    // Set type and default name
    this->type = Water;
    this->name = "Old Man Carp";

    return;
}

/**
 * @brief Update all of the monster's vitals
 * 
 */

void WaterType::doTick()
{
    MonsterBase::doTick();
}

/**
 * @brief Call MonsterBase's eat method
 * 
 * @param food Amount of food to eat
 */

void WaterType::eat(int food)
{
    MonsterBase::eat(food);
}

/**
 * @brief Set Godot command bindings
 * 
 */

void WaterType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &WaterType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &WaterType::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &WaterType::eat);
}
