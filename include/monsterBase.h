#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> // Testing
#include <string>
#include <sstream>

struct rgb
{
    int r, g, b;
};

class MonsterBase
{
public:
    MonsterBase(std::string bssid); // Generates basic data from SSID

private:
    int level;
    int hp;
    int maxHp;
    int hunger;
    int maxHunger;
    rgb color;
};

// BSSID format example:
//      20:4e:7f:21:48:81

#endif