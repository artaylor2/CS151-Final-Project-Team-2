#include "fireType.h"

FireType::FireType(int ssidHash) : MonsterBase(ssidHash)
{
    // Set type
    this->type = Fire;

    // Get name
    setName();
}

void FireType::eat(Food &f)
{
    if(this->isDead) // Check if monster is still alive
    {
        std::cout << this->name << " is dead\n";
        return;
    }

    // Heal hunger
    this->hunger += (2 * f.hungerRestored); // Add food restored to hunger
    if(this->hunger > maxHunger) // If is higher than maximum
    {
        this->hunger = maxHunger; // Set to max
    }

    // Heal hp
    this->hp += (f.hungerRestored / 2); // Add half of food restored to hp
    if(this->hp > maxHp) // If is higher than maximum
    {
        this->hp = maxHp; // Set to max
    }
}