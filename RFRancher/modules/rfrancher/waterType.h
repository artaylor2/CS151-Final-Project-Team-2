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

class WaterType : public MonsterBase
{
    GDCLASS(WaterType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick();
    void eat(int food);

    static void _bind_methods();
};

#endif