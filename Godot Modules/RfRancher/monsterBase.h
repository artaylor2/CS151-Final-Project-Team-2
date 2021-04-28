#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> // Testing
#include <string>
#include <iomanip>
#include <ctime>

#include "core/string/ustring.h"   // Godot string library
#include "core/object/reference.h" // Godot reference wrapper

class MonsterBase : public Reference
{
    GDCLASS(MonsterBase, Reference)

public:
    MonsterBase(); // Default constructor as if ssidHash == 1
    MonsterBase(int ssidHash); // Generates basic data from SSID
    // Default destructor will be created automatically
    virtual ~MonsterBase() = default;
    // Defined destructor unnecessary because no dynamic memory
    void setName(String newName); // May need refactoring for GUI integration
    bool eat(int food);
    bool play();
    void doTick(); // update happiness and hunger values

    // Temp testing methods
    String getName();
    String getHappy();
    String getHunger();
    String getTime();    

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
    int color [3]; // r 0-255, g 0-255, b 0-255

    static void _bind_methods(); // Godot method bindings
};

#endif