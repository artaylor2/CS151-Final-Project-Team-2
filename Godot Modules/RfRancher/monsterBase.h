#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> // Testing
#include <sstream>
#include <iomanip>
#include <ctime>

#include "core/base/reference.h" // Godot reference wrapper

struct Rgb
{
    int r, g, b;
};

class MonsterBase : public Reference
{
    GDCLASS(MonsterBase, Reference);

public:
    MonsterBase(); // Default constructor as if SSID = 1
    MonsterBase(int ssidHash); // Generates basic data from SSID
    // Default destructor will be created automatically
    virtual ~MonsterBase() = default;
    // Defined destructor unnecessary because no dynamic memory
    std::string toStr() const;
    void setName(); // May need refactoring for GUI integration
    void eat(int f);
    void play();
    void doTick(); // update happiness and hunger values

protected:
    String name;
    int type; // Enum from rfRancher.h
    double happiness; // 0-maxHappiness
    int maxHappiness; // 15
    int LastHappyTick; // last time happiness was updated
    double hp; // 0-maxHp
    int maxHp; // 20-50
    double hunger; // 0-maxHunger
    int maxHunger; // 5-20
    int lastHungerTick; // last time hunger was updated
    bool isDead; // current living status
    Rgb color; // r 0-255, g 0-255, b 0-255

    static void _bind_methods(); // Godot method wrapper
};

#endif