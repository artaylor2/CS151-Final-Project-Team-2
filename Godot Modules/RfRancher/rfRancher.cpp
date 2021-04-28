#include "rfRancher.h"

MonsterBase * RfRancher::getMonster(String curSSID)
{  
    int newHash = hashSsid(curSSID);
    MonsterBase * m = new MonsterBase;
    m->init(newHash);

    return m;
}

int RfRancher::hashSsid(String ssid)
{
    int total = 1;
    for(int i = 0; i < ssid.size(); i++)
    {
        total *= ssid[i]; // multiply by each ascii value
        total = total % 9999999 + 1000000; // limit number growth to prevent overflow and zero values
    }

    total = abs(total);

    return total;
}

int RfRancher::determineType(int ssidHash)
{
    return ssidHash % 6;
} // Returns enum defined in rfRancher.h

void RfRancher::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("getMonster"), &RfRancher::getMonster);
}
