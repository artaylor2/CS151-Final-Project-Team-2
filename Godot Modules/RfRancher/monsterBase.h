#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> // Testing
#include <string>
#include <iomanip>
#include <ctime>

#include "scene/main/node.h"
#include "core/string/ustring.h"   // Godot string library
#include "core/object/reference.h" // Godot reference wrapper

class MonsterBase : public Node
{
    GDCLASS(MonsterBase, Node)

public:
    void _notification(int p_what)
    {
        if(p_what == NOTIFICATION_READY)   
        {
        
        }
        else if(p_what == NOTIFICATION_PROCESS)   
        {
            doTick();
        }
    }

    MonsterBase() = default ; // Default constructor as if ssidHash == 1
    void init(int ssidHash);
    void setName(String newName); // May need refactoring for GUI integration
    bool eat(int food);
    bool play();
    void doTick(); // update happiness and hunger values

    // Temp testing methods
    String getName();
    String getHappy();
    String getHunger();
    String getTime();  
    int getType();  

protected:
    enum monstTypes {Undefined = -1, Ghost, Fire, Water, Forest, Rock, Ice};    
    
    String name;
    
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
    int type; // Enum from rfRancher.h

    static void _bind_methods(); // Godot method bindings
};

#endif