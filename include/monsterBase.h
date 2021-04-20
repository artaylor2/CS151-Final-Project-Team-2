#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> // Testing
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "rfRancher.h" // For enum types

struct Rgb
{
    int r, g, b;
};

struct Food
{
    std::string itemName;
    int hungerRestored;
    Food(std::string name, int hunger)
    {
        itemName = name;
        hungerRestored = hunger;
    }
};

class MonsterBase
{
public:
    MonsterBase(int ssidHash); // Generates basic data from SSID
    // Default destructor will be created automatically
    virtual ~MonsterBase() = default;
    // Defined destructor unnecessary because no dynamic memory
    std::string toStr() const;
    void setName(); // May need refactoring for GUI integration
    void eat(Food &f);
    void play();
    void doTick(); // update happiness and hunger values

protected:
    std::string name;
    int type; // Enum from rfRancher.h
    int happiness; // 0-maxHappiness
    int maxHappiness; // 15
    int LastHappyTick; // last time happiness was updated
    int hp; // 0-maxHp
    int maxHp; // 20-50
    int hunger; // 0-maxHunger
    int maxHunger; // 5-20
    int lastHungerTick; // last time hunger was updated
    bool isDead; // current living status
    Rgb color; // r 0-255, g 0-255, b 0-255
};

#endif