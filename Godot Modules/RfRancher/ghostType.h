#ifndef GHOSTTYPE_H
#define GHOSTTYPE_H

#include "monsterBase.h"

class GhostType : public MonsterBase
{
    GDCLASS(GhostType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick(); // Slower happiness ticks
    void eat(int food);

    static void _bind_methods();
};

#endif