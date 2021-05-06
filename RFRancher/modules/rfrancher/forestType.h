/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Forest type monster declaration file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FORESTTYPE_H
#define FORESTTYPE_H

#include "monsterBase.h"

/**
 * @brief Forest type monster class
 * 
 */ForestType : public MonsterBase
{
    // Godot class wrapping macro
    GDCLASS(ForestType, MonsterBase);

public:
    void init(int ssidHash); // Initialize the monster
    void doTick(); // Slower hunger ticks
    void eat(int food); // Feed the monster

    static void _bind_methods(); // Godot method bindings
};

#endif