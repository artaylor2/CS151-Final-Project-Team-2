/**
 * @file ghostType.h
 * @author Jacob Porath
 * @brief Header file for GhostType class
 * @date 2021-04-29
 */
#ifndef GHOSTTYPE_H
#define GHOSTTYPE_H

#include "monsterBase.h"

class GhostType : public MonsterBase
{
public:
    GhostType(int ssidHash);
    void doTick(); // Slower happiness ticks
};

#endif