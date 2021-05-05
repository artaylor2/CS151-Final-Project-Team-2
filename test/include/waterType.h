/**
 * @file waterType.h
 * @author Jacob Porath
 * @brief Header file for WaterType class
 * @date 2021-04-29
 */
#ifndef WATERTYPE_H
#define WATERTYPE_H

#include "monsterBase.h"

class WaterType : public MonsterBase
{
public:
    WaterType(int ssidHash);
};

#endif