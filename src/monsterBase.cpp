#include "monsterBase.h"

MonsterBase::MonsterBase(std::string &ssid)
{
    // Find the product of all ascii chars
    int total = 1;
    for(int i = 0; i < ssid.size(); i++)
    {
        total *= ssid[i]; // multiply by each ascii value
        total = total % 9999999 + 1000000; // limit number growth to prevent overflow and zero values
    }
    total = abs(total); // Value should be positive but just in case...

    this->maxHappiness = 15; // Assign maxHappiness
    this->happiness = this->maxHappiness; // Full by default

    this->maxHp = (total % 30) + 20; // Assign maxHp
    this->hp = this->maxHp; // Full health by default

    this->maxHunger = (total % 15) + 5; // Assign maxHunger
    this->hunger = this->maxHunger; // Full hunger by default

    // Create rgb values by coverting int to Hex
    std::stringstream strS("");
    strS << std::hex << total;
    std::string hexColor = strS.str();
    if(hexColor.size() == 5) // Smallest possible value has 5 digits
    {
        hexColor += "0"; // Append a zero to make it 6 chars
        strS.str(hexColor);
    }

    std::string tempR = "", tempG = "", tempB = ""; // Hold parts of hex color

    // Feed in the red values from hex color
    tempR += strS.get();
    tempR += strS.get();

    // Green values from hex color
    tempG += strS.get();
    tempG += strS.get();

    // Blue values from hex color
    tempB += strS.get();
    tempB += strS.get();

    // Convert to decimal and fill red
    strS.str(tempR);
    strS >> std::hex >> this->color.r;

    // Clear stream, Convert to decimal and fill Green
    strS.str("");
    strS.clear();
    strS.str(tempG);
    strS >> std::hex >> this->color.g;

    // Clear stream, Convert to decimal and fill Blue
    strS.str("");
    strS.clear();
    strS.str(tempB);
    strS >> std::hex >> this->color.b;

    // Name monster
    setName();
}

std::string MonsterBase::toStr() const
{
    std::stringstream strS("");
    strS << name << " " << happiness << " " << maxHappiness << " " << hp << " "
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