#ifndef FIRETYPE_H
#define FIRETYPE_H

#include "monsterBase.h"

class FireType : public MonsterBase
{
    GDCLASS(FireType, MonsterBase)

public:
    void init(int ssidHash);
    bool eat(int food); // Double hunger regen

protected:
    static void _bind_methods(); // Godot method bindings
};

#endif