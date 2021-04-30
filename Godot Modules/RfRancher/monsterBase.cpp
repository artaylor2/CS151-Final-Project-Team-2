#include "monsterBase.h"

void MonsterBase::init(int ssidHash)
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
    String hexColor = vformat("%x", ssidHash);

    while(hexColor.size() < 7)
    {
        hexColor += '0';
    }

    print_line(vformat("Color Hex: %s", hexColor));

    String tempR = "", tempG = "", tempB = ""; // Hold parts of hex color

    // Feed in the red values from hex color
    tempR = hexColor.substr(0,2);

    // Green values from hex color
    tempG = hexColor.substr(2,2);

    // Blue values from hex color
    tempB = hexColor.substr(4,2);

    // Convert to decimal and fill red
    color[0] = tempR.hex_to_int();

    // Convert to decimal and fill Green
    color[1] = tempG.hex_to_int();

    // Convert to decimal and fill Blue
    color[2] = tempB.hex_to_int();

    // Set blank name
    this->name = "";

    // set temporary type for child classes
    this->type = -1;

    return;
}

void MonsterBase::setName(String newName)
{
    name = newName;
}

bool MonsterBase::eat(int food)
{
    if(this->isDead) // Check if monster is still alive
    {
        return false;
    }

    // Heal hunger
    this->hunger += food; // Add food restored to hunger
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

bool MonsterBase::play()
{
    if(this->isDead) // Check if monster is still alive
    {
        return false;
    }

    this->happiness += 5; // Add 5 happiness
    if(this->happiness > 15) // If is higher than maximum
    {
        this->happiness = 15; // Set to max
    }
    // this->LastHappyTick = time(nullptr);

    return true;
}

void MonsterBase::doTick() // Remove 1 point of hunger and happiness per hour
{
    if(this->isDead) // Check if monster is still alive
    {
        return;
    }

    // Calculate points to remove
    int curTime = time(nullptr);
    double hungerRemove = curTime - this->lastHungerTick;
    double HappyRemove = curTime - this->LastHappyTick;
    hungerRemove /= 3600.0; // Remove 1 per hour
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

String MonsterBase::getName()
{
    return name;
}

String MonsterBase::getHappy()
{
    return vformat("%d / %d", happiness, maxHappiness);
}
String MonsterBase::getHunger()
{
    return vformat("%d / %d", hunger, maxHunger);
}
String MonsterBase::getTime()
{
    return vformat("%d", lastHungerTick);
}
int MonsterBase::getType()
{
    return type;
}

void MonsterBase::_bind_methods()
{
    //ClassDB::bind_method(D_METHOD("init"), &MonsterBase::init);
    ClassDB::bind_method(D_METHOD("setName"), &MonsterBase::setName);    
    //ClassDB::bind_method(D_METHOD("eat"), &MonsterBase::eat);    
    ClassDB::bind_method(D_METHOD("play"), &MonsterBase::play);    
    ClassDB::bind_method(D_METHOD("doTick"), &MonsterBase::doTick);
    ClassDB::bind_method(D_METHOD("getName"), &MonsterBase::getName);
    ClassDB::bind_method(D_METHOD("getHappy"), &MonsterBase::getHappy);
    ClassDB::bind_method(D_METHOD("getHunger"), &MonsterBase::getHunger);
    ClassDB::bind_method(D_METHOD("getTime"), &MonsterBase::getTime);
    ClassDB::bind_method(D_METHOD("getType"), &MonsterBase::getType);
}