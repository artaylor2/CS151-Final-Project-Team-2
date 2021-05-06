/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Water type monster declaration file
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef WATERTYPE_H
#define WATERTYPE_H

#include "monsterBase.h"

/**
 * @brief Water type monster class
 * 
 */
class WaterType : public MonsterBase
{
    // Godot class wrapping macro
    GDCLASS(WaterType, MonsterBase);

public:
    void init(int ssidHash); // Initialize the monster
    void doTick(); // Update the monster's vitals
    void eat(int food); // Feed the monster

    static void _bind_methods(); // Godot method bindings
};

#endif