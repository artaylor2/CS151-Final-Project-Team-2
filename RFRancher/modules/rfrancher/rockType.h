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

class RockType : public MonsterBase
{
    GDCLASS(RockType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick();
    void eat(int food);

    static void _bind_methods();
};

#endif