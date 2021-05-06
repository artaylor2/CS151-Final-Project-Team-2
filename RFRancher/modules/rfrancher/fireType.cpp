/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Fire type monster definition file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "fireType.h"

/**
 * @brief Initilize this fire type monster
 * 
 * @param ssidHash Integer from hash to generate from
 */

void FireType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);

    // Set type and default name
    this->type = Fire;
    this->name = "Igneous";

    ClassDB::bind_method(D_METHOD("eat"), &FireType::eat);

    return;
}

/**
 * @brief Overloaded eat function that games 2x hunger from food
 * 
 * @param food Amount the monster is eating
 * @return true Eat was successful
 * @return false Eat failed (monster dead)
 */

bool FireType::eat(int food)
{
    if(this->isDead) // Check if monster is still alive
    {
        return false;
    }

    // Heal hunger
    this->hunger += (2 * food); // Add food restored to hunger
    if(this->hunger > maxHunger) // If is higher than maximum
    {
        this->hunger = maxHunger; // Set to max
    }

    // Heal hp
    this->hp += (food / 2); // Add half of food restored to hp
    if(this->hp > maxHp) // If is higher than maximum
    {
        this->hp = maxHp; // Set to max
    }

    return true;
}

/**
 * @brief Update all of the monster's vitals
 * 
 */

void FireType::doTick()
{
    MonsterBase::doTick();

    return;
}

/**
 * @brief Set Godot command bindings
 * 
 */

void FireType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &FireType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &FireType::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &FireType::eat);
}