/**
 * @file forestType.h
 * @author Jacob Porath
 * @brief Header file for ForestType class
 * @date 2021-04-29
 */
#ifndef FORESTTYPE_H
#define FORESTTYPE_H

#include "monsterBase.h"

class ForestType : public MonsterBase
{
public:
    ForestType(int ssidHash);
    void doTick(); // Slower hunger ticks
};

#endif