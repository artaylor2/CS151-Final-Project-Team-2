#ifndef FORESTTYPE_H
#define FORESTTYPE_H

#include "monsterBase.h"

class ForestType : public MonsterBase
{
    GDCLASS(ForestType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick(); // Slower hunger ticks
    void eat(int food);

    static void _bind_methods();
};

#endif