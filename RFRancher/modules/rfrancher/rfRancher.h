/**
 * @file fireType.cpp
 * @author Porath, Jacob & Taylor, Alixandra
 * @brief RfRancher monster and wifi wrapper object declarations
 * @version 0.1
 * @date 2021-05-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef RFRANCHER_H
#define RFRANCHER_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ctime>

// Include all monster subclasses
#include "monsterBase.h"
#include "fireType.h"
#include "forestType.h"
#include "ghostType.h"
#include "iceType.h"
#include "forestType.h"
#include "rockType.h"
#include "waterType.h"
#include "wifiSniffer.h"

#include "core/ustring.h" // Godot string datatype
#include "core/reference.h" // Godot reference wrapper

/**
 * @brief RfRancher monster spawner class
 * 
 */
class RfRancher : public Reference
{
    // Godot wrapping macro
    GDCLASS(RfRancher, Reference);

    // Monster types enum
    enum monstTypes {Undefined = -1, Ghost, Fire, Water, Forest, Rock, Ice};

public:
    Node * testGetMonster(String curSSID); // getMonster() testing version that allows for a custom SSID
    Node * getMonster(); // Get a new monster
    int hashSsid(String ssid); // Hash a String and return the value

protected:
    static void _bind_methods(); // Godot method bindings

private:
    int determineType(int ssidHash); // Return what type of monster is given from a certain hash integer
};

#endif