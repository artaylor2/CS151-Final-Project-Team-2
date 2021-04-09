#include "monsterBase.h"

MonsterBase::MonsterBase(std::string bssid)
{
    std::stringstream bssidStrm(bssid);
    int temp;
    bssidStrm >> std::hex >> temp;
    std::cout << temp;
}