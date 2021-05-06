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

#include "monsterBase.h"
#include "fireType.h"
#include "forestType.h"
#include "ghostType.h"
#include "iceType.h"
#include "forestType.h"
#include "rockType.h"
#include "waterType.h"
#include "wifiSniffer.h"

#include "core/ustring.h"
#include "core/reference.h" // Godot reference wrapper

class RfRancher : public Reference
{
    GDCLASS(RfRancher, Reference);
    enum monstTypes {Undefined = -1, Ghost, Fire, Water, Forest, Rock, Ice};

public:
    Node * testGetMonster(String curSSID);
    Node * getMonster();
    int hashSsid(String ssid);

protected:
    static void _bind_methods();

private:
    int determineType(int ssidHash);
};

#endif