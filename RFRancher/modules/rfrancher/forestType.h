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

class ForestType : public MonsterBase
{
    GDCLASS(ForestType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick(); // Slower hunger ticks
    void eat(int food);

    static void _bind_methods();
};

#endif