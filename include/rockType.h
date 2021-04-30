/**
 * @file rockType.h
 * @author Jacob Porath
 * @brief Header file for RockType class
 * @date 2021-04-29
 */
#ifndef ROCKTYPE_H
#define ROCKTYPE_H

#include "monsterBase.h"

class RockType : public MonsterBase
{
public:
    RockType(int ssidHash);
};
#endif