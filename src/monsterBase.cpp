#include "monsterBase.h"

MonsterBase::MonsterBase(int ssidHash)
{
    this->isDead = false; // The monster is currently living

    this->maxHappiness = 15; // Assign maxHappiness
    this->happiness = this->maxHappiness; // Full by default

    this->LastHappyTick = time(nullptr); // Set last time interacted with

    this->maxHp = (ssidHash % 30) + 20; // Assign maxHp
    this->hp = this->maxHp; // Full health by default

    this->maxHunger = (ssidHash % 15) + 5; // Assign maxHunger
    this->hunger = this->maxHunger; // Full hunger by default

    this->lastHungerTick = time(nullptr); // Set last fed to current time

    // Create rgb values by coverting int to Hex
    std::stringstream strS("");
    strS << std::hex << ssidHash;
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

    // set temporary type for child classes
    this->type = Undefined;
}

std::string MonsterBase::toStr() const
{
    std::stringstream strS("");
    strS << name << " " << type << " " << happiness << " " 
         << maxHappiness << " " << LastHappyTick << " " << hp << " "
         << maxHp << " " << hunger << " " << maxHunger << " " 
         << lastHungerTick << " " << isDead << " " 
         << color.r << " " << color.g << " " << color.b;
    return strS.str();
}

void MonsterBase::setName()
{
    if(this->isDead) // Check if monster is still alive
    {
        std::cout << this->name << " is dead\n";
        return;
    }

    std::cout << "Give this monster a name: ";
    getline(std::cin, name);
}

void MonsterBase::eat(Food &f)
{
    if(this->isDead) // Check if monster is still alive
    {
        std::cout << this->name << " is dead\n";
        return;
    }

    this->hunger += f.hungerRestored; // Add food restored to hunger
    if(this->hunger > maxHunger) // If is higher than maximum
    {
        this->hunger = maxHunger; // Set to max
    }
    // Update last fed time
    // this->lastHungerTick = time(nullptr);
}

void MonsterBase::play()
{
    if(this->isDead) // Check if monster is still alive
    {
        std::cout << this->name << " is dead\n";
        return;
    }

    this->happiness += 5; // Add 5 happiness
    if(this->happiness > 15) // If is higher than maximum
    {
        this->happiness = 15; // Set to max
    }
    // this->LastHappyTick = time(nullptr);
}

void MonsterBase::doTick() // Remove 1 point of hunger and happiness per hour
{
    if(this->isDead) // Check if monster is still alive
    {
        std::cout << this->name << " is dead\n";
        return;
    }

    // Calculate points to remove
    int curTime = time(nullptr);
    int hungerRemove = curTime - this->lastHungerTick;
    int HappyRemove = curTime - this->LastHappyTick;
    hungerRemove /= 3600; // Remove 1 per hour
    HappyRemove /= 3600; // Remove 1 per hour

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