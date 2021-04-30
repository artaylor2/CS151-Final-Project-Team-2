/**
 * @file fireType.h
 * @author Jacob Porath
 * @brief Header file for FireType class
 * @date 2021-04-29
 */
#ifndef FIRETYPE_H
#define FIRETYPE_H

#include "monsterBase.h"

class FireType : public MonsterBase
{
public:
    FireType(int ssidHash);
    void eat(Food &f); // Double hunger regen
};

#endif