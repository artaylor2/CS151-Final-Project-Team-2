/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Fire type monster declaration file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FIRETYPE_H
#define FIRETYPE_H

#include "monsterBase.h"

/**
 * @brief FireType monster class
 * 
 */
class FireType : public MonsterBase
{
    // Godot class wrapping macro
    GDCLASS(FireType, MonsterBase);

public:
    void init(int ssidHash); // Initialize the monster
    bool eat(int food); // Double hunger regen
    void doTick(); // Update the monster's vitals

    static void _bind_methods(); // Godot method bindings
};

#endif