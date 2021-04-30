/**
 * @file iceType.h
 * @author Jacob Porath
 * @brief Header file for IceType class
 * @date 2021-04-29
 */
#ifndef ICETYPE_H
#define ICETYPE_H

#include "monsterBase.h"

class IceType : public MonsterBase
{
public:
    IceType(int ssidHash);
    void doTick(); // Hunger rate based on happiness
};

#endif