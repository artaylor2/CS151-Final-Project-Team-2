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