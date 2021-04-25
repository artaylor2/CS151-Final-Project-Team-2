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