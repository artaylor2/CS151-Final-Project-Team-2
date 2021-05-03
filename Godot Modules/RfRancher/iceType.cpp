#include "iceType.h"

void IceType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    
    // Set type and default name
    this->type = Ice;
    this->name = "Snowcrash";

    return;
}

void IceType::doTick() // Remove hunger based on happiness level
{
    print_line(vformat("Snowcrash Tick"));

    if(this->isDead) // Check if monster is still alive
    {
        return;
    }

    double hungerRate = happiness / maxHappiness; // Rate of hunger based on happiness

    if(hungerRate < 0.1)
    {
        hungerRate = 0.1; // Limit rate of change minimum to prevent division by 0 and make hunger still matter.
    }

    hungerRate = 1 / hungerRate; // Get reciprocal to adjust rate of hunger in the correct direction

    // Calculate points to remove
    int curTime = time(nullptr);
    double hungerRemove = curTime - this->lastHungerTick;
    double HappyRemove = curTime - this->LastHappyTick;
    hungerRemove /= (3600.0 * hungerRate);
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

void IceType::eat(int food)
{
    MonsterBase::eat(food);
}

void IceType::_bind_methods() // Godot method bindings
{
    ClassDB::bind_method(D_METHOD("init"), &IceType::init);
    ClassDB::bind_method(D_METHOD("doTick"), &IceType::doTick);
    ClassDB::bind_method(D_METHOD("eat"), &IceType::eat);
}