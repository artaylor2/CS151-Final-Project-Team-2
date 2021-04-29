#ifndef RFRANCHER_H
#define RFRANCHER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "monsterBase.h"
#include "scene/main/node.h"
#include "core/string/ustring.h"
#include "core/object/reference.h" // Godot reference wrapper

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