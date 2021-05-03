#ifndef RFRANCHER_H
#define RFRANCHER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "monsterBase.h"
#include "fireType.h"
#include "forestType.h"
#include "ghostType.h"
#include "iceType.h"
#include "forestType.h"
#include "rockType.h"
#include "waterType.h"
#include "core/ustring.h"
#include "core/reference.h" // Godot reference wrapper

class RfRancher : public Reference
{
    GDCLASS(RfRancher, Reference);
    enum monstTypes {Undefined = -1, Ghost, Fire, Water, Forest, Rock, Ice};

public:
    Node * getMonster(String curSSID);
    int hashSsid(String ssid);

protected:
    static void _bind_methods();

private:
    int determineType(int ssidHash);
};

#endif