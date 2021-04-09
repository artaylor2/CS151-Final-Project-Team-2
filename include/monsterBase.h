#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> // Testing
#include <string>
#include <sstream>

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
    MonsterBase(std::string bssid); // Generates basic data from SSID
    // Default destructor will be created automatically
    ~MonsterBase() = default;
    // Defined destructor unnecessary because no dynamic memory
    void levelUp();
    std::string toStr();
    void setName(); // May need refactoring for GUI integration
    void eat(Food &f);

private:
    std::string name;
    int level; // 0-15
    int hp; // 0-maxHp
    int maxHp; // 20-50
    int hunger; // 0-maxHunger
    int maxHunger; // 5-20
    Rgb color; // r 0-255, g 0-255, b 0-255
};

// BSSID format example:
//      20:4e:7f:21:48:81

#endif