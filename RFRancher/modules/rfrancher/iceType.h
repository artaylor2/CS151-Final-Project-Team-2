#ifndef ICETYPE_H
#define ICETYPE_H

#include "monsterBase.h"

class IceType : public MonsterBase
{
    GDCLASS(IceType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick(); // Hunger rate based on happiness
    void eat(int food);

    static void _bind_methods();
};

#endif