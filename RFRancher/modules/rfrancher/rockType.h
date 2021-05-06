/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Rock type monster declaration file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ROCKTYPE_H
#define ROCKTYPE_H

#include "monsterBase.h"

/**
 * @brief Rock type monster class
 * 
 */
class RockType : public MonsterBase
{
    // Godot class wrapping macro
    GDCLASS(RockType, MonsterBase);

public:
    void init(int ssidHash); // Initialize the monster
    void doTick(); // Update the monster's vitals
    void eat(int food); // Feed the monster

    static void _bind_methods(); // Godot method bindings
};

#endif