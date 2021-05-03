#include "rfRancher.h"

Node * RfRancher::getMonster(String curSSID)
{  
    // Get new hash and type selection integer
    int newHash = hashSsid(curSSID);
    int selection = newHash % 6;

    // Create monster pointer
    if(selection == 0)
    {
        GhostType* m = new GhostType;
        m->init(newHash);
        return m;
    }
    else if(selection == 1)
    {
        FireType* m = new FireType;
        m->init(newHash);
        return m;
    }
    else if(selection == 2)
    {
        WaterType* m = new WaterType;
        m->init(newHash);
        return m;
    }
    else if(selection == 3)
    {
        ForestType* m = new ForestType;
        m->init(newHash);
        return m;
    }
    else if(selection == 4)
    {
        RockType* m = new RockType;
        m->init(newHash);
        return m;
    }
    else
    {
        IceType* m = new IceType;
        m->init(newHash);
        return m;
    }    
}

int RfRancher::hashSsid(String ssid)
{
    int total = 1;
    for(int i = 0; i < ssid.size() - 1; i++)
    {
        total *= ssid[i]; // multiply by each ascii value
        total = total % 9999999 + 1000000; // limit number growth to prevent overflow and zero values
    }

    total = abs(total);

    return total;
}

void RfRancher::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("getMonster"), &RfRancher::getMonster);
    ClassDB::bind_method(D_METHOD("hashSSID"), &RfRancher::hashSsid);
}
