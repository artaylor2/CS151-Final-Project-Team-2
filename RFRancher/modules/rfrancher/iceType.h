/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Ice type monster declaration file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ICETYPE_H
#define ICETYPE_H

#include "monsterBase.h"

/**
 * @brief Ice type monster class
 * 
 */
class IceType : public MonsterBase
{
    // Godot class wrapping macro
    GDCLASS(IceType, MonsterBase);

public:
    void init(int ssidHash); // Initialize the monster
    void doTick(); // Hunger rate based on happiness
    void eat(int food); Feed the monster

    static void _bind_methods(); // Godot method bindings
};

#endif