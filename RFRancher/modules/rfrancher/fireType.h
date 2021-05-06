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

class FireType : public MonsterBase
{
    GDCLASS(FireType, MonsterBase);

public:
    void init(int ssidHash);
    bool eat(int food); // Double hunger regen

    void doTick();

    static void _bind_methods();
};

#endif