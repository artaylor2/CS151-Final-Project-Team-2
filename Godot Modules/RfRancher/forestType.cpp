#include "forestType.h"

void ForestType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);

    // Set type
    this->type = Forest;
    this->name = "Barkat";

    ClassDB::bind_method(D_METHOD("doTick"), &ForestType::doTick);

    return;
}

void ForestType::doTick() // Remove .5 point of hunger and 1 happiness per hour
{
    print_line(vformat("Barkat Tick"));
    if(this->isDead) // Check if monster is still alive
    {
        return;
    }

    // Calculate points to remove
    int curTime = time(nullptr);
    double hungerRemove = curTime - this->lastHungerTick;
    double HappyRemove = curTime - this->LastHappyTick;
    hungerRemove /= 7200.0; // Remove .5 per hour
    HappyRemove /= 3600.0; // Remove 1 per hour

    // Remove points from hunger
    this->hunger -= hungerRemove;
    if(hunger < 0) // If hunger is negative
    {
        this->hp += this->hunger; // remove negative points from health
        this->hunger = 0; // Set hunger to zero
    }
    this->lastHungerTick = time(nullptr); // Update hunger tick time

    // Remove points from happiness
    this->happiness -= HappyRemove;
    if(happiness < 0) // If happiness is negative
    {
        this->hp += this->happiness; // remove negative points from health
        this->happiness = 0; // Set happiness to zero
    }
    this->LastHappyTick = time(nullptr); // Update happy tick time
    if(this->hp <= 0)
    {
        this->isDead = true;
    }
}

void ForestType::eat(int food)
{
    MonsterBase::eat(food);

    return;
}

void ForestType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &ForestType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &ForestType::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &ForestType::eat);
}