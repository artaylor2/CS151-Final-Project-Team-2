#include "waterType.h"

void WaterType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    
    // Set type and default name
    this->type = Water;
    this->name = "Old Man Carp";

    return;
}

void WaterType::doTick()
{
    MonsterBase::doTick();
}

void WaterType::eat(int food)
{
    MonsterBase::eat(food);
}

void WaterType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &WaterType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &WaterType::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &WaterType::eat);
}
