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