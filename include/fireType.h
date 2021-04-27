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