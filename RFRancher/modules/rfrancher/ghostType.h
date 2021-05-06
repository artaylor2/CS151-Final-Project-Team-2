/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Ghost type monster declaration file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GHOSTTYPE_H
#define GHOSTTYPE_H

#include "monsterBase.h"

/**
 * @brief Ghost type monster class
 * 
 */
class GhostType : public MonsterBase
{
    // Godot class wrapping macro
    GDCLASS(GhostType, MonsterBase);

public:
    void init(int ssidHash); // Initialize the monster
    void doTick(); // Slower happiness ticks
    void eat(int food); // Feed the monster

    static void _bind_methods(); // Godot method bindings
};

#endif