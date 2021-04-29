#include "fireType.h"

void FireType::init(int ssidHash)
{
    MonsterBase::init(ssidHash);
    this->type = 1;
    print_line(vformat("Fire Type Set: %d", type));

    return;
}

bool FireType::eat(int food)
{
    if(this->isDead) // Check if monster is still alive
    {
        return false;
    }

    // Heal hunger
    this->hunger += (2 * food); // Add food restored to hunger
    if(this->hunger > maxHunger) // If is higher than maximum
    {
        this->hunger = maxHunger; // Set to max
    }

    // Heal hp
    this->hp += (food / 2); // Add half of food restored to hp
    if(this->hp > maxHp) // If is higher than maximum
    {
        this->hp = maxHp; // Set to max
    }

    return true;
}

void FireType::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("init"), &FireType::init);
    ClassDB::bind_method(D_METHOD("eat"), &FireType::eat);
}