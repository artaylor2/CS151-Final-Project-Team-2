/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief Base type monster template declaraction
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MONSTERBASE_H
#define MONSTERBASE_H

#include <iostream> 
#include <string>
#include <ctime>

#include "scene/main/node.h"    // Godot Node type library
#include "core/ustring.h"   // Godot string library

/**
 * @brief MonsterBase class
 * 
 */
class MonsterBase : public Node
{
    // Godot class wrapping macro
    GDCLASS(MonsterBase, Node)

public:
    // Godot timing flags
    void _notification(int p_what)
    {
        if(p_what == NOTIFICATION_READY)   
        {
        
        }
        else if(p_what == NOTIFICATION_PROCESS)   
        {
            this->doTick();
        }
    }

    MonsterBase() = default ;     // Default constructor as if ssidHash == 1
    void init(int ssidHash);      // Initialize the monster
    void setName(String newName); // May need refactoring for GUI integration
    bool eat(int food);           // Eat food
    bool play();                  // Play
    void doTick();                // update happiness and hunger values

    // Getter methods
    String getName();       
    String getColor();  
    
    float getHappy();
    float getHealth();
    float getHunger();
    int getMaxHappy();
    int getMaxHealth();
    int getMaxHunger();
    
    bool getDead();
    int getType();  

protected:
    // Enum for monster types
    enum monstTypes {Undefined = -1, Ghost, Fire, Water, Forest, Rock, Ice};    
    
    String name; // Monster's name
    String hexColor; // Monster's color augment value
    
    float happiness; // 0-maxHappiness
    int maxHappiness; // 15
    int LastHappyTick; // last time happiness was updated
    float hp; // 0-maxHp
    int maxHp; // 20-50
    float hunger; // 0-maxHunger
    int maxHunger; // 5-20
    int lastHungerTick; // last time hunger was updated
    bool isDead; // current living status
    int color [3]; // r 0-255, g 0-255, b 0-255
    int type; // Enum from rfRancher.h
    static void _bind_methods(); // Godot method bindings
};

#endif