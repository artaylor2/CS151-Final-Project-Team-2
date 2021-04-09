#include "monsterBase.h"

MonsterBase::MonsterBase(std::string bssid)
{
    std::stringstream bssidStrm(bssid);
    int temp;
    bssidStrm >> std::hex >> temp; // Get number from BSSID
    this->level = (temp % 14) + 1; // Assign level

    bssidStrm.get(); // get colon
    bssidStrm >> std::hex >> temp; // Get number from BSSID
    this->maxHp = (temp % 30) + 20; // Assign maxHp
    this->hp = this->maxHp; // Full health by default

    bssidStrm.get(); // get colon
    bssidStrm >> std::hex >> temp; // Get number from BSSID
    this->maxHunger = (temp % 15) + 5; // Assign maxHunger
    this->hunger = this->maxHunger; // Full hunger by default

    bssidStrm.get(); // get colon
    bssidStrm >> std::hex >> temp; // Get number from BSSID
    this->color.r = temp % 255; // Assign red
    
    bssidStrm.get(); // get colon
    bssidStrm >> std::hex >> temp; // Get number from BSSID
    this->color.g = temp % 255; // Assign green
    
    bssidStrm.get(); // get colon
    bssidStrm >> std::hex >> temp; // Get number from BSSID
    this->color.b = temp % 255; // Assign blue

    // Name monster
    setName();
}

void MonsterBase::levelUp()
{
    // Basic stat increases
    this->level++;
    this->maxHp = maxHp * 1.2; // 20% health increase
    this->hp = maxHp; // Full hp
    this->maxHunger += 5; // Add 5 maxHunger
    this->hunger += 5; // Add newly created 5 max hunger
}

std::string MonsterBase::toStr()
{
    std::stringstream strS("");
    strS << name << " " << level << " " << hp << " "
         << maxHp << " " << hunger << " " << maxHunger << " "
         << color.r << " " << color.g << " " << color.b;
    return strS.str();
}

void MonsterBase::setName()
{
    std::cout << "Give this monster a name: ";
    getline(std::cin, name);
}

void MonsterBase::eat(Food &f)
{
    if(this->hunger + f.hungerRestored <= this->maxHunger)
    {
        hunger += f.hungerRestored;
    }
    else
    {
        hunger = maxHunger;
    }
}