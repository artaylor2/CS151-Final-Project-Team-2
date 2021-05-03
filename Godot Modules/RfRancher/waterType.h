#ifndef WATERTYPE_H
#define WATERTYPE_H

#include "monsterBase.h"

class WaterType : public MonsterBase
{
    GDCLASS(WaterType, MonsterBase);

public:
    void init(int ssidHash);
    void doTick();
    void eat(int food);

    static void _bind_methods();
};

#endif