#ifndef ROCKTYPE_H
#define ROCKTYPE_H

#include "monsterBase.h"

class RockType : public MonsterBase
{
    GDCLASS(RockType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick();
    void eat(int food);

    static void _bind_methods();
};

#endif