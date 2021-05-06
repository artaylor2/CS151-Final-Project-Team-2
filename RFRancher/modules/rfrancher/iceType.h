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

class IceType : public MonsterBase
{
    GDCLASS(IceType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick(); // Hunger rate based on happiness
    void eat(int food);

    static void _bind_methods();
};

#endif