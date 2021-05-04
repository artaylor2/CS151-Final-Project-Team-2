#include "rockType.h"

void RockType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    
    // Set type and default name
    this->type = Rock;
    this->name = "Sledge";

    return;
}

void RockType::doTick()
{
    MonsterBase::doTick();
}

void RockType::eat(int food)
{
    MonsterBase::eat(food);
}

void RockType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &RockType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &MonsterBase::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &MonsterBase::eat);
}